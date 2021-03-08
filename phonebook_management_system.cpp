#include <iostream>
#include <fstream>
#include <cstring>
#include <conio.h>
#include<iomanip>

using namespace std;

class contacts

{

private:

	string FirstName,CityName,PhoneNumber,address,email,day,date,status;
     int ID,age;
public:

void input();


void display();

void SearchP();

void displayCalender();

void update(); 

void displaybackuplist();

void Delete();

};


void contacts::input()
{

ofstream x("contacts.txt", ios::app);
ofstream x1("Calender.txt", ios::out);
ofstream x2("backuplist.txt", ios::app);


			if (!x)
			{
			
			        cout<<"File Cannot be Opened \n";
			
			
			}

cout<<"\nEnter Your ID:";
cin>>ID;

cout<<"\nEnter Your First Name:";
cin>>FirstName;

cout<<"\nEnter Email:";
cin>>email;

cout<<"\nEnter Address:";
cin>>address;

cout<<"\nEnter Whatsapp Number:";
cin>>PhoneNumber;

cout<<"\nEnter Today Date:";
cin>>date;

cout<<"\nEnter Day:";
cin>>day;

cout<<"\nyou want to create BACKUP list of Contacts(yes/no):";
cin>>status;



if(status=="yes"||status=="YES")
{
  //x2<<"Successfully!Backup of your Contacts has been saved:"<<endl;
  x2<<ID<<"\t"<<FirstName<<"\t"<<email<<"\t"<<address<<"\t"<<PhoneNumber<<endl;
x<<ID<<"\t"<<FirstName<<"\t"<<email<<"\t"<<address<<"\t"<<PhoneNumber<<endl;
x1<<"Date:"<<date<<"\nDay:"<<day<<endl;
}
else
{
	x<<ID<<"\t"<<FirstName<<"\t"<<email<<"\t"<<address<<"\t"<<PhoneNumber<<endl;
	x1<<"Date:"<<date<<"\nDay:"<<day<<endl;
}


}
void contacts::display()

{

ifstream x("contacts.txt");


				if (!x)
				{
				
				        cout<<"File Cannot be Opened \n";
				
				}

while(x>>ID>>FirstName>>email>>address>>PhoneNumber)
{
cout<<ID<<"\t"<<FirstName<<"\t"<<email<<"\t"<<address<<"\t"<<PhoneNumber<<endl;
cout<<endl<<endl;
}


}

void contacts::displayCalender()

{

ifstream x1("calender.txt");

				if (!x1)
				{
				
				        cout<<"File Cannot be Opened \n";
				
				}

	while(x1>>date>>day)
{
	cout<<"\t\t\t\t\t___________________________________________\n";
	cout<<"\n\n\t\t\t\t\t\t\tToday Calender"<<endl<<endl;
	cout<<"\t\t\t\t\t___________________________________________\n\n\n";
	cout<<"\n\t\t\t\t\t\t"<<date<<"\n\n\t\t\t\t\t\t"<<day<<endl;
    cout<<endl<<endl;
}

}

void contacts::displaybackuplist()

{

ifstream x2("backuplist.txt");

				if (!x2)
				{
				
				        cout<<"File Cannot be Opened \n";
				
				}

while(x2>>ID>>FirstName>>email>>address>>PhoneNumber)
{
cout<<ID<<"\t"<<FirstName<<"\t"<<email<<"\t"<<address<<"\t"<<PhoneNumber<<endl;
cout<<endl<<endl;
}

}
void contacts::SearchP()

{

ifstream x("contacts.txt");

				if (!x) 
			
				{
				
			
				        cout<<"File Cannot be Opened \n";
				
		    
			    }

string s;

cout<<"\nEnter WhatsappNo You Want to Search-->";
cin>>s;

cout<<"ID "<<"\t"<<"First Name"<<"\t"<<"Email"<<"\t"<<"PhoneNumber"<<endl;
					
cout<<"---  "<<"\t"<<"---------"<<"\t"<<"---------"<<"\t"<<"---------"<<"\t"<<"------------"<<endl;

while(x>>ID>>FirstName>>email>>address>>PhoneNumber){

if(s.compare(PhoneNumber)==0)
cout<<ID<<"\t"<<FirstName<<"\t"<<email<<"\t"<<address<<"\t"<<PhoneNumber<<endl;
}


}


void contacts::Delete()
 {
 	cout<<"\n\n\t\t\t\t\t\tDelete Contacts Record:"<<endl;
 	cout<<"\t\t\t\t\t\t------------------------------"<<endl;
	 ifstream x;
	 x.open("contacts.txt",ios::out);
 	
	 ofstream y;
	 y.open("temp.txt",ios::out);
	 if(!x && !y)
	
	 {
	 	
	 	cout<<"File Not Exist";
	 	
	 	
	 }
 	
 	string Name;
 	
	 cout<<"\t\tEnter the Person Name you want to Delete the Record:";
 	
 	cin>>Name;
 	
 while(x>>ID>>FirstName>>email>>address>>PhoneNumber)
	
			{
				
		cout << FirstName <<endl;
    
			if(Name.compare(FirstName )==0)
{
						
			continue;
				
    		
            y<<ID<<"\t"<<FirstName<<"\t"<<email<<"\t"<<address<<"\t"<<PhoneNumber<<endl;

				cout<<endl;
			
				cout<<"You Have Successfully Deleted Your Data !!!";
				break;

}	

			
		else 
		
		{
		
		
		cout<<"No Data Exist in this Name"<<endl;
		
		cout<<"Try again"<<endl;
	
     	}
			
		    
}
		

	
    x.close();

    y.close();    

   remove("contacts.txt");

   rename("temp.txt","contacts.txt");

  
  }
  
   void contacts::update()
 {
 	cout<<"\n\n\n\t\t\t\t\t\t\tUpdate  Contacts Record:"<<endl;
 	cout<<"\t\t\t\t\t\t\t-------------------------"<<endl;
 	
	 ifstream x("contacts.txt",ios::out);
 	
	 ofstream y("temp.txt",ios::out);
	 
 	
 	string Name;
 	
	 cout<<"\t\tEnter the Person Name you update the Record:";
 	
 	cin>>Name;
 	
	 	 while(x>>ID>>FirstName>>email>>address>>PhoneNumber)
		{			
			//cout << FirstName <<endl;
    
				if(Name.compare(FirstName )==0)
			
				{
						cout<<"\nEnter Your ID:";
cin>>ID;

cout<<"\nEnter Your First Name:";
cin>>FirstName;

cout<<"\nEnter Email:";
cin>>email;

cout<<"\nEnter Address:";
cin>>address;

cout<<"\nEnter Whatsapp Number:";
cin>>PhoneNumber;
		
					

						y<<ID<<"\t"<<FirstName<<"\t"<<email<<"\t"<<address<<"\t"<<PhoneNumber<<endl;

						cout<<endl;
			
						cout<<"You Have Successfully Updated Your Data !!!";
						break;

				}	
				else 
				{
					
				cout<<"No Data Exist in this Name"<<endl;
				
				cout<<"Try again"<<endl;
			
		     	}
			
		    
   		}
   	
    x.close();

    y.close();    

   remove("contacts.txt");

   rename("temp.txt","contacts.txt");

   }
   
   

class Notes
{

private:

	string personName,Notespost;
public:

void input();

void display();

void SearchN();


} ;


void Notes::input(){

ofstream x("Notes.txt", ios::app);

			if (!x)
			{
			
			        cout<<"File Cannot be Opened \n";
			
			
			}

						
						cout<<"\nEnter A Person Name:";
						cin>>personName;

						cout<<"\nAttach a Sticky Notes(Enter 0 for End the Notes):";
						getline(cin,Notespost,'0');
 
 x<<"Name:"<<personName<<"\n"<<"StickyNotes:"<<Notespost<<endl;


}

void Notes::display()

{

ifstream x("Notes.txt");

				if (!x)
				{
				
				        cout<<"File Cannot be Opened \n";
				
				}
				
				else
				{
					while(x>>personName>>Notespost)

					 cout<<personName<<"\n"<<Notespost<<endl;
				}


				x.close();
}

void Notes::SearchN()

{

ifstream x("Notes.txt");

				if (!x) 
				{
				
				        cout<<"File Cannot be Opened \n";
				
		        }

string s;

cout<<"\nEnter Person Name-->";
cin>>s;

cout<<"Person Name"<<"\t\t"<<"StickyNotes"<<endl;
					
cout<<"----------"<<"\t"<<"-----------"<<endl;

	while(x>>personName>>Notespost){

if(s.compare(personName)==0){
cout<<personName<<"\n"<<Notespost<<endl;
}
}


}

class AlarmsReminder

{

private:

	string alarm,reminder;
public:

void input();

void display();



};


void AlarmsReminder::input()
{

ofstream x("AlarmsReminder.txt", ios::app);

			if (!x)
			{
			
			        cout<<"File Cannot be Opened \n";
			
			
			}

cout<<"\nSet Alarm(e.g 6:00PM):";
cin>>alarm;

cout<<"\nSet Reminder(eg 6:00PM00):";
cin>>reminder;


x<<"Alarm:"<<alarm<<"\nReminder"<<reminder<<endl;
x<<"--------------------------------------------"<<endl;

}

void AlarmsReminder::display()

{

ifstream x("AlarmsReminder.txt");


				if (!x)
				{
				
				        cout<<"File Cannot be Opened \n";
				
				}

while(x>>alarm>>reminder)
{
cout<<alarm<<"\n"<<reminder<<endl;
}

}
class Appointmentsr

{

private:

	string date,time,status;
public:

void input();

void display();



};


void Appointmentsr::input()
{

ofstream x("Appointmentsr.txt", ios::app);

			if (!x)
			{
			
			        cout<<"File Cannot be Opened \n";
			
			
			}

cout<<"\nDate(DD-MM-YY):";
cin>>date;

cout<<"\nTime(e.g 4:00AM):";
cin>>time;

cout<<"\nReceiverd SMS(yes/no):";
cin>>status;

x<<"Date:"<<date<<"\nTime:"<<time<<"\nReceivedSMS:"<<status<<endl<<endl;

if(status=="yes"||status=="YES")
{
  x<<"Your Appointment has been Approved:"<<endl;
}
else
{
  x<<"Your Appointment has been Canceled:"<<endl;
}
x<<"--------------------------------------------"<<endl;


}

void Appointmentsr::display()

{

ifstream x("Appointmentsr.txt");


				if (!x)
				{
				
				        cout<<"File Cannot be Opened \n";
				
				}

while(x>>date>>time>>status)
{
cout<<date<<"\n"<<time<<"\n"<<status<<endl;
}
if(status=="yes"||status=="YES")
{
	cout<<"\n\n\t\tYour Appointment has been Approved:";
}
}



   void welcome()
   
   {

	    string username,password;
	 system("COLOR E");
	
	  //system("cls"); 

 cout<<"\n\n\n\n\n\n\t\t\t\t\t_______________________________________________";
cout<<"\n\n\n\t\t\t\t\t\t\tWELCOME TO ";
cout<<"\n\t\t\t\t\t\tP H O N E B O O K MANAGEMENT SYSTEM"<<endl;
 cout<<"\n\t\t\t\t\t_______________________________________________\n\n\n";



	

	while(1)
	
	{
		


				cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t   Username:";
			
					cin>>username;
			
					cout<<"\t\t\t\t\t\t\t   Password:";
			
					cin>>password;
			
			 
	
        

		cout<<"\n\n\n\n\n***********************************************************************************************************************************************\n";

				if((username=="zikyan" || username=="ZIKYAN") && (password=="123" || password=="123"))
					
					{
			
						cout<<" \n\n\n\n\n\n\n\n\n\t\t\t\t\t\tyou are welcome!!!";
			
						system("pause");
			
						break;
			
					}
			
						else
						{
						
			cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tinvalid username or password\n";	}
			
				}
			
				}
				
int main()

{
	//welcome();

	system("cls");
	

		 contacts B;
		 Appointmentsr AP;
		 AlarmsReminder AR;
         Notes N;
	int *p=new int;
	int choice;
	char more;

    while(true){
    	while(true)
    	{
		fullup:

    	for(int i=0;i<10;i++,cout<<endl); 
    	 system("color 03");
    	 cout<<"\t\t\t\t\t_______________________________________________\n";
    	cout<<"\t\t\t\t\t_______________________________________________\n";
    
	  cout<<"\n\t\t\t\t\t\t  PHONEBOOK MANAGEMENT SYSTEM\n";
	
	  cout<<"\t\t\t\t\t_______________________________________________\n";
	  cout<<"\t\t\t\t\t________________________________________________\n\n\n";
	
	  cout<<"\t\t\t\t\t\t1___________________CONTACTS\n\n";
	
	  cout<<"\t\t\t\t\t\t2___________________NOTES\n\n";
	
	  cout<<"\t\t\t\t\t\t3___________________APPOINTMENTS\n\n";
	
	  cout<<"\t\t\t\t\t\t4___________________ALARMS AND REMINDER\n\n";
	
	  cout<<"\t\t\t\t\t\t5___________________TASKS\n\n";
	
	  cout<<"\t\t\t\t\t\t6___________________CALENDER\n\n";
	  
	  cout<<"\t\t\t\t\t\t7___________________REPORTS\n\n";
	  
	  cout<<"\t\t\t\t\t\t8___________________EXIT\n\n";
	
	  cout<<"\t\t\t\tEnter Your Choice-->";
	  cin>>choice;
	  switch(choice)
	  {
	  case 1:
up:
	
    system("cls");
    //system("color 05");
      cout<<"\t\t\t\t\t_______________________________________________\n";
    
	  cout<<"\n\t\t\t\t\t\t  CONTACTS\n";
	
	  cout<<"\t\t\t\t\t________________________________________________\n\n\n";
	
	  cout<<"\t\t\t\t\t\t1___________________Add Record\n\n";
	
	  cout<<"\t\t\t\t\t\t2___________________View/list Record\n\n";
	
	  cout<<"\t\t\t\t\t\t3___________________Search Record\n\n";
	
	  cout<<"\t\t\t\t\t\t4___________________Update\n\n";
	
	  cout<<"\t\t\t\t\t\t5___________________Delete\n\n";
	
	  cout<<"\t\t\t\t\t\t6___________________Main Menu\n\n";
	
	  cout<<"\t\t\t\tEnter Your Choice-->";


	cin>>*p;

	switch(*p)
	
	{

		
				case 1:
					
			        start:
							system("cls");
					
					cout<<"Enter Contacts Detail:"<<endl;
			        
					cout<<"---------------------";
			        
						B.input();
			          system("cls");
			
			         	
			cout<<"You want to Enter More Record or Not (y/n):";
			cin>>more;
			if(more=='y'||more=='Y')
			{
				goto start;
			}
			else
			{
				goto up;
			}
			break;
				
			
				case 2:
				
				system("cls");
			    
				int ch;
				while(true){
				
				
				cout<<"\t\t\t\t\t\t1___________________Display Contacts Record\n\n";

				
				cin>>ch;
				
				switch(ch)
				
				{
										case 1:			
											cout<<"ID "<<"\t"<<"FirstName"<<"\t"<<"Email"<<"\t\t"<<"Address"<<"\t\t"<<"PhoneNumber"<<endl;
					
                                            cout<<"---  "<<"\t"<<"---------"<<"\t"<<"---------"<<"\t"<<"---------"<<"\t"<<"------------"<<endl;
											
												B.display();
												system("pause");
												
												system("cls");
											goto up;
												break;

										default:cout<<"Plz input Valid input:";
											goto up;
											      break;
											
								}
					system("pause");
					break;
			
				case 3 : 
				
				system("cls");
				
				
				
			    B.SearchP();
			    
			
			   system("pause");
               system("cls");	
			   goto up;		
				
				break;
				
				case 4:
					system("cls");
				
					B.update();
					
					system("pause");
				
					system("cls");
					goto up;
					break;
			    
			    case 5:
			    	system("cls");
					B.Delete();
					
			    	system("pause");
					system("cls");
			    	goto up;
					break;
			    	
			    case 6:
			  	
				  system("cls");
			goto fullup;break;

			
				
				default: 
				
				cout<<"Wrong Choice Enter Once More!!!!!\n\n";
				system("pause");
			  goto up;
			  
			       break;
			}
			
		
	}
		break;
		case 2:
		Up:
		
		system("cls");
      cout<<"\t\t\t\t\t_______________________________________________\n";
    
	  cout<<"\n\t\t\t\t\t\t  NOTES DETAILS\n";
	
	  cout<<"\t\t\t\t\t________________________________________________\n\n\n";
	
	  cout<<"\t\t\t\t\t\t1___________________Add Notes\n\n";
	
	  cout<<"\t\t\t\t\t\t2___________________View/list Notes\n\n";
	
	  cout<<"\t\t\t\t\t\t3___________________Search Notes\n\n";
	
	  cout<<"\t\t\t\t\t\t4___________________Main Menu\n\n";
	
	  cout<<"\t\t\t\tEnter Your Choice-->";


	cin>>*p;

	switch(*p)
	
	{

		
				case 1:
					
			        start2:
							system("cls");
					
					cout<<"Enter Notes Details:"<<endl;
			        
					cout<<"---------------------";
			        
						N.input();
			          system("cls");
			
			         	
			cout<<"You want to Enter More Record or Not (y/n):";
			cin>>more;
			if(more=='y'||more=='Y')
			{
				goto start2;
			}
			else
			{
				goto Up;
			}
			break;
				
			
				case 2:
				
				system("cls");
			    
				int ch;
				while(true){
				
				
				cout<<"\t\t\t\t\t\t1___________________Display Notes Record\n\n";

				
				cin>>ch;
				
				switch(ch)
				
				{
										case 1:		
											
												N.display();
												system("pause");
												
												system("cls");
											goto Up;
												break;

										default:cout<<"Plz input Valid input:";
											goto up;
											      break;
											
								}
					system("pause");
					break;
			
				case 3 : 
				
				system("cls");
				
				
				
			    N.SearchN();
			    
			
			   system("pause");
               system("cls");
			   goto Up;			
				
				break;
		case 4:
			system("cls");
			goto fullup;break;
			}
			break;
	
	
	}
break;
case 3:
	up1:
	
    system("cls");
      cout<<"\t\t\t\t\t_______________________________________________\n";
    
	  cout<<"\n\t\t\t\t\t\t  APPOINTMENTS\n";
	
	  cout<<"\t\t\t\t\t________________________________________________\n\n\n";
	
	  cout<<"\t\t\t\t\t\t1___________________Add Apointment\n\n";
	
	  cout<<"\t\t\t\t\t\t2___________________View Record\n\n";
	
	  cout<<"\t\t\t\t\t\t3___________________Main Menu\n\n";
	
	  cout<<"\t\t\t\tEnter Your Choice-->";


	cin>>*p;

	switch(*p)
	
	{

		
				case 1:
					
			        start3:
							system("cls");
					
					cout<<"Enter Appointments Detail:"<<endl;
			        
					cout<<"---------------------"<<endl;
			        
						AP.input();
			          system("cls");
			
			         	
			cout<<"You want to Enter More Record or Not (y/n):";
			cin>>more;
			if(more=='y'||more=='Y')
			{
				goto start3;
			}
			else
			{
				goto up1;
			}
			break;
				
			
				case 2:
				
				system("cls");
			    
				int ch;
				while(true){
				
				
				cout<<"\t\t\t\t\t\t1___________________Display Appointments Record\n\n";

				
				cin>>ch;
				
				switch(ch)
				
				{
										case 1:			
								
											
												AP.display();
												system("pause");
												
												system("cls");
											goto up1;
												break;

										default:cout<<"Plz input Valid input:";
											goto up1;
											      break;
											
								}
					system("pause");
					break;
			    	
			    case 3:
			  	
				  system("cls");
			goto fullup;break;

			
				
				default: 
				
				cout<<"Wrong Choice Enter Once More!!!!!\n\n";
				system("pause");
			  goto up1;
			  
			       break;
			}
			
		
	}
		break;
	
	
	

case 4:

	up3:
	
    system("cls");
      cout<<"\t\t\t\t\t_______________________________________________\n";
    
	  cout<<"\n\t\t\t\t\t\t  ALARMS & REMINDER\n";
	
	  cout<<"\t\t\t\t\t________________________________________________\n\n\n";
	
	  cout<<"\t\t\t\t\t\t1___________________Set Alarm&Reminder\n\n";
	
	  cout<<"\t\t\t\t\t\t2___________________View\n\n";

	
	  cout<<"\t\t\t\t\t\t3___________________Main Menu\n\n";
	
	  cout<<"\t\t\t\tEnter Your Choice-->";


	cin>>*p;

	switch(*p)
	
	{

		
				case 1:
					
			        start5:
							system("cls");
					
					cout<<"Enter ALARMS & REMINDER Detail:"<<endl;
			        
					cout<<"---------------------";
			        
						AR.input();
			          system("cls");
			
			         	
			cout<<"You want to Enter More Record or Not (y/n):";
			cin>>more;
			if(more=='y'||more=='Y')
			{
				goto start5;
			}
			else
			{
				goto up3;
			}
			break;
				
			
				case 2:
				
				system("cls");
			    
				int ch;
				while(true){
				
				
				cout<<"\t\t\t\t\t\t1___________________Display Alarms & Reminder Record\n\n";

				
				cin>>ch;
				
				switch(ch)
				
				{
					case 1:
			system("cls");
											
												AR.display();
												system("pause");
												
												system("cls");
											goto up3;
												break;

										default:cout<<"Plz input Valid input:";
											goto up3;
											      break;
											
								}
					system("pause");
					break;
			    	
			    case 3:
			  	
				  system("cls");
			goto fullup;break;

			
				
				default: 
				
				cout<<"Wrong Choice Enter Once More!!!!!\n\n";
				system("pause");
			  goto up3;
			  
			       break;
			}
			
		
	}
		break;



break;
case 5:

	up5:
	
    system("cls");
      cout<<"\t\t\t\t\t_______________________________________________\n";
    
	  cout<<"\n\t\t\t\t\t\t  TASKS\n";
	
	  cout<<"\t\t\t\t\t________________________________________________\n\n\n";

	  cout<<"\t\t\t\t\t\t1___________________View Backup\n\n";
	
	
	  cout<<"\t\t\t\t\t\t2___________________Main Menu\n\n";
	
	  cout<<"\t\t\t\tEnter Your Choice-->";


	cin>>*p;

	switch(*p)
	
	{

		
				case 1:
						                  B.display();
												system("pause");
												
												system("cls");
											goto up5;
												break;
	
			    case 2:
			  	
				  system("cls");
			goto fullup;break;

			
				
				default: 
				
				cout<<"Wrong Choice Enter Once More!!!!!\n\n";
				system("pause");
			  goto up5;
			  
			       break;
			}
			
		
	
		break;
	

case 6:

	up7:
	
    system("cls");
      cout<<"\t\t\t\t\t_______________________________________________\n";
    
	  cout<<"\n\t\t\t\t\t\t  CALENDER\n";
	
	  cout<<"\t\t\t\t\t________________________________________________\n\n\n";
	
	  cout<<"\t\t\t\t\t\t1___________________View Calender\n\n";
	
	  cout<<"\t\t\t\t\t\t2___________________Main Menu\n\n";
	
	  cout<<"\t\t\t\tEnter Your Choice-->";


	cin>>*p;

	switch(*p)
	
	{

		                       
				                         case 1:
										 system("cls");
										 B.displayCalender();
												system("pause");
												
												system("cls");
											goto up7;
												break;
					
		    	
			    case 2:
			  	
				  system("cls");
			goto fullup;break;

			
				
				default: 
				
				cout<<"Wrong Choice Enter Once More!!!!!\n\n";
				system("pause");
			  goto up7;
			  
			       break;
			}
			
		
	
		break;
case 7:
	up8:
	
    system("cls");
      cout<<"\t\t\t\t\t_______________________________________________\n";
    
	  cout<<"\n\t\t\t\t\t\t  REPORTS\n";
	
	  cout<<"\t\t\t\t\t________________________________________________\n\n\n";
	
	  cout<<"\t\t\t\t\t\t1___________________View Contacts Report\n\n";
	
	  cout<<"\t\t\t\t\t\t2___________________View Notes Report\n\n";
	
	  cout<<"\t\t\t\t\t\t3___________________View Appointments Report\n\n";
	  
	  cout<<"\t\t\t\t\t\t4___________________View Alarms&Reminder Report\n\n";
	  
	  cout<<"\t\t\t\t\t\t5___________________View Backup Report\n\n";
	
	
	  cout<<"\t\t\t\t\t\t6___________________Main Menu\n\n";
	
	  cout<<"\t\t\t\tEnter Your Choice-->";


	cin>>*p;

	switch(*p)
	
	{

		
				case 1:
				                         	system("cls");
				                         	cout<<"\t\t\t\t\t_______________________________________________\n";
			                                cout<<"\n\t\t\t\t\t\tContacts Report"<<endl;
			                                cout<<"\t\t\t\t\t_______________________________________________\n\n\n";
													B.display();
													system("pause");
													
													system("cls");
												goto up8;
													break;
				
			
				case 2:
					system("cls");
					cout<<"\t\t\t\t\t_______________________________________________\n";
				    cout<<"\n\t\t\t\t\t\tNotes Report"<<endl;
				    cout<<"\t\t\t\t\t_______________________________________________\n\n\n";
												N.display();
												system("pause");
												
												system("cls");
											goto up8;
												break;
				case 3 : 
				
				system("cls");
				                         	cout<<"\t\t\t\t\t_______________________________________________\n";
			                                cout<<"\n\t\t\t\t\t\tAppointments Report"<<endl;
			                                cout<<"\t\t\t\t\t_______________________________________________\n\n\n";
													AP.display();
													system("pause");
													
													system("cls");
												goto up8;
													break;
				break;
                  case 4:
                  	system("cls");
				                         	cout<<"\t\t\t\t\t_______________________________________________\n";
			                                cout<<"\n\t\t\t\t\t\tAlarms&Reminder Report"<<endl;
			                                cout<<"\t\t\t\t\t_______________________________________________\n\n\n";
													AR.display();
													system("pause");
													
													system("cls");
												goto up8;
													break;
			    	case 5:
			    		system("cls");
				                         	cout<<"\t\t\t\t\t_______________________________________________\n";
			                                cout<<"\n\t\t\t\t\t\tBackup Report"<<endl;
			                                cout<<"\t\t\t\t\t_______________________________________________\n\n\n";
													B.display();
													system("pause");
													
													system("cls");
												goto up8;
													break;
			    case 6:
			  	
				  system("cls");
			goto fullup;break;

			
				
				default: 
				
				cout<<"Wrong Choice Enter Once More!!!!!\n\n";
				system("pause");
			  goto up8;
			  
			       break;
			
			
		
	}
		break;
	
case 8:		exit(0);break;
default:
	cout<<"\n\n\n\t\tplz Enter Valid Choice:";
	system("cls");
	goto fullup;
	system("pause");break;

break;

}

}

}

}



