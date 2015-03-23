#include "secondwidget.h"
#include "ui_secondwidget.h"

SecondWidget::SecondWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SecondWidget)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(buttonSlot()));
}

SecondWidget::~SecondWidget()
{
    delete ui;
}

void SecondWidget::buttonSlot()
{
    emit buttonPushed();
}

void SecondWidget::updateValueView(int value)
{
    ui->textEdit->append(QString("New value is %1").arg(value));
}
