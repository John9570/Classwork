#include <QString>
#include <QMap>
#include <QDebug>
#include <QTime>
#include <iostream>
using namespace std;

// number of inserts an finds to do
const int MAX_NUM_SAMPLES = 2000000;
// incremental number of samples
const int INTERVAL_NUM_SAMPLES = 100000;

/* Simple example of QMap with timer etc */

int main() {

    QMap<int, QString> myMapTable;
    QTime timer;
    int msecTime;

    for (int n=INTERVAL_NUM_SAMPLES; n<= MAX_NUM_SAMPLES; n+=INTERVAL_NUM_SAMPLES) {
        timer.start();
        QString str;
        for (int i=0; i<n*2; i+=2) {
            str = QString("Value is %1").arg(i);
            myMapTable.insert(i,str);
        }
        msecTime = timer.elapsed();
        cout << "Rate to insert " << n
    	      << " items into the hash table is " 
    	      << (float)msecTime*1000.0/(float)n
    	      << " microseconds/item."  << endl;

        QMap<int, QString>::iterator itr;
        int key;
        timer.start();
        for (int i=0; i<n; i+=1) {
            key = rand()%(n*2);
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
        cout << "Rate to retrieve " 
    	      << n << " values from table is " 
    	      << (float)msecTime*1000.0/float(n) << " microseconds/item." 
    	      << endl;
        // clear out the table
        myMapTable.clear();
    }

    return 0;
}

