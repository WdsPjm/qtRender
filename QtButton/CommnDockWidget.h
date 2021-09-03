//
// Created by WDS on 2021/8/28.
//

#ifndef QTOPENGL_COMMNDOCKWIDGET_H
#define QTOPENGL_COMMNDOCKWIDGET_H
#include <QDockWidget>
#include <QEvent>
#include <QEnterEvent>
class CommnDockWidget :public  QDockWidget{

Q_OBJECT

public:
    CommnDockWidget(QWidget* parent);
   ~CommnDockWidget();

    void enterEvent(QEnterEvent* event);
    void leaveEvent(QEvent* event);
    void setWindowSize(std::string& selfName, int value);
public:
    std::string mSelfName;
};


#endif //QTOPENGL_COMMNDOCKWIDGET_H
