/*
name: John Marshall
S_ID: 905710486
Email: John9570@vt.edu
Class: ECE 3574
Assignment: Homework 3
Date: 3-3-2015
*/




#include "./include/simplemainwindow.h"
#include "./include/mymainwindow.h"
#include <QApplication>

int main( int argc, char ** argv ) {
    QApplication app( argc, argv );
    SimpleMainWindow mainWindow;
//    MyMainWindow w;
//    w.show();
    mainWindow.show();

    return app.exec();


}
