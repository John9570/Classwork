#ifndef MODEL_H
#define MODEL_H

#include <QObject>

class Model : public QObject
{
    Q_OBJECT
public:
    explicit Model(QObject *parent = 0);

signals:
    void modelChanged(int);

public slots:
    void changeModel();

private:
    int modelValue;

};

#endif // MODEL_H
