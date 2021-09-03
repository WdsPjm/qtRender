#ifndef _DOCK_SCEN_TREE_H_
#define _DOCK_SCEN_TREE_H_


#include <QDockWidget>
#include "CommnDockWidget.h"
#include "../QtRendererVideo.h"
class XSlider;
class LeftDockWidget : public CommnDockWidget
{
	Q_OBJECT

public:
	LeftDockWidget(QWidget *parent);
	~LeftDockWidget();

public:
    std::shared_ptr<XSlider>& getSlider();
    std::shared_ptr<QtRendererVideo> mRenderVideo;
    void  setRenderVideo(std::shared_ptr<QtRendererVideo>& renderVideo);
private:
    std::shared_ptr<XSlider>mSlider;
public slots:
    void slotPicturMix();
    void slotdiscard();



};


#endif