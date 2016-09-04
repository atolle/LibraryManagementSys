/* 
   Author: Andrew Tolle (andrewtolle2@my.unt.edu) 
   EUID: 10511855
   Date: Apr 21, 2015 
   Instructor: David Keathly
   Purpose: this program creates a library management system using inheritance
*/

#include "class.h"	// include class header file

void proginfo();									// declares author info function
void menu(Patrons &patrons, Items &items, Borrows &borrows, Library &library);		// declares main menu function
void pmenu(Patrons &patrons, Items &items, Borrows &borrows, Library &library);		// declares patron menu function
void bmenu(Patrons &patrons, Items &items, Borrows &borrows, Library &library);		// declares item menu function
void lmenu(Patrons &patrons, Items &items, Borrows &borrows, Library &library);		// declares library settings menu function
