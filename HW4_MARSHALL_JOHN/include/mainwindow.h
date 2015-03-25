#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>

namespace Ui {
class MainWindow;
}

//forward declarations
class QLabel;
class QTextEdit;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
//    void executeLine(QString); //parses PC command
    void executeNext();
    void updateDataMem(); 
    void rephreshPCBrowser();
    void addAccumulator(int value);

protected slots:
    virtual void openFile();
    virtual void exitApplication();


public slots:
    void updatePC_LCD(int value);
    void updateAcc_LCD(int value);


private slots:
    void stepSlot();
    void runSlot();
    void resetSlot();

signals:
    void stepPushed();
    void runPushed();
    void resetPushed();

protected:
    virtual void createFileMenu();
    virtual void createStatusBar();
    virtual void loadFile(const QString &fileName);
   // virtual void setCurrentFile(const QString &fileName);
    QString strippedName(const QString &fullFileName);
    QTextEdit *m_PMEM;
    QTextEdit *m_DMEM;
    QAction *m_OpenAction;
    QAction *m_ExitAction;

    //QString m_FileName; 
      
    QMenu *m_FileMenu;
    QMenu *m_ExitMenu;
    QLabel *m_StatusLabel;

private:
    Ui::MainWindow *ui;
    int PCvalue;
    int AccValue;
    QMap<int, int> m_DataMem;
    QMap<int, QString> m_ProgMem;

    bool progHalt; //true when halt reached
    bool jumped;  //true when we are jumping
};

#endif // MAINWINDOW_H
