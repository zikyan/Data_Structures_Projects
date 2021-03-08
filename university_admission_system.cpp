#include<iostream>						// this project has total 10 features, one feature is login screen and remaining are other 9.

#include<fstream>

using namespace std;					

main_screen()
   
   {

		string user,pass;
	 system("COLOR E");
	
	  system("cls"); 			// to create new screen

 cout<<"\t\t---------------------------------------------------"<<endl<<endl;
cout<<"\t\tU N I V E R S I T Y  A D M I S S I O N  S Y S T E M"<<endl<<endl;
 cout<<"\t\t---------------------------------------------------"<<endl<<endl;



	

	while(true)			//so that loop continues to run untill it encounters a break statement
	
	{
		


				cout<<"\t\tEnter Username:";
			
					cin>>user;
					
					cout<<endl<<endl;
			
					cout<<"\t\tEnter Password:";
			
					cin>>pass;
			
			 
	
        

		cout<<"\n\t\t--------------------------------------------------------------------------------------------\n";

				if((user=="lahore" || user=="LAHORE") && (pass=="9999" || pass=="9999"))
					
					{
			
						cout<<" \n\t\tW E L C O M E  T O  U N I V E R S I T Y  A D M I S S I O N  S Y S T E M   P O R T A L"<<endl<<endl<<endl;
			
						system("pause");
			
						break;
			
					}
			
						else
						{
						
			cout<<"\n\t\tWrong Credentials Try Again\n"<<endl;	
			}
			
				}
			
				}
				
class queue			//default queue class
{
	int *data;
	int cap;
	int rear;
	int front;
	int no;
	public:
		queue(int s)
		{
			data=new int[s];
			cap=s;
			rear=0;
			front=0;
			no=0;
		}
		bool isfull()
		{
			if(no==cap)
			return true;
			else
			return false;
		}
		bool isempty()
		{
			if(no==0)
			return true;
			else
			return false;
		}
		enqueue(int item)
		{
			if(isfull())
			cout<<"Already Full"<<endl;
			else
			{
				data[rear++]=item;
				no++;
			}
		}
		int dequeue()
		{
			if(isempty())
			cout<<"Empty"<<endl;
			else
			{
				no--;
				return data[front++];
			}
		}
};

class stack			//default stack class
{
	string *data;
	
	int capacity;
	
	int top;
	
	public:
		stack(int s)
		{
			data=new string[s];
			
			capacity=s;
			
			top=0;
		}
		bool isFuLL()
		{
			if(top==capacity)
			
			return true;
			
			else
			
			return false;
		}
		void push(string d)
		{
			if(isFuLL())
			
			cout<<"Stack is full"<<endl;
			
			else
			
			data[top++]=d;
			
		}
		bool isEmpty()
		{
			if(top==0)
			
			return true;
			
			else
			
			return false;
		}
		string pop()
		{
			if(isEmpty())
			
			cout<<"Stack is empty"<<endl;
			
			else
			
			return data[--top];
		}
		
};				

class AdmissionStack	//using stack

{

private:

	string firstname,lastname,cityname,phonenumber,address,email,flag,degname,note;
	
public:

void add_student();				// defining class functions.


void display_student();

void remove_student();

void modify_student();

void search_student(); 

};

void AdmissionStack::add_student()		//writing functions outside of class using scope resolution operator to make class looks lean.
{
	system("color e");
		system("cls");
				ofstream file("Admission_Details.txt", ios::app); 	//ios::app (appends) means that the file wil continue to operate where you left it otherwise it will create another new file named Admission_Details.txt
			int var=0,var1=0;
			cout<<"Number of students you want to add..? ";			// so that we can make stack.
			cin>>var;
			var1=var*8;			// multiplying by 8 because we have 8 attributes to enter in the stack so we have to make a stack that has capacity of 8.
			stack reverse(var1);			//because stack is first-in-last-out(FILO), thats why we have used two stack because first stack will give you names in reverse order, to make the order original we have used another stack called original. we will pop the value from first stack called reverse and push it in the second stack called original
		
			string flag;
			for(int i=1;i<=var;i++)		//if there are two students entered by user then loop will run 2 times because var=2;
			{
				cout<<endl;
				cout<<"Enter your first name : ";
				cin>>firstname;
				cout<<"Enter your last name : ";
				cin>>lastname;
				cout<<"Enter your city name : ";
				cin>>cityname;
				cout<<"Enter your phone number : ";
				cin>>phonenumber;
				cout<<"Enter your address : ";
				cin>>address;
				cout<<"Enter your email : ";
				cin>>email;
				cout<<"Enter the name of your degree : ";
				cin>>degname;
				cout<<"Enter your Nationality : ";
				cin>>note;
				reverse.push(note);				//pushing element one-by-one in the stack
				reverse.push(degname);
				reverse.push(email);
				reverse.push(address);
				reverse.push(phonenumber);
				reverse.push(cityname);
				reverse.push(lastname);
				reverse.push(firstname);
			}
			stack original(var1);
			
				for(int i=0;i<var1;i++) 	//loop will run 8 times because var1=8 because a student has 8 attributes that were entered by the user. var1 was multiplied by 8 see above.
				{
					original.push(reverse.pop());		// to keep the order original in the file handling  we have poped the value from stack 1 and pushed it in stack 2.
				}
				
				cout<<endl<<"you want to create backup of Addmission info(yes/no):";
				
				cin>>flag;
				
				if((flag=="yes")||(flag=="YES"))		// is yes, then it will write in the file to create backup otherwise there will be no backup created
				{
					for(int i=0;i<var;i++)
					{
						file<<original.pop()<<"\t"<<original.pop()<<"\t"<<original.pop()<<"\t"<<original.pop()<<"\t"<<original.pop()<<"\t"<<original.pop()<<"\t"<<original.pop()<<"\t"<<original.pop()<<"\t"<<endl;
					}	// popping elements from stack and writing them in the file.
				}
				
				file.close(); 		//closing file
		
}

void AdmissionStack::search_student()
{
		string firstname,lastname,cityname,phonenumber,address,email,degname,note;
		string key;
		cout<<"Enter the Name of the student you want to search the record for : ";
		cin>>key;
		cout<<endl<<endl;
			ifstream file("Admission_Details.txt",ios::in); //ios::in means that we are reading a file
			while(file>>firstname>>lastname>>cityname>>phonenumber>>address>>email>>degname>>note)		// loop will continue to run untill there is no element present in the file from where we are reading. >> this operator is used to read from the file and << is used to write in the file.
			{
				if(key==firstname)
				{
					cout<<firstname<<"\t"<<lastname<<"\t"<<cityname<<"\t"<<phonenumber<<"\t"<<address<<"\t"<<email<<"\t"<<degname<<"\t"<<note<<endl;
				}
			}
			file.close();
}

void AdmissionStack::display_student()
{
			string firstname,lastname,cityname,phonenumber,address,email,degname,note;
			
			ifstream file("Admission_Details.txt",ios::in);
			if (!file)
			cout<<"File is not present or deleted"<<endl;
			while(file>>firstname>>lastname>>cityname>>phonenumber>>address>>email>>degname>>note)
			{
				cout<<firstname<<endl<<lastname<<endl<<cityname<<endl<<phonenumber<<endl<<address<<endl<<email<<endl<<degname<<endl<<note<<endl<<endl;
			}
			
			file.close();
}

void AdmissionStack::remove_student()
{
			ifstream file("Admission_Details.txt",ios::app);
			
			ofstream writefile("temp.txt",ios::app);
			
			
		string firstname,lastname,cityname,phonenumber,address,email,degname,note;
		
		string name;
		
		cout<<"Enter the Name of the student you want to remove the record for : ";
		
		cin>>name;
		
		cout<<endl<<endl;
			
			while(file>>firstname>>lastname>>cityname>>phonenumber>>address>>email>>degname>>note)
			{
				if(name.compare(firstname)==0)		// another way of comparing, instead of name==firstname
				{
					continue;		//if condition gets true it will skip that current iteration of the loop because we dont want to add that name in which the condition gets true. in this way it will remove that perticular name that we wanted to remove.
				}
				writefile<<firstname<<"\t"<<lastname<<"\t"<<cityname<<"\t"<<phonenumber<<"\t"<<address<<"\t"<<email<<"\t"<<degname<<"\t"<<note<<endl;
				cout<<endl;
			}
			
				cout<<"Data has been deleted !!!";
				
				
		
		
						file.close();
					
					    writefile.close();    
					
					   remove("Admission_Details.txt"); 	//removeing previouse file that has the name that we wanted to remove
					
					   rename("temp.txt","Admission_Details.txt");		// making a new file in which that name has been removed that we wanted to remove and then renaming the file on the previouse name.
}


void AdmissionStack::modify_student()
{
			ifstream file("Admission_Details.txt",ios::app);
			
			ofstream writefile("temp.txt",ios::app);
			
			
		string firstname,lastname,cityname,phonenumber,address,email,degname,note;
		
		string name;
		
		cout<<"Enter the Name of the student you want to modify the record for : ";
		
		cin>>name;
		
		cout<<endl<<endl;
			
			while(file>>firstname>>lastname>>cityname>>phonenumber>>address>>email>>degname>>note)
			{
				if(name.compare(firstname)==0)
				{
					cout<<endl;
					cout<<"Enter your first name : ";
					cin>>firstname;
					cout<<"Enter your last name : ";
					cin>>lastname;
					cout<<"Enter your city name : ";
					cin>>cityname;
					cout<<"Enter your phone number : ";
					cin>>phonenumber;
					cout<<"Enter your address : ";
					cin>>address;
					cout<<"Enter your email : ";
					cin>>email;
					cout<<"Enter the name of your degree : ";
					cin>>degname;
					cout<<"Enter your Nationality : ";
					cin>>note;
					writefile<<firstname<<"\t"<<lastname<<"\t"<<cityname<<"\t"<<phonenumber<<"\t"<<address<<"\t"<<email<<"\t"<<degname<<"\t"<<note<<endl;
					continue;
				}
				
				writefile<<firstname<<"\t"<<lastname<<"\t"<<cityname<<"\t"<<phonenumber<<"\t"<<address<<"\t"<<email<<"\t"<<degname<<"\t"<<note<<endl;
				
				
				cout<<endl;
			}
			
				cout<<"Data has been modified !!!";
				
				
		
		
						file.close();
					
					    writefile.close();    
					
					   remove("Admission_Details.txt");
					
					   rename("temp.txt","Admission_Details.txt");
}


class DegreeQueue		// using queue
{
			int id,age,metric,fsc,fee;
			float floatfee;
			string name,college;
	public:
		
		void add();
		
};

void DegreeQueue::add()
{
	system("color e");
		system("cls");
			ofstream file("Academic_Details.txt", ios::app);
			int var=0,var1=0;
			cout<<"Number of students you want to add..? ";		//so that we can create a queue
			cin>>var;
			var1=var*5;		//multiplying by 5 just like what we did in stack, because every student has 5 attributes and that will store one by one in the queue.
			queue original(var1);		//there is no need to make the order original in queue because queue is first-in-fisrt-out (FIFO) so, the order is already in the original form
			string flag;		// all the remaing functionality of queue is the exact same as stack, if you understand the stack, queue is same.
			for(int i=1;i<=var;i++)
			{
				cout<<endl;
				cout<<"Enter your unique id : ";
				cin>>id;
				cout<<"Enter your age : ";
				cin>>age;
				cout<<"Enter your Metric : ";
				cin>>metric;
				cout<<"Enter your FSC marks : ";
				cin>>fsc;
				cout<<"Enter semester fee you can afford choose from (1-4)lakh : ";
				cin>>fee;
				floatfee=fee;
				original.enqueue(fee);			//just like stack, we are enqueueing elements in the queue. enqueue is just like push. just names are different.
				original.enqueue(fsc);
				original.enqueue(metric);
				original.enqueue(age);
				original.enqueue(id);
				
				cout<<endl<<"you want to create backup of your Academic info(yes/no):";
				
				cin>>flag;
				
				if((flag=="yes")||(flag=="YES"))
				{
						file<<"ID:"<<original.dequeue()<<"\t"<<"Age:"<<original.dequeue()<<"\t"<<"Metric:"<<original.dequeue()<<"\t"<<"FSC:"<<original.dequeue()<<"\t"<<"Fee:"<<original.dequeue()<<endl;
						file<<"______________________________________________"<<endl; 		//dequeueing elements from the queue and writing elements in the file.
				}
				
				cout<<endl<<"After Analyzing your entered marks and fee you can choose the following degrees"<<endl<<endl;
				if((fsc>=0 && fsc<=600) && (floatfee>=1))
				{
					cout<<"Bachelor of Computer Engineering [BSCE]"<<endl;
					cout<<"Bachelor of  Environmental Sciences [BSES]"<<endl;
					cout<<"Bachelor of  Economics Honors [BSEH]"<<endl;
					cout<<"Bachelor of  LAW [LLB]"<<endl;
				}
				
				else if((fsc>=0 && fsc<=700) && (fee<=2))
				{
					cout<<"Bachelor of Software Engineering [BSSE]"<<endl;
					cout<<"Bachelor of Civil Engineering [BSCE]"<<endl;
					cout<<"Bachelor of Power and Energy System [BSPE]"<<endl;
					cout<<"Bachelor of Power and Energy System [BSPE]"<<endl;
				}
				
				else if((fsc>=0 && fsc<=800) && (fee<=3))
				{
					cout<<"Bachelor of Computer Science [BSCS]"<<endl;
					cout<<"Bachelor of Mechanical Science [BSMS]"<<endl;
					cout<<"Bachelor of Chemical Science [BSCS]"<<endl;
					cout<<"Bachelor of Electrical Science [BSES]"<<endl;
				}
				
				else if((fsc>=0 && fsc<=900) && (fee<=4))
				{
					cout<<"Bachelors of Medical Science [MBBS]"<<endl;
					cout<<"Doctor of Physical Therapy [DPT]"<<endl;
					cout<<"Doctor of Dental Surgery [DDS]"<<endl;
				}
				
				
			}
				file.close();
		
}


struct node
{
	string name,station,route,Tinfo1,Tinfo2,Tinfo3,Hinfo1,Hinfo2,Hinfo3;
	string Finfo1,Finfo2,Finfo3,Finfo4,Finfo5,Finfo6,Finfo7,Finfo8,Finfo9;
	node *link;
};


class HostelLinkedList			//using Linked List
{
	node *head;
	public:
		ContactLinkList()		//deafult constructor
		{
			head=NULL;
		}
		void add();
		
};


class FeeLinkedList
{
	node *head;
	public:
		feeLinkedList()
		{
			head=NULL;
		}
		void add();
};

void FeeLinkedList::add()
{
	string name,info1,info2,info3,info4,info5,info6,info7,info8,info9;
	int choose;
			node *temp=new node;
			ofstream file("Fee_Voucher.txt", ios::app);
			string status;
			cout<<"Enter Your Name : ";
			cin>>name;
			temp->name=name;
			cout<<endl<<"Select your Degree : "<<endl<<endl;
			cout<<"1_______BSCS"<<endl;
	        cout<<"2_______BSSE"<<endl;
	        cout<<"3_______BSCE"<<endl;
	        cout<<"4_______LLB"<<endl;
	        cout<<"5_______EE"<<endl;
	        cout<<"6_______MBBS"<<endl;
	        cout<<"7_______DPT"<<endl<<endl;
	        cout<<"Enter your Choice : ";
			cin>>choose;
			cout<<endl;
			temp->link=NULL;			//so that the last node has NULL in it instead of garbage value
			if(choose==1)
			{
					cout<<"University of Lahore"<<endl;
					info1="Fees per Year";
					temp->Finfo1=info1;		//string values in the info of the linkedlist
	                info2="Tution Fees= 1,00,000";
	                temp->Finfo2=info2;
	                info3="College University Fees = 35,000";
	                temp->Finfo3=info3;
	                info4="University Eligibility Fees = 1,500";
	                temp->Finfo4=info4;
	                info5="Hostel Fees";
	                temp->Finfo5=info5;
	                info6="Caution Deposit = 15,000";
	                temp->Finfo6=info6;
	                info7="Room Rent/Electricity Charges = 48,000";
	                temp->Finfo7=info7;
	                info8="Total Hostel Fees";
	                temp->Finfo8=info8;
	                info9="Hostel Mess Charges = 1800/- per month";
	                temp->Finfo9=info9;
	                cout<<info1<<endl;
					cout<<info2<<endl;
					cout<<info3<<endl;
					cout<<info4<<endl;
					cout<<info5<<endl;
					cout<<info6<<endl;
					cout<<info7<<endl;
					cout<<info8<<endl;
					cout<<info9<<endl;
					
				cout<<endl<<"you want to create backup of your Fee Voucher Info(yes/no):";
						cin>>status;
						if(status=="yes"||status=="YES")
							file<<temp->name<<"\t"<<temp->Finfo1<<"\t"<<temp->Finfo2<<"\t"<<temp->Finfo3<<"\t"<<temp->Finfo4<<"\t"<<temp->Finfo5<<"\t"<<temp->Finfo6<<"\t"<<temp->Finfo7<<"\t"<<temp->Finfo8<<"\t"<<temp->Finfo9<<endl;
			}					//writing in the file by accessing data from the linked list
			else if(choose==2)
			{
				cout<<"University of Lahore"<<endl;
					info1="Fees per Year";
					temp->Finfo1=info1;
	                info2="Tution Fees= 1,20,000";
	                temp->Finfo2=info2;
	                info3="College University Fees = 25,000";
	                temp->Finfo3=info3;
	                info4="University Eligibility Fees = 2,500";
	                temp->Finfo4=info4;
	                info5="Hostel Fees";
	                temp->Finfo5=info5;
	                info6="Caution Deposit = 11,000";
	                temp->Finfo6=info6;
	                info7="Room Rent/Electricity Charges = 20,000";
	                temp->Finfo7=info7;
	                info8="Total Hostel Fees";
	                temp->Finfo8=info8;
	                info9="Hostel Mess Charges = 2800/- per month";
	                temp->Finfo9=info9;
	                cout<<info1<<endl;
					cout<<info2<<endl;
					cout<<info3<<endl;
					cout<<info4<<endl;
					cout<<info5<<endl;
					cout<<info6<<endl;
					cout<<info7<<endl;
					cout<<info8<<endl;
					cout<<info9<<endl;
					
				cout<<endl<<"you want to create backup of your Fee Voucher Info(yes/no):";
						cin>>status;
						if(status=="yes"||status=="YES")
							file<<temp->name<<"\t"<<temp->Finfo1<<"\t"<<temp->Finfo2<<"\t"<<temp->Finfo3<<"\t"<<temp->Finfo4<<"\t"<<temp->Finfo5<<"\t"<<temp->Finfo6<<"\t"<<temp->Finfo7<<"\t"<<temp->Finfo8<<"\t"<<temp->Finfo9<<endl;
			}
			else if(choose==3)
			{
				cout<<"University of Lahore"<<endl;
					info1="Fees per Year";
					temp->Finfo1=info1;
	                info2="Tution Fees= 1,30,000";
	                temp->Finfo2=info2;
	                info3="College University Fees = 45,000";
	                temp->Finfo3=info3;
	                info4="University Eligibility Fees = 3,500";
	                temp->Finfo4=info4;
	                info5="Hostel Fees";
	                temp->Finfo5=info5;
	                info6="Caution Deposit = 35,000";
	                temp->Finfo6=info6;
	                info7="Room Rent/Electricity Charges = 25,000";
	                temp->Finfo7=info7;
	                info8="Total Hostel Fees";
	                temp->Finfo8=info8;
	                info9="Hostel Mess Charges = 2200/- per month";
	                temp->Finfo9=info9;
	                cout<<info1<<endl;
					cout<<info2<<endl;
					cout<<info3<<endl;
					cout<<info4<<endl;
					cout<<info5<<endl;
					cout<<info6<<endl;
					cout<<info7<<endl;
					cout<<info8<<endl;
					cout<<info9<<endl;
					
				cout<<endl<<"you want to create backup of your Fee Voucher Info(yes/no):";
						cin>>status;
						if(status=="yes"||status=="YES")
							file<<temp->name<<"\t"<<temp->Finfo1<<"\t"<<temp->Finfo2<<"\t"<<temp->Finfo3<<"\t"<<temp->Finfo4<<"\t"<<temp->Finfo5<<"\t"<<temp->Finfo6<<"\t"<<temp->Finfo7<<"\t"<<temp->Finfo8<<"\t"<<temp->Finfo9<<endl;
			}
			else if(choose==4)
			{
				cout<<"University of Lahore"<<endl;
					info1="Fees per Year";
					temp->Finfo1=info1;
	                info2="Tution Fees= 1,30,000";
	                temp->Finfo2=info2;
	                info3="College University Fees = 33,000";
	                temp->Finfo3=info3;
	                info4="University Eligibility Fees = 7,500";
	                temp->Finfo4=info4;
	                info5="Hostel Fees";
	                temp->Finfo5=info5;
	                info6="Caution Deposit = 25,000";
	                temp->Finfo6=info6;
	                info7="Room Rent/Electricity Charges = 7,000";
	                temp->Finfo7=info7;
	                info8="Total Hostel Fees";
	                temp->Finfo8=info8;
	                info9="Hostel Mess Charges = 6600/- per month";
	                temp->Finfo9=info9;
	                cout<<info1<<endl;
					cout<<info2<<endl;
					cout<<info3<<endl;
					cout<<info4<<endl;
					cout<<info5<<endl;
					cout<<info6<<endl;
					cout<<info7<<endl;
					cout<<info8<<endl;
					cout<<info9<<endl;
					
				cout<<endl<<"you want to create backup of your Fee Voucher Info(yes/no):";
						cin>>status;
						if(status=="yes"||status=="YES")
							file<<temp->name<<"\t"<<temp->Finfo1<<"\t"<<temp->Finfo2<<"\t"<<temp->Finfo3<<"\t"<<temp->Finfo4<<"\t"<<temp->Finfo5<<"\t"<<temp->Finfo6<<"\t"<<temp->Finfo7<<"\t"<<temp->Finfo8<<"\t"<<temp->Finfo9<<endl;
			}
			else if(choose==5)
			{
				cout<<"University of Lahore"<<endl;
					info1="Fees per Year";
					temp->Finfo1=info1;
	                info2="Tution Fees= 1,40,000";
	                temp->Finfo2=info2;
	                info3="College University Fees = 45,000";
	                temp->Finfo3=info3;
	                info4="University Eligibility Fees = 4,500";
	                temp->Finfo4=info4;
	                info5="Hostel Fees";
	                temp->Finfo5=info5;
	                info6="Caution Deposit = 11,000";
	                temp->Finfo6=info6;
	                info7="Room Rent/Electricity Charges = 12,000";
	                temp->Finfo7=info7;
	                info8="Total Hostel Fees";
	                temp->Finfo8=info8;
	                info9="Hostel Mess Charges = 4400/- per month";
	                temp->Finfo9=info9;
	                cout<<info1<<endl;
					cout<<info2<<endl;
					cout<<info3<<endl;
					cout<<info4<<endl;
					cout<<info5<<endl;
					cout<<info6<<endl;
					cout<<info7<<endl;
					cout<<info8<<endl;
					cout<<info9<<endl;
					
				cout<<endl<<"you want to create backup of your Fee Voucher Info(yes/no):";
						cin>>status;
						if(status=="yes"||status=="YES")
							file<<temp->name<<"\t"<<temp->Finfo1<<"\t"<<temp->Finfo2<<"\t"<<temp->Finfo3<<"\t"<<temp->Finfo4<<"\t"<<temp->Finfo5<<"\t"<<temp->Finfo6<<"\t"<<temp->Finfo7<<"\t"<<temp->Finfo8<<"\t"<<temp->Finfo9<<endl;
			}
			else if(choose==6)
			{
				cout<<"University of Lahore"<<endl;
					info1="Fees per Year";
					temp->Finfo1=info1;
	                info2="Tution Fees= 1,10,000";
	                temp->Finfo2=info2;
	                info3="College University Fees = 15,000";
	                temp->Finfo3=info3;
	                info4="University Eligibility Fees = 1,100";
	                temp->Finfo4=info4;
	                info5="Hostel Fees";
	                temp->Finfo5=info5;
	                info6="Caution Deposit = 11,000";
	                temp->Finfo6=info6;
	                info7="Room Rent/Electricity Charges = 11,000";
	                temp->Finfo7=info7;
	                info8="Total Hostel Fees";
	                temp->Finfo8=info8;
	                info9="Hostel Mess Charges = 1200/- per month";
	                temp->Finfo9=info9;
	                cout<<info1<<endl;
					cout<<info2<<endl;
					cout<<info3<<endl;
					cout<<info4<<endl;
					cout<<info5<<endl;
					cout<<info6<<endl;
					cout<<info7<<endl;
					cout<<info8<<endl;
					cout<<info9<<endl;
					
				cout<<endl<<"you want to create backup of your Fee Voucher Info(yes/no):";
						cin>>status;
						if(status=="yes"||status=="YES")
							file<<temp->name<<"\t"<<temp->Finfo1<<"\t"<<temp->Finfo2<<"\t"<<temp->Finfo3<<"\t"<<temp->Finfo4<<"\t"<<temp->Finfo5<<"\t"<<temp->Finfo6<<"\t"<<temp->Finfo7<<"\t"<<temp->Finfo8<<"\t"<<temp->Finfo9<<endl;
			}
			else if(choose==7)
			{
				cout<<"University of Lahore"<<endl;
					info1="Fees per Year";
					temp->Finfo1=info1;
	                info2="Tution Fees= 1,70,000";
	                temp->Finfo2=info2;
	                info3="College University Fees = 75,000";
	                temp->Finfo3=info3;
	                info4="University Eligibility Fees = 7,500";
	                temp->Finfo4=info4;
	                info5="Hostel Fees";
	                temp->Finfo5=info5;
	                info6="Caution Deposit = 7,000";
	                temp->Finfo6=info6;
	                info7="Room Rent/Electricity Charges = 7,000";
	                temp->Finfo7=info7;
	                info8="Total Hostel Fees";
	                temp->Finfo8=info8;
	                info9="Hostel Mess Charges = 7700/- per month";
	                temp->Finfo9=info9;
	                cout<<info1<<endl;
					cout<<info2<<endl;
					cout<<info3<<endl;
					cout<<info4<<endl;
					cout<<info5<<endl;
					cout<<info6<<endl;
					cout<<info7<<endl;
					cout<<info8<<endl;
					cout<<info9<<endl;
					
				cout<<endl<<"you want to create backup of your Fee Voucher Info(yes/no):";
						cin>>status;
						if(status=="yes"||status=="YES")
							file<<temp->name<<"\t"<<temp->Finfo1<<"\t"<<temp->Finfo2<<"\t"<<temp->Finfo3<<"\t"<<temp->Finfo4<<"\t"<<temp->Finfo5<<"\t"<<temp->Finfo6<<"\t"<<temp->Finfo7<<"\t"<<temp->Finfo8<<"\t"<<temp->Finfo9<<endl;
			}
			if(head==NULL)
			{
				head=temp;
			}
}

class TransportLinkedList
{
	node *head;
	string name,station,info1,info2,info3;
	int route;
	public:
		TransportLinkedList()
		{
			head=NULL;
		}
		void add();
};

void TransportLinkedList::add()
{
			int choice;
			node *temp=new node;
			ofstream file("Transport_Dues.txt", ios::app);
			string status;
			cout<<"Enter Your Name : ";
			cin>>name;
			temp->name=name;
			cout<<"Where are you from your Station (city name): ";
			cin>>station;
			temp->station=station;
			cout<<endl<<"Choose Your Desired route : "<<endl<<endl;
			cout<<"1_______University of Lahore to Shiekhupura"<<endl;
	        cout<<"2_______University of Lahore to Defence"<<endl;
	        cout<<"3_______University of Lahore to Samnabad"<<endl;
	        cout<<"4_______University of Lahore to Thokar"<<endl;
	        cout<<"5_______University of Lahore to Sadar"<<endl;
	        cout<<"6_______University of Lahore to Mall Road"<<endl;
	        cout<<"7_______University of Lahore to Liberty"<<endl<<endl;
	        cout<<"Enter your Choice : ";
			cin>>route;
			cout<<endl;
			temp->route=route;
			temp->link=NULL;
			if(route==1)
			{
				string info1,info2,info3;
				info1="Fee per semester : 17000 per student";
				temp->Tinfo1=info1;
				info2="Bus Type : Coster";
				temp->Tinfo2=info2;
				info3="Bus Capacity : 60 students";
				temp->Tinfo3=info3;
				cout<<info1<<endl;
				cout<<info2<<endl;
				cout<<info3<<endl;
				cout<<endl<<"you want to create backup of your Transportation Info(yes/no):";
						cin>>status;
						if(status=="yes"||status=="YES")
							file<<temp->name<<"\t"<<temp->station<<"\t"<<temp->Tinfo1<<"\t"<<temp->Tinfo2<<"\t"<<temp->Tinfo3<<"\t"<<endl;
			}
			else if(route==2)
			{
				string info1,info2,info3;
				info1="Fee per semester : 13000 per student";
				temp->Tinfo1=info1;
				info2="Bus Type : Toyota Hiace";
				temp->Tinfo2=info2;
				info3="Bus Capacity : 20 students";
				temp->Tinfo3=info3;
				cout<<info1<<endl;
				cout<<info2<<endl;
				cout<<info3<<endl;
				cout<<endl<<"you want to create backup of your Transportation Info(yes/no):";
						cin>>status;
						if(status=="yes"||status=="YES")
							file<<temp->name<<"\t"<<temp->station<<"\t"<<temp->Tinfo1<<"\t"<<temp->Tinfo2<<"\t"<<temp->Tinfo3<<"\t"<<endl;
			}
			else if(route==3)
			{
				string info1,info2,info3;
				info1="Fee per semester : 15000 per student";
				temp->Tinfo1=info1;
				info2="Bus Type : Bus";
				temp->Tinfo2=info2;
				info3="Bus Capacity : 90 students";
				temp->Tinfo3=info3;
				cout<<info1<<endl;
				cout<<info2<<endl;
				cout<<info3<<endl;
				cout<<endl<<"you want to create backup of your Transportation Info(yes/no):";
						cin>>status;
						if(status=="yes"||status=="YES")
							file<<temp->name<<"\t"<<temp->station<<"\t"<<temp->Tinfo1<<"\t"<<temp->Tinfo2<<"\t"<<temp->Tinfo3<<"\t"<<endl;
			}
			else if(route==4)
			{
				string info1,info2,info3;
				info1="Fee per semester : 13000 per student";
				temp->Tinfo1=info1;
				info2="Bus Type : Mini Bus";
				temp->Tinfo2=info2;
				info3="Bus Capacity : 50 students";
				temp->Tinfo3=info3;
				cout<<info1<<endl;
				cout<<info2<<endl;
				cout<<info3<<endl;
				cout<<endl<<"you want to create backup of your Transportation Info(yes/no):";
						cin>>status;
						if(status=="yes"||status=="YES")
							file<<temp->name<<"\t"<<temp->station<<"\t"<<temp->Tinfo1<<"\t"<<temp->Tinfo2<<"\t"<<temp->Tinfo3<<"\t"<<endl;
			}
			else if(route==5)
			{
				string info1,info2,info3;
				info1="Fee per semester : 16000 per student";
				temp->Tinfo1=info1;
				info2="Bus Type : Mini Bus";
				temp->Tinfo2=info2;
				info3="Bus Capacity : 50 students";
				temp->Tinfo3=info3;
				cout<<info1<<endl;
				cout<<info2<<endl;
				cout<<info3<<endl;
				cout<<endl<<"you want to create backup of your Transportation Info(yes/no):";
						cin>>status;
						if(status=="yes"||status=="YES")
							file<<temp->name<<"\t"<<temp->station<<"\t"<<temp->Tinfo1<<"\t"<<temp->Tinfo2<<"\t"<<temp->Tinfo3<<"\t"<<endl;
			}
			else if(route==6)
			{
				string info1,info2,info3;
				info1="Fee per semester : 17000 per student";
				temp->Tinfo1=info1;
				info2="Bus Type : Toyota Hiace";
				temp->Tinfo2=info2;
				info3="Bus Capacity : 20 students";
				temp->Tinfo3=info3;
				cout<<info1<<endl;
				cout<<info2<<endl;
				cout<<info3<<endl;
				cout<<endl<<"you want to create backup of your Transportation Info(yes/no):";
						cin>>status;
						if(status=="yes"||status=="YES")
							file<<temp->name<<"\t"<<temp->station<<"\t"<<temp->Tinfo1<<"\t"<<temp->Tinfo2<<"\t"<<temp->Tinfo3<<"\t"<<endl;
			}
			else if(route==7)
			{
				string info1,info2,info3;
				info1="Fee per semester : 10000 per student";
				temp->Tinfo1=info1;
				info2="Bus Type : Mini Bus";
				temp->Tinfo2=info2;
				info3="Bus Capacity : 40 students";
				temp->Tinfo3=info3;
				cout<<info1<<endl;
				cout<<info2<<endl;
				cout<<info3<<endl;
				cout<<endl<<"you want to create backup of your Transportation Info(yes/no):";
						cin>>status;
						if(status=="yes"||status=="YES")
							file<<temp->name<<"\t"<<temp->station<<"\t"<<temp->Tinfo1<<"\t"<<temp->Tinfo2<<"\t"<<temp->Tinfo3<<"\t"<<endl;
			}
			if(head==NULL)
			{
				head=temp;
			}
			
}


class Aggregate
{
	node *head;
	float metric,fsc,nts;
	float percentage1,percentage2,percentage3,final;
	string status;
	public:
		Aggregate()
		{
			head=NULL;
		}
		void find();
		
};


void Aggregate::find()
{
	ofstream file("Aggregate.txt",ios::app);
	cout<<"Enter your Metric marks : ";
	cin>>metric;
	cout<<"Enter your FSC marks : ";
	cin>>fsc;
	cout<<"Enter your (NTS/other entry test) marks : ";
	cin>>nts;
	percentage1=(((metric/1050)*1100)*0.10);			// aggregate finding formulas.
	percentage2=((fsc/1100)*1100)*0.40;
	percentage3=((nts/1100)*1100)*0.50;
	final=percentage1+percentage2+percentage3;
	final=(final/1100)*100;
	cout<<endl;
	cout<<"Your Aggregate is : "<<final<<endl;
	
	cout<<endl<<"you want to create backup of your Aggregate Info(yes/no):";
						cin>>status;
						if(status=="yes"||status=="YES")
							file<<"Metric:"<<metric<<"\t"<<"FSC:"<<fsc<<"\t\t"<<"NTS:"<<nts<<"\t\t"<<"Aggregate:"<<final<<endl;
}


int main()
{
	main_screen();
	system("cls");
	
	
	// creating objects of class we have made above
	
	AdmissionStack admin;
	DegreeQueue uni;
	TransportLinkedList trans;
	FeeLinkedList fee;
	Aggregate per;
	int choice;
	
	while(true)
    	{
		label1:		// a goto statement label to jump on this line number
    	 system("color E");
    	 cout<<"\t\t---------------------------------------------------"<<endl<<endl;
		 cout<<"\t\tU N I V E R S I T Y  A D M I S S I O N  S Y S T E M"<<endl<<endl;
 		 cout<<"\t\t---------------------------------------------------"<<endl<<endl;
	
	  cout<<"\t\t1.ADD STUDENT'S' GENERAL RECORDS\n\n";
	
	  cout<<"\t\t2.DISPLAY STUDENT RECORDS\n\n";
	
	  cout<<"\t\t3.SEARCH A RECORD\n\n";
	
	  cout<<"\t\t4.REMOVE A RECORD\n\n";
	
	  cout<<"\t\t5.MODIFY A RECORD\n\n";
	
	  cout<<"\t\t6.ENTER ACADEMIC RESULTS & GET YOUR DEGREE NAME\n\n";
	  
	  cout<<"\t\t7.VEE VOUCHER\n\n";
	  
	  cout<<"\t\t8.GET TRANSPORT DUES\n\n";
	  
	  cout<<"\t\t9.FIND YOUR AGGREGATE PERCENTAGE\n\n";
	  
	  cout<<"\t\t10.EXIT\n\n";
	
	  cout<<"\t\tEnter Your Option...";
	  cin>>choice;
	  switch(choice)
	  {
	  	case 1:
	  		
	  		
	  		system("cls");				// for a new screen
					admin.add_student();
					system("pause");		//to pause the newly created screen
					system("cls");
					goto label1;
				break;
				
				
		case 2:
			
			
			system("cls");
					admin.display_student();
					system("pause");
					system("cls");
					goto label1;
				break;
				
		case 3:
			
			
				system("cls");
					admin.search_student();
					cout<<endl<<endl;
					system("pause");
					system("cls");
					goto label1;
				break;
				
		case 4:
		
				system("cls");
					admin.remove_student();
					cout<<endl<<endl;
					system("pause");
					system("cls");
					goto label1;
				break;
				
		case 5:
				system("cls");
					admin.modify_student();
					cout<<endl<<endl;
					system("pause");
					system("cls");
					goto label1;
				break;
				
		case 6:
				system("cls");
					uni.add();
					cout<<endl<<endl;
					system("pause");
					system("cls");
					goto label1;
				break;
				
		case 7:
		
				system("cls");
					fee.add();
					cout<<endl<<endl;
					system("pause");
					system("cls");
					goto label1;
				break;
				
		case 8:
				system("cls");
					trans.add();
					cout<<endl<<endl;
					system("pause");
					system("cls");
					goto label1;
				break;
				
		case 9:
				system("cls");
					per.find();
					cout<<endl<<endl;
					system("pause");
					system("cls");
					goto label1;
				break;
				
		default:
				
				cout<<"Wrong Choice Enter Again...";
				system("cls");
				goto label1;
				system("pause");		
				break;		
				
						
	  }
break;	//while loop break to break the loop.
}
return 0;
}

