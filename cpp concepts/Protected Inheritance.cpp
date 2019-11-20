//Computer Programing Lab
//Lab Task 
//17-6157
#include <iostream>
using namespace std;
class a
{
	friend class b;
public:
int d;

void fun1()
{
 e=2;
}
	
private:
int e;
protected:
int c;
};
class b:protected a
{
	
	
public:
int f;
friend void fun()
{
 d=2;
 c=5; // Protected member can be accessed here
 e=5 ; // error private can't be accessed here
 fun1();
}
};
int main()
{
 b g;
 g.d=3; //public member can’t be accessed here directly because now it is protected member
 g.c=4; //protected member can't be accessed here
 
}
