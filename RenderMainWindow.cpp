//
// Created by WDS on 2021/8/25.
//

#include "RenderMainWindow.h"
#include "Qtbutton/LeftDockWidget.h"
#include "QtButton/BottomDockWidget.h"
#include "QtButton/RightDockWidget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

RenderMainWindow::RenderMainWindow(QWidget *parent) {

    iniUi();
}

RenderMainWindow::~RenderMainWindow() {

}

void RenderMainWindow::slotSliderValueChanged(int value) {
    float tempValue ;
    for(auto tempShder:mQtRenderVideo->getQGlFunObj()->getShaderValues())
    {
        if(tempShder == SHADERTYPE::PICTUREFIX)
        {
            tempValue = (float)value/100.0f;
            mQtRenderVideo->getQGlFunObj()->setmixValue(tempValue);
        }else if(tempShder == SHADERTYPE::DISCARD)
        {
            tempValue = (float)value/100.0f;
            mQtRenderVideo->getQGlFunObj()->setmDiscardValue(tempValue);
        }
        else{

        }
    }

}

bool RenderMainWindow::eventFilter(QObject *watched, QEvent *event) {
    return QObject::eventFilter(watched, event);
}

void RenderMainWindow::iniUi() {

    mQtRenderVideo = std::make_shared<QtRendererVideo>(this);

    QWidget* widgetCenter = new QWidget(this);
    QVBoxLayout* vLayout = new QVBoxLayout(widgetCenter);
    QHBoxLayout* hLayout = new QHBoxLayout(widgetCenter);

    mLeftDockWindow =std::make_shared<LeftDockWidget>(this);
    mLeftDockWindow->setRenderVideo(mQtRenderVideo);
    connect(mLeftDockWindow->getSlider().get(), &XSlider::valueChanged,this,&RenderMainWindow::slotSliderValueChanged);
    mBottomWindow = std::make_shared<BottomDockWidget>(this);
    mRightWindow = std::make_shared<RightDockWidget>(this);

    mLeftDockWindow->setFeatures(QDockWidget::DockWidgetMovable);
    mBottomWindow->setFeatures(QDockWidget::DockWidgetMovable);
    mRightWindow->setFeatures(QDockWidget::DockWidgetMovable);

    mLeftDockWindow->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    mBottomWindow->setAllowedAreas(Qt::BottomDockWidgetArea);
    mRightWindow->setAllowedAreas(Qt::RightDockWidgetArea | Qt::LeftDockWidgetArea);

    this->addDockWidget(Qt::LeftDockWidgetArea, mLeftDockWindow.get());
    this->addDockWidget(Qt::BottomDockWidgetArea,mBottomWindow.get());
    this->addDockWidget(Qt::RightDockWidgetArea, mRightWindow.get());
    hLayout->addWidget(mQtRenderVideo.get());
    vLayout->addLayout(hLayout);
    this->setCentralWidget(widgetCenter);

    showMaximized();
}

