#include <QApplication>
//#include "QtRendererVideo.h"
#include "RenderMainWindow.h"
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
  //  QtRendererVideo t;
  RenderMainWindow t;
  t.show();
    return QApplication::exec();
}
