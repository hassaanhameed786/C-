#include<iostream>
#include<string>

using namespace std;


class dateType
{
	int month, day, year;
public:
	dateType(int m=1, int d=1, int y=1900);
	int getDay();
	int getMonth();
	int getYear();
	void printDate();
};

