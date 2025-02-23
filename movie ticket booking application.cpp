#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<conio.h>

void call_main();

using namespace std;

class admin
{
	public :
		char movie_name[100];
		int num_of_tick;
		float price;
		
	public :
		void add_movie();
		void customer_list();
		void speak_1(string );
};

class customer
{
	public :
		char cust_name[100];
		char booked_movie[100];
		long mobile;
		
	public :
		void book_ticket();
		void check_av_movie();
		void speak_2(string );
};

void customer :: book_ticket()
{
	system("cls");
	
	cout<<"\n\t\t*********** WELCOME ************";   speak_2("welcome");
	cout<<"\nEnter your name : ";     speak_2("Enter your name");
	cin>>cust_name;
	
	cout<<"\nEnter movie name : ";    speak_2("Enter movie name");
	cin>>booked_movie;
	
	cout<<"\nEnter mobile number : ";  speak_2("Enter mobile number");
	cin>>mobile;
	
	cout<<"\nMessage for payment is sent on your mobile number................";  speak_2("Message for payment is sent on your mobile number");
	cout<<"\nComplete payment ,  After completion your ticket will booked.";   speak_2("Complete payment. After completion your ticket will booked");
	
	ofstream data;
	data.open("customer.txt",ios::app);
	data<< cust_name <<"  "<< booked_movie <<"  "<<mobile <<endl;
	
	data.close();
	
	system("cls");
	cout<<"It will take some minutes for directing to customer page .........."; speak_2("It will take some minutes for directing to customer page");
	sleep(4);
}

void customer :: check_av_movie()
{
	system("cls");
	cout<<"\n\n\t\t Movies list loding "; speak_2("loding Movies list");
	for(int i=0;i<=10;i++)
	{
		cout<<".";
		for(int j=0;j<=99999999;j++)
		{
			
		}
	}

	fstream   file;
	file.open("Admin.txt",ios::in);
	cout<<"\n\t"<<"Movie name "<<"\t\t"<<"Number of tickets "<<"\t\t"<<"Price";
	do
	{
		cout<<"\n";
		
		string m_name = "No movie";
		int num_tick = 0;
		float price =0;
		
		file >> m_name >> num_tick >> price;  
		cout<<"\t"<< m_name <<"\t\t\t"<< num_tick <<"\t\t\t" << price <<" "<< endl;
		
	}
	while(!(file.eof()));
//	system("start admin.txt");
	
	char ch;
	cout<<"\n\n\t\tEnter any character to move customer page : "; speak_2("Enter any character to move customer page");
	getch();
}

void admin :: add_movie()
{
	system("cls");
	cout<<"\n\t$$$$$$$$$$$ WELCOME $$$$$$$$$$$$";
	cout<<"\n\tEnter movie name : ";  speak_1("enter movie name");
	cin>>movie_name;
	
	cout<<"\n\tNumber of tickets available : ";  speak_1("enter number of tickets available");
	cin>>num_of_tick;
	
	cout<<"\n\tEnter price of one ticket : ";  speak_1("enter price of one ticket");
	cin>>price;
	
	ofstream input;
	input.open("admin.txt",ios::app);
	
	input<< movie_name << "  " << num_of_tick <<"  "<< price <<endl;	
	input.close();
	
	cout<<"\n\t\t\t &&&& New Movie Added Succesfully &&&&";  speak_1("new movie added succesfully");
	
	cout<<"\n\n\t\tEnter any character to move admin page : ";
	getch();
	
}

void admin :: customer_list()
{
	system("cls");
	cout<<"\n\n\t\t Customer list loading "; speak_1("loading customer list");
	for(int i=0;i<=10;i++)
	{
		cout<<".";
		for(int j=0;j<=99999999;j++)
		{
			
		}
	}

    fstream   cu_file;
	cu_file.open("customer.txt",ios::in);
	cout<<"\n\t"<<"Customer name "<<"\t\t"<<"Movie name "<<"\t\t"<<"Mobile number";
	do
	{
		cout<<"\n";
		
		string cu_name = "No customer";
		string m_name = "No movie";
		int mobile = 0;
		
		cu_file >> cu_name >> m_name >> mobile;  
		cout<<"\t"<< cu_name <<"\t\t\t"<< m_name <<"\t\t\t" << mobile <<"\t\t\t"<< endl;
		
	}
	while(!(cu_file.eof()));
		
//	system("start customer.txt");
	
	char ch;
	cout<<"\n\n\t\tEnter any character to move admin page : ";
	getch();
	
}

void admin:: speak_1(string line)
{
	string command = "espeak \"" + line + "\"";    //  Concat the phrase to the command
	const char* charCommand = command.c_str();    // Convert to a const char*
	system(charCommand);    // Send the command to cmd to execute espeak with the phrase an argument
}

void customer:: speak_2(string line)
{
	string command = "espeak \"" + line + "\"";    //  Concat the phrase to the command
	const char* charCommand = command.c_str();    // Convert to a const char*
	system(charCommand);    // Send the command to cmd to execute espeak with the phrase an argument
}

void speak(string line)
{
	string command = "espeak \"" + line + "\"";    //  Concat the phrase to the command
	const char* charCommand = command.c_str();    // Convert to a const char*
	system(charCommand);    // Send the command to cmd to execute espeak with the phrase an argument
}

void front_page()
{
	system("cls");	
	cout<<"\n\t\t****************** Welcome to movie center ******************";   speak("Welcome to movie center");
	cout<<"\n\t\t 1. Admin login ";  speak("option one admin login");
	cout<<"\n\t\t 2. Customer login ";  speak("option two customer login");
	cout<<"\n\t\t 3. Exit ";  speak("option three exit");
}

void admin_page()
{
	again :
	system("cls");
	cout<<"\n\t\t *********** WELCOME TO ADMIN PAGE ***********"; speak("welcome to admin page");
	cout<<"\n\n\t\t 1. Add new movie ticket.";
	cout<<"\n\t\t 2. Check customer list.";
	cout<<"\n\t\t 3. Go back";

	int choice;
	cout<<"\n\n\t\t Enter your choice : ";  speak("enter your choice");
	cin>>choice;
	
	if(choice==1)
	{
		admin a1;
		a1.add_movie();
		
		goto again;
	}
	else if(choice==2)
	{
		admin a1;
		a1.customer_list();
		goto again;
	}
	else
	{
		system("cls");
		call_main();
	}
}

void customer_page()
{
	int choice;
	
	while(choice!=3)
	{
		system("cls");
		cout<<" \n\n\t\t ************ WELCOME TO CUSTOMER PAGE ************ ";
		speak("welcome to cutomer page");
		cout<<"\n\n\t\t 1. Book a ticket.";
		cout<<"\n\t\t 2. Check available tickets of movies";
		cout<<"\n\t\t 3. Go back";
	
		cout<<"\n\n\t\t Enter your choice : ";  speak("enter your choice");
		cin>>choice;
		
		if(choice==1)
		{
			customer c1;
			c1.book_ticket();
		}
		else if(choice==2)
		{
			customer c1;
			c1.check_av_movie();
		}
			
			choice == 0;
	}	
		system("cls");
		call_main();
	
}

int choice;

void call_main()
{	
	while(1)
	{
		front_page();
		
		cout<<"\n\n\t\t  Enter your choice : ";   speak("Enter your choice");
		cin>>choice;
		
		if(choice==1)
		{
			admin_page();
		}
		else if(choice==2)
		{
			customer_page();
		}
		else if(choice==3)
		{
			system("cls");
			cout<<"\n\n\t\tThanks for visiting my program .......";
			speak("Thanks for visiting our movie ticket booking system");
			sleep(20);
			break;
			sleep(20);
		}
		else
		{
			cout<<"\n\t\t ^^^^^^^ Invalid Option ^^^^^^^ Please try again ^^^^^^^";   speak("invalid otion please try again");
		}
	}
	
}

int main()
{
		system("color E4");
	call_main();
	if(choice==3)
	{
		return 0;
	}
}
