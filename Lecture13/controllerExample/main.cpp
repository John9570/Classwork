#include <QApplication>
#include "controller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    controller myController;
    myController.init();

    return a.exec();
}
