#include "firstwidget.h"
#include "ui_firstwidget.h"

FirstWidget::FirstWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FirstWidget)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(buttonSlot()));
}

FirstWidget::~FirstWidget()
{
    delete ui;
}

void FirstWidget::buttonSlot()
{
    emit buttonPushed();
}

void FirstWidget::updateValueView(int value)
{
    ui->lcdNumber->display(value);
}
