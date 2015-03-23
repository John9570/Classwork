#include "mymainwindow.h"
#include "ui_mymainwindow.h"
#include <iostream>

using namespace std;

MyMainWindow::MyMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyMainWindow)
{
    ui->setupUi(this);
    connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),this,SLOT(useIntegerValue(int)));
}

MyMainWindow::~MyMainWindow()
{
    delete ui;
}

void MyMainWindow::useIntegerValue(int value)
{
    QString textLine=QString("The new slider <i>value</i> is <b>%1</b>").arg(value);
    ui->textEdit->append(textLine);
}
