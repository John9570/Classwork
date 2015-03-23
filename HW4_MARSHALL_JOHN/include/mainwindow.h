#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

protected slots:
    virtual void openFile();
    virtual void saveFile();
    virtual void exitApplication();


public slots:
    void updatePC_LCD(int);
  //  void updateAccumulator_LCD(int);


private slots:
    void stepSlot();
  //  void runSlot();
    void resetSlot();

signals:
    void stepPushed();
//    void runPushed();
    void resetPushed();

protected:
    virtual void createFileMenu();
    virtual void createStatusBar();
    virtual void loadFile(const QString &fileName);
    virtual void saveFile(const QString &fileName);
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
//    bool progHalt; //true when halt reached
   // QList<int> m_DataMem;
//    Qlist<QString> m_ProgMem;

};

#endif // MAINWINDOW_H
