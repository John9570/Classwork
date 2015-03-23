#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "model.h"
#include "firstwidget.h"
#include "secondwidget.h"

class controller : public QObject
{
    Q_OBJECT
public:
    explicit controller(QObject *parent = 0);
    void init();

signals:

public slots:

private:
    FirstWidget *myFirstWidget;
    SecondWidget *mySecondWidget;
    Model *myModel;
};

#endif // CONTROLLER_H
