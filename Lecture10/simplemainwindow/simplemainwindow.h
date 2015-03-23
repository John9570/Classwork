#ifndef SIMPLEMAINWINDOW_H
#define SIMPLEMAINWINDOW_H

#include <QMainWindow>

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

protected slots:
    virtual void openFile();
    virtual void saveFile();
    virtual void exitApplication();

protected:
    virtual void createFileMenu();
    virtual void createStatusBar();
    virtual void loadFile(const QString &fileName);
    virtual void saveFile(const QString &fileName);
    virtual void setCurrentFile(const QString &fileName);
    QString strippedName(const QString &fullFileName);
    QSplitter *m_horizontalSplitter;
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

