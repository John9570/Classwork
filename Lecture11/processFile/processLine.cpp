#include <QString>
#include <QStringList>
#include <QDebug>

// process a word using a regular expression
inline QString processWord(const QString word)
{
    QString returnWord = word;
    returnWord.replace(QRegExp("^\\W"),"");
    returnWord.replace(QRegExp("^\\W"),"");
    returnWord.replace(QRegExp("\\W$"),"");
    returnWord.replace(QRegExp("\\W$"),"");
    returnWord.replace(QRegExp("[0-9]"),"");
    return(returnWord);
}

// process a word using the qstring replace method
inline QString processWord2(const QString word)
{
    QString returnWord = word;
    returnWord.replace("!","");
    returnWord.replace(".","");
    returnWord.replace(",","");
    returnWord.replace("?","");
    returnWord.replace("'","");
    returnWord.replace("“","");
    returnWord.replace("”","");
    returnWord.replace(" ","");
    return(returnWord);
}

// Take a line from the text, split it into words, and remove extra 
// characters from the words 
QStringList processLine(const QString line)
{
    QStringList splitList = line.split(QRegExp(" |-"));
    QStringList outputList;
    QListIterator<QString> itr (splitList);
    while (itr.hasNext()) {
        QString current = itr.next();
        QString newWord = processWord(current);
        if (newWord.size() > 0) {
            qDebug() << newWord;
            outputList += newWord;
        }
    }
    return(outputList);
}

