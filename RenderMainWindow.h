//
// Created by WDS on 2021/8/25.
//

#ifndef QTOPENGL_RENDERMAINWINDOW_H
#define QTOPENGL_RENDERMAINWINDOW_H
#include <QMainWindow>
#include "QtRendererVideo.h"
#include "QtButton/xslider.h"
#include <QEvent>
class TempMainWindow;
class LeftDockWidget;
class BottomDockWidget;
class RightDockWidget;
class RenderMainWindow : public QMainWindow{
Q_OBJECT
public:
    RenderMainWindow(QWidget *parent = Q_NULLPTR);
    ~RenderMainWindow();

private:
    std::shared_ptr<QtRendererVideo> mQtRenderVideo;
    std::shared_ptr<LeftDockWidget> mLeftDockWindow;
    std::shared_ptr<BottomDockWidget> mBottomWindow;
    std::shared_ptr<RightDockWidget> mRightWindow;
protected:
    bool eventFilter(QObject* watched, QEvent* event);
    void iniUi();
public slots:
    void slotSliderValueChanged(int value);
};


#endif //QTOPENGL_RENDERMAINWINDOW_H
