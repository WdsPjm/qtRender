//
// Created by WDS on 2021/8/28.
//

#include "RightDockWidget.h"
#include <QPushButton>
RightDockWidget::RightDockWidget(QWidget *parent): CommnDockWidget(parent) {
    QPushButton* btn = new QPushButton("Right",this);
    mSelfName = "RightDockWidget";
    setFixedWidth(1);
}

RightDockWidget::~RightDockWidget() {

}

