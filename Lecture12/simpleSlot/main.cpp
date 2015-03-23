// A really simple example of signals and slots
// Note that this program does not use an event loop
// Idea is that a change to b affects a change to c
// and that a change to a affects a change to b, etc.

#include <QTextStream>
#include "simpleSlot.h"

static QTextStream cout(stdout, QIODevice::WriteOnly);

int main() {
    using namespace std;
    SimpleSlot a, b, c;
    a.setValue( 1 );
    b.setValue( 2 );
    c.setValue( 3 );
    cout << "The initial values of a, b, and c are: " << a.value() << ", " 
       << b.value() << ", " << c.value() << endl;
    cout << "Setting a to 4" << endl;
    a.setValue( 4 );
    cout << "After this, the values of a, b, and c are: " << a.value() << ", " 
       << b.value() << ", " << c.value() << endl;
    cout << "Now we connect up some signals and slots: a -> b -> c" << endl;
    SimpleSlot::connect(&a, SIGNAL(valueChanged(int)), &b, SLOT(setValue(int)));
    SimpleSlot::connect(&b, SIGNAL(valueChanged(int)), &c, SLOT(setValue(int)));
    cout << "Setting b to 11" << endl;
    b.setValue( 11 ); 
    cout << "After this, the values of a, b, and c are: " << a.value() << ", " 
       << b.value() << ", " << c.value() << endl;
    cout << "Setting a to 79" << endl;
    a.setValue( 79 ); // a == 79         b == 79
    cout << "After this, the values of a, b, and c are: " << a.value() << ", " 
       << b.value() << ", " << c.value() << endl;
    return(0);
};

