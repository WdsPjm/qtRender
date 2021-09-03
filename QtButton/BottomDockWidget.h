//
// Created by WDS on 2021/8/28.
//

#ifndef QTOPENGL_BOTTOMDOCKWIDGET_H
#define QTOPENGL_BOTTOMDOCKWIDGET_H
#include <QDockWidget>
#include "CommnDockWidget.h"

class BottomDockWidget: public CommnDockWidget {
Q_OBJECT

public:
    BottomDockWidget(QWidget *parent);
    ~BottomDockWidget();


};


#endif //QTOPENGL_BOTTOMDOCKWIDGET_H
