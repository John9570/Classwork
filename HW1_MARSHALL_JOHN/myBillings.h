/*
Name: John Marshall
S_ID: 905710486
Email: John9570@vt.edu
Class: ECE 3574
Assignment: Homework 1
Date: 1-29-2015
*/

#ifndef MYBILLINGS_H
#define MYBILLINGS_H

#include <QDate>
#include <QTime>
#include <QFile>
#include <QString>
#include <QStringList>
#include <QTextStream>
#include "qstd.h"

using namespace qstd;

/*
	This class stores a list of billing entries.
	It can add new entries, delete existing ones, and list them. 
*/
class MyBilling
{
private:
	//file which the constructor reads and destructor writes to
	static QFile sm_fileData;
	//directs all output streamed into here, to stdout
	static QTextStream sm_cout;
	//keeps a list of all entries read from the sm_fileData
	QStringList	m_listBillingEntries;
   // line formater
	QString formatLine(QString confNameDateBeginEnd);
public:
	// Constructor
	MyBilling();
	// Destructor
	~MyBilling();

	void addBillingEntry(QString name, QString date, QString begin, QString end);
	void deleteBillingEntry(QString confnum);
	void printBillingTotalHours();
	void printBillingEntryNames(QString name);
	void printBillingEntries(QString date);
	void printBillingEntries();
	void printBillingHelp();
	 int createConfNumber();
};

#endif
