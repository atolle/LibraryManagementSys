/*
   Author: Andrew Tolle (andrewtolle2@my.unt.edu)
   EUID: 10511855
   Date: Apr 21, 2015
   Instructor: David Keathly
   Purpose: this program creates a library management system using inheritance
*/

#include "func.h"		// includes functions header file

void proginfo()			// defines author info function
{
	cout<<setw(60)<<right<<" -------------------------------------------------- "<<endl;	// prints author info
	cout<<setw(60)<<right<<"|        CSCE 1040.001 -  Homework Program 6       |"<<endl;
	cout<<setw(60)<<right<<"|              Author: Andrew Tolle                |"<<endl;
	cout<<setw(60)<<right<<"|     EUID: 10511855    andrewtolle2@my.unt.edu    |"<<endl;
	cout<<setw(60)<<right<<" -------------------------------------------------- "<<endl;
	cout<<endl<<endl<<"Welcomt to the Library Management System"<<endl;
	cout<<endl<<"Press ENTER to go to main menu"<<endl<<">";
	cin.get();		// waits for user input
}

void menu(Patrons &patrons, Items &items, Borrows &borrows, Library &library)		// defines main menu function
{
	int choice;	// declares user choice for menu
	char filename[100]; 	// filename for saving/loading files

	cout<<endl<<setw(30)<<right<<"Main Menu"<<endl<<"---------------------------------------------------"<<endl;	// prints menu
	cout<<"Select from the following"<<endl<<endl;
	cout<<"1. Check-out"<<endl<<"2. Check-in"<<endl<<"3. Patron information"<<endl<<"4. Catalog information"<<endl<<"5. Library settings"
	    <<endl<<"6. Save"<<endl<<"7. Load"<<endl<<"8. Exit"<<endl<<">";
	cin>>choice;	// reads in user choice
	cin.ignore();	// cleans buffer
	while(choice < 1 || choice > 8 || cin.fail())	// checks user choice
	{
		if(cin.fail())					// checks to see if input was wrong format
		{
			cin.clear();				// clears fail flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n');	// ignores rest of input - taken from http://stackoverflow.com/questions/16726657
		}								//                            /checking-for-valid-type-input-using-stdin-c
		cout<<endl<<"Invalid selection. Try again."<<endl<<">";
		cin>>choice;	// reads in user choice
		cin.ignore();	// cleans buffer
	}

	switch(choice)		// switches choice
	{
		case 1: borrows.checkout();			// calls checkout function
			break;
		case 2: borrows.checkin();			// calls checkin function
			break;
		case 3: pmenu(patrons,items,borrows,library);	// calls patron menu function
			break;
		case 4: bmenu(patrons,items,borrows,library);	// calls item menu function
			break;
		case 5: lmenu(patrons,items,borrows,library);	// calls library menu function
			break;
		case 6:	cout<<endl<<"Save database as (i.e. file.dat): ";
			cin.getline(filename,100);	// reads in filename
			library.save(filename);		// saves library settings
			patrons.save(filename);		// saves patron info
			items.save(filename);		// saves item info
			borrows.save(filename);		// saves borrow info
			break;
		case 7:	cout<<endl<<"Filename (i.e. file.dat): ";
			cin.getline(filename,100);	// reads in filename
			library.load(filename);		// loads library settings
			patrons.load(filename);		// loads patrons
			items.load(filename);		// loads items
			borrows.load(filename);		// loads borrows
			break;
		case 8: return;					// returns to main
	}
	menu(patrons,items,borrows,library);			// recalls main menu function
}

void pmenu(Patrons &patrons, Items &items, Borrows &borrows, Library &library)		// defines patron menu function
{
	long id;	// declares id to be used with find functions
	int choice;	// declares user choice

	cout<<endl<<setw(32)<<right<<"Patron Menu"<<endl<<"---------------------------------------------------"<<endl;
	cout<<"Select from the following"<<endl<<endl;
	cout<<"1. Add patron"<<endl<<"2. Delete patron"<<endl<<"3. Edit patron"<<endl<<"4. View patron"<<endl<<"5. Sort patrons by ID number"
	    <<endl<<"6. Sort patrons by last name"<<endl<<"7. View all patrons"<<endl<<"8. View all patrons with outstanding balances"<<endl
            <<"9. Print address labels"<<endl<<"10. View number of items checked-out by patron"<<endl<<"11. Make a payment"<<endl<<"12. Go back"<<endl<<">";
	cin>>choice;	// reads in user choice
	cin.ignore();
	while(choice < 1 || choice > 12 || cin.fail())		// checks user choice
	{
		if(cin.fail())					// checks to see if input was wrong format
		{
			cin.clear();				// clears fail flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n');	// ignores rest of input - taken from http://stackoverflow.com/questions/16726657
		}								//                            /checking-for-valid-type-input-using-stdin-c
		cout<<endl<<"Invalid selection. Try again."<<endl<<">";
		cin>>choice;	// reads in user choice
		cin.ignore();	// cleans buffer
	}

	switch(choice)		// switches choice
	{
		case 1: patrons.add_patron();		// calls add patron function
			break;
		case 2: patrons.delete_patron();	// calls delte patron function
			break;
		case 3: id = patrons.find_patron();	// calls find patron function
			if(id == -1);			// does nothing if patron was not found
			else
			{
				patrons.edit_patron(id);	// calls edit patron function
				cout<<endl<<"Patron edited successfully. Press ENTER to return to the menu."<<endl<<">";
				cin.get();
			}
			break;
		case 4: id = patrons.find_patron();	// calls find patron function
			if(id == -1);			// does nothing if patron was not found
			else
			{
				patrons.print_patron(id);	// calls print patron function
				cout<<endl<<endl<<"Press ENTER to return to the menu."<<endl<<">";
				cin.get();
			}
			break;
		case 5: patrons.sort_patrons("id");	// calls sort function by ID
			break;
		case 6: patrons.sort_patrons("last");	// calls sort function by last name
			break;
		case 7: patrons.print_allpatrons();	// calls function to print all patrons
			break;
		case 8: patrons.print_patronbalances();	// calls function to print patrons with balances
			break;
		case 9: patrons.print_addresslabels();	// calls functions to print address labels
			break;
		case 10: id = patrons.find_patron();	// calls find patron function
			if(id == -1);			// does nothing if patron was not found
			else
			{
				int n = patrons.get_numitems(id);					// set n as the number of items patron has checked out
				cout<<endl<<"Number of items checked-out: "<<n;				// prints number of items
				cout<<endl<<endl<<"Press ENTER to return to the menu."<<endl<<">";
				cin.get();
			}
			break;
		case 11: id = patrons.find_patron();	// calls find patrons function
			 if(id == -1);			// does nothing if patron was not found
			 else
			 {
			 	patrons.pay_balance(id);	// calls pay balance function
			 }
			 break;
		case 12: break;			// does nothing - returns to menu
	}
}

void bmenu(Patrons &patrons, Items &items, Borrows &borrows, Library &library)		// defines item menu function
{
	long id;		// declares id to be used with find functions
	int choice;		// declares user choice

	cout<<endl<<setw(33)<<right<<"Catalog Menu"<<endl<<"---------------------------------------------------"<<endl;
	cout<<"Select from the following"<<endl<<endl;
	cout<<"1. Add item"<<endl<<"2. Delete item"<<endl<<"3. Edit item"<<endl<<"4. View item"<<endl<<"5. Sort items by ID number"
	    <<endl<<"6. Sort items by author/director's last name"<<endl<<"7. Sort items by title"<<endl<<"8. Sort items by type"
	    <<endl<<"9. View all items"<<endl<<"10. View all overdue items"<<endl<<"11. Report item as lost"<<endl<<"12. Go back"<<endl<<">";
	cin>>choice;	// reads in user choice
	cin.ignore();	// cleans buffer
	while(choice < 1 || choice > 12 || cin.fail())		// checks choice
	{
		if(cin.fail())					// checks to see if input was wrong format
		{
			cin.clear();				// clears fail flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n');	// ignores rest of input - taken from http://stackoverflow.com/questions/16726657
		}								//                            /checking-for-valid-type-input-using-stdin-c
		cout<<endl<<"Invalid selection. Try again."<<endl<<">";
		cin>>choice;	// reads in choice
		cin.ignore();	// cleans buffer
	}

	switch(choice)		// switches choice
	{
		case 1: items.add_item();		// calls add item function
			break;
		case 2: items.delete_item();		// calls delete item function
			break;
		case 3: id = items.find_item();		// calls find item function
			if(id == -1);			// does nothing if item was not found
			else
			{
				items.edit_item(id);	// calls edit item function
				cout<<endl<<"Item edited successfully. Press ENTER to return to the menu."<<endl<<">";
				cin.get();
			}
			break;
		case 4: id = items.find_item();		// calls find item function
			if(id == -1);			// does nothing if item was not found
			else
			{
				items.print_item(id);	// calls print item function
				cout<<endl<<endl<<"Press ENTER to return to the menu."<<endl<<">";
				cin.get();
			}
			break;
		case 5: items.sort_items("id");		// calls sort function by id
			break;
		case 6: items.sort_items("last");	// calls sort function by last name
			break;
		case 7: items.sort_items("title");	// calls sort function by title
			break;
        case 8: items.sort_items("type");   // calls sort function by type
            break;
		case 9: items.print_allitems();		// calls function to print all items
			break;
		case 10: borrows.print_ODitems();	// calls function to print all overdue items
			break;
		case 11: borrows.reportlost();		// calls function to report a item as lost
			break;
		case 12: break;		 // does nothing - returns to menu
	}
}

void lmenu(Patrons &patrons, Items &items, Borrows &borrows, Library &library)		// defines library settings menu function
{
	int choice, type;		// declares user choice

	cout<<endl<<setw(32)<<right<<"Library Menu"<<endl<<"---------------------------------------------------"<<endl;
	cout<<"Select from the following"<<endl<<endl;
	cout<<"1. Set fine rate"<<endl<<"2. Set borrow time"<<endl<<"3. Set how frequently fines are added"<<endl
	    <<"4. Set max items per patron"<<endl<<"5. Print library information"<<endl<<"6. Go back"<<endl<<">";
	cin>>choice;	// reads in choice
	cin.ignore();	// cleans buffer
	while(choice < 1 || choice > 6 || cin.fail())	// checks choice
	{
		cin.clear();				// clears fail flag
		cin.ignore(numeric_limits<streamsize>::max(), '\n');	// ignores rest of input - taken from http://stackoverflow.com/questions/16726657
		cout<<endl<<"Invalid selection. Try again."<<endl<<">";	//				      /checking-for-valid-type-input-using-stdin-c
		cin>>choice;	// reads in choice
		cin.ignore();	// cleans buffer
	}

	switch(choice)		// switches choice
	{
		case 1: cout<<endl<<"Set fine for:"<<endl<<"1. Books"<<endl<<"2. DVDs"<<endl<<"3. Audio books"<<endl<<">";
			cin>>type;
			cin.ignore();
			while(type < 1 || type > 3 || cin.fail())	// checks choice
            {
                cin.clear();				// clears fail flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n');	// ignores rest of input - taken from http://stackoverflow.com/questions/16726657
                cout<<endl<<"Invalid selection. Try again."<<endl<<">";	//				      /checking-for-valid-type-input-using-stdin-c
                cin>>type;	// reads in type
                cin.ignore();	// cleans buffer
            }

			switch(type)
			{
				case 1: library.set_fine("book");	// calls function to set fine rate for books
					break;
				case 2: library.set_fine("dvd");	// calls function to set fine rate for DVDs
					break;
				case 3: library.set_fine("abook");	// calls function to set fine rate for audio books
				 	break;
			}
			cout<<endl<<"Fine rate set. Press ENTER to return to the menu."<<endl<<">";
			cin.get();
			break;
		case 2: cout<<endl<<"Set borrow time for:"<<endl<<"1. Books"<<endl<<"2. DVDs"<<endl<<"3. Audio books"<<endl<<">";
			cin>>type;
			cin.ignore();
			while(type < 1 || type > 3 || cin.fail())	// checks type
            {
                cin.clear();				// clears fail flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n');	// ignores rest of input - taken from http://stackoverflow.com/questions/16726657
                cout<<endl<<"Invalid selection. Try again."<<endl<<">";	//				      /checking-for-valid-type-input-using-stdin-c
                cin>>type;	// reads in type
                cin.ignore();	// cleans buffer
            }

			switch(type)
			{
				case 1: library.set_borrowdays("book");	// calls function to set borrow days for books
					break;
				case 2: library.set_borrowdays("dvd");	// calls function to set borrow days for DVDs
					break;
				case 3: library.set_borrowdays("abook");// calls function to set borrow days for audio books
				 	break;
			}
			cout<<endl<<"Borrow time set. Press ENTER to return to the menu."<<endl<<">";
			cin.get();
			break;
		case 3: cout<<endl<<"Set fine frequency for:"<<endl<<"1. Books"<<endl<<"2. DVDs"<<endl<<"3. Audio books"<<endl<<">";
			cin>>type;
			cin.ignore();
			while(type < 1 || type > 3 || cin.fail())	// checks type
            {
                cin.clear();				// clears fail flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n');	// ignores rest of input - taken from http://stackoverflow.com/questions/16726657
                cout<<endl<<"Invalid selection. Try again."<<endl<<">";	//				      /checking-for-valid-type-input-using-stdin-c
                cin>>type;	// reads in type
                cin.ignore();	// cleans buffer
            }

			switch(type)
			{
				case 1: library.set_finedays("book");	// calls function to set borrow days for books
					break;
				case 2: library.set_finedays("dvd");	// calls function to set borrow days for DVDs
					break;
				case 3: library.set_finedays("abook");// calls function to set borrow days for audio books
				 	break;
			}
			cout<<endl<<"Fine frequency set. Press ENTER to return to the menu."<<endl<<">";
			cin.get();
			break;
		case 4: library.set_maxitems();		// calls function to set maximum items allowed per patron
			cout<<endl<<"Max items set. Press ENTER to return to the menu."<<endl<<">";
			cin.get();
			break;
		case 5: library.print_libraryinfo();	// calls function to print library settings
			cout<<endl<<endl<<"Press ENTER to return to the menu."<<endl<<">";
			cin.get();
			break;
		case 6: break; 		// does nothing - returns to menu
	}
}
