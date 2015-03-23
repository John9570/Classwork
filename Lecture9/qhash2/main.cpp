#include <QString>
#include <QMap>
#include <QDebug>
#include <QTime>
#include <iostream>
using namespace std;

// number of inserts an finds to do
const int NUM_SAMPLES = 2000000;

/* Simple example of QMap with timer etc */

int main() {

    QMap<int, QString> myMapTable;
    QTime timer;
    int msecTime;

    timer.start();
    QString str;
    for (int i=0; i<NUM_SAMPLES*2; i+=2) {
        str = QString("Value is %1").arg(i);
        myMapTable.insert(i,str);
    }
    msecTime = timer.elapsed();
    cout << "Time to insert " << NUM_SAMPLES 
    	<< " items into the hash table is " 
    	<< (float)msecTime/1000.0
    	<< " sec."  << endl;

    QMap<int, QString>::iterator itr;
    int key;
    timer.start();
    for (int i=0; i<NUM_SAMPLES; i+=1) {
        key = rand()%(NUM_SAMPLES*2);
        itr = myMapTable.find(key);
        if (itr != myMapTable.end()) {
            qDebug() << "Value for key " << key << " is " 
            	<< itr.value();
        } else {
            qDebug() << "Nothing in the hash table for key " 
            	<< key;
        }
    }
    msecTime = timer.elapsed();
    cout << "Time to retrieve " 
    	<< NUM_SAMPLES << " values from table is " 
    	<< (float)msecTime/1000.0 << " sec." 
    	<< endl;

    return 0;
}

