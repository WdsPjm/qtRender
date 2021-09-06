#include <QPushButton>
#include <QTreeWidget>
#include <QVBoxLayout>
#include <QDebug>
#include "LeftDockWidget.h"
#include <iostream>
#include <QButtonGroup>
#include <QGridLayout>
#include "colorbutton.h"
#include "xslider.h"

LeftDockWidget::LeftDockWidget(QWidget *parent): CommnDockWidget(parent)
{
    mSelfName = "LeftDockWidget";
    setFixedWidth(1);

    QWidget *PictureWidget = new QWidget(this);
    QGridLayout* gLayout = new QGridLayout(PictureWidget);

    ColorButton* cbxMix = new ColorButton(this);
    cbxMix->setFixedSize(80,40);
    cbxMix->setText("PctureMix");
    connect(cbxMix, &ColorButton::clicked,this, &LeftDockWidget::slotPicturMix );

    ColorButton* discard = new ColorButton(this);
    discard->setFixedSize(80,40);
    discard->setText("Discard");
    connect(discard, &ColorButton::clicked,this, &LeftDockWidget::slotdiscard );

    gLayout->setSpacing(10);//设置间距
    gLayout->addWidget(cbxMix, 0, 0);//往网格的不同坐标添加不同的组件
    gLayout->addWidget(discard,0,1);
    PictureWidget->setLayout(gLayout);
    this->setWidget(PictureWidget);
    mSlider =std::make_shared<XSlider>(nullptr);

}

LeftDockWidget::~LeftDockWidget()
{
}

void LeftDockWidget::slotPicturMix() {
   mRenderVideo->getQGlFunObj()->setRenderType(RENDERTYPE::SQUARERENDER);
   mRenderVideo->getQGlFunObj()->setShaderType(SHADERTYPE::PICTUREFIX);
   mRenderVideo->getQGlFunObj()->setShaderType(SHADERTYPE::LIGHT);
   mRenderVideo->getQGlFunObj()->rEstartRender();
   mSlider->show();

}

std::shared_ptr<XSlider>& LeftDockWidget::getSlider() {
    return mSlider;
}

void LeftDockWidget::setRenderVideo(std::shared_ptr<QtRendererVideo> &renderVideo) {
  mRenderVideo = renderVideo;
}

void LeftDockWidget::slotdiscard() {
    mRenderVideo->getQGlFunObj()->setRenderType(RENDERTYPE::SQUARERENDER);
    mRenderVideo->getQGlFunObj()->setShaderType(SHADERTYPE::DISCARD);
    mRenderVideo->getQGlFunObj()->rEstartRender();
    mSlider->show();
}





