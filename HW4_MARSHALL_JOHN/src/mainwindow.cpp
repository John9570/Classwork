#include <QtWidgets>
#include "../include/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    PCvalue = 0; //handle in a reset function

    connect(ui->stepButton, SIGNAL(clicked()),this,SLOT(stepSlot()));
    connect(ui->resetButton, SIGNAL(clicked()),this,SLOT(resetSlot()));

    //set up the file menu and status bar
    createFileMenu();
//    createStatusBar();
    //add a title
    setWindowTitle(tr("Simulator"));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::openFile() {
    // We use QDileDialog to browse files... very easy!
    QString fileName = QFileDialog::getOpenFileName(this);
    if (!fileName.isEmpty()) {
        loadFile(fileName);
    }
}

void MainWindow::saveFile() {
    // We use QDileDialog to browse files... very easy!
    QString fileName = QFileDialog::getSaveFileName(this);
    if (!fileName.isEmpty()) {
        saveFile(fileName);
    }
}



void MainWindow::createFileMenu(){
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
    // exit action
    m_ExitAction = new QAction(QIcon(), tr("&Exit"), this);
    m_ExitAction->setShortcut(tr("Ctrl+E"));
    m_ExitAction->setStatusTip(tr("Exit Application"));
    connect(m_ExitAction, SIGNAL(triggered()), this, SLOT(exitApplication()));
    m_ExitMenu = menuBar()->addMenu(tr("&Exit"));
    m_ExitMenu->addAction(m_ExitAction);



}

void MainWindow::loadFile(const QString &fileName) {

}

void MainWindow::saveFile(const QString &fileName) {


}

void MainWindow::createStatusBar() {
    m_StatusLabel = new QLabel(tr(" Status Label "));
    m_StatusLabel->setAlignment(Qt::AlignHCenter);
    m_StatusLabel->setMinimumSize(m_StatusLabel->sizeHint());
    m_StatusLabel->clear();

    statusBar()->addWidget(m_StatusLabel, 0);
}

void MainWindow::exitApplication() {
    // qApp is a global variable that points to the QApplication
    // whose event loop is being run in the main()
    qApp->quit();
}


void MainWindow::stepSlot(){
     PCvalue++;
     updatePC_LCD(PCvalue);
     //fetch next PC instruction and continue


}

void MainWindow::resetSlot(){
//     progHalt = false;
     PCvalue = 0;
     updatePC_LCD(PCvalue);

     //need to reset the view in PC and data mem

}

void MainWindow::updatePC_LCD(int value){
    ui->PC->display(value);
}






