#ifndef PERSON_H
#define PERSON_H

#include <QObject>
#include <QString>

class Person : public QObject {
 public:
    Person(QObject* parent, QString name);
    virtual ~Person();
};

#endif 
