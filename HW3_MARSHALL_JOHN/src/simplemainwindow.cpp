/*
name: John Marshall
S_ID: 905710486
Email: John9570@vt.edu
Class: ECE 3574
Assignment: Homework 2
Date: 2-15-2015
*/


#include <QtWidgets>
#include "../include/simplemainwindow.h"
#include "../include/mymainwindow.h"
#include "../include/Dictionary.h"
#include "../include/functions.h"

//  Main Window for ECE 3574 project 3

SimpleMainWindow::SimpleMainWindow() {
    
    //default dictionary is american
    dictSrc = "/usr/share/dict/american-english";

    m_TextEdit1 = new QTextEdit;
    m_TextEdit1->setMinimumSize(500,350);

    setCentralWidget(m_TextEdit1);

    // set up the file menu and status bar
    createFileMenu();
    createStatusBar();

    // put a title on the top of the window
    setWindowTitle(tr("Dictionary"));

}

//called when the button is clicked
void SimpleMainWindow::openFile() {
    // We use QDileDialog to browse files... very easy!
    QString fileName = QFileDialog::getOpenFileName(this);
    lastFile = fileName;
    if (!fileName.isEmpty()) {
        loadFile(fileName);
    }
}

//called when the menu button is clicked
void SimpleMainWindow::saveFile() {
    // We use QDileDialog to browse files... very easy!
    QString fileName = QFileDialog::getSaveFileName(this);
    if (!fileName.isEmpty()) {
        saveFile(fileName);
    }
}

//called when the menu button is clicked
void SimpleMainWindow::aeDict(){
   
    dictSrc = "/usr/share/dict/american-english";
    w.setAE();
    w.reset();
    loadFile(lastFile);
}

//called when the menu button is clicked
void SimpleMainWindow::beDict(){

    dictSrc = "/usr/share/dict/british-english";
    w.setBE();
    w.reset();
    loadFile(lastFile);
}

//called when the menu button is clicked
void SimpleMainWindow::exitApplication() {
    // qApp is a global variable that points to the QApplication
    // whose event loop is being run in the main()
    qApp->quit();
}


//creates the look of the file menu at the top of the window
void SimpleMainWindow::createFileMenu() {
    // open file action
    m_OpenAction = new QAction(QIcon(), tr("&Open"), this);
    m_OpenAction->setShortcut(tr("Ctrl+O"));
    m_OpenAction->setStatusTip(tr("Open an existing file"));
    m_OpenAction->setEnabled(true);
    connect(m_OpenAction, SIGNAL(triggered()), this, SLOT(openFile()));
    m_FileMenu = menuBar()->addMenu(tr("&File"));
    m_FileMenu->addAction(m_OpenAction);
    // save file action
    m_OpenAction = new QAction(QIcon(), tr("&Save"), this);
    m_OpenAction->setShortcut(tr("Ctrl+S"));
    m_OpenAction->setStatusTip(tr("Save to file"));
    m_OpenAction->setEnabled(true);
    connect(m_OpenAction, SIGNAL(triggered()), this, SLOT(saveFile()));
    m_FileMenu->addAction(m_OpenAction);


    // choose dictionary  action
    m_OpenAction = new QAction(QIcon(), tr("&American-English"), this);
    m_OpenAction->setShortcut(tr("Ctrl+G"));
    m_OpenAction->setStatusTip(tr("Use the American English Dictionary"));
    m_OpenAction->setEnabled(true);
    connect(m_OpenAction, SIGNAL(triggered()), this, SLOT(aeDict()));
    m_FileMenu = menuBar()->addMenu(tr("&Dictionary"));
    m_FileMenu->addAction(m_OpenAction);

    //choose dictonary cont. 
    m_OpenAction = new QAction(QIcon(), tr("&British-English"), this);
    m_OpenAction->setShortcut(tr("Ctrl+B"));
    m_OpenAction->setStatusTip(tr("Use the Britsh English Dictionary"));
    m_OpenAction->setEnabled(true);
    connect(m_OpenAction, SIGNAL(triggered()), this, SLOT(beDict()));
    m_FileMenu->addAction(m_OpenAction);

    // exit action
    m_ExitAction = new QAction(QIcon(), tr("&Exit"), this);
    m_ExitAction->setShortcut(tr("Ctrl+E"));
    m_ExitAction->setStatusTip(tr("Exit Application"));
    connect(m_ExitAction, SIGNAL(triggered()), this, SLOT(exitApplication()));
    m_ExitMenu = menuBar()->addMenu(tr("&Exit"));
    m_ExitMenu->addAction(m_ExitAction);


}

//Creates status bar at the bottom
void SimpleMainWindow::createStatusBar() {
    m_StatusLabel = new QLabel(tr(" Status Label "));
    m_StatusLabel->setAlignment(Qt::AlignHCenter);
    m_StatusLabel->setMinimumSize(m_StatusLabel->sizeHint());
    m_StatusLabel->clear();

    statusBar()->addWidget(m_StatusLabel, 0);
}

//Helper function for openning files
void SimpleMainWindow::loadFile(const QString &fileName) {

    //Dictionary source 

    //Dictionary object
    Dictionary newDict(dictSrc);

    //clear window
    m_TextEdit1->clear();

    QStringList toWindow;

    toWindow = mainHelperFunction(fileName, &newDict); 

    //sets the title (I think) to the current filename
    setCurrentFile(fileName);

    for(int iterator=0; iterator<toWindow.size(); iterator++){
	QString temp = toWindow.at(iterator);
        m_TextEdit1->append(temp);
    } 

    statusBar()->showMessage(tr("File loaded"), 2000);
 
    w.setFile(fileName); //set the filename

    w.reset();

    w.show();


}


//Helper function for saving files
void SimpleMainWindow::saveFile(const QString &fileName) {
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Simple Mian Window Example"),
                tr("Cannot read file %1:\n%2.")
                .arg(fileName).arg(file.errorString()));
        return;
    }

    QTextStream out(&file);
    out << m_TextEdit1->toPlainText() << endl;

    setCurrentFile(fileName);
    statusBar()->showMessage(tr("File saved"), 2000);
}


void SimpleMainWindow::setCurrentFile(const QString &fileName) {
    m_FileName = fileName;
    m_StatusLabel->clear();

    if (m_FileName.isEmpty())
        setWindowTitle(tr("Spell Check Viewer"));
    else
        setWindowTitle(tr("%1 - %2").arg(strippedName(m_FileName))
                .arg(tr("Spell Check Viewer")));
}

QString SimpleMainWindow::strippedName(const QString &fullFileName) {
    return QFileInfo(fullFileName).fileName();
}

