#ifndef _QT_RENDERVIDEO_H_
#define _QT_RENDERVIDEO_H_
#include <QtWidgets/QWidget>
#include <windows.h>
#include <QEvent>
#include "GL/eglew.h"
#include "GLFun/GlContext.h"
#include "GLFun/MyOpenGl.h"
#include "QtOpenGlFun/QtOpenglFun.h"
class GlShader;

class QtRendererVideo : public QWidget {
Q_OBJECT

public:
    QtRendererVideo(QWidget *parent = Q_NULLPTR);
    ~QtRendererVideo();

public:
    virtual  QPaintEngine* paintEngine() const { return NULL; }
    virtual void resizeEvent(QResizeEvent* event);
    std::shared_ptr<QtOpenglFun>& getQGlFunObj();
private:
    void Renderer();
    bool  event(QEvent* event);
    void UpdateRender();
    void IniRender();
    std::shared_ptr<QtOpenglFun>mQtOpenglFun = nullptr;
protected:
    bool eventFilter(QObject* watched, QEvent* event);

public slots:
    void Tick();
};
#endif