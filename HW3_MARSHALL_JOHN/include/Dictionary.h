/*
Name: John Marshall
S_ID: 905710486
Email: John9570@vt.edu
Class: ECE 3574
Assignment: Homework 3
Date: 3-3-2015
*/


//put #includes here
#include <QString>
#include <QHash>
//#include <QDate>
//#include <QTime>
#include <QFile>
#include <QStringList>
#include <QTextStream>


#ifndef DICTIONARY_H
#define DICTIONARY_H


#include "qstd.h"

using namespace qstd;






/* Short description about the class goes here


*/ 



class Dictionary{



	public: 

		Dictionary(QString filename);
		Dictionary();
		
		struct dictionaryType { 
			int hitCount;
			QString name;
		} dictTypeVar, temp;
 
		void insertItem(QString name);

		//Need a function to query dictionary for a word.
		//Function also increments a counter for words that are queried
		bool isWordThere(QString name); 

		//If a word is not in the dictionary, the function must add it
		//to a list of mispelled words (with a counter for # times hit)
		void foundBadWord(QString name);
	
		//Function to return the number of most used words


		//These functions will not update hit count.
		//Function to return top good word hit count
		void topBadWordHits();	

		//Function to return top bad word hit count 
		void topGoodWordHits();

		//Function to return list of <int> good words with top hit counts
		void matchingGoodHits(int hit);

		void matchingBadHits(int hit);
		
		//returns a iterable list of the top good hits, formatted
		QStringList printGoodTopHits();

		QStringList printBadTopHits();
		//Function to return list of words with hit counts for an int
//		QHash<int, dictionaryType> matchingBadHits(int hit);

	private:

		//key numbers 
		int itemIndex;
		int badItemIndex; 

		int topGoodIndex;
		int topBadIndex;
		//directs all output streamed into here, to stdout
        	static QTextStream sm_cout;


		//A Q hash table to store the dictionary
		QHash<int, dictionaryType> theDictionary;

		//A Q hash table to store the misspelled words
		QHash<int, dictionaryType> theMisspelled;
		

		//Other dictionaries:
		QHash<int, dictionaryType> theTopGood;

		QHash<int, dictionaryType> theTopBad;
};



#endif

