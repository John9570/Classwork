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
	wid.setMinimumSize(500,300);
        wid.setAcceptRichText(true);

	QString inputDict = argv[2];
	QString dictName;
	if(inputDict == "american"){
		dictName = "/usr/share/dict/american-english";
	}
	else if(inputDict == "british"){
		dictName = "/usr/share/dict/british-english";
	}



	//dictionary object
	Dictionary myDict(dictName);

	//file from commandline arg
	QString inFile(argv[1]);

	//This creates a list of edited strings
	QStringList editedFile = mainHelperFunction(inFile, &myDict);

	//Take strings from the list, and append to window
	for(int iterator=0; iterator < editedFile.size(); iterator++){
	
		QString temp = editedFile.at(iterator);

		wid.append(temp);

	}

	//make it visible
	wid.show(); 

	//enter event loop
	return myapp.exec(); 
}
