#include <QString>
#include <QHash>
#include <QDebug>

/* Very simple example of QHash */

int main() {

    QHash<int, QString> myHashTable;

    int key = 1400;
    QString str = QString("Hello There");
    myHashTable.insert(key,str);
    
    int key2 = 347;
    QString str2 = QString("To be or not to be");
    myHashTable.insert(key2,str2);

    int key3 = 3400;
    QString str3 = QString("blah");
    myHashTable.insert(key3,str3);

    int key4 = 7892;
    QString str4 = QString("Who is John Galt?");
    myHashTable.insert(key4,str4);

    qDebug() << "++++++++++++++++";
    QHash<int, QString>::iterator itr = myHashTable.find(key2);
    if (itr != myHashTable.end()) {
        qDebug() << "Value for key2 is " << itr.value();
    } else {
        qDebug() << "Nothing in the hash table";
    }

    qDebug() << "++++++++++++++++";
    // Can run through list of items in QHash
    itr = myHashTable.begin();
    qDebug() << "My Hash Table:";
    while (itr != myHashTable.end()) {
        qDebug() << itr.key() << " " << itr.value();
        itr++;
    }

    qDebug() << "++++++++++++++++";
    // can sort Qt containers that contain things with "<" defined
    QList<int> myList;
    myList << 2 << 5 << 1 << 3;
    QList<int>::iterator itr2 = myList.begin();
    qDebug() << "Before sort:";
    while (itr2 != myList.end()) {
        qDebug() << *itr2;
        itr2++;
    }

    qDebug() << "++++++++++++++++";

    // After sort
    qSort(myList.begin(),myList.end());
    itr2 = myList.begin();
    qDebug() << "After sort:";
    while (itr2 != myList.end()) {
        qDebug() << *itr2;
        itr2++;
    }

    qDebug() << "++++++++++++++++";
    return 0;
}

