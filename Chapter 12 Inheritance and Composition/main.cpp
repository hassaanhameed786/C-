#include "extPersonType.h"
#include "dataType.h"
#include "addressType.h"
#include<fstream>

char displayMenu();
void readFromFile();
void writeToFile();
void sort();

class arrayListType
{
	extPersonType *arrayList;
	int size;
 public:
	 arrayListType(int n=500);
	 extPersonType & operator[](int i);
	 void removeLast();// remove last element
	 void add (const extPersonType &);// add new element
	 int getSize()const;// get arrayList size
 };

 arrayListType::arrayListType(int n)
 {
	arrayList=new extPersonType[n];
	size=n;
 }
 int arrayListType::getSize()const
 {
	return size;
 }
 void arrayListType::removeLast()
 {
	size--;
 }
 void arrayListType::add(const extPersonType &p)
 {
	arrayList[size++]=p;
 }
 extPersonType & arrayListType::operator[](int i)
 {
	return arrayList[i];
 }

 class addressBookType :public arrayListType 
{
 private:
	 extPersonType persons;
 public:
	
	void print(int i);// print personal data of [i] person
 };
 
 void addressBookType::print(int i)
 {
	 persons.printPersonDetails();
 }
 
 
int count=0;
addressBookType addressbook;
int main()
{
	bool flag=true;
	char ch;
	readFromFile();
	do
	{
		ch=displayMenu();
		switch(ch)
		{
		case '1':
			{
				string firstName;
				string lastName;
				string StreetAddress;
				string City;
				string State;
				string Zip;
				string phone;
				int month, day, year;
				int Type;
				cout<<"Enter first name: ";
				cin>>firstName;
				cout<<"Enter last name: ";
				cin>>lastName;
				cin.ignore();
				cout<<"Enter street addess: ";
				getline(cin,StreetAddress);
				
				cout<<"Enter city: ";
				cin>>City;
				cout<<"Enter State: ";
				cin>>State;
				cout<<"Enter Zip: ";
				cin>>Zip;
				cout<<"Enter date of birth: "<<endl;
				cout<<"Enter month: ";
				cin>>month;
				cout<<"Enter day: ";
				cin>>day;
				cout<<"Enter year: ";
				cin>>year;
				cout<<"Enter 1-Family member, 2-friend, 3-business associate: ";
				cin>>Type;
				cout<<"Enter phone number: ";
				cin>>phone;
				addressbook[count].setPerson(personType(firstName, lastName));
				addressbook[count].setDOB(dateType(month, day, year));
				addressbook[count].setAddress(addressType(StreetAddress, City, State, Zip));
				addressbook[count].setType(Type);
				addressbook[count].setPhone(phone);
				count++;
			}
			break;
		case '2'://>/>/Sort by last name
			{
				sort();
			}
			break;
		case '3'://>/>/search by last name
			{
				int total=0;
				string ln;
				cout<<"Enter last name to search: ";
				cin>>ln;
				for(int i=0;i<count;i++)
				{
					if(addressbook[i].getPerson().getLastName() == ln)
					{
						addressbook[i].printPersonDetails();
						addressbook[i].getType();
						cout<<endl<<"-----------------------------"<<endl;
						total++;
					}
				}
				cout<<endl<<"Match entries found: "<<total<<endl;
			}
			break;
		case '4'://>/>/Print the address, phone number, and date of birth
			{
				
				for(int i=0;i<count;i++)
				{
					addressbook[i].printPersonDetails();
					addressbook[i].getType();
					cout<<endl<<"-----------------------------"<<endl;
				}
				cout<<endl<<"Total entries: "<<count<<endl;
			}
			break;
		case '5'://>/>/Print the names of the people whose birthdays are in a given month
			{
				int total=0;
				int month;
				cout<<"Enter month of DOB to search: ";
				cin>>month;
				for(int i=0;i<count;i++)
				{
					if(addressbook[i].getDate().getMonth() == month)
					{
						addressbook[i].printPersonDetails();
						addressbook[i].getType();
						cout<<endl<<"-----------------------------"<<endl;
						total++;
					}
				}
				cout<<endl<<"Match entries found: "<<total<<endl;
			}
			break;
		case '6'://>/>/Print the names of all the people between two last names
			{
				sort();
				string ln1, ln2;
				cout<<"Enter last name 1: ";
				cin>>ln1;
				cout<<"Enter last name 2: ";
				cin>>ln2;
				for(int i=0;i<count;i++)
				{
					if(ln1 <= addressbook[i].getPerson().getLastName() && addressbook[i].getPerson().getLastName()<=ln2) 
					{
						addressbook[i].printPersonDetails();
						addressbook[i].getType();
						cout<<endl<<"-----------------------------"<<endl;
						
					}
				}
			}
			break;
		case '7'://>/>/Depending on the user's request, print the names of all family members friends, or business associates
			{
				int total=0;
				int type;
				cout<<"Enter 1-Family member, 2-friend, 3-business associate: ";
				cin>>type;
				for(int i=0;i<count;i++)
				{
					if(addressbook[i].getIntType()==type)
					{
						addressbook[i].printPersonDetails();
						addressbook[i].getType();
						cout<<endl<<"-----------------------------"<<endl;
						total++;
					}
				}
				cout<<endl<<"Match entries found: "<<total<<endl;
			}
			break;
		case '0':
			{
				writeToFile();
				flag=false;
			}
			break;
		}
	}while(flag);

	system("pause");
	return 0;
}

char displayMenu()
{
	char ch;
	do{
		cout<<endl<<"1. Add a address"<<endl;
		cout<<"2. Sort by last name"<<endl;
		cout<<"3. Search by last name"<<endl;
		cout<<"4. Print the address, phone number, and date of birth "<<endl;
		cout<<"5. Print the names of the people whose birthdays are in a given month"<<endl;
		cout<<"6. Print the names of all the people between two last names"<<endl;
		cout<<"7. Depending on the user's request, print the names of all family members friends, or business associates"<<endl;
		cout<<"0. Exit"<<endl;
		cout<<"Enter option: ";
		cin>>ch;
		if(ch=='1' || ch=='2' || ch=='3' || ch=='4' || ch=='5' || ch=='6' || ch=='7' || ch=='0')
			return ch;
		cout<<endl<<"ERROR: Invalid option entered"<<endl;
	}while(true);
}

void readFromFile()
{
	ifstream fin;
	fin.open("addresses.txt");
	string firstName;
	string lastName;
	string StreetAddress;
	string City;
	string State;
	string Zip;
	int month, day, year;
	int Type;
	string phone;
	while(fin>>firstName)
	{
		fin>>lastName;
		fin.ignore();
		getline(fin,StreetAddress);
		fin>>City;
		fin>>State;
		fin>>Zip;
		fin>>month;
		fin>>day;
		fin>>year;
		fin>>Type;
		fin>>phone;
		addressbook[count].setPerson(personType(firstName, lastName));
		addressbook[count].setDOB(dateType(month, day, year));
		addressbook[count].setAddress(addressType(StreetAddress, City, State, Zip));
		addressbook[count].setType(Type);
		addressbook[count].setPhone(phone);
		count++;
	}
	fin.close();
}

void sort()
{
	for(int i=0;i<count;i++)
	{
		for(int j=i+1;j<count;j++)
		{
			if(addressbook[i].getPerson().getLastName() > addressbook[j].getPerson().getLastName())
			{
				extPersonType tPerson;
				tPerson = addressbook[i].getPerson();
				addressbook[i].setPerson(addressbook[j].getPerson());
				addressbook[j].setPerson(tPerson);

				addressType tAddress;
				tAddress = addressbook[i].getAddress();
				addressbook[i].setAddress(addressbook[j].getAddress());
				addressbook[j].setAddress(tAddress);

				dateType tdate;
				tdate = addressbook[i].getDate();
				addressbook[i].setDOB(addressbook[j].getDate());
				addressbook[j].setDOB(tdate);

				int ttype;
				ttype=addressbook[i].getIntType();
				addressbook[i].setType(addressbook[j].getIntType());
				addressbook[j].setType(ttype);

			}
		}
	}
}



