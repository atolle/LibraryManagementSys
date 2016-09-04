/*
   Author: Andrew Tolle (andrewtolle2@my.unt.edu)
   EUID: 10511855
   Date: Apr 21, 2015
   Instructor: David Keathly
   Purpose: this program creates a library management system using inheritance
*/

#include <iomanip>		// declares iomanip header for output manipulation
#include <iostream>		// declares iostream header for cin cout
#include <string>		// declares string header for string manipulation
#include <limits>		// declares limits header to check for correct input
#include <ctime>		// declares ctime header for due date calculation
#include <fstream>		// declares header file for file i/o
using namespace std;

#define CHUNK 5			// sets chunk size for patrons, items, and borrows

class Library			// defines library class for library settings
{
	private:
		float bk_fine;		// fine rate for books
		float dvd_fine;		// fine rate for DVDs
		float ab_fine;		// fine for audio books
		int bk_finedays;	// fine frequency rate for books
		int dvd_finedays;	// fine frequency rate for DVDs
		int ab_finedays;	// fine frequency rate for audio books
		int bk_borrowdays;	// book borrow time
		int dvd_borrowdays;	// DVD borrow time
		int ab_borrowdays;	// audio book borrow time
		int maxitems;		// max items per patron

	public:
		Library()			// initializes values if user doesn't set them
		{
			bk_fine = .25;		// initializes values
			dvd_fine = .50;
			ab_fine = .25;
			bk_finedays = 7;
			dvd_finedays = 2;
			ab_finedays = 7;
			bk_borrowdays = 14;
			dvd_borrowdays = 3;
			ab_borrowdays = 7;
			maxitems = 5;
		}

		float get_fine(string type)		// returns fine depending on which one is asked for
		{
			if(type == "book")
				return bk_fine;
			else if(type == "dvd")
			  	return dvd_fine;
			else if(type == "abook")
				return ab_fine;
		}

		int get_finedays(string type)		// returns fine frequency rate depending on which one is asked for
		{
			if(type == "book")
			 	return bk_finedays;
			else if(type == "dvd")
			  	return dvd_finedays;
			else if(type == "abook")
				return ab_finedays;
		}

		int get_borrowdays(string type)		// returns borrow days depending on which one is asked for
		{
			if(type == "book")
			 	return bk_borrowdays;
			else if(type == "dvd")
			  	return dvd_borrowdays;
			else if(type == "abook")
				return ab_borrowdays;
		}

		int get_maxitems()		{return maxitems;}		// gets max items per patron

		void set_fine(string type)		// sets fine depending on item
		{
			float f;
			cout<<endl<<"Enter fine rate per day late: ";
			cin>>f;		// reads in fine
			cin.ignore();		// cleans buffer

			while(cin.fail())	// checks for valid input
			{
				if(cin.fail())			// checks to see if input was wrong format
				{
					cin.clear();		// clears fail flag
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					// ignores rest of input - taken from http://stackoverflow.com/questions/16726657
				}	//                            /checking-for-valid-type-input-using-stdin-c
				cout<<endl<<"Invalid amount. Enter fine amount: ";;
				cin>>f;	// reads in fine
				cin.ignore();	// cleans buffer
			}
            if(type == "book")
			 	bk_fine = f;
			else if(type == "dvd")
			  	dvd_fine = f;
			else if(type == "abook")
				ab_fine = f;
		}

		void set_finedays(string type)		// sets fine frequency rate
		{
			int fd;				// fine days
			cout<<endl<<"Enter how frequently fines are added (in days): ";
			cin>>fd;		// reads in rate
			cin.ignore();		// cleans buffer

			while(cin.fail())	// checks for valid input
			{
				if(cin.fail())			// checks to see if input was wrong format
				{
					cin.clear();		// clears fail flag
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					// ignores rest of input - taken from http://stackoverflow.com/questions/16726657
				}	//                            /checking-for-valid-type-input-using-stdin-c
				cout<<endl<<"Invalid input. Enter how frequently fines are added (in days): ";;
				cin>>fd;	// reads in rate
				cin.ignore();	// cleans buffer
			}
			if (type == "book")
			 	bk_finedays = fd;
			else if(type == "dvd")
			  	dvd_finedays = fd;
			else if(type == "abook")
				ab_finedays = fd;
		}

		void set_borrowdays(string type)		// sets borrow time
		{
			int bd;			// borrow days
			cout<<endl<<"Enter borrow time in days: ";
			cin>>bd;	// reads in borrow time
			cin.ignore();		// cleans buffer

			while(cin.fail())	// checks for valid input
			{
				if(cin.fail())			// checks to see if input was wrong format
				{
					cin.clear();		// clears fail flag
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					// ignores rest of input - taken from http://stackoverflow.com/questions/16726657
				}	//                            /checking-for-valid-type-input-using-stdin-c
				cout<<endl<<"Invalid input. Enter borrow time in days: ";;
				cin>>bd;	// reads in borrow time
				cin.ignore();		// cleans buffer
			}
			if(type == "book")
			 	bk_borrowdays = bd;
			else if(type == "dvd")
			  	dvd_borrowdays = bd;
			else if(type == "abook")
				ab_borrowdays = bd;
		}

		void set_maxitems(int mb)		{maxitems = mb;} 	// sets max items to passed variable

		void set_maxitems()		// sets max items per patron
		{
			cout<<endl<<"Enter max items per patron: ";
			cin>>maxitems;		// reads in max items
			cin.ignore();		// cleans buffer

			while(cin.fail())	// checks for valid input
			{
				if(cin.fail())			// checks to see if input was wrong format
				{
					cin.clear();		// clears fail flag
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					// ignores rest of input - taken from http://stackoverflow.com/questions/16726657
				}	//                            /checking-for-valid-type-input-using-stdin-c
				cout<<endl<<"Invalid input. Enter max items per patron: ";;
				cin>>maxitems;	// reads in max items
				cin.ignore();	// cleans buffer
			}
		}

		void print_libraryinfo()		// prints library setting info
		{
			cout<<endl<<"Fine rates: "<<endl<<setw(20)<<left<<"Books:"<<fixed<<"$"<<setprecision(2)<<bk_fine<<endl<<setw(20)<<"DVDs:"
                <<fixed<<"$"<<setprecision(2)<<dvd_fine<<endl<<setw(20)<<"Audio books:"<<fixed<<"$"<<setprecision(2)<<ab_fine;
            cout<<endl<<endl<<"Borrow time:"<<endl<<setw(20)<<"Books:"<<setw(2)<<right<<bk_borrowdays<<" days"<<endl<<left
                <<setw(20)<<"DVDS:"<<setw(2)<<right<<dvd_borrowdays<<" days"<<endl<<left<<setw(20)<<"Audio books:"<<setw(2)
                <<right<<ab_borrowdays<<" days"<<left;
			cout<<endl<<endl<<"Fine frequency:"<<endl<<setw(20)<<"Books:"<<setw(2)<<right<<bk_finedays<<" days"<<endl<<left
                <<setw(20)<<"DVDS:"<<setw(2)<<right<<dvd_finedays<<" days"<<endl<<left<<setw(20)<<"Audio books: "<<setw(2)
                <<right<<ab_finedays<<" days"<<left;
            cout<<endl<<endl<<"Max items:"<<setw(12)<<right<<maxitems;
		}

		void save(char filename[])		// save function
		{
			ofstream file;		// creates the file pointer

			file.open(filename);		// opens filename

			if(!file)			// if the file could not be opened
			{
				cout<<endl<<"Error - file could not be saved."<<endl<<"Press ENTER to return to the menu."<<endl<<">";
				cin.get();	// prompts user to return to menu
			}
			else				// if the file was opened
			{
				file<<get_fine("book")<<endl;			// prints library settings to file
				file<<get_fine("dvd")<<endl;
				file<<get_fine("abook")<<endl;
				file<<get_finedays("book")<<endl;
				file<<get_finedays("dvd")<<endl;
				file<<get_finedays("abook")<<endl;
				file<<get_borrowdays("book")<<endl;
				file<<get_borrowdays("dvd")<<endl;
				file<<get_borrowdays("abook")<<endl;
				file<<get_maxitems()<<endl;

				file.close();		// closes file
			}
		}

		void load(char filename[])		// save function
		{
			ifstream file;		// creates the file pointer

			file.open(filename);		// opens filename

			if(!file)			// if the file could not be opened
			{
				cout<<endl<<"Error - file could not be loaded."<<endl<<"Press ENTER to return to the menu."<<endl<<">";
				cin.get();	// prompts user to return to menu
			}
			else				// if the file was opened
			{
				file>>bk_fine;		// prints library settings to file
				file>>dvd_fine;
				file>>ab_fine;
				file>>bk_finedays;
				file>>dvd_finedays;
				file>>ab_finedays;
				file>>bk_borrowdays;
				file>>dvd_borrowdays;
				file>>ab_borrowdays;
				file>>maxitems;
			}
		}
};

class Patron		// defines patron class
{
	private:
		long patronID;		// patron ID number
		string lastname;	// patron last name
		string firstname;	// patron first name
		string address;		// patron address (street number and street name)
		string city;		// patron city
		string state;		// patron state
		string zip;		// patron zip code
		string phone;		// patron phone number
		string email;		// patron email
		float balance;		// patron balance
		string patronstatus;	// patron status
		int numitems;		// patron number of items

	public:
		long get_patronID() 		{return patronID;}			// these get the above variables
		string get_lastname() 		{return lastname;}
		string get_firstname()		{return firstname;}
		string get_flname()		{return firstname + " " + lastname;}	// concatenates first and last name
		string get_lfname()		{return lastname + " " + firstname;}	// concatenates last and first name
		string get_address()		{return address;}
		string get_city()		{return city;}
		string get_state()		{return state;}
		string get_zip()		{return zip;}
		string get_phone()		{return phone;}
		string get_email()		{return email;}
		float get_balance() 		{return balance;}
		string get_patronstatus()	{return patronstatus;}
		int get_numitems()		{return numitems;}

		Patron()		// constructor
		{
			balance = 0.00;			// balance set to zero
			numitems = 0;			// number of items set to zero
			patronstatus = "No balance";	// status is no balance
		}

		void set_patronID(long id)		{patronID = id;}	// sets patron ID to passed variable

		void set_patronID()		// sets patron ID
		{
			cout<<endl<<"Enter new patron ID number: ";
			cin>>patronID;	// reads in patron ID
			cin.ignore();	// cleans buffer

			while(cin.fail())	// checks for valid input
			{
				if(cin.fail())			// checks to see if input was wrong format
				{
					cin.clear();		// clears fail flag
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					// ignores rest of input - taken from http://stackoverflow.com/questions/16726657
				}	//                            /checking-for-valid-type-input-using-stdin-c
				cout<<endl<<"Invalid ID. Enter new patron ID number: ";;
				cin>>patronID;	// reads in patron ID
				cin.ignore();	// cleans buffer
			}
		}

		void set_lastname(string ln)		{lastname = ln;}	// sets last name to passed variable

		void set_lastname()		// sets last name
		{
			cout<<endl<<"Enter last name: ";
			getline(cin,lastname);	// reads in last name
		}

		void set_firstname(string fn)		{firstname = fn;}	// sets first name to passed variable

		void set_firstname()		// sets first name
		{
			cout<<endl<<"Enter first name: ";
			getline(cin,firstname);	// reads in first name
		}

		void set_address(string ad)		{address = ad;}		// sets address to passed variable

		void set_city(string ci)		{city = ci;}		// sets city to passed variable

		void set_state(string st)		{state = st;}		// sets state to passed variable

		void set_zip(string zi)			{zip = zi;}		// sets zip to passed variable

		void set_fulladdress()		// sets address
		{
			cout<<endl<<"Enter street address (i.e. 1234 College St.): ";
			getline(cin,address);	// reads in street
			cout<<endl<<"Enter city: ";
			getline(cin,city);	// reads in city
			cout<<endl<<"Enter state (i.e. TX): ";
			cin>>state;		// reads in state
			cin.ignore();		// cleans buffer
			cout<<endl<<"Enter zip code: ";
			cin>>zip;		// reads in zip code
			cin.ignore();		// cleans buffer
		}

		void set_phone(string ph)		{phone = ph;}		// sets phone to passed variable

		void set_phone()		// sets phone number
		{
			cout<<endl<<"Enter phone number (xxx-xxx-xxxx): ";
			cin>>phone;		// reads in phone number
			cin.ignore();		// cleans buffer
		}

		void set_email(string em)		{email = em;}		// sets email to passed variable

		void set_email()		// sets email
		{
			cout<<endl<<"Enter email address: ";
			cin>>email;		// reads in email
			cin.ignore();		// cleans buffer
		}

		void set_balance(float ba)		{balance = ba;}		// sets balance to passed variable

		void set_patronstatus(string ps)	{patronstatus = ps;}	// sets patron status to passed variable

		void set_numitems(int nb)		{numitems = nb;}	// sets number of items to passed variable

		void add_fine(float fine)		{balance += fine;}	// adds fine to balance

		void edit_patron()		// edits patrons
		{
			int choice;		// user choice at menu

			cout<<endl<<"Select the information you would like to edit:";		// prints menu
			cout<<endl<<"1. Patron ID"<<endl<<"2. First name"<<endl<<"3. Last name"<<endl<<"4. Address"<<endl
			    <<"5. Phone number"<<endl<<"6. Email address"<<endl<<">";
			cin>>choice;	// reads in choice
			cin.ignore();	// cleans buffer

			while(choice < 1 || choice > 6 || cin.fail())		// checks for valid input
			{
				if(cin.fail())			// checks to see if input was wrong format
				{
					cin.clear();		// clears fail flag
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					// ignores rest of input - taken from http://stackoverflow.com/questions/16726657
				}	//                            /checking-for-valid-type-input-using-stdin-c
				cout<<endl<<"Invalid selection."<<endl<<">";
				cin>>choice;	// reads in choice
				cin.ignore();	// cleans buffer
			}

			switch(choice)
			{
				case 1: cout<<endl<<"Current patron ID: "<<patronID;	// show patron ID
					set_patronID();					// calls set patron ID
					break;
				case 2: cout<<endl<<"Current first name: "<<firstname;	// shows patron first name
					set_firstname();				// calls set patron first name
					break;
				case 3: cout<<endl<<"Current last name: "<<lastname;	// shows patron last name
					set_lastname();					// calls set patron last name
					break;
				case 4: cout<<endl<<"Current address: "<<address<<" "<<city<<", "<<state<<" "<<zip;	// shows patron address
					set_fulladdress();									// calls set patron address
					break;
				case 5: cout<<endl<<"Current phone number: "<<phone;	// shows patron phone number
					set_phone();					// calls set phone number
					break;
				case 6: cout<<endl<<"Current email address: "<<email;	// shows patron email
					set_email();					// calls set email
					break;
			}
		}

		void buy_item(float price)	// function to have patron buy item, is passed price when called
		{
			cout<<endl<<"Current balance: $"<<balance<<endl<<"Item price: $"<<price;	// shows current balance and price of item
			balance += price;								// increases balance by price
			cout<<endl<<"New balance: $"<<balance;						// shows new balance
		}

		void pay_balance()		// function to pay balance
		{
			float payment;		// payment to be made

			cout<<endl<<"Current balance: "<<balance;		// shows current balance
			do{
				cout<<endl<<"Enter amount to be paid: ";
				cin>>payment;					// reads in payment
				cin.ignore();					// cleans buffer
				if(cin.fail())			// checks to see if input was wrong format
				{
					cin.clear();		// clears fail flag
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					// ignores rest of input - taken from http://stackoverflow.com/questions/16726657
				}	//                            /checking-for-valid-type-input-using-stdin-c
				if((balance - payment) < 0)	// checks to make sure user didn't overpay
					cout<<endl<<"Invalid amount - overpayment.";
			}while((balance - payment) < 0 || cin.fail());	// loops until user enters valid payment

			balance -= payment;			// decreases balance by payment
			if(balance == 0)			// checks to see if patron paid full balance
				patronstatus = "No balance";	// updates patron status to no balance

			cout<<endl<<"New balance: $"<<balance;				// prints new balance
			cout<<endl<<"Press ENTER to return to the menu."<<endl<<">";	// prompts user to return to menu
			cin.get();

		}

		void print_patron()		// function prints patron information
		{
			cout<<endl<<"Patron ID: "<<patronID<<endl<<"Name: "<<firstname + " " + lastname<<endl<<"Address: "<<address
			    <<" "<<city<<", "<<state<<" "<<zip<<endl<<"Phone: "<<phone
			    <<endl<<"Email: "<<email<<endl<<"Balance: $"<<fixed<<setprecision(2)<<balance<<endl<<"Status: "<<patronstatus
			    <<endl<<"Number of items: "<<numitems;
		}

		void edit_patronstatus()	// function edits patron status
		{
			int choice;	// user choice at menu

			cout<<endl<<"Choose new patron status:";
			cout<<endl<<"1. No balance"<<endl<<"2. Balance due"<<endl<<">";
			cin>>choice;	// reads in user choice
			cin.ignore();	// cleans buffer

			while(choice < 1 || choice > 2 || cin.fail())	// checks for valid input
			{
				if(cin.fail())			// checks to see if input was wrong format
				{
					cin.clear();		// clears fail flag
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					// ignores rest of input - taken from http://stackoverflow.com/questions/16726657
				}	//                            /checking-for-valid-type-input-using-stdin-c
				cout<<endl<<"Invalid selection."<<endl<<">";
				cin>>choice;	// reads in choice
				cin.ignore();	// cleans buffer
			}

			switch(choice)		// switches choice
			{
				case 1: patronstatus = "No balance";	// sets patron status to no balance
					break;
				case 2: patronstatus = "Balance due";	// sets patron status to balance due
					break;
			}
		}

		void checkout()			{numitems++;}			// increments number of items when patron checks out item

		void checkin()			{numitems--;}			// decrements number of items when patron checks in item

		void balancedue()		{patronstatus = "Balance due";}	// changes patron status to balance due
};

class Item		// defines item class
{
	private:
		long itemID;		// item ID
		string title;		// title
		string genre;		// item genre
		float price;		// item price
        string type;        // item type
		string itemstatus;	// item status

	public:
		long get_itemID()   		{return itemID;}			// these get the above variables
		string get_title()	    	{return title;}
		string get_genre()		    {return genre;}
		float get_price() 		    {return price;}
		string get_type()           {return type;}
		string get_itemstatus()		{return itemstatus;}

		Item(string n)		// constructor
		{
		    type = n;
			itemstatus = "Checked-in";	// initializes item status to checked-in
		}

		void set_itemID(long id)		{itemID = id;}		// sets ID to passed variable

		void set_itemID()	// sets item ID
		{
			cout<<endl<<"Enter new item ID number: ";
			cin>>itemID;	// reads in item ID
			cin.ignore();	// cleans buffer

			while(cin.fail())	// checks for valid input
			{
				if(cin.fail())			// checks to see if input was wrong format
				{
					cin.clear();		// clears fail flag
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					// ignores rest of input - taken from http://stackoverflow.com/questions/16726657
				}	//                            /checking-for-valid-type-input-using-stdin-c
				cout<<endl<<"Invalid ID. Enter new item ID number: ";;
				cin>>itemID;	// reads in item ID
				cin.ignore();	// cleans buffer
			}
		}

		void set_title(string ti)		{title = ti;}		// sets title to passed variable

		void set_title()	// sets title
		{
			cout<<endl<<"Enter title: ";
			getline(cin,title);	// reads in title
		}

		void set_genre(string gn)		{genre = gn;}		// sets genre to passed variable

		void set_genre()	// sets item genre
		{
			cout<<endl<<"Enter genre: ";
			getline(cin,genre);	// reads in genre
		}

		void set_price(float pr)		{price = pr;}		// sets price to passed variable

		void set_price()	// sets item price
		{
			cout<<endl<<"Enter price: ";
			cin>>price;	// reads in price
			cin.ignore();	// cleans buffer

			while(cin.fail())	// checks for valid input
			{
				if(cin.fail())			// checks to see if input was wrong format
				{
					cin.clear();		// clears fail flag
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					// ignores rest of input - taken from http://stackoverflow.com/questions/16726657
				}	//                            /checking-for-valid-type-input-using-stdin-c
				cout<<endl<<"Invalid price. Enter price: ";;
				cin>>price;	// reads in price
				cin.ignore();	// cleans buffer
			}
		}

		void set_itemstatus(string is)		{itemstatus = is;}	// sets item status to passed variable

		virtual void edit_item() = 0;	            	// pure virtual edit function

		virtual void print_item() = 0;		// pure virtual print function

		virtual void set_authorfirst() = 0;     // pure virtual set author first name function

		virtual void set_authorfirst(string n) = 0;  // pure virtual set author first name function to passed name

		virtual void set_authorlast() = 0;      // pure virtual set author last name function

		virtual void set_authorlast(string n) = 0;  // pure virtual set author last name function to passed name

		virtual string get_authorfirst() = 0;   // pure virtual get author first name function

		virtual string get_authorlast() = 0;       // pure virtual get author last name function

		virtual string get_authorname() = 0;    // pure virtual get author whole name

		virtual void set_runtime(){}         // virtual set runtime function

		virtual void set_runtime(int r){}   // virtual set runtime function

		virtual int get_runtime(){}          // virtual get runtime function

        virtual void set_narratorlast(){}     // virtual set narrator last function

        virtual void set_narratorfirst(){}    // virtual set narrator first function

        virtual void set_narratorlast(string n){}      // virtual set narrator last function

        virtual void set_narratorfirst(string n){}      // virtual set narrator first function

        virtual string get_narratorlast(){}   //  virtual get narrator last name function

		virtual string get_narratorfirst(){}  //  virtual get narrator first name function

		virtual string get_narratorname(){}   //  virtual get narrator whole name function

		void edit_itemstatus()			// function edits item status
		{
			int choice;	// user choice at menu

			cout<<endl<<"Choose new item status:";	// prints menu
			cout<<endl<<"1. Checked-in"<<endl<<"2. Checked-out"<<endl<<"3. Lost"<<endl<<"4. Damaged"<<endl<<"5. Out for repair"<<endl<<">";
			cin>>choice;	// user choice
			cin.ignore();	// cleans buffer

			while(choice < 1 || choice > 5 || cin.fail())	// checks for valid input
			{
				if(cin.fail())			// checks to see if input was wrong format
				{
					cin.clear();		// clears fail flag
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					// ignores rest of input - taken from http://stackoverflow.com/questions/16726657
				}	//                            /checking-for-valid-type-input-using-stdin-c
				cout<<endl<<"Invalid selection."<<endl<<">";
				cin>>choice;	// reads in choice
				cin.ignore();	// cleans buffer
			}

			switch(choice)	// switches choice
			{
				case 1: itemstatus = "Checked-in";	// sets item status to checked-in
					break;
				case 2: itemstatus = "Checked-out";	// sets item status to checked-out
					break;
				case 3: itemstatus = "Lost";		// sets item status to lost
					break;
				case 4: itemstatus = "Damaged";		// sets item status to damaged
					break;
				case 5: itemstatus = "Out for repair";	// sets item status to out for repair
					break;
			}
		}
		void reportlost()	{itemstatus = "Lost";}		// sets item status to lost
		void checkout()		{itemstatus = "Checked-out";}	// sets item status to checked-out
		void checkin()		{itemstatus = "Checked-in";}	// sets item status to checked-in
};

class Book : public Item    // defines book class derived from Item class
{
    private:
        string authorlast;	// author last name
		string authorfirst;	// author first name

	public:
        Book(string t) : Item(t){};        // constructor - uses item constructor to assign type
                                        // "C++ Inheritance, Polymorphism, Virtual Functions, Abstract Base Class" youtube video
        string get_authorlast() 	{return authorlast;}
		string get_authorfirst()	{return authorfirst;}                         // gets for author name
		string get_authorname() 	{return authorfirst + " " + authorlast;}

		void set_authorlast(string n)		{authorlast = n;}	// sets last name to passed variable

		void set_authorlast()	// sets author last name
		{
			cout<<endl<<"Enter author last name: ";
			getline(cin,authorlast);	// reads in author last name
		}

		void set_authorfirst(string n)		{authorfirst = n;}	// sets first name to passed variable

		void set_authorfirst()	// sets author first name
		{
			cout<<endl<<"Enter author first name: ";
			getline(cin,authorfirst);	// reads in author first name
		}

		void print_item()		// function prints item info
		{
			cout<<endl<<"Type: "<<get_type()<<endl<<"Item ID: "<<get_itemID()<<endl<<"Title: "<<get_title()
                <<endl<<"Author: "<<get_authorname()<<endl<<"Genre: "<<get_genre()<<endl<<"Price: $"
                <<fixed<<setprecision(2)<<get_price()<<endl<<"Status: "<<get_itemstatus();
		}

        void edit_item()		// function edits item info
		{
			int choice;	// user choice at menu

			cout<<endl<<"Select the information you would like to edit:";	// prints menu
			cout<<endl<<"1. Item ID"<<endl<<"2. Title"<<endl<<"3. Author last name"<<endl<<"4. Author first name"<<endl<<"5. Genre"
		            <<endl<<"6. Price"<<endl<<">";
			cin>>choice;	// reads in choice
			cin.ignore();	// cleans buffer

			while(choice < 1 || choice > 6 || cin.fail())	// checks for valid input
			{
				if(cin.fail())			// checks to see if input was wrong format
				{
					cin.clear();		// clears fail flag
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					// ignores rest of input - taken from http://stackoverflow.com/questions/16726657
				}	//                            /checking-for-valid-type-input-using-stdin-c
				cout<<endl<<"Invalid selection."<<endl<<">";
				cin>>choice;	// reads in choice
				cin.ignore();	// cleans buffer
			}

			switch(choice)	// switches choice
			{
				case 1: cout<<endl<<"Current item ID: "<<get_itemID();	// shows current item ID
					set_itemID();					// calls set item ID
					break;
				case 2: cout<<endl<<"Current title: "<<get_title();		// shows current title
					set_title();					// calls set title
					break;
				case 3: cout<<endl<<"Current author last name: "<<authorlast;	// shows current author last name
					set_authorlast();					// calls set author last name
					break;
				case 4: cout<<endl<<"Current author first name: "<<authorfirst;	// shows current author first name
					set_authorfirst();					// calls set author first name
					break;
				case 5: cout<<endl<<"Current genre: "<<get_genre();			// show current genre
					set_genre();						// calls set genre
					break;
				case 6: cout<<endl<<"Current price: "<<get_price();			// shows current price
					set_price();						// calls set price
					break;
			}
		}
};

class DVD : public Item     // defines DVD class derived from Item class
{
        private:
        string directorlast;	// director last name
		string directorfirst;	// director first name
		int runtime;

	public:
        DVD(string t) : Item(t){};        // constructor - uses item constructor to assign type
                                        // "C++ Inheritance, Polymorphism, Virtual Functions, Abstract Base Class" youtube video
        string get_authorlast() 	{return directorlast;}
		string get_authorfirst()	{return directorfirst;}                         // gets for director name
		string get_authorname()	    {return directorfirst + " " + directorlast;}

		void set_authorlast(string n)		{directorlast = n;}	// sets last name to passed variable

		void set_authorlast()	// sets director last name
		{
			cout<<endl<<"Enter director last name: ";
			getline(cin,directorlast);	// reads in director last name
		}

		void set_authorfirst(string n)		{directorfirst = n;}	// sets first name to passed variable

		void set_authorfirst()	// sets director first name
		{
			cout<<endl<<"Enter director first name: ";
			getline(cin,directorfirst);	// reads in director first name
		}

        void set_runtime(int r)             {runtime = r;}          // sets runtime to passed variable

		void set_runtime()          // sets runtime
		{
		    cout<<endl<<"Enter runtime in minutes: ";
		    cin>>runtime;       // reads in runtime
		    cin.ignore();

            while(cin.fail())	// checks for valid input
			{
				if(cin.fail())			// checks to see if input was wrong format
				{
					cin.clear();		// clears fail flag
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					// ignores rest of input - taken from http://stackoverflow.com/questions/16726657
				}	//                            /checking-for-valid-type-input-using-stdin-c
				cout<<endl<<"Invalid runtime. Enter runtime in minutes: ";;
				cin>>runtime;	// reads in runtime
				cin.ignore();	// cleans buffer
			}
		}

        int get_runtime()       {return runtime;}   // gets runtime

		void print_item()		// function prints item info
		{
			cout<<endl<<"Type: "<<get_type()<<endl<<"Item ID: "<<get_itemID()<<endl<<"Title: "<<get_title()
			    <<endl<<"Director: "<<get_authorname()<<endl<<"Genre: "<<get_genre()<<endl<<"Runtime: "
			    <<runtime<<" minutes"<<endl<<"Price: $"<<fixed<<setprecision(2)<<get_price()<<endl<<"Status: "
			    <<get_itemstatus();
		}

        void edit_item()		// function edits item info
		{
			int choice;	// user choice at menu

			cout<<endl<<"Select the information you would like to edit:";	// prints menu
			cout<<endl<<"1. Item ID"<<endl<<"2. Title"<<endl<<"3. Director last name"<<endl<<"4. Director first name"<<endl<<"5. Genre"
		            <<endl<<"7. Runtime"<<endl<<"7. Price"<<">";
			cin>>choice;	// reads in choice
			cin.ignore();	// cleans buffer

			while(choice < 1 || choice > 7 || cin.fail())	// checks for valid input
			{
				if(cin.fail())			// checks to see if input was wrong format
				{
					cin.clear();		// clears fail flag
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					// ignores rest of input - taken from http://stackoverflow.com/questions/16726657
				}	//                            /checking-for-valid-type-input-using-stdin-c
				cout<<endl<<"Invalid selection."<<endl<<">";
				cin>>choice;	// reads in choice
				cin.ignore();	// cleans buffer
			}

			switch(choice)	// switches choice
			{
				case 1: cout<<endl<<"Current item ID: "<<get_itemID();	// shows current item ID
					set_itemID();					// calls set item ID
					break;
				case 2: cout<<endl<<"Current title: "<<get_title();		// shows current title
					set_title();					// calls set title
					break;
				case 3: cout<<endl<<"Current director last name: "<<directorlast;	// shows current director last name
					set_authorlast();					// calls set director last name
					break;
				case 4: cout<<endl<<"Current director first name: "<<directorfirst;	// shows current director first name
					set_authorfirst();					// calls set director first name
					break;
				case 5: cout<<endl<<"Current genre: "<<get_genre();			// show current genre
					set_genre();						// calls set genre
					break;
                case 6: cout<<endl<<"Current runtime: "<<runtime;           // show current runtime
                    set_runtime();                      // calls set runtime
                    break;
				case 7: cout<<endl<<"Current price: "<<get_price();			// shows current price
					set_price();						// calls set price
					break;
			}
		}
};

class audioBook : public Item   // defines audioBook class derived from Item class
{
        private:
        string authorlast;	// author last name
		string authorfirst;	// author first name
		string narratorlast;  // narrator last name
		string narratorfirst; // narrator first name
		int runtime;

	public:
        audioBook(string t) : Item(t){};        // constructor - uses item constructor to assign type
                                        // "C++ Inheritance, Polymorphism, Virtual Functions, Abstract Base Class" youtube video
        string get_authorlast() 	{return authorlast;}
		string get_authorfirst()	{return authorfirst;}                         // gets for author and narrator names
		string get_authorname()	    {return authorfirst + " " + authorlast;}
		string get_narratorlast()     {return narratorlast;}
		string get_narratorfirst()    {return narratorfirst;}
		string get_narratorname()     {return narratorfirst + " " + narratorlast;}

		void set_authorlast(string n)		{authorlast = n;}	// sets last name to passed variable

		void set_authorlast()	// sets author last name
		{
			cout<<endl<<"Enter author last name: ";
			getline(cin,authorlast);	// reads in author last name
		}

		void set_authorfirst(string n)		{authorfirst = n;}	// sets first name to passed variable

		void set_authorfirst()	// sets author first name
		{
			cout<<endl<<"Enter author first name: ";
			getline(cin,authorfirst);	// reads in author first name
		}

		void set_narratorlast(string n)		{narratorlast = n;}	// sets last name to passed variable

		void set_narratorlast()	// sets author last name
		{
			cout<<endl<<"Enter narrator last name: ";
			getline(cin,narratorlast);	// reads in author last name
		}

		void set_narratorfirst(string n)		{narratorfirst = n;}	// sets first name to passed variable

		void set_narratorfirst()	// sets author first name
		{
			cout<<endl<<"Enter narrator first name: ";
			getline(cin,narratorfirst);	// reads in author first name
		}

		void set_runtime()          // sets runtime
		{
		    cout<<endl<<"Enter runtime in minutes: ";
		    cin>>runtime;       // reads in runtime
		    cin.ignore();

            while(cin.fail())	// checks for valid input
			{
				if(cin.fail())			// checks to see if input was wrong format
				{
					cin.clear();		// clears fail flag
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					// ignores rest of input - taken from http://stackoverflow.com/questions/16726657
				}	//                            /checking-for-valid-type-input-using-stdin-c
				cout<<endl<<"Invalid runtime. Enter runtime in minutes: ";;
				cin>>runtime;	// reads in runtime
				cin.ignore();	// cleans buffer
			}
		}

		void set_runtime(int r)     {runtime = r;}  // sets runtime to passed variable

        int get_runtime()       {return runtime;}   // gets runtime

		void print_item()		// function prints item info
		{
			cout<<endl<<"Type: "<<get_type()<<endl<<"Item ID: "<<get_itemID()<<endl<<"Title: "<<get_title()
			    <<endl<<"Author: "<<get_authorname()<<endl<<"Narrator: "<<get_narratorname()<<endl<<"Genre: "<<get_genre()
			    <<endl<<"Runtime: "<<runtime<<" minutes"<<endl<<"Price: $"<<fixed<<setprecision(2)<<get_price()
			    <<endl<<"Status: "<<get_itemstatus();
		}

        void edit_item()		// function edits item info
		{
			int choice;	// user choice at menu

			cout<<endl<<"Select the information you would like to edit:";	// prints menu
			cout<<endl<<"1. Item ID"<<endl<<"2. Title"<<endl<<"3. Author last name"<<endl<<"4. Author first name"
			    <<endl<<"5. Narrator last name"<<endl<<"6. Narrator first name"<<endl<<"7. Genre"
                <<endl<<"8. Runtime"<<endl<<"9. Price"<<endl<<">";
			cin>>choice;	// reads in choice
			cin.ignore();	// cleans buffer

			while(choice < 1 || choice > 9 || cin.fail())	// checks for valid input
			{
				if(cin.fail())			// checks to see if input was wrong format
				{
					cin.clear();		// clears fail flag
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					// ignores rest of input - taken from http://stackoverflow.com/questions/16726657
				}	//                            /checking-for-valid-type-input-using-stdin-c
				cout<<endl<<"Invalid selection."<<endl<<">";
				cin>>choice;	// reads in choice
				cin.ignore();	// cleans buffer
			}

			switch(choice)	// switches choice
			{
				case 1: cout<<endl<<"Current item ID: "<<get_itemID();	// shows current item ID
					set_itemID();					// calls set item ID
					break;
				case 2: cout<<endl<<"Current title: "<<get_title();		// shows current title
					set_title();					// calls set title
					break;
				case 3: cout<<endl<<"Current author last name: "<<authorlast;	// shows current author last name
					set_authorlast();					// calls set author last name
					break;
				case 4: cout<<endl<<"Current author first name: "<<authorfirst;	// shows current author first name
					set_authorfirst();					// calls set author first name
					break;
                case 5: cout<<endl<<"Current narrator last name: "<<narratorlast;
                    set_narratorlast();
                    break;
                case 6: cout<<endl<<"Current narrator first name: "<<narratorfirst;
                    set_narratorfirst();
                    break;
				case 7: cout<<endl<<"Current genre: "<<get_genre();			// show current genre
					set_genre();						// calls set genre
					break;
                case 8: cout<<endl<<"Current runtime: "<<runtime;           // show current runtime
                    set_runtime();                      // calls set runtime
                    break;
				case 9: cout<<endl<<"Current price: "<<get_price();			// shows current price
					set_price();						// calls set price
					break;
			}
		}
};

class Reference : public Item   // defines Reference class derived from Item class
{
    private:
        string authorlast;	// author last name
		string authorfirst;	// author first name

	public:
        Reference(string t) : Item(t){};        // constructor - uses item constructor to assign type
                                        // "C++ Inheritance, Polymorphism, Virtual Functions, Abstract Base Class" youtube video
        string get_authorlast() 	{return authorlast;}
		string get_authorfirst()	{return authorfirst;}                         // gets for author name
		string get_authorname()	    {return authorfirst + " " + authorlast;}

		void set_authorlast(string n)		{authorlast = n;}	// sets last name to passed variable

		void set_authorlast()	// sets author last name
		{
			cout<<endl<<"Enter author last name: ";
			getline(cin,authorlast);	// reads in author last name
		}

		void set_authorfirst(string n)		{authorfirst = n;}	// sets first name to passed variable

		void set_authorfirst()	// sets author first name
		{
			cout<<endl<<"Enter author first name: ";
			getline(cin,authorfirst);	// reads in author first name
		}

		void print_item()		// function prints item info
		{
			cout<<endl<<"Type: "<<get_type()<<endl<<"Item ID: "<<get_itemID()<<endl<<"Title: "<<get_title()
                <<endl<<"Author: "<<get_authorname()<<endl<<"Genre: "<<get_genre()<<endl<<"Price: $"
                <<fixed<<setprecision(2)<<get_price()<<endl<<"Status: "<<get_itemstatus();
		}

        void edit_item()		// function edits item info
		{
			int choice;	// user choice at menu

			cout<<endl<<"Select the information you would like to edit:";	// prints menu
			cout<<endl<<"1. Item ID"<<endl<<"2. Title"<<endl<<"3. Author last name"<<endl<<"4. Author first name"<<endl<<"5. Genre"
		            <<endl<<"6. Price"<<endl<<">";
			cin>>choice;	// reads in choice
			cin.ignore();	// cleans buffer

			while(choice < 1 || choice > 6 || cin.fail())	// checks for valid input
			{
				if(cin.fail())			// checks to see if input was wrong format
				{
					cin.clear();		// clears fail flag
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					// ignores rest of input - taken from http://stackoverflow.com/questions/16726657
				}	//                            /checking-for-valid-type-input-using-stdin-c
				cout<<endl<<"Invalid selection."<<endl<<">";
				cin>>choice;	// reads in choice
				cin.ignore();	// cleans buffer
			}

			switch(choice)	// switches choice
			{
				case 1: cout<<endl<<"Current item ID: "<<get_itemID();	// shows current item ID
					set_itemID();					// calls set item ID
					break;
				case 2: cout<<endl<<"Current title: "<<get_title();		// shows current title
					set_title();					// calls set title
					break;
				case 3: cout<<endl<<"Current author last name: "<<authorlast;	// shows current author last name
					set_authorlast();					// calls set author last name
					break;
				case 4: cout<<endl<<"Current author first name: "<<authorfirst;	// shows current author first name
					set_authorfirst();					// calls set author first name
					break;
				case 5: cout<<endl<<"Current genre: "<<get_genre();			// show current genre
					set_genre();						// calls set genre
					break;
				case 6: cout<<endl<<"Current price: "<<get_price();			// shows current price
					set_price();						// calls set price
					break;
			}
		}
};

class Borrow		// defines borrow class
{
	private:
		long borrowID;		// borrow ID
		long patronID;		// patron ID
		long itemID;		// item ID
		time_t duedate;		// due date in seconds
		string borrowstatus;	// borrow status

	public:
		long get_borrowID() 		{return borrowID;}	// these get the above variables
		long get_patronID()		{return patronID;}
		long get_itemID() 		{return itemID;}
		time_t get_duedate()		{return duedate;}
		string get_borrowstatus()	{return borrowstatus;}

		void set_borrowID(int bID)		{borrowID = bID;}

		void set_borrowID()	// sets borrow ID
		{
			cout<<endl<<"Enter new borrow ID number: ";
			cin>>borrowID;	// reads in borrow ID
			cin.ignore();	// cleans buffer
			while(cin.fail())	// checks for valid input
			{
				if(cin.fail())			// checks to see if input was wrong format
				{
					cin.clear();		// clears fail flag
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					// ignores rest of input - taken from http://stackoverflow.com/questions/16726657
				}	//                            /checking-for-valid-type-input-using-stdin-c
				cout<<endl<<"Invalid ID. Enter new borrow ID number: ";;
				cin>>borrowID;	// reads in borrow ID
				cin.ignore();	// cleans buffer
			}
		}

		void set_patronID(long pID)		{patronID = pID;}	// sets patron ID to passed pID

		void set_itemID(long iID)		{itemID = iID;}		// sets item ID to passed bID

		void set_duedate(int borrowdays)	// sets due date
		{
			time_t now = time(NULL);	// stores the current date - learned from cplusplus.com
			tm* now_ptr = localtime(&now);	// converts current date into tm pointer, which can show day, month, year, etc.
			cout<<endl<<"Current date: "<<now_ptr->tm_mon+1<<"/"<<now_ptr->tm_mday<<"/"<<now_ptr->tm_year+1900;	// prints current date
			time_t due = time(NULL)+(borrowdays*24*60*60);	// sets due date plus borrow time (which has to be multiplied by hrs mins sec)
			tm* due_ptr = localtime(&due);			// converts to tm pointer
			cout<<endl<<"Due date: "<<due_ptr->tm_mon+1<<"/"<<due_ptr->tm_mday<<"/"<<due_ptr->tm_year+1900;		// prints due date
			duedate = time(NULL)+(borrowdays*24*60*60);	// stores due date
		}

		void set_duedate_load(int due)		{duedate = due;}		// sets due date to passed variable

		void set_borrowstatus()			{borrowstatus = "Good";}	// sets borrow status to good

		void set_borrowstatus(string bs)	{borrowstatus = bs;}		// sets borrow status to passed variable

		void print_borrow()					// prints borrow info
		{
			tm* due_ptr = localtime(&duedate);	// converts due date to tm pointer
			cout<<endl<<"Borrow ID: "<<borrowID<<endl<<"Patron ID: "<<patronID<<endl<<"Item ID: "<<itemID<<endl<<"Due date: "
			    <<due_ptr->tm_mon+1<<"/"<<due_ptr->tm_mday<<"/"<<due_ptr->tm_year+1900<<endl<<"Status: "<<borrowstatus;
		}

		void edit_borrowstatus()		// option for librarian to edit borrow status manually
		{
			int choice;	// user choice at menu

			cout<<endl<<"Choose new borrow status:";		// prints menu
			cout<<endl<<"1. Borrowed"<<endl<<"2. Returned"<<endl<<"3. Overdue"<<endl<<"4. Fined"<<endl<<">";
			cin>>choice;	// reads in choice
			cin.ignore();	// cleans buffer

			while(choice < 1 || choice > 4 || cin.fail())	// checks for valid input
			{
				if(cin.fail())			// checks to see if input was wrong format
				{
					cin.clear();		// clears fail flag
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					// ignores rest of input - taken from http://stackoverflow.com/questions/16726657
				}	//                            /checking-for-valid-type-input-using-stdin-c
				cout<<endl<<"Invalid selection."<<endl<<">";
				cin>>choice;	// reads in choice
			}

			switch(choice)	// switches choice
			{
				case 1: borrowstatus = "Borrowed";		// changes borrow status to borrowed
					break;
				case 2: borrowstatus = "Returned";		// changes borrow status to returned
					break;
				case 3: borrowstatus = "Overdue";		// changes borrow status to overdue
					break;
				case 4: borrowstatus = "Fined";			// changes borrow status to fined
					break;
			}
		}
};

class Patrons		// defines patrons class
{
	friend class Borrows;		// allows borrows to access patron variables (used to access array)

	private:
		int patroncnt;		// count of patrons
		int maxpatrons;		// max number of patrons before more space needs to be allocated
		Patron *patron_list;	// array of patrons

	public:
		Patrons()	// constructor
		{
			patroncnt = 0;		// initializes count to zero
			patron_list = new Patron[CHUNK];	// creates CHUNK many patrons
			maxpatrons = CHUNK;			// initializes max patrons
		}

		~Patrons()	// destructor
		{
			delete[]patron_list;	// free's memory occupied by patron list
		}

		int get_patroncnt()		{return patroncnt;}	// gets patron count

		void add_patron()	// function to add patrons to patron_list
		{
			if(patroncnt >= maxpatrons)	// checks for space in patron_list array
			{
				Patron *temp = new Patron[patroncnt + CHUNK];	// creates temporary array of current size plus CHUNK
				for(int i = 0; i < patroncnt; i++)		// copies array
					temp[i] = patron_list[i];
				delete[]patron_list;				// deletes old array
				patron_list = temp;				// copies array
				maxpatrons += CHUNK;				// increments max patrons
			}

			patron_list[patroncnt].set_patronID();			// calls set ID function
			for(int i = 0; i < patroncnt; i++)			// checks to see if patron exists
			{
				while(patron_list[patroncnt].get_patronID() == patron_list[i].get_patronID())	// loops until user inputs valid ID
				{
					cout<<endl<<"Error - patron ID number already exists."<<endl;
					patron_list[patroncnt].set_patronID();	// calls set ID function
					i = 0;					// resets i
				}
			}
			patron_list[patroncnt].set_lastname();		// calls set last name function
			patron_list[patroncnt].set_firstname();		// calls set first name fuction
			patron_list[patroncnt].set_fulladdress();	// calls set address function
			patron_list[patroncnt].set_phone();		// calls set phone function
			patron_list[patroncnt].set_email();		// calls set email function
			patroncnt++;					// increments patron count

			cout<<endl<<"Patron added. Press ENTER to return to the menu"<<endl<<">";
			cin.get();	// prompts user to return to menu

		}

		void delete_patron()	// function to delete patron
		{
			if(patroncnt == 0)	// checks to make sure there are patrons in system
			{
				cout<<endl<<"No patrons in system. Press ENTER to return to the menu."<<endl<<">";
				cin.get();	// prompts user to return to menu
			}
			else			// if patrons in system
			{
				int input;	// input ID
				char sure;	// character for user to double check their deletion
				cout<<endl<<"Enter ID number of patron to be deleted: ";
				cin>>input;	// reads in ID
				cin.ignore();	// cleans buffer

				while(cin.fail())	// checks for valid input
				{
					cin.clear();		// clears fail flag
					cin.ignore(numeric_limits<streamsize>::max(), '\n');	// ignores rest of input
					cout<<endl<<"Invalid ID. Enter ID number of patron to be deleted: ";;
					cin>>input;	// reads in patron ID
					cin.ignore();	// cleans buffer
				}

				for(int i = 0; i < patroncnt; i++)	// runs through patron list
				{
					if(patron_list[i].get_patronID() == input)	// executes if patron ID is found in patron list
					{
						if(patron_list[i].get_patronstatus() == "Balance due")	// executes if patron has balance due
						{
							cout<<endl<<"Patron cannot be deleted - balance of $"<<patron_list[i].get_balance()<<" due."
             						    <<endl<<"Press ENTER to return to the menu."<<endl<<">";
							cin.get();	// prompts user to return to menu
							return;		// returns to menu
						}
						else if(patron_list[i].get_numitems() > 0)	// executes if patron has items checked out
						{
							cout<<endl<<"Patron cannot be deleted - "<<patron_list[i].get_numitems()<<" items checked out."
             						    <<endl<<"Press ENTER to return to the menu."<<endl<<">";
							cin.get();	// prompts user to return to menu
							return;		// returns to menu
						}
						else	// if user can be deleted
						{
							patron_list[i].print_patron();	// prints patron info and asks user if they're sure
							cout<<endl<<"Are you sure you want to delete this patron? (y/n)"<<endl<<">";
							cin>>sure;	// reads in sure
							cin.ignore();	// cleans buffer
							if(sure == 'y' || sure == 'Y')	// if user is sure patron is deleted
							{
								for(int j = i; j < patroncnt - 1; j++)	// moves everything after the patron back on in the array
								{
									patron_list[j] = patron_list[j + 1];
								}

								patroncnt--;	// decrements patron count
								cout<<endl<<"Patron deleted. Press ENTER to return to the menu"<<endl<<">";
								cin.get();	// prompts user to return to menu
								return;		// returns to menu
							}
							else	// if user is not sure deletion is cancelled
							{
								cout<<endl<<"Deletion cancelled. Press ENTER to return to the menu."<<endl<<">";
								cin.get();	// prompts user to return to menu
								return;		// returns to menu
							}
						}
					}
				}
				// displays if patron on in list
				cout<<endl<<"Error - could not locate patron. Press ENTER to return to the menu."<<endl<<">";
				cin.get();	// prompts user to return to menu
			}
		}

		void sort_patrons(string code)	// sorts patrons by passed string
		{
			if(patroncnt == 0)	// executes if no patrons in system
			{
				cout<<endl<<"No patrons in system. Press ENTER to return to the menu."<<endl<<">";
				cin.get();	// prompts user to return to menu
				return;		// returns to menu
			}
			else if(code == "id")	// if user wants to sort by ID
			{
				Patron temp;	// creates temporary patron
				for(int i = 0; i < patroncnt; i++)
				{
					for(int j = 0; j < patroncnt; j++)
					{
						if(patron_list[i].get_patronID() < patron_list[j].get_patronID())	// if current patron ID is smaller than next
						{
							temp = patron_list[i];			// sets temp to current patron
							patron_list[i] = patron_list[j];	// switches patron elements
							patron_list[j] = temp;			// replaces patron

						}
					}
				}
				cout<<endl<<"Patrons sorted. Press ENTER to return to the menu"<<endl<<">";
				cin.get();	// prompts user to return to menu
			}
			else if(code == "last")	// if user wants to sort by last name
			{
				Patron temp;	// creates temporary patron
				for(int i = 0; i < patroncnt; i++)
				{
					for(int j = 0; j < patroncnt; j++)
					{
						if(patron_list[i].get_lfname() < patron_list[j].get_lfname())	// if current last name is smaller than next
						{
							temp = patron_list[i];			// sets temp to current patron
							patron_list[i] = patron_list[j];	// switches patron elements
							patron_list[j] = temp;			// replaces patron

						}
					}
				}
				cout<<endl<<"Patrons sorted. Press ENTER to return to the menu"<<endl<<">";
				cin.get();	// prompts user to return to menu
			}
		}

		void print_allpatrons()		// function to print all patrons
		{
			if(patroncnt == 0)	// checks to see if there are patrons in system
			{
				cout<<endl<<"No patrons in system. Press ENTER to return to the menu."<<endl<<">";
				cin.get();	// prompts user to return to menu
			}
			else			// executes if patrons in system
			{
				for(int i = 0; i < patroncnt; i++)	// goes through patron list
				{
					cout<<endl<<endl<<"Patron "<<i + 1<<": "<<endl;	// prints patron number
					patron_list[i].print_patron();			// calls print patron function
				}
				cout<<endl<<endl<<"Press ENTER to return to the menu."<<endl<<">";
				cin.get();	// prompts user to return to menu
			}
		}

		int find_patron()		// function to find patron
		{
			if(patroncnt == 0)	// checks to see if there are patrons in system
			{
				cout<<endl<<"No patrons in system. Press ENTER to return to the menu."<<endl<<">";
				cin.get();	// prompts user to return to menu
				return -1;	// returns -1, signaling there are no patrons
			}
			else			// executes if patrons in system
			{
				long input;	// for input ID
				cout<<endl<<"Enter patron ID number: ";
				cin>>input;	// reads in ID
				cin.ignore();	// cleans buffer
				while(cin.fail())	// checks for valid input
				{
					cin.clear();	// clears fail flag
					cin.ignore(numeric_limits<streamsize>::max(), '\n');	// ignore rest of input - taken from stackoverflow.com
					cout<<endl<<"Invalid ID. Enter patron ID number: ";;
					cin>>input;	// reads in ID
					cin.ignore();	// cleans buffer
				}

				for(int i = 0; i < patroncnt; i++)	// runs through patron list
				{
					if(patron_list[i].get_patronID() == input)
					{
						return i;	// returns element of the patron once it's found
					}
				}

				cout<<endl<<"Error - could not locate patron. Press ENTER to return to the menu."<<endl<<">";	// prints if patron wasn't found
				cin.get();	// prompts user to return to menu
				return -1;	// -1 signals patron not found
			}
		}

		void print_patronbalances()	// prints all patrons with balances
		{
			if(patroncnt == 0)	// executes if no patrons in system
			{
				cout<<endl<<"No patrons in system. Press ENTER to return to the menu."<<endl<<">";
				cin.get();	// prompts user to return to menu
			}
			else			// executes if patrons in system
			{
				int balancecnt = 0;	// counter for patrons with balances
				for(int i = 0; i < patroncnt; i++)	// runs through patron list
				{
					if(patron_list[i].get_balance() > 0)	// if patron has a balance
					{
						patron_list[i].print_patron();		// prints patron info
						balancecnt++;				// increments balance count
					}
				}
				if(balancecnt == 0)	// if no patrons have balances
				{
					cout<<endl<<"No patrons in system with balances. Press ENTER to return to the menu."<<endl<<">";
					cin.get();	// prompts user to return to menu
				}
				else			// if patrons have balances
				{
					cout<<endl<<endl<<"Press ENTER to return to the menu."<<endl<<">";
					cin.get();	// prompts user to return to menu
				}
			}
		}

		void print_addresslabels()		// prints address labels for all patrons
		{
			if(patroncnt == 0)		// if no patrons in system
			{
				cout<<endl<<"No patrons in system. Press ENTER to return to the menu."<<endl<<">";
				cin.get();	// prompts user to return to menu
			}
			else		// if patrons in system
			{
				for(int i = 0; i < patroncnt; i++)	// runs through patron list
				{
					cout<<endl<<endl<<"Patron "<<i + 1<<": "<<endl;		// prints patron number
					cout<<endl<<patron_list[i].get_flname();		// prints patron name and address
					cout<<endl<<patron_list[i].get_address();
					cout<<endl<<patron_list[i].get_city()<<", "<<patron_list[i].get_state()<<" "<<patron_list[i].get_zip();
				}
				cout<<endl<<endl<<"Press ENTER to return to the menu."<<endl<<">";
				cin.get();	// prompts user to return to menu
			}
		}

		void edit_patron(int id)		{patron_list[id].edit_patron();}		// calls edit patron function given patron element (id)

		void print_patron(int id)		{patron_list[id].print_patron();}		// calls print patron fuction given patron element (id)

		int get_numitems(int id)		{return patron_list[id].get_numitems();}	// gets number of items given patron element (id)

		int find_patron(long id)	// overloaded function to find specific patron element given user provided ID (id)
		{
			for(int i = 0; i < patroncnt; i++)	// runs through patron list
			{
				if(id == patron_list[i].get_patronID())	// returns element if patron is found
					return i;
			}
			return -1;	// return -1 if patron not found
		}

		void pay_balance(int id)		{patron_list[id].pay_balance();}	// calls pay balance for patron element (id)

		void save(char filename[])		// save function
		{
			ofstream file;		// creates the file pointer

			file.open(filename,ios::app);		// opens filename

			if(!file);			// if the file could not be opened
			else				// if the file was opened
			{
				file<<patroncnt<<endl;	// prints patron count

				for(int i = 0; i < patroncnt; i++)	// runs through list of patrons and prints their info line by line
				{
					file<<patron_list[i].get_patronID()<<endl;
					file<<patron_list[i].get_lastname()<<endl;
					file<<patron_list[i].get_firstname()<<endl;
					file<<patron_list[i].get_address()<<endl;
					file<<patron_list[i].get_city()<<endl;
					file<<patron_list[i].get_state()<<endl;
					file<<patron_list[i].get_zip()<<endl;
					file<<patron_list[i].get_phone()<<endl;
					file<<patron_list[i].get_email()<<endl;
					file<<patron_list[i].get_balance()<<endl;
					file<<patron_list[i].get_patronstatus()<<endl;
					file<<patron_list[i].get_numitems()<<endl;
				}
				file.close();		// closes file
			}
		}

		void load(char filename[])		// save function
	    {
			ifstream file;		// creates the file pointer

			file.open(filename);		// opens filename

			if(!file);			// if the file could not be opened
			else				// if the file was opened
			{
				long id;
				string tempstr, last, first, addr, city, st, zip, phn, eml, status;
				float balance;
				int numitems;

				for(int i = 0; i < 10; i++)	// skips library setting
					getline(file,tempstr);

				file>>patroncnt;		// stores patron count
				file.ignore();

				Patron *temp = new Patron[patroncnt + CHUNK];	// creates temporary array of current size plus CHUNK
				delete[]patron_list;				// deletes old array
				patron_list = temp;				// copies array
				maxpatrons += (patroncnt + CHUNK);				// increments max patrons

				for(int i = 0; i < patroncnt; i++)	// runs through list of patrons and prints their info line by line
				{
					file>>id;		        patron_list[i].set_patronID(id);	// populates patron data
					file.ignore();
					getline(file,last);	    patron_list[i].set_lastname(last);
					getline(file,first);	patron_list[i].set_firstname(first);
					getline(file,addr); 	patron_list[i].set_address(addr);
					getline(file,city);	    patron_list[i].set_city(city);
					getline(file,st);	    patron_list[i].set_state(st);
					getline(file,zip);	    patron_list[i].set_zip(zip);
					getline(file,phn);	    patron_list[i].set_phone(phn);
					getline(file,eml);	    patron_list[i].set_email(eml);
					file>>balance;		    patron_list[i].set_balance(balance);
					file.ignore();
					getline(file,status);	patron_list[i].set_patronstatus(status);
					file>>numitems;		    patron_list[i].set_numitems(numitems);
					file.ignore();
				}
				file.close();		// closes file
			}
		}


};

class Items		// defines items class
{
	friend class Borrows;	// give borrows access to items private variable (specifically to access item list array)
	private:
		int itemcnt;		// count of number of item in array
		int maxitems;		// max item for dynamic reallocation
		Item **item_list;	// array of items

	public:
		Items()		// constructor
		{
			itemcnt = 0;			// intializes item count to zero
			item_list = new Item*[CHUNK];	// makes new item list of size CHUNK
			maxitems = CHUNK;		// intializes max items to CHUNK
		}

		~Items()	// destructor
		{
			delete[]item_list;		// free's memory occupied by item list
		}

		int get_itemcnt()		{return itemcnt;}	// gets item count

		void add_item()		// function to add item to item list
		{
            int type;

			if(itemcnt >= maxitems)		// checks to see if more memory needs to be allocated
			{
				Item **temp = new Item*[itemcnt + CHUNK];		// creates temporary array of items of current size + CHUNK
				for(int i = 0; i < itemcnt; i++)		// copies array
					temp[i] = item_list[i];
				delete[]item_list;				// deletes old array
				item_list = temp;				// replaces array
				maxitems += CHUNK;				// increments max items
			}

            cout<<endl<<"What library item do you want to add?"<<endl<<"1. Book"<<endl<<"2. DVD"<<endl<<"3. Audio Book"<<endl
                <<"4. Reference"<<endl<<">";
            cin>>type;
            while(type < 1 || type > 4 || cin.fail())	// checks type
            {
                cin.clear();				// clears fail flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n');	// ignores rest of input - taken from http://stackoverflow.com/questions/16726657
                cout<<endl<<"Invalid selection. Try again."<<endl<<">";	//				      /checking-for-valid-type-input-using-stdin-c
                cin>>type;	// reads in type
                cin.ignore();	// cleans buffer
            }

            switch(type)
            {
                case 1: item_list[itemcnt] = new Book("Book");      // adds new book to array
                        item_list[itemcnt]->set_itemID();           // sets new book ID
                        for(int i = 0; i < itemcnt; i++)			// runs through item list
                        {
                            while(item_list[itemcnt]->get_itemID() == item_list[i]->get_itemID())	// checks to see if user input ID is already in array
                            {
                                cout<<endl<<"Error - item ID already exists."<<endl;
                                item_list[itemcnt]->set_itemID();	// recalls set ID function
                                i = 0;		// resets i
                            }
                        }
                        item_list[itemcnt]->set_title();			// calls set title function
                        item_list[itemcnt]->set_authorlast();		// calls set author last name function
                        item_list[itemcnt]->set_authorfirst();		// calls set author first name function
                        item_list[itemcnt]->set_genre();			// calls set genre function
                        item_list[itemcnt]->set_price();			// calls set price function
                        itemcnt++;					// increments item count
                        break;

                case 2: item_list[itemcnt] = new DVD("DVD");        // adds new DVD to array
                        item_list[itemcnt]->set_itemID();           // sets DVD ID
                        for(int i = 0; i < itemcnt; i++)			// runs through item list
                        {
                            while(item_list[itemcnt]->get_itemID() == item_list[i]->get_itemID())	// checks to see if user input ID is already in array
                            {
                                cout<<endl<<"Error - item ID already exists."<<endl;
                                item_list[itemcnt]->set_itemID();	// recalls set ID function
                                i = 0;		// resets i
                            }
                        }
                        item_list[itemcnt]->set_title();			// calls set title function
                        item_list[itemcnt]->set_authorlast();		// calls set author last name function
                        item_list[itemcnt]->set_authorfirst();		// calls set author first name function
                        item_list[itemcnt]->set_genre();			// calls set genre function
                        item_list[itemcnt]->set_runtime();          // calls set runtime function
                        item_list[itemcnt]->set_price();			// calls set price function
                        itemcnt++;					// increments item count
                        break;

                case 3: item_list[itemcnt] = new audioBook("Audio Book");        // adds new DVD to array
                        item_list[itemcnt]->set_itemID();           // sets DVD ID
                        for(int i = 0; i < itemcnt; i++)			// runs through item list
                        {
                            while(item_list[itemcnt]->get_itemID() == item_list[i]->get_itemID())	// checks to see if user input ID is already in array
                            {
                                cout<<endl<<"Error - item ID already exists."<<endl;
                                item_list[itemcnt]->set_itemID();	// recalls set ID function
                                i = 0;		// resets i
                            }
                        }
                        item_list[itemcnt]->set_title();			// calls set title function
                        item_list[itemcnt]->set_authorlast();		// calls set author last name function
                        item_list[itemcnt]->set_authorfirst();		// calls set author first name function
                        item_list[itemcnt]->set_narratorlast();       // calls set narrator last name function
                        item_list[itemcnt]->set_narratorfirst();      // calls set narrator first name function
                        item_list[itemcnt]->set_genre();			// calls set genre function
                        item_list[itemcnt]->set_runtime();          // calls set runtime function
                        item_list[itemcnt]->set_price();			// calls set price function
                        itemcnt++;					// increments item count
                        break;

                case 4: item_list[itemcnt] = new Reference("Reference");      // adds new book to array
                        item_list[itemcnt]->set_itemID();           // sets new book ID
                        for(int i = 0; i < itemcnt; i++)			// runs through item list
                        {
                            while(item_list[itemcnt]->get_itemID() == item_list[i]->get_itemID())	// checks to see if user input ID is already in array
                            {
                                cout<<endl<<"Error - item ID already exists."<<endl;
                                item_list[itemcnt]->set_itemID();	// recalls set ID function
                                i = 0;		// resets i
                            }
                        }
                        item_list[itemcnt]->set_title();			// calls set title function
                        item_list[itemcnt]->set_authorlast();		// calls set author last name function
                        item_list[itemcnt]->set_authorfirst();		// calls set author first name function
                        item_list[itemcnt]->set_genre();			// calls set genre function
                        item_list[itemcnt]->set_price();			// calls set price function
                        itemcnt++;					// increments item count
                        break;
            }

            cout<<endl<<"Item added. Press ENTER to return to the menu"<<endl<<">";
			cin.get();	// prompts user to return to menu
		}

		void delete_item()		// function to delete a item
		{
			if(itemcnt == 0)	// checks to see if item in system
			{
				cout<<endl<<"No items in system. Press ENTER to return to the menu."<<endl<<">";
				cin.get();	// prompts user to return to menu
			}
			else		// if items in system
			{
				int input;	// input for item ID
				char sure;	// sure for user to double check deletion
				cout<<endl<<"Enter ID number of item to be deleted: ";
				cin>>input;	// reads in input
				cin.ignore();	// cleans buffer

				while(cin.fail())	// checks for valid input
				{
					cin.clear();		// clears fail flag
					cin.ignore(numeric_limits<streamsize>::max(), '\n');	// ignores rest of input
					cout<<endl<<"Invalid ID. Enter ID number of item to be deleted: ";;
					cin>>input;	// reads in patron ID
					cin.ignore();	// cleans buffer
				}

				for(int i = 0; i < itemcnt; i++)	// runs through item list
				{
					if(item_list[i]->get_itemID() == input)	// if item is found
					{
						if(item_list[i]->get_itemstatus() == "Checked-out")	// if item is checked out
						{
							cout<<endl<<"Item is currently checked out and cannot be deleted."
             						    <<endl<<"Press ENTER to return to the menu."<<endl<<">";
							cin.get();	// prompts user to return to menu
							return;		// returns to menu
						}
						else if(item_list[i]->get_itemstatus() == "Reference")	// if item is a reference
						{
							cout<<endl<<"Reference materials cannot be checked out."
             						    <<endl<<"Press ENTER to return to the menu."<<endl<<">";
							cin.get();	// prompts user to return to menu
							return;		// returns to menu
						}
						item_list[i]->print_item();	// prints item info and asks user if they're sure
						cout<<endl<<"Are you sure you want to this item? (y/n)"<<endl<<">";
						cin>>sure;	// reads in sure
						cin.ignore();	// cleans buffer
						if(sure == 'y' || sure == 'Y')	// if user is sure item is deleted
						{
							for(int j = i; j < itemcnt - 1; j++)	// moves all items after deleted one back one element in array
							{
								item_list[j] = item_list[j + 1];
							}
							itemcnt--;	// decrements item count
							cout<<endl<<"Item deleted. Press ENTER to return to the menu"<<endl<<">";
							cin.get();	// prompts user to return to menu
							return;		// returns to menu
						}
						else	// if user is not sure deletion is cancelled
						{
							cout<<endl<<"Deletion cancelled. Press ENTER to return to the menu."<<endl<<">";
							cin.get();	// prompts user to return to menu
							return;		// returns to menu
						}
					}
				}

				cout<<endl<<"Error - could not locate item. Press ENTER to return to the menu."<<endl<<">";	// prints if item not found
				cin.get();	// prompts user to return to menu
			}
		}

		void sort_items(string code)	// sorts item by provided code
		{
			if(itemcnt == 0)	// returns to menu if no items in system
			{
				cout<<endl<<"No items in system. Press ENTER to return to the menu."<<endl<<">";
				cin.get();	// prompts user to return to menu
				return;		// returns to menu
			}
			else if(code == "id")	// sorts by item ID
			{
				Item *temp;	// creates temporary item
				for(int i = 0; i < itemcnt; i++)		// runs through array
				{
					for(int j = 0; j < itemcnt; j++)
					{
						if(item_list[i]->get_itemID() < item_list[j]->get_itemID())	// if ID is smaller than the next
						{
							temp = item_list[i];		// current item is stored in temp
							item_list[i] = item_list[j];	// current item and next one are swapped
							item_list[j] = temp;		// other item is replaced by temp

						}
					}
				}
				cout<<endl<<"Items sorted. Press ENTER to return to the menu"<<endl<<">";
				cin.get();	// prompts user to return to menu
			}
			else if(code == "last")		// sorts items by director last name
			{
				Item *temp;	// creates temporary item
				for(int i = 0; i < itemcnt; i++)		// runs through array
				{
					for(int j = 0; j < itemcnt; j++)
					{
						if(item_list[i]->get_authorlast() < item_list[j]->get_authorlast())	// if last name is smaller than next
						{
							temp = item_list[i];		// current item is stored in temp
							item_list[i] = item_list[j];	// current item and next one are swapped
							item_list[j] = temp;		// other item is replaced by temp

						}
					}
				}
				cout<<endl<<"Items sorted. Press ENTER to return to the menu"<<endl<<">";
				cin.get();	// prompts user to return to menu
			}
			else if(code == "title")	// sorts item by title
			{
				Item *temp;	// creates temporary item
				for(int i = 0; i < itemcnt; i++)		// runs through array
				{
					for(int j = 0; j < itemcnt; j++)
					{
						if(item_list[i]->get_title() < item_list[j]->get_title())			// if title is smaller than next
						{
							temp = item_list[i];		// current item is stored in temp
							item_list[i] = item_list[j];	// current item and next one are swapped
							item_list[j] = temp;		// other item is replaced by temp

						}
					}
				}
				cout<<endl<<"Items sorted. Press ENTER to return to the menu"<<endl<<">";
				cin.get();	// prompts user to return to menu
			}
            else if(code == "type")	// sorts item by title
			{
				Item *temp;	// creates temporary item
				for(int i = 0; i < itemcnt; i++)		// runs through array
				{
					for(int j = 0; j < itemcnt; j++)
					{
						if(item_list[i]->get_type() < item_list[j]->get_type())			// if title is smaller than next
						{
							temp = item_list[i];		// current item is stored in temp
							item_list[i] = item_list[j];	// current item and next one are swapped
							item_list[j] = temp;		// other item is replaced by temp

						}
					}
				}
				cout<<endl<<"Items sorted. Press ENTER to return to the menu"<<endl<<">";
				cin.get();	// prompts user to return to menu
			}
		}

		void print_allitems()		// function prints all items
		{
			if(itemcnt == 0)	// if no items in system
			{
				cout<<endl<<"No items in system. Press ENTER to return to the menu."<<endl<<">";
				cin.get();	// prompts user to return to menu
			}
			else			// if items in system
			{
				for(int i = 0; i < itemcnt; i++)	// runs through array
				{
					cout<<endl<<endl<<"Item "<<i + 1<<": "<<endl;	// prints item number in array
					item_list[i]->print_item();			// calls print item function
				}
				cout<<endl<<endl<<"Press ENTER to return to the menu."<<endl<<">";
				cin.get();	// prompts user to return to menu
			}
		}

		int find_item()			// function for finding a item
		{
			if(itemcnt == 0)	// if no items in system
			{
				cout<<endl<<"No items in system. Press ENTER to return to the menu."<<endl<<">";
				cin.get();	// prompts user to return to menu
				return -1;	// -1 signals fail
			}
			else			// if items in system
			{
				long input;	// input for ID number
				cout<<endl<<"Enter item ID number: ";
				cin>>input;	// reads in input
				cin.ignore();	// cleans buffer

				while(cin.fail())	// checks for valid input
				{
					cin.clear();	// clear fail flag
					cin.ignore(numeric_limits<streamsize>::max(), '\n');	// ignore rest of input - taken from stackoverflow.com
					cout<<endl<<"Invalid ID. Enter item ID number: ";;
					cin>>input;	// reads in input
					cin.ignore();	// cleans buffer
				}

				for(int i = 0; i < itemcnt; i++)	// runs through array
				{
					if(item_list[i]->get_itemID() == input)	// returns element of item if found
					{
						return i;
					}
				}
				cout<<endl<<"Error - could not locate item. Press ENTER to return to the menu."<<endl<<">"; 	// prints if item not found
				cin.get();	// prompts user to return to menu
				return -1;	// -1 signals fail
			}
		}

		void edit_item(int id)			{item_list[id]->edit_item();}	// calls edit item given list element (id)

		void print_item(int id)			{item_list[id]->print_item();}	// calls print item given list element (id)

		void reportlost(int id)							// reports a item lost given list element (id)
		{
			if(itemcnt > 0)				// ensures that there are items in array
				item_list[id]->reportlost();
		}

		int find_item(long id)					// overloaded function to find specific item given ID (id)
		{
			for(int i = 0; i < itemcnt; i++)		// runs through item list
			{
				if(id == item_list[i]->get_itemID())	// returns element if item is found
					return i;
			}
			return -1;	// -1 signals fail if item not found
		}

		void save(char filename[])		// save function
		{
			ofstream file;		// creates the file pointer

			file.open(filename,ios::app);		// opens filename

			if(!file);			// if the file could not be opened
			else				// if the file was opened
			{
				file<<itemcnt<<endl;	// prints item count

				for(int i = 0; i < itemcnt; i++)	// runs through list of items and prints their info line by line
				{
				    if(item_list[i]->get_type() == "Book")        // saves book info
                    {
                        file<<item_list[i]->get_type()<<endl;
                        file<<item_list[i]->get_itemID()<<endl;
                        file<<item_list[i]->get_title()<<endl;
                        file<<item_list[i]->get_authorlast()<<endl;
                        file<<item_list[i]->get_authorfirst()<<endl;
                        file<<item_list[i]->get_genre()<<endl;
                        file<<item_list[i]->get_price()<<endl;
                        file<<item_list[i]->get_itemstatus()<<endl;
                    }
				    else if(item_list[i]->get_type() == "DVD")        // saves dvd info
                    {
                        file<<item_list[i]->get_type()<<endl;
                        file<<item_list[i]->get_itemID()<<endl;
                        file<<item_list[i]->get_title()<<endl;
                        file<<item_list[i]->get_authorlast()<<endl;
                        file<<item_list[i]->get_authorfirst()<<endl;
                        file<<item_list[i]->get_genre()<<endl;
                        file<<item_list[i]->get_runtime()<<endl;
                        file<<item_list[i]->get_price()<<endl;
                        file<<item_list[i]->get_itemstatus()<<endl;
                    }
				    else if(item_list[i]->get_type() == "Audio Book")        // saves audio book info
                    {
                        file<<item_list[i]->get_type()<<endl;
                        file<<item_list[i]->get_itemID()<<endl;
                        file<<item_list[i]->get_title()<<endl;
                        file<<item_list[i]->get_authorlast()<<endl;
                        file<<item_list[i]->get_authorfirst()<<endl;
                        file<<item_list[i]->get_narratorlast()<<endl;
                        file<<item_list[i]->get_narratorfirst()<<endl;
                        file<<item_list[i]->get_genre()<<endl;
                        file<<item_list[i]->get_runtime()<<endl;
                        file<<item_list[i]->get_price()<<endl;
                        file<<item_list[i]->get_itemstatus()<<endl;
                    }
                    else if(item_list[i]->get_type() == "Reference")        // saves reference info
                    {
                        file<<item_list[i]->get_type()<<endl;
                        file<<item_list[i]->get_itemID()<<endl;
                        file<<item_list[i]->get_title()<<endl;
                        file<<item_list[i]->get_authorlast()<<endl;
                        file<<item_list[i]->get_authorfirst()<<endl;
                        file<<item_list[i]->get_genre()<<endl;
                        file<<item_list[i]->get_price()<<endl;
                        file<<item_list[i]->get_itemstatus()<<endl;
                    }
				}
				file.close();		// closes file
			}
		}

		void load(char filename[])		// save function
		{
			ifstream file;		// creates the file pointer

			file.open(filename);		// opens filename

			if(!file);			// if the file could not be opened
			else				// if the file was opened
			{
				long id;
				string tempstr, title, last, first, genre, status, type;
				float price;
				int pcnt, runtime;

				for(int i = 0; i < 10; i++)	// skips library setting
					getline(file,tempstr);

				file>>pcnt;			// gets patron count
                file.ignore();

				for(int i = 0; i < pcnt; i++)
				{
					file>>tempstr;
					file.ignore();
					getline(file,tempstr);		// skips patron info in file
					getline(file,tempstr);
					getline(file,tempstr);
					getline(file,tempstr);
					getline(file,tempstr);
					getline(file,tempstr);
					getline(file,tempstr);
					getline(file,tempstr);
					file>>tempstr;
					file.ignore();
					getline(file,tempstr);
					file>>tempstr;
					file.ignore();
				}

				file>>itemcnt;		// stores item count
				file.ignore();

				Item **temp = new Item*[itemcnt + CHUNK];		// creates temporary array of items of current size + CHUNK
				for(int i = 0; i < itemcnt; i++)		// copies array
					temp[i] = item_list[i];
				delete[]item_list;				// deletes old array
				item_list = temp;				// replaces array
				maxitems += CHUNK;				// increments max items

				for(int i = 0; i < itemcnt; i++)	// runs through list of items and prints their info line by line
				{
				    getline(file,type);
				    if(type == "Book")
				    {
				        item_list[i] = new Book("Book");
				 		file>>id;		        item_list[i]->set_itemID(id);
                        file.ignore();
                        getline(file,title);	item_list[i]->set_title(title);		// populates book data
                        getline(file,last);	    item_list[i]->set_authorlast(last);
                        getline(file,first);	item_list[i]->set_authorfirst(first);
                        getline(file,genre);	item_list[i]->set_genre(genre);
                        file>>price;		    item_list[i]->set_price(price);
                        file.ignore();
                        getline(file,status);	item_list[i]->set_itemstatus(status);
				    }
                    else if(type == "DVD")
                    {
                        item_list[i] = new DVD("DVD");
				 		file>>id;		        item_list[i]->set_itemID(id);
                        file.ignore();
                        getline(file,title);	item_list[i]->set_title(title);		// populates dvd data
                        getline(file,last);	    item_list[i]->set_authorlast(last);
                        getline(file,first);	item_list[i]->set_authorfirst(first);
                        getline(file,genre);	item_list[i]->set_genre(genre);
                        file>>runtime;          item_list[i]->set_runtime(runtime);
                        file.ignore();
                        file>>price;		    item_list[i]->set_price(price);
                        file.ignore();
                        getline(file,status);	item_list[i]->set_itemstatus(status);
                    }
                    else if(type == "Audio Book")
                    {
                        item_list[i] = new audioBook("Audio Book");
				 		file>>id;		        item_list[i]->set_itemID(id);
                        file.ignore();
                        getline(file,title);	item_list[i]->set_title(title);		    // populates audio book data
                        getline(file,last);	    item_list[i]->set_authorlast(last);
                        getline(file,first);	item_list[i]->set_authorfirst(first);
                        getline(file,last);     item_list[i]->set_narratorlast(last);
                        getline(file,first);    item_list[i]->set_narratorfirst(first);
                        getline(file,genre);	item_list[i]->set_genre(genre);
                        file>>runtime;          item_list[i]->set_runtime(runtime);
                        file.ignore();
                        file>>price;		    item_list[i]->set_price(price);
                        file.ignore();
                        getline(file,status);	item_list[i]->set_itemstatus(status);
                    }
                    else if(type == "Reference")
                    {
                        item_list[i] = new Reference("Reference");
				 		file>>id;		        item_list[i]->set_itemID(id);
                        file.ignore();
                        getline(file,title);	item_list[i]->set_title(title);		    // populates reference data
                        getline(file,last);	    item_list[i]->set_authorlast(last);
                        getline(file,first);	item_list[i]->set_authorfirst(first);
                        getline(file,genre);	item_list[i]->set_genre(genre);
                        file>>price;		    item_list[i]->set_price(price);
                        file.ignore();
                        getline(file,status);	item_list[i]->set_itemstatus(status);
                    }
				}
				file.close();		// closes file
			}
		}
};

class Borrows			// defines borrows class
{
	private:
		int borrowcnt;		// counter for borrows
		int maxborrows;		// max borrows for dynamic reallocation
		Borrow *borrow_list;	// list of borrows
		Patrons *patrons;	// list of patrons
		Items *items;		// list of items
		Library *library;	// library settings

	public:
		Borrows(Patrons *p, Items *b, Library *l)	// constructor is passed list of patrons, list of items, and library settings
		{
			borrowcnt = 0;				// borrow count intitialized to zero
			borrow_list = new Borrow[CHUNK];	// borrow list created for size CHUNK
			patrons = p;				// stores patron list
			items = b;				// stores item list
			library = l;				// stores library settings
			maxborrows = CHUNK;			// intializes max borrows
		}

		~Borrows()	// destructor
		{
			delete[]borrow_list;	// free's memory occupied by borrow list
		}

		void checkout()		// function for checking out a item
		{
			if(borrowcnt >= maxborrows)	// checks to see if more memory needs to be allocated
			{
				Borrow *temp = new Borrow[borrowcnt + CHUNK];	// creates temporary borrows list of current size + CHUNK
				for(int i = 0; i < borrowcnt; i++)		// copies borrow array
					temp[i] = borrow_list[i];
				delete[]borrow_list;				// deletes old array
				borrow_list = temp;				// copies array back to borrow list
				maxborrows += CHUNK;				// increments max borrows
			}
			if(items->get_itemcnt() == 0 && patrons->get_patroncnt() == 0)	// if no items and patrons in system
			{
				cout<<endl<<"No patrons or items in system. Press ENTER to return to the menu."<<endl<<">";
				cin.get();	// prompts user to return to menu
				return;		// returns to menu
			}
			else if(patrons->get_patroncnt() == 0)	// if no patrons in system
			{
				cout<<endl<<"No patrons in system. Press ENTER to return to the menu."<<endl<<">";
				cin.get();	// prompts user to return to menu
				return;		// returns to menu
			}
			else if(items->get_itemcnt() == 0)	// if no item in system
			{
				cout<<endl<<"No items in system. Press ENTER to return to the menu."<<endl<<">";
				cin.get();	// prompts user to return to menu
				return;		// returns to menu
			}
			else		// if items and patrons in system
			{
				int pID, iID;	// elements for patron and item lists

				pID = patrons->find_patron();	// finds patron
				if(pID == -1)			// returns to menu if patron could not be found
					return;
				else		// if patron found
				{
					if(patrons->patron_list[pID].get_patronstatus() == "No balance" &&
					   patrons->patron_list[pID].get_numitems() < library->get_maxitems())	// if patron has no balance and room for items
					{
						iID = items->find_item();	// find item
						if(iID == -1)			// returns to menu if item could not be found
							return;
                        if(items->item_list[iID]->get_type() == "Reference")    // checks to see if item is reference
                        {
                            cout<<endl<<"Reference books cannot be checked out. Press ENTER to return to the menu."<<endl<<">";
                            cin.get();
                            return;     // returns to menu
                        }
						else if(items->item_list[iID]->get_itemstatus() == "Checked-in")	// if item is checked in
						{
							borrow_list[borrowcnt].set_borrowID();		// calls set borrow ID
							// calls set patron ID given pID element
							borrow_list[borrowcnt].set_patronID(patrons->patron_list[pID].get_patronID());
							// calls set item ID given iID element
							borrow_list[borrowcnt].set_itemID(items->item_list[iID]->get_itemID());
							borrow_list[borrowcnt].set_borrowstatus();	// calls set borrow status
							if(items->item_list[iID]->get_type() == "Book")
                                borrow_list[borrowcnt].set_duedate(library->get_borrowdays("book"));	// calls set due date for book
                            else if(items->item_list[iID]->get_type() == "DVD")
                                borrow_list[borrowcnt].set_duedate(library->get_borrowdays("dvd"));	// calls set due date for DVD
                            else if(items->item_list[iID]->get_type() == "Audio Book")
                                borrow_list[borrowcnt].set_duedate(library->get_borrowdays("abook"));	// calls set due date for DVD
							borrowcnt++;					// increments borrow count
							patrons->patron_list[pID].checkout();		// calls checkout function for patron [pID]
							items->item_list[iID]->checkout();		// calls checkout function for item [iID]

							cout<<endl<<"Item checked-out. Press ENTER to return to the menu."<<endl<<">";
							cin.get();	// prompts user to return to menu
							return;		// returns to menu
						}
						else if(items->item_list[iID]->get_itemstatus() == "Checked-out")	// if item is checked out
						{
							cout<<endl<<"Item is already checked-out. Press ENTER to return to the menu."<<endl<<">";
							cin.get();	// prompts user to return to menu
							return;		// returns to menu
						}
						else			// if item is lost or out for repair
						{
							cout<<endl<<"Item is unavailable. Press ENTER to return to the menu."<<endl<<">";
							cin.get();	// prompts user to return to menu
							return;		// returns to menu
						}
					}
					else if(patrons->patron_list[pID].get_patronstatus() == "Balance due")	// if patron has balance they cannot check-out item
					{
						cout<<endl<<"Patron has balance of $"<<patrons->patron_list[pID].get_balance()	// prints balance
						    <<". Balance must be paid before check-out.";
						cout<<endl<<endl<<"Press ENTER to return to the menu."<<endl<<">";
						cin.get();	// prompts user to return to menu
						return;		// returns to menu
					}
					else if(patrons->patron_list[pID].get_numitems() >= library->get_maxitems())	// if patron has max items they cannot
					{										// check-out a item
						cout<<endl<<"Patron has too many items checked out. Press ENTER to return to the menu."<<endl<<">";
						cin.get();	// prompts user to return to menu
						return;		// returns to menu
					}
				}
			}
		}

		void checkin()			// function for checking in a item
		{
			if(borrowcnt == 0)	// if no items checked out
			{
				cout<<endl<<"No items checked out. Press ENTER to return to the menu."<<endl<<">";
				cin.get();	// prompts user to return to menu
				return;		// returns to menu
			}
			else			// if items checked out
			{
				float fine;	// fine amount
				long itemID;	// item ID number
				int iID, pID, timediff;		// elements in patron and item array (pID and iID) and time difference for calculating fine
				time_t now = time(NULL);	// intializes the current date

				cout<<endl<<"Enter item ID number: ";
				cin>>itemID;	// reads in item ID
				cin.ignore();	// cleans buffer

				while(cin.fail())	// checks for valid input
				{
					cin.clear();	// clears fail flag
					cin.ignore(numeric_limits<streamsize>::max(), '\n');	// ignore rest of input - taken from stackoverflow.com
					cout<<endl<<"Invalid ID. Enter item ID number: ";;
					cin>>itemID;	// reads in item ID
					cin.ignore();	// cleans buffer
				}

				for(int i = 0; i < borrowcnt; i++)	// runs through borrow list
				{
					if(itemID == borrow_list[i].get_itemID())	// if item ID is found in item list
					{
						iID = items->find_item(borrow_list[i].get_itemID());		// finds item element
						pID = patrons->find_patron(borrow_list[i].get_patronID());	// finds patron element

						if(items->item_list[iID]->get_itemstatus() == "Lost")		// if item is lost it cannot be checked in
						{
							cout<<endl<<"Item is lost. Press ENTER to return to the menu."<<endl<<">";
							cin.get();	// prompts user to return to menu
							return;		// returns to menu
						}
						else if(now > borrow_list[i].get_duedate())	// if item is overdue
						{
							timediff = (now - borrow_list[i].get_duedate())/24/60/60; 	// calculates time difference in days
							if(items->item_list[iID]->get_type() == "Book")
							{
								fine = library->get_fine("book");					    // gets fine rate for book
                                if((timediff - 1) / library->get_finedays("book") > 0)		// checks how many days late the item is
                                {								                        // and against the fine frequency
                                    fine =  library->get_fine("book") + (library->get_fine("book") * ((timediff - 1) / library->get_finedays("book")));
                                }
							}
							else if(items->item_list[iID]->get_type() == "DVD")
							{
								fine = library->get_fine("dvd");					    // gets fine rate for dvd
                                if((timediff - 1) / library->get_finedays("dvd") > 0)		// checks how many days late the item is
                                {								                        // and against the fine frequency
                                    fine =  library->get_fine("dvd") + (library->get_fine("dvd") * ((timediff - 1) / library->get_finedays("dvd")));
                                }
							}
							else if(items->item_list[iID]->get_type() == "Audio Book")
							{
								fine = library->get_fine("abook");					    // gets fine rate for audio book
                                if((timediff - 1) / library->get_finedays("abook") > 0)		// checks how many days late the item is
                                {								                        // and against the fine frequency
                                    fine =  library->get_fine("abook") + (library->get_fine("abook") * ((timediff - 1) / library->get_finedays("abook")));
                                }
							}

							items->item_list[iID]->checkin();		// calls item check-in
							patrons->patron_list[pID].checkin();		// calls patron check-in (to decrement patron item count)
							patrons->patron_list[pID].add_fine(fine);	// adds fine to patron
							patrons->patron_list[pID].balancedue();		// changes patron status to balance due

							cout<<endl<<"Item is "<<timediff<<" days overdue."<<endl; 	// prints how overdue the item is and the fine
							cout<<endl<<"Fine of $"<<fixed<<setprecision(2)<<fine<<" added to patron account.";
							cout<<endl<<endl<<"Press ENTER to return to the menu."<<endl<<">";
							cin.get();	// prompt user to return to menu

							for(int j = i; j < borrowcnt - 1; j++)		// removes borrow from borrow list
							{
								borrow_list[j] = borrow_list[j + 1];
							}
							borrowcnt--;	// decrements borrow count
							return;		// returns to menu
						}
						else	// if item is on time
						{
							for(int j = i; j < borrowcnt - 1; j++)		// removes borrow from list
							{
								borrow_list[j] = borrow_list[j + 1];
							}
							borrowcnt--;				// decrements borrow count
							items->item_list[iID]->checkin();	// calls item check-in
							patrons->patron_list[pID].checkin();	// calls patron check-in

							cout<<endl<<"Item checked in. Press ENTER to return to the menu."<<endl<<">";
							cin.get();	// prompts user to return to menu
							return;		// returns to menu
						}
					}
				}
				cout<<endl<<"Item is not checked-out. Press ENTER to return to the menu."<<endl<<">"; // if item not in borrow list
				cin.get();	// prompts user to return to menu
				return;		// returns to menu
			}
		}

		void print_ODitems()		// prints a list of overdue items
		{
			if(borrowcnt == 0)	// if no items checked out
			{
				cout<<endl<<"No items checked out. Press ENTER to return to the menu."<<endl<<">";
				cin.get();	// prompts user to return to menu
				return;		// returns to menu
			}
			else			// if item checked out
			{
				int iID, pID;			// elements for patron and item lists
				time_t now = time(NULL);	// initializes now to current time
				time_t due;			// declares due variable
				for(int i = 0; i < borrowcnt; i++)	// runs through borrow list
				{
					if(now > borrow_list[i].get_duedate())	// if a item is overdue
					{
						iID = items->find_item(borrow_list[i].get_itemID());		// gets item element
						pID = patrons->find_patron(borrow_list[i].get_patronID());	// gets patron element

						cout<<endl<<"Patron: "<<patrons->patron_list[pID].get_flname();	//prints patron, item, and overdue information
						cout<<endl<<"Title: "<<items->item_list[iID]->get_title();
						due = borrow_list[i].get_duedate();
						tm* due_ptr = localtime(&due);
						cout<<endl<<"Due date: "<<due_ptr->tm_mon+1<<"/"<<due_ptr->tm_mday<<"/"<<due_ptr->tm_year+1900;
						cout<<endl<<endl<<"Press ENTER to return to the menu."<<endl<<">";
						cin.get();	// prompts user to return to menu
						return;		// returns to menu
					}
				}
				cout<<endl<<"No items overdue. Press ENTER to return to the menu."<<endl<<">"; 	// if no item are overdue
				cin.get();	// prompts user to return to menu
				return;		// returns to menu
			}
		}

		void reportlost()		// function to report a item as lost
		{
			float fine;			// fine amount
			long itemID;			// item ID number
			int iID, pID, timediff;		// elements for item and patron list, and time difference
			time_t now = time(NULL);	// intitializes now to current time
			cout<<endl<<"Enter item ID number: ";
			cin>>itemID;	// reads in item ID
			cin.ignore();	// cleans buffer

			while(cin.fail())	// checks for valid input
			{
				cin.clear();	// clears fail flag
				cin.ignore(numeric_limits<streamsize>::max(), '\n');	// ignore rest of input - taken from stackoverflow.com
				cout<<endl<<"Invalid ID. Enter item ID number: ";;
				cin>>itemID;	// reads in item ID
				cin.ignore();	// cleans buffer
			}

			if(borrowcnt > 0)	// if there are items out it checks to see if the lost item is checked out
			{
				for(int i = 0; i < borrowcnt; i++)		// runs through borrow list
				{
					if(itemID == borrow_list[i].get_itemID())	// if the item ID if found in borrow list
					{
						iID = items->find_item(borrow_list[i].get_itemID());		// gets item element
						pID = patrons->find_patron(borrow_list[i].get_patronID());	// gets patron element

						items->item_list[iID]->print_item();		// prints item info
						items->item_list[iID]->reportlost();		// reports item lost
						patrons->patron_list[pID].checkin();		// calls patron check-in (decrements patron item count)
						patrons->patron_list[pID].balancedue();		// changes patron status to balance due

						cout<<endl<<endl<<"Item checked out by "<<patrons->patron_list[pID].get_flname()<<".";	// prints patron info and charge
						cout<<endl<<"Price of item added to patron account:";
						patrons->patron_list[pID].buy_item(items->item_list[iID]->get_price());	// adds price to patron balance
						cout<<endl<<endl<<"Press ENTER to return to the menu."<<endl<<">";
						cin.get();	// prompts user to return to menu
						return;		// return to menu
					}
				}
			}
			iID = items->find_item(itemID);		// calls find item if not checked out
			if(iID == -1)				// if find fails
			{
				cout<<endl<<"Error - could not locate item. Press ENTER to return to the menu."<<endl<<">";
				cin.get();	// prompts user to return to menu
				return;		// returns to menu
			}
			else			// if item is found
			{
				items->item_list[iID]->reportlost();	// reports item as lost
				cout<<endl<<"Item reported as lost. Press ENTER to return to the menu."<<endl<<">";
				cin.get();	// prompts user to return to menu
				return;		// returns to menu
			}
		}

		void save(char filename[])		// save function
		{
			ofstream file;		// creates the file pointer

			file.open(filename,ios::app);	// opens filename

			if(!file);			// if the file could not be opened
			else				// if the file was opened
			{
				file<<borrowcnt<<endl;	// prints borrow count

				for(int i = 0; i < borrowcnt; i++)	// runs through list of borrows and prints their info line by line
				{
					file<<borrow_list[i].get_borrowID()<<endl;
					file<<borrow_list[i].get_patronID()<<endl;
					file<<borrow_list[i].get_itemID()<<endl;
					file<<borrow_list[i].get_duedate()<<endl;
					file<<borrow_list[i].get_borrowstatus()<<endl;
				}
				file.close();		// closes file

				cout<<endl<<"File saved! Press ENTER to return to the menu."<<endl<<">";
				cin.get();
			}
		}

		void load(char filename[])		// save function
		{
			ifstream file;		// creates the file pointer

			file.open(filename);		// opens filename

			if(!file);			// if the file could not be opened
			else				// if the file was opened
			{
				long id;
				string tempstr, status, type;
				int due, icnt, pcnt;

				for(int i = 0; i < 10; i++)	// skips library setting
					getline(file,tempstr);

				file>>pcnt;			// gets patron count
				file.ignore();

				for(int i = 0; i < pcnt; i++)
				{
					file>>tempstr;
					file.ignore();
					getline(file,tempstr);		// skips patron info in file
					getline(file,tempstr);
					getline(file,tempstr);
					getline(file,tempstr);
					getline(file,tempstr);
					getline(file,tempstr);
					getline(file,tempstr);
					getline(file,tempstr);
					file>>tempstr;
					file.ignore();
					getline(file,tempstr);
					file>>tempstr;
					file.ignore();
				}

				file>>icnt;			// gets item count
				file.ignore();

				for(int i = 0; i < icnt; i++)
				{
                    getline(file,type);
				    if(type == "Book")
				    {
				 		file>>tempstr;
                        file.ignore();
                        getline(file,tempstr);		// skips book data
                        getline(file,tempstr);
                        getline(file,tempstr);
                        getline(file,tempstr);
                        file>>tempstr;
                        file.ignore();
                        getline(file,tempstr);
				    }
                    else if(type == "DVD")
                    {
				 		file>>tempstr;
                        file.ignore();
                        getline(file,tempstr);		// skips dvd data
                        getline(file,tempstr);
                        getline(file,tempstr);
                        getline(file,tempstr);
                        file>>tempstr;
                        file.ignore();
                        file>>tempstr;
                        file.ignore();
                        getline(file,tempstr);
                    }
                    else if(type == "Audio Book")
                    {
				 		file>>tempstr;
                        file.ignore();
                        getline(file,tempstr);	// skips audio book data
                        getline(file,tempstr);
                        getline(file,tempstr);
                        getline(file,tempstr);
                        getline(file,tempstr);
                        getline(file,tempstr);
                        file>>tempstr;
                        file.ignore();
                        file>>tempstr;
                        file.ignore();
                        getline(file,tempstr);
                    }
                    else if(type == "Reference")
                    {
				 		file>>tempstr;
                        file.ignore();
                        getline(file,tempstr);	// skips reference data
                        getline(file,tempstr);
                        getline(file,tempstr);
                        getline(file,tempstr);
                        file>>tempstr;
                        file.ignore();
                        getline(file,tempstr);
                    }
				}

				file>>borrowcnt;		// stores borrow count
				file.ignore();

				Borrow *temp = new Borrow[borrowcnt + CHUNK];	// creates temporary array of current size plus CHUNK
				delete[]borrow_list;				// deletes old array
				borrow_list = temp;				// copies array
				maxborrows += (borrowcnt + CHUNK);				// increments max items

				for(int i = 0; i < borrowcnt; i++)	// stores borrow info
				{
					file>>id;		borrow_list[i].set_borrowID(id);
					file>>id;		borrow_list[i].set_patronID(id);
					file>>id;		borrow_list[i].set_itemID(id);
					file>>due;		borrow_list[i].set_duedate_load(due);
					file.ignore();
					getline(file,status);	borrow_list[i].set_borrowstatus(status);
				}
				file.close();		// closes file

				cout<<endl<<"File loaded! Press ENTER to return to the menu."<<endl<<">";
				cin.get();
			}
		}
};
