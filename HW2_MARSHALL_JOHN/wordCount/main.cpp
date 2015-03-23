/*
name: John Marshall
S_ID: 905710486
Email: John9570@vt.edu
Class: ECE 3574
Assignment: Homework 2
Date: 2-15-2015
*/

#include "../include/Dictionary.h"
#include "../include/functions.h"


QTextStream sm_cout(stdout);

int main(int argc, char *argv[])
{

	// All Qt GUI applications need to create one of these at the start of main(). 
	QApplication myapp(argc, argv);

	//Initialize the text window
	QTextEdit wid;
	QTextEdit badWid;

	wid.setMinimumSize(500,300);
        wid.setAcceptRichText(true);

	badWid.setMinimumSize(500,300);
        badWid.setAcceptRichText(true);

	QString inputDict = argv[2];
	QString dictName;
	if(inputDict == "american"){
		dictName = "/usr/share/dict/american-english";
	}
	else if(inputDict == "british"){
		dictName = "/usr/share/dict/british-english";
	}

	QString inputInt = argv[3];
	int inputInteger = inputInt.toInt();



	//dictionary object
	Dictionary myDict(dictName);

	//file from commandline arg
	QString inFile(argv[1]);

	//This creates a list of edited strings
	QStringList editedFile = otherMainHelperFunction(inFile, &myDict, inputInteger);

	//Take strings from the list, and append to window
	for(int iterator=0; iterator < editedFile.size(); iterator++){
	
		QString temp = editedFile.at(iterator);

		wid.append(temp);

	}


	

	editedFile = findBadWords(&myDict, inputInteger);


	//Take strings from the list, and append to window
	for(int iterator=0; iterator < editedFile.size(); iterator++){
	
		QString temp = editedFile.at(iterator);

		badWid.append(temp);

	}


	//make it visible
	wid.show(); 
	badWid.show(); 

	//enter event loop
	return myapp.exec(); 
}
