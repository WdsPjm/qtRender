cmake_minimum_required(VERSION 3.19)
project(QtOpengl)

set(CMAKE_PREFIX_PATH "G:\\qt6\\installfiles\\6.2.0\\msvc2019_64\\lib\\cmake")
#set(CMAKE_PREFIX_PATH "G:\\qt5.14\\installifle\\5.14.0\\msvc2017_64\\lib\\cmake")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

include_directories(../Soft/include/glew)
include_directories(../Soft/include)
include_directories(../Soft/glfw64/include)
#include_directories(../Soft/OpencvSdk/include)
link_directories(../Soft/lib/glew/x64)
#link_directories(../Soft/OpencvSdk/lib)
link_directories(../Soft/glfw64/lib-vc2019)
include_directories(../Soft/include/ffmpeg)
set(QT_VERSION 6)
set(REQUIRED_LIBS Core Gui Widgets)
#set(REQUIRED_LIBS_QUALIFIED Qt6::Core Qt6::Gui Qt6::Widgets  glew32.lib  OpenGL32.lib  opencv_core451.lib opencv_imgcodecs451.lib)
set(REQUIRED_LIBS_QUALIFIED Qt6::Core Qt6::Gui Qt6::Widgets  glew32.lib  OpenGL32.lib glfw3.lib)

add_executable(${PROJECT_NAME} main.cpp QtRendererVideo.h QtRendererVideo.cpp QtEvent.h GLFun/GlShader.cpp GLFun/GlShader.h GLFun/GlContext.cpp GLFun/GlContext.h GLFun/MyOpenGl.cpp GLFun/MyOpenGl.h QtOpenGlFun/QtOpenglFun.cpp QtOpenGlFun/QtOpenglFun.h GLFun/GlTexture2D.cpp GLFun/GlTexture2D.h
        ../Soft/stbImage/stb_image.cpp RenderMainWindow.cpp RenderMainWindow.h QtButton/xslider.h QtButton/xslider.cpp QtButton/LeftDockWidget.cpp QtButton/LeftDockWidget.h QtButton/BottomDockWidget.cpp QtButton/BottomDockWidget.h QtButton/RightDockWidget.cpp QtButton/RightDockWidget.h
        QtButton/CommnDockWidget.cpp QtButton/CommnDockWidget.h QtButton/colorcombobox.cpp QtButton/colorcombobox.h
        QtButton/colorbutton.cpp QtButton/colorbutton.h QtOpenGlFun/CommonGlobal.h Image/ImageFun.cpp Image/ImageFun.h GLFun/camera.hpp)

if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})
if (WIN32)
    set(DEBUG_SUFFIX)
    if (CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB ${REQUIRED_LIBS})
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt${QT_VERSION}${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
