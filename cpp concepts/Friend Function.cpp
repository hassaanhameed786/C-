#include <iostream>
using namespace std;
class Distance
{
 private:
 int meter;
 public:
 Distance(): meter(0){ }
 friend int func(Distance); //friend function
 };
int func(Distance d) //function definition
{
 d.meter=5; //accessing private data from non-member function
 return d.meter;
}
int main()
{
 Distance D;
 cout<<"Distace: "<<func(D);
 return 0;
}

