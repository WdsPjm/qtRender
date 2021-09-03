//
// Created by WDS on 2021/8/28.
//

#ifndef QTOPENGL_RIGHTDOCKWIDGET_H
#define QTOPENGL_RIGHTDOCKWIDGET_H
#include <QDockWidget>
#include "CommnDockWidget.h"

class RightDockWidget: public CommnDockWidget {
Q_OBJECT
public:
    RightDockWidget(QWidget *parent);
    ~RightDockWidget();

};


#endif //QTOPENGL_RIGHTDOCKWIDGET_H
