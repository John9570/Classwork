/*
name: John Marshall
S_ID: 905710486
Email: John9570@vt.edu
Class: ECE 3574
Assignment: Homework 2
Date: 2-15-2015
*/



//put #includes here
#include <QString>
#include <QHash>
#include <QFile>
#include <QStringList>
#include <QTextStream>
#include "qstd.h"
#include "Dictionary.h"

#include <QApplication>
#include <QTextEdit>
#include <QWidget>





QStringList mainHelperFunction(QString inputFile, Dictionary *obj);



QStringList otherMainHelperFunction(QString inputFile, Dictionary *obj, int hit);

QStringList findBadWords(Dictionary *obj, int hit);

