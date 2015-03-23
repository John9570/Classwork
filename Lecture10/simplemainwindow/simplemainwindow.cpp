#include <QtWidgets>
#include "simplemainwindow.h"

//  Simple Window Example for ECE 3574
//  Showing how to use QFileDialog to make it easy to browse
//  for a file to open.  Paul Plassmann

SimpleMainWindow::SimpleMainWindow() {
    // Note that the Central Widget for a Main Window 
    // must be defined.  We use a horizontalSplitter 
    // for no particular reason...
    m_horizontalSplitter = new QSplitter;
    m_TextEdit1 = new QTextEdit;
    m_TextEdit2 = new QTextEdit;
    m_horizontalSplitter->addWidget(m_TextEdit1);
    m_horizontalSplitter->addWidget(m_TextEdit2);
    setCentralWidget(m_horizontalSplitter);

    // set up the file menu and status bar
    createFileMenu();
    createStatusBar();

    // put a title on the top of the window
    setWindowTitle(tr("Dictionary"));
}

void SimpleMainWindow::openFile() {
    // We use QDileDialog to browse files... very easy!
    QString fileName = QFileDialog::getOpenFileName(this);
    if (!fileName.isEmpty()) {
        loadFile(fileName);
    }
}

void SimpleMainWindow::saveFile() {
    // We use QDileDialog to browse files... very easy!
    QString fileName = QFileDialog::getSaveFileName(this);
    if (!fileName.isEmpty()) {
        saveFile(fileName);
    }
}

void SimpleMainWindow::exitApplication() {
    // qApp is a global variable that points to the QApplication
    // whose event loop is being run in the main()
    qApp->quit();
}

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
    // exit action
    m_ExitAction = new QAction(QIcon(), tr("&Exit"), this);
    m_ExitAction->setShortcut(tr("Ctrl+E"));
    m_ExitAction->setStatusTip(tr("Exit Application"));
    connect(m_ExitAction, SIGNAL(triggered()), this, SLOT(exitApplication()));
    m_ExitMenu = menuBar()->addMenu(tr("&Exit"));
    m_ExitMenu->addAction(m_ExitAction);
}

void SimpleMainWindow::createStatusBar() {
    m_StatusLabel = new QLabel(tr(" Status Label "));
    m_StatusLabel->setAlignment(Qt::AlignHCenter);
    m_StatusLabel->setMinimumSize(m_StatusLabel->sizeHint());
    m_StatusLabel->clear();

    statusBar()->addWidget(m_StatusLabel, 0);
}

void SimpleMainWindow::loadFile(const QString &fileName) {
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Simple Mian Window Example"),
                tr("Cannot read file %1:\n%2.")
                .arg(fileName).arg(file.errorString()));
        return;
    }

    QTextStream in(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    m_TextEdit1->setPlainText(in.readAll());
    QApplication::restoreOverrideCursor();

    setCurrentFile(fileName);
    statusBar()->showMessage(tr("File loaded"), 2000);
}

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
        setWindowTitle(tr("Simple Main Window Example"));
    else
        setWindowTitle(tr("%1 - %2").arg(strippedName(m_FileName))
                .arg(tr("Simple Main Window Example")));
}

QString SimpleMainWindow::strippedName(const QString &fullFileName) {
    return QFileInfo(fullFileName).fileName();
}

