/*
name: John Marshall
S_ID: 905710486
Email: John9570@vt.edu
Class: ECE 3574
Assignment: Homework 2
Date: 2-15-2015
*/


#ifndef SIMPLEMAINWINDOW_H
#define SIMPLEMAINWINDOW_H

#include <QMainWindow>
#include "mymainwindow.h"


//  Simple Window Example for ECE 3574
//  Showing how to use QFileDialog to make it easy to browse
//  for a file to open.  Paul Plassmann

// forward declarations
class QLabel;
class QTextEdit;
class QSplitter;

// Super simple version of QMianWindow
class SimpleMainWindow : public QMainWindow {
    Q_OBJECT

public:
    SimpleMainWindow();
    MyMainWindow w;
    QString dictSrc;
    QString lastFile;

protected slots:
    virtual void openFile();
    virtual void saveFile();
    virtual void exitApplication();
    virtual void aeDict();
    virtual void beDict();

protected:
    virtual void createFileMenu();
    virtual void createStatusBar();
    virtual void loadFile(const QString &fileName);
    virtual void saveFile(const QString &fileName);
    virtual void setCurrentFile(const QString &fileName);
    QString strippedName(const QString &fullFileName);
    QTextEdit *m_horizontalSplitter;
    QTextEdit *m_TextEdit1;
    QTextEdit *m_TextEdit2;
    QAction *m_OpenAction;
    QAction *m_ExitAction;

    QString m_FileName;

    QMenu *m_FileMenu;
    QMenu *m_ExitMenu;
    QLabel *m_StatusLabel;
};

#endif

