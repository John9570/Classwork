// Modified version of qapp from the text...
//
#include <QApplication>
#include <QString>
#include <QTextEdit>
#include <QDebug>
#include <QTextStream>

int main(int argc, char * argv[]) {
    // All Qt GUI applications need to create one of these at the start of main(). 
    QApplication myapp(argc, argv);
    // we are replacing the widget with a "QTextEdit" window.. 
    QTextEdit wid; 
    wid.setMinimumSize(500,300);
    wid.setAcceptRichText(true);
    qDebug() << "sizeof QTextEdit: " << sizeof(wid) 
             << " sizeof qapplication: " << sizeof(myapp) ;
    QString message;
    QTextStream buf(&message); /* This is a stream that allows us to
        "write" to the string, similar usage to std::stringstream. */
    buf << "A QWdget is " << sizeof(wid)
          << " bytes. \nA QObject is " << sizeof(QObject)
          << " bytes. \nA QApplication is " << sizeof(myapp)
          << " bytes.\n";
// THIS IS REVERSED    message << qDebug();   
    QString newString = QString("<b>is this bold?</b>");
    QString newNewString = QString("<font size=\"8\" color=\"red\">is this red?</font>");
//    wid.append(message);
    wid.append(newString);
    wid.append(newNewString);
    wid.show();    /* Make the label visible. */
    return myapp.exec(); /* Enter the event loop, and wait for
        the user to do something. When the user exits, 
        so does myapp.exec(). */
}

