#include "simplemainwindow.h"
#include <QApplication>

int main( int argc, char ** argv ) {
    QApplication app( argc, argv );
    SimpleMainWindow mainWindow;
    mainWindow.show();
    return app.exec();
}
