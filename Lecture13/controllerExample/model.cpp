#include "model.h"

Model::Model(QObject *parent) :
    QObject(parent)
{
    modelValue = 0;
}

void Model::changeModel()
{
    modelValue++;
    emit modelChanged(modelValue);
}
