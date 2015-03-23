// Processing File With Regular Expressions Example

#include <QApplication>
#include <QTextEdit>
#include <QDebug>
#include <QStringList>
#include <QTextStream>
#include "qstd.h"
using namespace qstd;

QTextStream cout(stdout);
QTextStream cerr(stderr);

QStringList processLine(const QString);

// process an input file line by line
QStringList processFile(QString inputFileName)
{
    // open the text file
    QFile wordFile(inputFileName);
    QStringList returnStringList;
    if (!wordFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        cerr << "ERROR:  Unable to open word file." << endl;
        return returnStringList;
    }
    QTextStream readFile(&wordFile);

    // read line by line, process the line and insert words into a QStringList
    while (!readFile.atEnd()) {
        QString newLine = readFile.readLine();
        QStringList wordList = processLine(newLine);
        QListIterator<QString> itr (wordList);
        while (itr.hasNext()) {
            QString word = itr.next();
            qDebug() << word;
        }
        returnStringList.append(wordList);
    }
    wordFile.close();
    return(returnStringList);
}

// display the processed words in a TextEdit window
int displayProcessedWordList(const QStringList &outputList, QTextEdit &myWindow)
{
    myWindow.setWindowTitle(QString("Spelling Output"));
    myWindow.setMinimumSize(600,300);
    QListIterator<QString> itr (outputList);
    while (itr.hasNext()) {
        QString current = itr.next();
        myWindow.append(current);
    }
    myWindow.moveCursor(QTextCursor::Start);
    myWindow.show();
    return 0;
}

int main(int argc, char *argv[])
{
    // our Qt application...
    QApplication myApp(argc,argv);

    // get arguments
    QStringList clArguments = myApp.arguments();
    QString filename;

    // check if there is a filename on the command line
    if (clArguments.size() != 2) {
        cout << "should be ./processFile <filename>" << endl;
        return 0;
    } else {
        filename = clArguments[1];
    }

    // Output the processed words from the file
    QStringList outputList = processFile(filename);
    QTextEdit myWindow;
    displayProcessedWordList(outputList, myWindow);

    // enter the event loop...
    return myApp.exec();
}

