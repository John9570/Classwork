/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *runButton;
    QPushButton *stepButton;
    QLCDNumber *PC;
    QLCDNumber *Accumulator;
    QLabel *label;
    QLabel *label_2;
    QTextBrowser *programBrowser;
    QTextBrowser *dataBrowser;
    QLabel *label_3;
    QLabel *label_4;
    QTextBrowser *outputBrowser;
    QLabel *label_5;
    QPushButton *resetButton;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(688, 420);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        runButton = new QPushButton(centralWidget);
        runButton->setObjectName(QStringLiteral("runButton"));
        runButton->setGeometry(QRect(20, 10, 101, 21));
        stepButton = new QPushButton(centralWidget);
        stepButton->setObjectName(QStringLiteral("stepButton"));
        stepButton->setGeometry(QRect(130, 10, 101, 21));
        PC = new QLCDNumber(centralWidget);
        PC->setObjectName(QStringLiteral("PC"));
        PC->setGeometry(QRect(290, 20, 64, 23));
        PC->setAutoFillBackground(false);
        PC->setFrameShadow(QFrame::Raised);
        PC->setSegmentStyle(QLCDNumber::Flat);
        Accumulator = new QLCDNumber(centralWidget);
        Accumulator->setObjectName(QStringLiteral("Accumulator"));
        Accumulator->setGeometry(QRect(390, 20, 64, 23));
        Accumulator->setSegmentStyle(QLCDNumber::Flat);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(380, 0, 91, 17));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(280, 0, 67, 17));
        programBrowser = new QTextBrowser(centralWidget);
        programBrowser->setObjectName(QStringLiteral("programBrowser"));
        programBrowser->setGeometry(QRect(20, 90, 221, 192));
        dataBrowser = new QTextBrowser(centralWidget);
        dataBrowser->setObjectName(QStringLiteral("dataBrowser"));
        dataBrowser->setGeometry(QRect(340, 90, 256, 192));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(70, 50, 151, 31));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(410, 60, 111, 17));
        outputBrowser = new QTextBrowser(centralWidget);
        outputBrowser->setObjectName(QStringLiteral("outputBrowser"));
        outputBrowser->setGeometry(QRect(110, 290, 391, 61));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(260, 270, 67, 17));
        resetButton = new QPushButton(centralWidget);
        resetButton->setObjectName(QStringLiteral("resetButton"));
        resetButton->setGeometry(QRect(550, 20, 99, 27));
        MainWindow->setCentralWidget(centralWidget);
        runButton->raise();
        stepButton->raise();
        Accumulator->raise();
        label->raise();
        label_2->raise();
        programBrowser->raise();
        dataBrowser->raise();
        label_3->raise();
        label_4->raise();
        outputBrowser->raise();
        label_5->raise();
        resetButton->raise();
        PC->raise();
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 688, 25));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        runButton->setText(QApplication::translate("MainWindow", "Run", 0));
        stepButton->setText(QApplication::translate("MainWindow", "Step", 0));
        label->setText(QApplication::translate("MainWindow", "Accumulator", 0));
        label_2->setText(QApplication::translate("MainWindow", "        PC", 0));
        label_3->setText(QApplication::translate("MainWindow", "Program Memory", 0));
        label_4->setText(QApplication::translate("MainWindow", "Date Memory", 0));
        label_5->setText(QApplication::translate("MainWindow", "Output", 0));
        resetButton->setText(QApplication::translate("MainWindow", "Reset", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
