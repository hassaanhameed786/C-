#include <iostream>
using namespace std;
class a
{
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
class b:public a
{
public:
int f;
void fun()
{
 d=2;
 c=5; // Protected member can be accessed here
 //e=5 ; // error private can't be accessed here
 fun1();
}
};
int main()
{
 b g;
 g.d=3; //public member directly accessed here
// g.c=4; //protected member can't be accessed here
 g.fun();
 system("pause");
}

