/*
name: John Marshall
S_ID: 905710486
Email: John9570@vt.edu
Class: ECE 3574
Assignment: Homework 2
Date: 2-15-2015
*/



#include "../include/mymainwindow.h"
#include "ui_mymainwindow.h"
#include <iostream>

using namespace std;


//Constructor
MyMainWindow::MyMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyMainWindow)
{
    ui->setupUi(this);
    connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),this,SLOT(useIntegerValue(int)));
    lastValue = 0;
    
    //default value
    dictSrc = "/usr/share/dict/american-english";

}

MyMainWindow::~MyMainWindow()
{
    delete ui;
}

//This controls what happens when the slider is moved
void MyMainWindow::useIntegerValue(int value)
{

      Dictionary thisDict(dictSrc);

      QStringList toWindow = otherMainHelperFunction(fileName, &thisDict, value);

      //clear the window
      ui->textEdit->clear(); 
       
      //rephresh it
      for(int iterator=0; iterator < toWindow.size(); iterator++){
 
          QString temp = toWindow.at(iterator);
          ui->textEdit->append(temp);

      }

      toWindow = findBadWords(&thisDict, value);
           
          ui->textEdit->append(" "); //newline
 
      for(int iterator=0; iterator < toWindow.size(); iterator++){
 
          QString temp = toWindow.at(iterator);
          ui->textEdit->append(temp);
     }

     lastValue = value; 
 
}

//resets the main window, outside of the slider moving.
void MyMainWindow::reset(){


      Dictionary thisDict(dictSrc);

      QStringList toWindow = otherMainHelperFunction(fileName, &thisDict, lastValue);

      //clear the window
      ui->textEdit->clear(); 
       
      //rephresh it
      for(int iterator=0; iterator < toWindow.size(); iterator++){
 
          QString temp = toWindow.at(iterator);
          ui->textEdit->append(temp);

      }

      toWindow = findBadWords(&thisDict, lastValue);
           
          ui->textEdit->append(" "); //newline
 
      for(int iterator=0; iterator < toWindow.size(); iterator++){
 
          QString temp = toWindow.at(iterator);
          ui->textEdit->append(temp);
      } 


}

//sets the file name to use
void MyMainWindow::setFile(QString inFile){
     fileName = inFile;
}


//sets dictionary to american-english
void MyMainWindow::setAE(){
     dictSrc = "/usr/share/dict/american-english";
}

//sets dictionary to british-english
void MyMainWindow::setBE(){
     dictSrc = "/usr/share/dict/british-english";
}
