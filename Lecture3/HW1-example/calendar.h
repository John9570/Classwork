// Example for ECE 3574

#ifndef CALENDAR_H
#define CALENDAR_H

#include <QDate>
#include <QFile>
#include <QString>
#include <QStringList>
#include <QTextStream>
#include "qstd.h"

using namespace qstd;

/*
	This class stores a list of calendar entries.
	It can add new entries, delete existing ones, and list them. 
*/
class Calendar
{
private:
	//file which the constructor reads and destructor writes to
	static QFile sm_fileData;
	//directs all output streamed into here, to stdout
	static QTextStream sm_cout;
	//keeps a list of all entries read from the sm_fileData
	QStringList	m_listCalendarEntries;
   // line formater
	QString formatLine(QString nameDateHour);
public:
	// Constructor
	Calendar();
	// Destructor
	~Calendar();

	void addCalendarEntry(QString name, QString date, QString hour);
	void deleteCalendarEntry(QString name, QString date, QString hour);
	void printCalendarEntries(QString date);
	void printCalendarEntries();
	void printCalendarHelp();
};

#endif
