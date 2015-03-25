#include <QtWidgets>
#include "../include/mainwindow.h"
#include "ui_mainwindow.h"

#define ZERO 0

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
   
    connect(ui->stepButton, SIGNAL(clicked()),this,SLOT(stepSlot()));
    connect(ui->resetButton, SIGNAL(clicked()),this,SLOT(resetSlot()));
    connect(ui->runButton, SIGNAL(clicked()),this,SLOT(runSlot()));
     
    m_PMEM = new QTextEdit;

    //set up the file menu and status bar
    createFileMenu();
//    createStatusBar();
    //add a title
    setWindowTitle(tr("Simulator"));

 
    //populate the data memory 
    for(int i=0; i<512; i++){
        m_DataMem.insert(i, 0);
    }

    //call the reset function
    resetSlot();



 
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


void MainWindow::createFileMenu(){
    // open file action
    m_OpenAction = new QAction(QIcon(), tr("&Open"), this);
    m_OpenAction->setShortcut(tr("Ctrl+O"));
    m_OpenAction->setStatusTip(tr("Open an existing file"));
    m_OpenAction->setEnabled(true);
    connect(m_OpenAction, SIGNAL(triggered()), this, SLOT(openFile()));
    m_FileMenu = menuBar()->addMenu(tr("&File"));
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
  
    int tempPos = 0; 

     //clear window
    ui->programBrowser->clear();

    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Simple Mian Window Example"),
                tr("Cannot read file %1:\n%2.")
                .arg(fileName).arg(file.errorString()));
        return;
    }

    QTextStream in(&file);

    QString firstLine = in.readLine();
    m_ProgMem.insert(tempPos, firstLine);

    tempPos++;

    firstLine.prepend("<font color=\"red\">");
    firstLine.append("</font>");

    ui->programBrowser->append(firstLine);

    while(!in.atEnd()){
        QString line = in.readLine();
        ui->programBrowser->append(line);
        m_ProgMem.insert(tempPos, line);
        tempPos++;
    }


    //statusBar()->showMessage(tr("File loaded"), 2000);


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


void MainWindow::runSlot(){
    
     if(PCvalue == 127 || progHalt == true){
       progHalt = true;       
       return;
     }

     while(progHalt == false){
       stepSlot();
     }
}


void MainWindow::stepSlot(){

     if(PCvalue == 127 || progHalt == true){
       progHalt = true;
       return;
     }
        
     executeNext();
     rephreshPCBrowser(); 
     //dont touch PC if we are jumping! 
     if (!jumped){
       PCvalue++;
     }
     else{
       //else statement uneccesary but it looks better
       //reset jump condition
       jumped = false; 
     }
     updatePC_LCD(PCvalue);

     //fetch next PC instruction and continue
     

}

void MainWindow::resetSlot(){

     progHalt = false;
     jumped = false;
     PCvalue = 0;
     AccValue = 0;
     updatePC_LCD(PCvalue);
     updateAcc_LCD(AccValue);         


 
    //clear data memory
    for(int i=0; i<512; i++){
        m_DataMem.insert(i, 0);
    }
    
    //update data memory and clear program memory
    updateDataMem(); 
    ui->programBrowser->clear();
    ui->outputBrowser->clear();
    m_ProgMem.clear();

}

void MainWindow::updatePC_LCD(int value){
    ui->PC->display(value);
}

void MainWindow::updateAcc_LCD(int value){
    ui->Accumulator->display(value);
}

void MainWindow::updateDataMem(){
    
    ui->dataBrowser->clear();

    for(int i=0; i<512; i++){
       int val = m_DataMem[i];
       QString toWindow = QString::number(i, 16);
       toWindow.append("   |   ");
       toWindow.append(QString::number(val, 10));
       ui->dataBrowser->append(toWindow);
    } 


}

void MainWindow::executeNext(){

QString currentInst = m_ProgMem[PCvalue]; 

QStringList splitInst = currentInst.split(QRegExp("\\s+"));

   if(splitInst[ZERO].contains("LOAD")){
     splitInst = currentInst.split(QRegExp(" "));
     int location = splitInst[1].toInt(NULL,16);

     //error checking
     if((location < 0) || (location > 511)){
        QString error = "Bad instruction location: ";
        error.append(QString::number(location, 10));
        error.append(" At PC line: ");
        error.append(QString::number(PCvalue, 10));      
        ui->outputBrowser->append(error);
        return;
     }

     AccValue = ZERO; 
     addAccumulator(m_DataMem[location]);

   } 
   else if(splitInst[ZERO].contains("STORE")){
     splitInst = currentInst.split(QRegExp(" ")); 
     int location = splitInst[1].toInt(NULL,16);

     if((location < 0) || (location > 511)){
        QString error = "Bad instruction location: ";
        error.append(QString::number(location, 10));
        error.append(" At PC line: ");
        error.append(QString::number(PCvalue, 10));      
        ui->outputBrowser->append(error);
        return;
     }

     m_DataMem.insert(location, AccValue);
     updateDataMem();
   }
   else if(splitInst[ZERO].contains("ADDV")){
      //error checking below here

      //actual add
      addAccumulator(splitInst[1].toInt());
   }
   else if(splitInst[ZERO].contains("ADD")){

     splitInst = currentInst.split(QRegExp(" "));
     int location = splitInst[1].toInt(NULL,16);

     //error checking
     if((location < 0) || (location > 511)){
        QString error = "Bad instruction location: ";
        error.append(QString::number(location, 10));
        error.append(" At PC line: ");
        error.append(QString::number(PCvalue, 10)); 
        ui->outputBrowser->append(error);
        return;
     }

     addAccumulator(m_DataMem[location]);

   }
   else if(splitInst[ZERO].contains("BGTZ")){
   
     int jumpAddr = splitInst[1].toInt();

     //Make sure the branch address is within reach
     if(jumpAddr > m_ProgMem.size()){ 
        QString error = "Bad branch location: ";
        error.append(QString::number(jumpAddr, 10));
        error.append(" At PC line: ");
        error.append(QString::number(PCvalue, 10));
        ui->outputBrowser->append(error);
        return; 
     }
     
     if(AccValue > 0){
        PCvalue = jumpAddr;
        jumped = true; 
     }

   }
   else if(splitInst[ZERO].contains("NOP")){

   }
   else if(splitInst[ZERO].contains("CLEAR")){
      AccValue = ZERO;
      addAccumulator(ZERO);
   }
   else if(splitInst[ZERO].contains("HALT")){
      progHalt = true;
   }
   else if(splitInst[ZERO].contains("OUT")){
      //splitInst = currentInst.split(QRegExp("\"([A-Za-z0-9_\\./\\-\\s]*)\""));
 
     splitInst = currentInst.split(QRegExp("\""));
     splitInst[1].replace("%A", QString::number(AccValue, 10));
     ui->outputBrowser->append(splitInst[1]);
   }
   else{
      QString error = "Unrecognized instruction: ";
      error.append(splitInst[ZERO]);
      error.append(" At PC line: ");
      error.append(QString::number(PCvalue, 10));      
      ui->outputBrowser->append(error);
      progHalt = true; //STOP EXECUTING!
   }   



}


void MainWindow::rephreshPCBrowser(){

  ui->programBrowser->clear();
  
  for(int i=0; i<m_ProgMem.size(); i++){
    
      QString toWindow = m_ProgMem[i];
      if(i == PCvalue){
         toWindow.prepend("<font color=\"red\">");
         toWindow.append("</font>");
      }
      ui->programBrowser->append(toWindow);

  }
}

void MainWindow::addAccumulator(int value){

     AccValue += value; 
    
     if(AccValue > 511){
        AccValue = 511;
     }
     if(AccValue < -512){
        AccValue = -512;
     } 
    
     updateAcc_LCD(AccValue);         
      

}













