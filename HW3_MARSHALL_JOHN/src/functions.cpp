/*
name: John Marshall
S_ID: 905710486
Email: John9570@vt.edu
Class: ECE 3574
Assignment: Homework 2
Date: 2-15-2015
*/



#include "../include/functions.h"
#include "../include/Dictionary.h"
#include <QDebug> 
#include <QStringList>


QStringList mainHelperFunction(QString inputFile, Dictionary *obj){


	QFile sm_inputFile(inputFile);

	sm_inputFile.open(QIODevice::ReadOnly);

	QTextStream readFile(&sm_inputFile);

	//list that stores entire file of edited text
	QStringList wholeFile;

	//read line by line
	while(!readFile.atEnd()) {
		QString line = readFile.readLine();
		QString unparsed = line;

		//remove crap from the string:
		line.remove(QChar('{'), Qt::CaseInsensitive);
		line.remove(QChar('}'), Qt::CaseInsensitive);
		line.remove(QChar('.'), Qt::CaseInsensitive);
		line.remove(QChar(','), Qt::CaseInsensitive);
		line.remove(QChar(':'), Qt::CaseInsensitive);
		line.remove(QChar(';'), Qt::CaseInsensitive);
		line.remove(QChar('?'), Qt::CaseInsensitive);
		line.remove(QChar('!'), Qt::CaseInsensitive);
		line.remove(QChar('('), Qt::CaseInsensitive);
		line.remove(QChar(')'), Qt::CaseInsensitive);
		line.remove(QRegExp("[\\n\\t\\r]"));

		
		QStringList words = line.split(QRegExp("\\s+")); 
		QStringList unparsedWords = unparsed.split(QRegExp("\\s+"));
		
		//at this point we need to check each word
		for(int i = 0; i < words.size(); i++){
			bool inDictionary = false;

			inDictionary = obj->isWordThere( words.at(i) );

			if(inDictionary == false){

				QString temp = unparsedWords.at(i);
				temp.prepend("<font color=\"red\">");
				temp.append("</font>");
				unparsedWords.replace(i, temp);
			}
		}

		//print for debug		
	//	for(int i = 0; i < words.size(); i++){
	//	   qDebug() << words.at(i) << endl;
	//	}
		
		QString editedLine = unparsedWords.join(" ");
//		qDebug() << editedLine << endl;	
		
		wholeFile.append(editedLine);

	}

	
	return wholeFile;

}






QStringList otherMainHelperFunction(QString inputFile, Dictionary *obj, int hit){


	QFile sm_inputFile(inputFile);

	sm_inputFile.open(QIODevice::ReadOnly);

	QTextStream readFile(&sm_inputFile);

	//list that stores entire file of edited text
	QStringList wholeFile;

	QString header = "Most Common Words:";

	//read line by line
	while(!readFile.atEnd()) {
		QString line = readFile.readLine();

		//remove crap from the string:
		line.remove(QChar('{'), Qt::CaseInsensitive);
		line.remove(QChar('}'), Qt::CaseInsensitive);
		line.remove(QChar('.'), Qt::CaseInsensitive);
		line.remove(QChar(','), Qt::CaseInsensitive);
		line.remove(QChar(':'), Qt::CaseInsensitive);
		line.remove(QChar(';'), Qt::CaseInsensitive);
		line.remove(QChar('?'), Qt::CaseInsensitive);
		line.remove(QChar('!'), Qt::CaseInsensitive);
		line.remove(QChar('('), Qt::CaseInsensitive);
		line.remove(QChar(')'), Qt::CaseInsensitive);
		line.remove(QRegExp("[\\n\\t\\r]"));


//		qDebug() << line << endl;		
		QStringList words = line.split(QRegExp("\\s+")); 
		
		//at this point we need to check each word
		for(int i = 0; i < words.size(); i++){
			obj->isWordThere( words.at(i) );
		}

		
					
	
	}

	obj->matchingGoodHits(hit);
	
	wholeFile = obj->printGoodTopHits();	

	wholeFile.prepend(header);
	return wholeFile;

}


QStringList findBadWords(Dictionary *obj, int hit){


	//list that stores entire file of edited text
	QStringList wholeFile;

	QString header = "Most Misspelled (BAD) Words:";


	obj->matchingBadHits(hit);
	
	wholeFile = obj->printBadTopHits();	

	wholeFile.prepend(header);
	return wholeFile;

}


