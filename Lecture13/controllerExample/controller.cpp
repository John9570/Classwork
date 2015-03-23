#include "controller.h"

controller::controller(QObject *parent) :
    QObject(parent)
{
    myFirstWidget = new FirstWidget();
    mySecondWidget = new SecondWidget();
    myModel = new Model(this);
}

void controller::init()
{
    connect(myFirstWidget,SIGNAL(buttonPushed()),myModel,SLOT(changeModel()));
    connect(myModel,SIGNAL(modelChanged(int)),myFirstWidget,
            SLOT(updateValueView(int)));
    connect(mySecondWidget,SIGNAL(buttonPushed()),myModel,SLOT(changeModel()));
    connect(myModel,SIGNAL(modelChanged(int)),mySecondWidget,
            SLOT(updateValueView(int)));
    myFirstWidget->show();
    mySecondWidget->show();
}
