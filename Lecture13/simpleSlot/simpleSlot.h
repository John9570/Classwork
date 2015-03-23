#ifndef SIMPLE_SLOT_H
#define SIMPLE_SLOT_H

// A very simple example of signals and slots.
// Note the Q_OBJECT macro.  Paul Plassmann

#include <QObject>

class SimpleSlot : public QObject
{
Q_OBJECT
  public:
    SimpleSlot();
    int value() const { return m_val; }
  public slots:
    void setValue( int );
  signals:
    void valueChanged( int );
  private:
    int m_val;
};

#endif
