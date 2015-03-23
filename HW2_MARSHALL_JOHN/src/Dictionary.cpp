/*
name: John Marshall
S_ID: 905710486
Email: John9570@vt.edu
Class: ECE 3574
Assignment: Homework 2
Date: 2-15-2015
*/

#include "../include/Dictionary.h"

#define STR_EQUAL 0
#define ZERO 0
#define ONE 1

//static variables
QTextStream Dictionary::sm_cout(stdout);


//the constructor:
Dictionary::Dictionary(QString filename){

	QFile sm_fileData(filename);
	
	//Both lists have initially nothing in them
	itemIndex = 0;
	badItemIndex = 0;

	topGoodIndex = 0;
	topBadIndex = 0;

	sm_fileData.open(QIODevice::ReadOnly);

        QTextStream readFile(&sm_fileData);

	// read line by line and insert into hash table
        // from QFile documentation
        while (!readFile.atEnd()) {
		QString line = readFile.readLine(); 
                insertItem( line ); //add all the items to the dictionary
//		sm_cout << "item is: " << line << endl;
        }

        sm_fileData.close();
	
//	sm_cout << "total items in dictionary: " << itemIndex-1 << endl;

//	sm_cout << "This is a test. Constructor called." << endl;


}

//Inserts an item into the dictionary
void Dictionary::insertItem(QString name){

	dictTypeVar.name = name;
	dictTypeVar.hitCount = 0;

	theDictionary.insert(itemIndex, dictTypeVar);

	itemIndex++;
}

//Determines if a word is in the dictionary, if it is it updates its hit count.
//If it isn't, the word is added to the misspelled word list.
bool Dictionary::isWordThere(QString name){

	//check word by word
	for(int i=0; i<itemIndex; i++){
		
//		if(theDictionary.contains(i)){
	
		dictTypeVar = theDictionary.value(i);

		if( QString::compare(name, dictTypeVar.name, Qt::CaseInsensitive) == STR_EQUAL){			
			//up the hit count
			dictTypeVar.hitCount += 1;
			theDictionary.insert(i, dictTypeVar);
			return true;
			}  
//		}
	}

	//add word to the misspelled list
	foundBadWord(name);

	return false;
}

//Adds a non-dictionary word to the misspelled dictionary.
void Dictionary::foundBadWord(QString name){

	for(int i=0; i<badItemIndex; i++){
		
		if(theMisspelled.contains(i)){
	
			dictTypeVar = theMisspelled.value(i);
//			sm_cout << "dicttypevar name is: " << dictTypeVar.name << endl;

			if( QString::compare(name, dictTypeVar.name, Qt::CaseInsensitive) == STR_EQUAL){			
				//up the hit count
				dictTypeVar.hitCount += 1;
				theMisspelled.insert(i, dictTypeVar);
				return;
			}

		}
	}

	//If we get to here the word isn't in the dictionary. 
	dictTypeVar.name = name;
	dictTypeVar.hitCount = 1; //its been searched for once

	theMisspelled.insert(badItemIndex, dictTypeVar);

	badItemIndex++;
}









//Function to return top bad word hit count
void Dictionary::topBadWordHits(){

	int top = 0;

	for(int i=0; i<badItemIndex; i++){
		
		if(theMisspelled.contains(i)){
	
			dictTypeVar = theMisspelled.value(i);

			if( dictTypeVar.hitCount > top){			
				top = dictTypeVar.hitCount;
				temp = dictTypeVar; //temp has top word and count
			}

		}
	}
	
//	sm_cout << "the worst word is: " << temp.name << "the hit count is: " << temp.hitCount << endl;
	return;
}



//Function to return top good word hit count
void Dictionary::topGoodWordHits(){

	int top = ZERO;
	temp.hitCount = ZERO;
	for(int i=0; i<itemIndex; i++){
		
		if(theDictionary.contains(i)){
	
			dictTypeVar = theDictionary.value(i);

			if( dictTypeVar.hitCount > top){			
				top = dictTypeVar.hitCount;
				temp = dictTypeVar; //temp has top word and count
			}

		}
	}
	
//	sm_cout << "the most hit word is: " << temp.name << " the hit count is: " << temp.hitCount << endl;
	return;
}


//Function to return list of <int> good words with top hit counts
void Dictionary::matchingGoodHits(int hit){

	int mostHit = ZERO;
	topGoodWordHits();
	
	mostHit = temp.hitCount; 


	//if we got nothing, give up.	
	if(mostHit == ZERO){
		return;
	}

	sm_cout << "entering iterator" << endl;
	
	//iterate through the number of top hits we want displayed
	int numberFound = 0;
	while(numberFound < hit){

		sm_cout << "iterating...." << endl;
		for(int i=0; i<itemIndex; i++){
		
			if(theDictionary.contains(i)){
	
				dictTypeVar = theDictionary.value(i);

				//check if word hit matches current top
				if( dictTypeVar.hitCount == mostHit ){
					theTopGood.insert(topGoodIndex, dictTypeVar);
					topGoodIndex++;
					sm_cout << "adding item: " << endl;
					sm_cout << dictTypeVar.name << endl;			
					numberFound++;
				}
			}
		}

		mostHit = mostHit - 1;

		if(mostHit == ZERO){
			return;
		}

	}

}


QStringList Dictionary::printGoodTopHits(){

	QStringList editedList;

	for(int i=0; i<topGoodIndex; i++){

		 if(theTopGood.contains(i)){

			dictTypeVar = theTopGood.value(i);
			QString temp = dictTypeVar.name;
			temp.append(":");
			QString tempInt = QString::number(dictTypeVar.hitCount);
			temp.append(tempInt);
			editedList.append(temp); 

       		 }

	}
		
	return editedList;

}




//Function to return list of <int> bad words with top hit counts
void Dictionary::matchingBadHits(int hit){

	int mostHit = ZERO;
	topBadWordHits();
	
	mostHit = temp.hitCount; 


	//if we got nothing, give up.	
	if(mostHit == ZERO){
		return;
	}

	
	//iterate through the number of top hits we want displayed
	int numberFound = 0;
	while(numberFound < hit){

		for(int i=0; i<badItemIndex; i++){
		
			if(theMisspelled.contains(i)){
	
				dictTypeVar = theMisspelled.value(i);

				//check if word hit matches current top
				if( dictTypeVar.hitCount == mostHit ){
					theTopBad.insert(topBadIndex, dictTypeVar);
					topBadIndex++;
					numberFound++;
				}
			}
		}

		mostHit = mostHit - 1;

		if(mostHit == ZERO){
			return;
		}

	}

}


QStringList Dictionary::printBadTopHits(){

	QStringList editedList;

	for(int i=0; i<topBadIndex; i++){

		 if(theTopBad.contains(i)){

			dictTypeVar = theTopBad.value(i);
			QString temp = dictTypeVar.name;
			temp.append(":");
			QString tempInt = QString::number(dictTypeVar.hitCount);
			temp.append(tempInt);
			editedList.append(temp); 

       		 }

	}
		
	return editedList;

}




