/*
Name: John Marshall
S_ID: 905710486
Email: John9570@vt.edu
Class: ECE 3574
Assignment: Homework 1
Date: 1-29-2015
*/

#include "myBillings.h"


#include <QCoreApplication>
#include <QDebug>
#include "argumentlist.h"

/** Obtain the command line arguments from the currently
    running QApplication */
ArgumentList::ArgumentList() {
   if (qApp != NULL)  /* A global pointer to the current QApplication. */
      *this = qApp->arguments();
}


void ArgumentList::argsToStringlist(int argc, char * argv []) {
   for (int i=0; i < argc; ++i) {
      *this += argv[i];
   }
}

bool ArgumentList::getSwitch (QString option) {
   QMutableStringListIterator itr(*this);
   while (itr.hasNext()) {
     if (option == itr.next()) {
        itr.remove();
        return true;
     }
   }
    return false;
}

QString ArgumentList::getSwitchArg(QString option, QString defaultValue) {
   if (isEmpty())
      return defaultValue;
   QMutableStringListIterator itr(*this);
   while (itr.hasNext()) {
      if (option == itr.next()) {
         itr.remove();
         if (itr.hasNext()) {
            QString retval = itr.next();
            itr.remove();
            return retval;
         }
         else {
            qDebug() << "Missing Argument for " << option;
            return QString();
         }
      }
   }
   return defaultValue;
}

