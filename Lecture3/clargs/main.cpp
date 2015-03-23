#include <QTextStream>

int main (int argCount, char* argValue[])
{    
    QTextStream cout(stdout);

    for (int i=0; i<argCount; i++) {
        cout << "argv# " << i << " is " << argValue[i] << endl;
    }

    if (argCount > 0) {
        cout << "that character is a " << argValue[1][1] << endl;
    }
    return 0; 
}


