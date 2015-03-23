/*
Name: John Marshall
S_ID: 905710486
Email: John9570@vt.edu
Class: ECE 3574
Assignment: Homework 1
Date: 1-29-2015
*/

#include "myBillings.h"

// Static variables
QFile MyBilling::sm_fileData("mybillings.dat");
QTextStream MyBilling::sm_cout(stdout);

//	The default construtor Reads the content from the sm_fileData 
//	and stores it into a QStringList
MyBilling::MyBilling()
{
	sm_fileData.open(QIODevice::ReadOnly);

	QTextStream readFile(&sm_fileData);

	// read line by line and insert into a QStringList
	// from QFile documentation
	while (!readFile.atEnd()) {
		m_listBillingEntries << readFile.readLine();
	}

	sm_fileData.close();
}

//	The deconstructor writes content from the QStringList back 
//	into the sm_fileData
MyBilling::~MyBilling()
{
	sm_fileData.open(QIODevice::WriteOnly);

	QTextStream writeFile(&sm_fileData);

	// Write every line in the QStringList to the file sm_fileData by
	// reading and popping the top of the list each time.
	while ( !m_listBillingEntries.isEmpty() ) {
		writeFile << m_listBillingEntries.front() << endl;
		m_listBillingEntries.pop_front();
	}

	sm_fileData.close();
}

/*	this function adds entries to the billing list 
	in chrnological order.
*/
void MyBilling::addBillingEntry(QString name, QString date, QString begin, QString end)
{
	//Acquire confirmation number
	int conf = createConfNumber();	

	// convert the QString date into a QDate
	QDate newDate = QDate::fromString(date, "M-d-yyyy");

	// convert the QString time into a QDateTime
	QDateTime newBeginTime(newDate, QTime::fromString(begin, "h:mmAP"));
	QDateTime newEndTime(newDate, QTime::fromString(end, "h:mmAP"));

        double timeDelta = newBeginTime.secsTo(newEndTime);
	timeDelta = timeDelta/3600; //convert to hours	
		
	//sm_cout << "The time difference is: " << timeDelta << endl;	

	// Invalid input checking

	// If the date entered is of valid year/month/date
	if (!newDate.isValid())	{
		sm_cout << "The date " << date << " is invalid" << endl;
		return;
	}

	//Check if date before current date
	QDateTime currentTime(QDateTime::currentDateTime());
	if(newEndTime > currentTime){
		sm_cout << "Error! That date/time is in the future, please enter a valid date and time." << endl;
		return;
	}
	//If the time entered is invalid
	if( newBeginTime > newEndTime ){
		sm_cout << "The begin time must be before the end time" << endl;
		return;
	}


	int posInsert = m_listBillingEntries.size();

	bool foundLocation = false;
	// Loop through each element, keeping track of an index variable
	// Compares dates and inserts the new bill in chronological order
	for ( int i = 0; i < m_listBillingEntries.size(); i++) {
		// get the nameDate
		QString element = m_listBillingEntries[i];
		//extract just the date
		QString elem = element.split("|")[2]; 
		// convert string to QDateTime in correct format
		QDate elemDate = QDate::fromString(elem, "M-d-yyyy");
	     	QDateTime tempDate(elemDate, QTime::fromString(element.split("|")[3], "h:mmAP"));
               
		//compare current end time with lists end time
		if ( newEndTime < tempDate ) {

			//check prior entry end time with current begin time
			if(i > 0){
				element = m_listBillingEntries[i-1];
				elem = element.split("|")[2];
				QDate elemDate = QDate::fromString(elem, "M-d-yyyy");
	     			QDateTime tempDate(elemDate, QTime::fromString(element.split("|")[4], "h:mmAP"));
				
				if( newBeginTime > tempDate ) { 
					posInsert = i;
					foundLocation = true;
					break;
				}
				else{
					sm_cout << "Error, billing times may not overlap!" << endl;
					return;
				}
			}
		}
		
		
	}
	if(!foundLocation && !m_listBillingEntries.isEmpty()){
	
		QString element = m_listBillingEntries.last();
		QString elem = element.split("|")[2];
		QDate elemDate = QDate::fromString(elem, "M-d-yyyy");
		QDateTime tempDate(elemDate, QTime::fromString(element.split("|")[4], "h:mmAP"));
		
		if( newBeginTime > tempDate ) {
			//nothing to see here 
		}
		else{
			sm_cout << "Error, billing times may not overlap!" << endl;
			return;
		}
			

	}

	// insert new billing entry with correct index position
	QString newBillingEntry = QString::number(conf) + "|" + name + "|" + date + "|" + begin + "|" + end + "|" + QString::number(timeDelta);
	m_listBillingEntries.insert(posInsert, newBillingEntry);

	sm_cout << "The billing entry for " << name << " has been added." << endl;
}

/*	This function takes in either a confirmation number 
	and removes the matching entry in the string list.
*/
void MyBilling::deleteBillingEntry(QString conf){
	//to check if item is located
	bool itemFound = false;
	//convert input into an interger
        int confNum = conf.toInt();
	//create an index variable
	int index = 0;

	//iterate until the item to be removed is found
	for ( int currentItemIndex = 0; currentItemIndex < m_listBillingEntries.size(); currentItemIndex++) {
		// get the nameDate
		QString element = m_listBillingEntries[currentItemIndex];
		//extract just the confirmation number
		QString elem = element.split("|")[0]; 
		// convert string to int 
		int tmpConf = elem.toInt();
		if ( confNum == tmpConf ) { // compare confirmation numbers
			itemFound = true;
			index = currentItemIndex;
		}
	}
	if(itemFound){
		m_listBillingEntries.removeAt(index);
		sm_cout << "The billing entry with confirmation number: " << confNum << " has been removed." << endl;
	}
	else{
		sm_cout << "Could not find an entry with confirmation number: " << confNum << endl;
	}
		

}


/*
	This function prints the total hours for each person
	in the list.
*/
void MyBilling::printBillingTotalHours(){

	//temp list	
	QStringList m_tempBillingEntries = m_listBillingEntries;

	while( !m_tempBillingEntries.isEmpty() ){
		
		//var to keep track of total hours per person
		double totalHours = 0;		
		//var to keep track of first person
		QString topName  = m_tempBillingEntries[0];
		//extract name
		topName = topName.split("|")[1];

		//if there is a hit, we need remove the item, break, and search for another match.
		bool noMatches = true;
		while(noMatches){
			noMatches = false;
			for ( int index = 0; index < m_tempBillingEntries.size(); index++) {
				// get the entry
				QString element = m_tempBillingEntries[index];
				//extract just the name
				QString elem = element.split("|")[1];
				if ( (QString::compare(topName, elem, Qt::CaseInsensitive) ) == 0 ) { // compare names
					//extract hours
					QString elemHours = element.split("|")[5];
					//add to total hours
					totalHours += elemHours.toDouble();
					m_tempBillingEntries.removeAt(index);
					//search for another match before exiting loop
					noMatches = true;
					break;				
				}
			}
		}
		
		

		//Print out the total hours for the person
		sm_cout << "The total time for " << topName << " is " << QString::number(totalHours) << endl;

	}

}




/*
	This function takes in an entry name and prints
	all the corresponding bills associated with that name.
*/
void MyBilling::printBillingEntryNames(QString name){

	for ( int currentItemIndex = 0; currentItemIndex < m_listBillingEntries.size(); currentItemIndex++) {
		// get the entry
		QString element = m_listBillingEntries[currentItemIndex];
		//extract just the name
		QString elem = element.split("|")[1];
		if ( (QString::compare(name, elem, Qt::CaseInsensitive) ) == 0 ) { // compare dates
			sm_cout << formatLine(element) << endl; //print entry
		}
	}

}


/*	This function takes in a date from the command line.
	It prints out entries corresponding to that date.
*/
void MyBilling::printBillingEntries(QString date)
{
	
	QDate searchDate = QDate::fromString(date, "M-d-yyyy");
	
	for ( int currentItemIndex = 0; currentItemIndex < m_listBillingEntries.size(); currentItemIndex++) {
		// get the Date
		QString element = m_listBillingEntries[currentItemIndex];
		//extract just the date number
		QString elem = element.split("|")[2];
		//convert string to date
		QDate currentDate = QDate::fromString(elem, "M-d-yyyy"); 
		if ( currentDate == searchDate ) { // compare dates
			sm_cout << formatLine(element) << endl; //print entry
		}
	}
}


/* 
	This function prints all billing entries.
*/
void MyBilling::printBillingEntries()
{
	foreach (QString str, m_listBillingEntries) {
		sm_cout << formatLine(str) << endl;
	}
}

void MyBilling::printBillingHelp()
{
	sm_cout << "Need to implement a Calendar help function! " << endl;
}


/*
	This function creates a unique confirmation number.
*/
int MyBilling::createConfNumber(){

	int newConfNum = m_listBillingEntries.size();
	bool uniqueConf = false;	

	// Loop until confirmation number is unique
	while(uniqueConf == false){

		uniqueConf = true;
		for ( int i = 0; i < m_listBillingEntries.size(); i++) {
			// get the nameDate
			QString element = m_listBillingEntries[i];
			//extract just the confirmation number
			QString elem = element.split("|")[0]; 
			// convert string to int 
			int tmpConf = elem.toInt();
			if ( newConfNum == tmpConf ) { // compare confirmation
				newConfNum += 1; //change conf number
				uniqueConf = false; //recheck new conf number
			}
		}

	} //end of while

	return newConfNum;
}	

/*	This is a helper function which takes in a name/date/hour tripple
   as formatted within the
	saved file (sm_fileData) and formats it to 
   the correct format.
*/
QString MyBilling::formatLine(QString confNameDateBeginEnd)
{
	QStringList element = confNameDateBeginEnd.split("|");
        QString conf = element[0];   // Extract confirmation number
	QString name = element[1];   // Extract name
	QString date = element[2];   // Extract date
	QString begin = element[3];  // Extract begin time
	QString end = element[4];    // Extract end time

	QString output;
	QTextStream os(&output);

	os << conf << " "  << name << " " << date << " " << begin << " " << end;

	return output;
}


