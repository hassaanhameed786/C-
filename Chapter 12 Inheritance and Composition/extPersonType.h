#include<iostream>
#include<string>

using namespace std;


class extPersonType 
{
public:
	string firstName;
	string lastName;
public:
	extPersonType();
	extPersonType(string first, string last);
	void print() const;
	void setName(string first, string last);
	string getFirstName() const;
	string getLastName() const;
};
