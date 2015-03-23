/*
Name: John Marshall
S_ID: 905710486
Email: John9570@vt.edu
Class: ECE 3574
Assignment: Homework 1
Date: 1-29-2015
*/

#include "myBillings.h"
#include "argumentlist.h"	

/*
	This program allows adds / deletes / and lists billing entries 
      entered by the user.
	The program can be called in the following ways:

	* myBillings								no parameters simply list calendar entires
	* myBillings -a -n namespec -d datespec -s timespec -e timespec 	adds a new billing entry 
	* myBillings -r confnumspec						deletes a billing entry based on confirmation number 
	* myBillings -l -d datespec             				prints entries for a particular date
	* myBillings -l -n namespec             				prints entries based on name
	* myBillings -t                   					prints total hours of billing for each client
	* myBillings -h                   					prints out help

	This class assumes case-insensitivity when searching/deleting names
*/
int main(int argc, char *argv[])
{
	MyBilling myBill;
	
	//use argumentlist class to parse args
        ArgumentList al(argc, argv);	
	
	//Check arg availability: 
	bool addAvailable = al.getSwitch("-a"); 
	QString namespec = al.getSwitchArg("-n", "0");
	QString datespec = al.getSwitchArg("-d", "0");
	QString beginspec = al.getSwitchArg("-s", "0");
	QString endspec = al.getSwitchArg("-e", "0");
	QString confnumspec = al.getSwitchArg("-r", "0");
	bool listAvailable = al.getSwitch("-l");
	bool hourspecAvailable = al.getSwitch("-t"); 
	bool helpspecAvailable = al.getSwitch("-h");

	//trying to add entry to billing list
	if(addAvailable){  

		if( (namespec != "0") && (datespec != "0") && (beginspec != "0") && (endspec != "0") ){
	
			myBill.addBillingEntry(namespec, datespec, beginspec, endspec);		

		}
		else{
			printf("Invalid input\n");
			printf("usage: ./myBillings -a -n namespec -d datespec -s beginspec -e endspec\n");
			return 1;
		}	

	}

	//trying to remove entry from billing list
       else if(confnumspec != "0"){
		myBill.deleteBillingEntry(confnumspec);
	}


	//trying to list billing entries	
	else if(listAvailable){
		
		if(datespec != "0"){
			myBill.printBillingEntries(datespec);	
		}
		else if(namespec != "0"){
			myBill.printBillingEntryNames(namespec);	
		}
		else{
			printf("Please enter a datespec or namespec along with -l (-d datespec and -n namespec\n");
		}

	}

	
	//trying to list total hours for each customer
	else if(hourspecAvailable){
		//list total hours for each person
		myBill.printBillingTotalHours();
	}

	//show help menu
	else if(helpspecAvailable){
		printf("This program allows adds / deletes / and lists billing entries entered by the user.\n\n");
        printf("The program can be called in the following ways:\n\n\n");

         printf("myBillings                                                            no parameters simply list calendar entires\n");
         printf("myBillings -a -n namespec -d datespec -s timespec -e timespec         adds a new billing entry \n");
         printf("myBillings -r confnumspec                                             deletes a billing entry based on confirmation number\n"); 
         printf("myBillings -l -d datespec                                             prints entries for a particular date\n");
         printf("myBillings -l -n namespec                                             prints entries based on name\n");
         printf("myBillings -t                                                         prints total hours of billing for each client\n");
         printf("myBillings -h                                                         prints out help\n\n");

        printf("This class assumes case-insensitivity when searching/deleting names\n");
	}


	return 0;

}
/*
	if (argc == 1 ) {       // no arguments are supplied
		myBill.printBillingEntries();
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
*/
