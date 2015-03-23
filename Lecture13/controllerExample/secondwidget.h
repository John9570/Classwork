#ifndef SECONDWIDGET_H
#define SECONDWIDGET_H

#include <QWidget>

namespace Ui {
    class SecondWidget;
}

class SecondWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SecondWidget(QWidget *parent = 0);
    ~SecondWidget();

public slots:
    void updateValueView(int);

private slots:
    void buttonSlot();

signals:
    void buttonPushed();

private:
    Ui::SecondWidget *ui;
};

#endif // SECONDWIDGET_H
