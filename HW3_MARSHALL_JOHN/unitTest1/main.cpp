/*
name: John Marshall
S_ID: 905710486
Email: John9570@vt.edu
Class: ECE 3574
Assignment: Homework 3
Date: 3-3-2015
*/


#include "../include/simplemainwindow.h"
#include "../include/mymainwindow.h"
#include <QApplication>


//static variables
QTextStream sm_cout(stdout);


int main( int argc, char ** argv ) {
    QApplication app( argc, argv );
    SimpleMainWindow mainWindow;
//    MyMainWindow w;
//    w.show();
//    mainWindow.show();
    

    sm_cout << "This unitTest will test the isWordThere function of the dictionary" << endl;

    sm_cout << "Creating american dictionary object" << endl;
    
    QString fileName = "/usr/share/dict/american-english";
    Dictionary myFancyDict(fileName);
   

    QString badword = "PEWP!";
    sm_cout << "Testing if: " << badword << " is in dict" << endl;   
    if(myFancyDict.isWordThere(badword) == true){
	sm_cout << "ERROR, word shouldnt have been in dictionary" << endl; 
  	return 1;
    }
    else{
	sm_cout << badword << " was not in dictionary, as expected" << endl;
    }
    
    QString goodword = "poop";
  
    if(myFancyDict.isWordThere(goodword) == true){
        sm_cout << goodword << " was in dictionary" << endl; 
    }
    else{ 
	sm_cout << "Error, " << goodword << " was not in dictionary" << endl;
 	return 1;
    }
 
    QString badword2 = "Johnnyboiii";

    sm_cout << "The word " << badword2 << " will be queried 127 times to the dictionary" << endl;
  
    for(int i=0; i<127; i++){
 
        myFancyDict.isWordThere(badword2);

    }

   //Tell the dictionary to create an internal list of top 1
   //bad hit(s). 
   myFancyDict.matchingBadHits(1);

   //get that internal list to print it
   QStringList topBad = myFancyDict.printBadTopHits(); 

    sm_cout << "The current most misspelled word is: " << topBad[0] << endl;




    QString goodword2 = "hi";

    sm_cout << "The word " << goodword2 << " will be queried 100 times to the dictionary" << endl;
  
    for(int i=0; i<100; i++){
 
        myFancyDict.isWordThere(goodword2);

    }

   //Tell the dictionary to create an internal list of top 1
   //bad hit(s). 
   myFancyDict.matchingGoodHits(1);

   //get that internal list to print it
   QStringList topGood = myFancyDict.printGoodTopHits(); 

    sm_cout << "The current most used word is: " << topGood[0] << endl;





    sm_cout << "This unit test has completed successfully." << endl;


    


    return 0;


}
