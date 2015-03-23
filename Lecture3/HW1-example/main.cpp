// Assignment: Homework 1 Example

#include "calendar.h"

/*
	This program allows adds / deletes / and lists calendar entries 
      entered by the user.
	The program can be called in the following ways:

	* calendar			no parameters simply list calendar entires
	* calendar -a name date hour 	adds a new calendar entry 
	* calendar -d name date hour		deletes an entry 
	* calendar -p date              prints entries for a date
	* calendar -h                   prints out help

	This class assumes case-insensitivity when searching/deleting names
*/
int main(int argc, char *argv[])
{
	Calendar myCal;

	if (argc == 1 ) {       // no arguments are supplied
		myCal.printCalendarEntries();
	} else if (argc == 3) {  // two arguments are supplied
		QString dateString = argv[2];
		myCal.printCalendarEntries(dateString);
	} else if (argc == 5) {  // four arguments are supplied
		QString nameString = argv[2];
		QString dateString = argv[3];
		QString hourString = argv[4];

		switch (argv[1][1])		// check which letter has been inputted as an argument
		{
			case 'a': myCal.addCalendarEntry(nameString,dateString,hourString); break;
			case 'd': myCal.deleteCalendarEntry(nameString,dateString,hourString); break;
			default: printf("Invalid argument, please try again.\n");
		}
	} else {
		myCal.printCalendarHelp();
   }

	return 0;
}

