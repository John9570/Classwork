#include "simpleSlot.h"

// A very simple signals and slots example.
// The setValue method is the slot and 
// valueChanged is the signal.  They both
// must have the same type to be able to be
// connected.  Paul Plassmann

// constructor does nothing
SimpleSlot::SimpleSlot()
{
}

// if the value changes, send a signal
void SimpleSlot::setValue( int v )
{
    if ( v != m_val ) {
       m_val = v;
       emit valueChanged(v);
    }
}

