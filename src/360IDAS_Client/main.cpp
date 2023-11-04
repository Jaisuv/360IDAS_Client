#include "Window/widget.h"
#include "Window/csettinginit.h"
#include <QApplication>
#include "Window/loginwin.h"
#include "Window/systemmainwin.h"
#include "Window/videoplayerwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setOrganizationName("360IDAS_Organization");
    a.setApplicationName("360IDAS_Application");

    //开机动画
    Widget w;
    w.show();

    return a.exec();
}
