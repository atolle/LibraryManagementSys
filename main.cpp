/* 
   Author: Andrew Tolle (andrewtolle2@my.unt.edu) 
   EUID: 10511855
   Date: Apr 21, 2015 
   Instructor: David Keathly
   Purpose: this program creates a library management system using inheritance
*/

#include "func.h"	// includes functions header file

int main()		// defines main function of program
{
	Library library;	// creates a library settings object 
	Patrons patrons;	// creates a patrons collection object
	Items items;		// creates a books collections object
	Borrows borrows(&patrons,&items,&library);	// creates a borrows collection object
	proginfo();					// calls function to print author info
	menu(patrons,items,borrows,library);		// calls main menu function
	
	return 0;		// returns 0 and ends program
}
