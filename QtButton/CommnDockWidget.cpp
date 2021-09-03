//
// Created by WDS on 2021/8/28.
//

#include "CommnDockWidget.h"
#include <iostream>
#include <QDebug>
CommnDockWidget::CommnDockWidget(QWidget *parent): QDockWidget(parent) {

}

CommnDockWidget::~CommnDockWidget() {

}

void CommnDockWidget::enterEvent(QEnterEvent *event) {

    setWindowSize(mSelfName,200);
    QWidget::enterEvent(event);
}

void CommnDockWidget::leaveEvent(QEvent *event) {
    setWindowSize(mSelfName,1);
    QWidget::leaveEvent(event);
}

void CommnDockWidget::setWindowSize(std::string &selfName, int value) {
    if(selfName == "BottomDockWidget")
    {
        setFixedHeight(value);
    }else if(selfName == "LeftDockWidget"){
        setFixedWidth(value);
    }else{
        setFixedWidth(value);
    }

}
