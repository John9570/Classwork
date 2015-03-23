/*
name: John Marshall
S_ID: 905710486
Email: John9570@vt.edu
Class: ECE 3574
Assignment: Homework 3
Date: 3-3-2015
*/


#include "../include/simplemainwindow.h"
#include "../include/mymainwindow.h"
#include <QApplication>


//static variables
QTextStream sm_cout(stdout);


int main( int argc, char ** argv ) {
    QApplication app( argc, argv );
    SimpleMainWindow mainWindow;
    MyMainWindow w;
    w.show();
//    mainWindow.show();
    

    sm_cout << "This unitTest will test the Dictionary GUI (American)" << endl;

      
    sm_cout << "OPENING THE TEST FILE NOW." << endl; 
    QString fileName = "./test.txt";

    w.setFile(fileName);

    w.reset(); 

    sm_cout << "You should now have just the wordcount window and slider on your screen" << endl;

    sm_cout << "Moving the slider far right should display all words in file" << endl;

    sm_cout << "Close the window to end test." << endl;

//    mainWindow.show();

//    mainWindow.loadFile(fileName);



    return app.exec();





}
