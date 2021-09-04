#include <QResizeEvent>
#include <QApplication>
#include "QtRendererVideo.h"
#include <QEvent>
#include "QtEvent.h"
#include <Qtimer>
#include <QMouseEvent>
#include <QDir>
#include <memory>
#include "GLFun/GlShader.h"
#include "QtOpenGlFun/QtOpenglFun.h"
#include "Image/ImageFun.h"

QtRendererVideo::QtRendererVideo(QWidget *parent):QWidget(parent, Qt::MSWindowsOwnDC)
{
    setAttribute(Qt::WA_PaintOnScreen); //禁用默认的渲染引擎
    setAttribute(Qt::WA_NoSystemBackground);
    setAutoFillBackground(true);

    mQtOpenglFun= std::make_shared<QtOpenglFun>();
    mQtOpenglFun->QtGLinit((HWND)winId());

    setFocusPolicy(Qt::FocusPolicy::TabFocus);
  
    setMouseTracking(true);
    IniRender();
    QTimer *timer = new QTimer(parent);
    timer->setInterval(1);
    connect(timer, &QTimer::timeout, this, &QtRendererVideo::Tick);
    timer->start();
    installEventFilter(this);
}

QtRendererVideo::~QtRendererVideo()
{
}
void QtRendererVideo::resizeEvent(QResizeEvent* event)
{
    glViewport(0, 0, event->size().width(),  event->size().height());
    UpdateRender();
}

void QtRendererVideo::Renderer() {
    mQtOpenglFun->setWidthHeigth(1920,1080);
    mQtOpenglFun->QtRender();
}


void QtRendererVideo::UpdateRender()
{

    QApplication::postEvent(this, new QtEvent(QtEvent::QtEventType::GL_Render));
}


void QtRendererVideo::IniRender()
{
    mQtOpenglFun->QtInitRender();
}


bool QtRendererVideo::event(QEvent *event) {

    if (event->type() == QtEvent::QtEventType::GL_Render)
    {
        Renderer();
    }
    return QWidget::event(event);
}

void QtRendererVideo::Tick() {

     UpdateRender();
  //  ImageFun::snap_shot(512,512);
}

std::shared_ptr<QtOpenglFun>& QtRendererVideo::getQGlFunObj() {
    return mQtOpenglFun;
}
//
bool QtRendererVideo::eventFilter(QObject *watched, QEvent *event) {
//    if (!tsk->taskStart_)
//    {
//        return true;
//    }

    //qDebug() << event->type() << endl;

    if (watched == this)
    {
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            std::cout<<mQtOpenglFun->getCameraType()->type<<std::endl;
            std::cout<<Camera::firstperson<<std::endl;
            if (mQtOpenglFun->getCameraType()->type == Camera::firstperson)
            {
                if (keyEvent->key() == Qt::Key_A)
                {
                    mQtOpenglFun->getCameraType()->keys.left = true;
					/*float x = QCursor::pos().x();
					float y = QCursor::pos().y();
					mQtOpenglFun->handleMouseMove(x, y);*/
                }
                else if (keyEvent->key() == Qt::Key_D)
                {
                    mQtOpenglFun->getCameraType()->keys.right = true;
                }
                else if (keyEvent->key() ==Qt::Key_S)
                {
                    mQtOpenglFun->getCameraType()->keys.down = true;
                }
                else if (keyEvent->key() == Qt::Key_W)
                {
                    mQtOpenglFun->getCameraType()->keys.up = true;
                }
				
            }

        }
        else if (event->type() == QEvent::KeyRelease)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if (mQtOpenglFun->getCameraType()->type == Camera::firstperson)
            {
                if (keyEvent->key() == Qt::Key_A)
                {
                    mQtOpenglFun->getCameraType()->keys.left = false;
                }
                else if (keyEvent->key() == Qt::Key_D)
                {
                    mQtOpenglFun->getCameraType()->keys.right = false;
                }
                else if (keyEvent->key() == Qt::Key_S)
                {
                    mQtOpenglFun->getCameraType()->keys.down = false;
                }
                else if (keyEvent->key() == Qt::Key_W)
                {
                    mQtOpenglFun->getCameraType()->keys.up = false;
                }

            }
        }

        else if (event->type() == QEvent::MouseMove)
        {
            float x = QCursor::pos().x();
            float y = QCursor::pos().y();
            mQtOpenglFun->handleMouseMove(x, y);


        }
        else if (event->type() == QEvent::MouseButtonRelease)
        {

            mQtOpenglFun->mouseButtons.right = false;
            mQtOpenglFun->mouseButtons.left = false;
            mQtOpenglFun->mouseButtons.middle = false;
            mQtOpenglFun->mouseButtons.middleScal = false;

        }
        else if (event->type() == QEvent::MouseButtonPress)
        {
            auto event1 = dynamic_cast<QMouseEvent*>(event);


            if (event1->button() == Qt::RightButton)
            {
                mQtOpenglFun->mouseButtons.right = true;
                mQtOpenglFun->mouseButtons.left = false;
                mQtOpenglFun->mouseButtons.middle = false;
                mQtOpenglFun->mouseButtons.middleScal = true;
            }
            else if (event1->button() == Qt::MiddleButton)
            {
                mQtOpenglFun->mouseButtons.middle = true;
            }
            else if (event1->button() == Qt::LeftButton)
            {
                mQtOpenglFun->mouseButtons.left = true;
                mQtOpenglFun->mouseButtons.right = false;
                mQtOpenglFun->mouseButtons.middle = false;
                mQtOpenglFun->mouseButtons.middleScal = false;


            }
        }
        else if (event->type() == QEvent::Wheel)
        {
            mQtOpenglFun->mouseButtons.middle = false;
            mQtOpenglFun->mouseButtons.left = false;
            mQtOpenglFun->mouseButtons.right = false;
            mQtOpenglFun->mouseButtons.middleScal = true;
            auto event1 = dynamic_cast<QWheelEvent*>(event);

            if (mQtOpenglFun->mouseButtons.middleScal)
            {
                //short wheelDelta = event1->pixelDelta();
                //TODO
                short wheelDelta = 1.0;
                mQtOpenglFun->MouseWheelScal(wheelDelta);
            }
        }

    }
    return QWidget::eventFilter(watched, event);
}



