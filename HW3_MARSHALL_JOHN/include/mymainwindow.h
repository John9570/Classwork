/*
name: John Marshall
S_ID: 905710486
Email: John9570@vt.edu
Class: ECE 3574
Assignment: Homework 2
Date: 2-15-2015
*/


#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QMainWindow>
#include "Dictionary.h"
#include "functions.h"

namespace Ui {
class MyMainWindow;
}

class MyMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyMainWindow(QWidget *parent = 0);
    ~MyMainWindow();
    int lastValue;
    void setFile(QString inFile);
    void reset();
    void setAE();
    void setBE(); 

public slots:
    void useIntegerValue(int value);

private:
    Ui::MyMainWindow *ui;
    QString fileName;
    QString dictSrc;
};

#endif // MYMAINWINDOW_H
