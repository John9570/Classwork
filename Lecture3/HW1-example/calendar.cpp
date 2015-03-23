// Example for ECE 3574

#include "calendar.h"

// Static variables
QFile Calendar::sm_fileData("calendar.dat");
QTextStream Calendar::sm_cout(stdout);

//	The default construtor Reads the content from the sm_fileData 
//	and stores it into a QStringList
Calendar::Calendar()
{
	sm_fileData.open(QIODevice::ReadOnly);

	QTextStream readFile(&sm_fileData);

	// read line by line and insert into a QStringList
	// from QFile documentation
	while (!readFile.atEnd()) {
		m_listCalendarEntries << readFile.readLine();
	}

	sm_fileData.close();
}

//	The deconstructor writes content from the QStringList back 
//	into the sm_fileData
Calendar::~Calendar()
{
	sm_fileData.open(QIODevice::WriteOnly);

	QTextStream writeFile(&sm_fileData);

	// Write every line in the QStringList to the file sm_fileData by
	// reading and popping the top of the list each time.
	while ( !m_listCalendarEntries.isEmpty() ) {
		writeFile << m_listCalendarEntries.front() << endl;
		m_listCalendarEntries.pop_front();
	}

	sm_fileData.close();
}

/*	this function adds entries to the calendar 
	private string list in chrnological order.
*/
void Calendar::addCalendarEntry(QString name, QString date, QString hour)
{
	// convert the QString date into a QDate
	QDate newDate = QDate::fromString(date, "MM-dd-yyyy");

	// Invalid input checking
	// If the date entered is of valid year/month/date
	if (!newDate.isValid())	{
		sm_cout << "The date " << date << " is invalid" << endl;
		return;
	}
	//Check to see if date entered is the year 2013 or 2014
	else if (( newDate.year() != 2013) && ( newDate.year() != 2014)) {
		sm_cout << "The year must be in 2013 or 2014" << endl;
		return;
	}

	int posInsert = m_listCalendarEntries.size();

	// Loop through each element, keeping track of an index variable
	// Compares birthdays and inserts the new birthday in chronological order
	for ( int i = 0; i < m_listCalendarEntries.size(); i++) {
		// get the nameDate
		QString element = m_listCalendarEntries[i];
		//extract just the date
		QString elem = element.split(":")[1]; 
		// convert string to QDate in correct format
		QDate tmpDate = QDate::fromString(elem, "MM-dd-yyyy");
		if ( newDate <= tmpDate ) { // compare dates
			posInsert = i;
			break;
		}
	}

	// insert new calendar entry with correct index position
	QString newCalendarEntry = name + ":" + date + ":" + hour;
	m_listCalendarEntries.insert(posInsert, newCalendarEntry);

	sm_cout << "The calendar entry for " << name << " has been added." << endl;
}

/*	This function takes in either a name/date/hour 
	and removes the matching entry in the string list.
*/
void Calendar::deleteCalendarEntry(QString name, QString date, QString hour)
{
	int index = 0;

	//Loop through each element to see if nameDateHour equals 
	// and delete entry that matches
	foreach (QString str, m_listCalendarEntries) {
		sm_cout << "Entry " << index << ": " << formatLine(str) << endl;
		index++;
	}

}

/*	This function takes in a date from the command line.
	It should print out entries.
*/
void Calendar::printCalendarEntries(QString dateString)
{
	sm_cout << "printCalendarEntry is not implemented yet..." << endl;
	sm_cout << "should print out entries for date " << dateString << endl;
}

void Calendar::printCalendarEntries()
{
	foreach (QString str, m_listCalendarEntries) {
		sm_cout << formatLine(str) << endl;
	}
}

void Calendar::printCalendarHelp()
{
	sm_cout << "Need to implement a Calendar help function! " << endl;
}

/*	This is a helper function which takes in a name/date/hour tripple
   as formatted within the
	saved file (sm_fileData) and formats it to 
   the correct format.
*/
QString Calendar::formatLine(QString nameDateHour)
{
	QStringList element = nameDateHour.split(":");
	QString name = element[0]; // Extract name
	QString date = element[1]; // Extract birthday
	QString hour = element[2]; // Extract birthday

	QString output;
	QTextStream os(&output);

	os << "The calendar entry is for " << name << " at date " << date
      << " for hour " << hour;

	return output;
}


