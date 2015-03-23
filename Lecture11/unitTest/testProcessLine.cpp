// Simple Unit Test for the processLine function
// example from class. Based on "Chapter 1: Writing 
// a Unit Test" from the Qt Test Tutorial in the 
// Qt Documentation.

#include <QtTest/QtTest>
#include <QStringList>

QStringList processLine(const QString);

class TestProcessLine: public QObject
{
    Q_OBJECT
        private slots:
            void processLineSlot();
};

void TestProcessLine::processLineSlot()
{
    QString str = "(Hello There!) I 'hope' ##that James's **TEST** \"works.\"";
    QStringList result = processLine(str);
    if (result.size() == 8) {
        QCOMPARE(result[0], QString("Hello"));
        QCOMPARE(result[1], QString("There"));
        QCOMPARE(result[2], QString("I"));
        QCOMPARE(result[3], QString("hope"));
        QCOMPARE(result[4], QString("that"));
        QCOMPARE(result[5], QString("James's"));
        QCOMPARE(result[6], QString("TEST"));
        QCOMPARE(result[7], QString("works"));
    } else {
        QCOMPARE(result.size(), 8);
    }
}

QTEST_MAIN(TestProcessLine)
#include "testProcessLine.moc"

