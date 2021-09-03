//
// Created by WDS on 2021/8/28.
//

#include "BottomDockWidget.h"
#include <iostream>
#include <QPushButton>
BottomDockWidget::BottomDockWidget(QWidget *parent): CommnDockWidget(parent)
{
    QPushButton* test = new QPushButton("Bottom",this);
    mSelfName = "BottomDockWidget";
    setFixedHeight(1);
}

BottomDockWidget::~BottomDockWidget() {

}


