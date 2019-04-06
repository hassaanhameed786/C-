#include <iostream>
using namespace std;
class Distance
{
private:
	int feet;
	float inches;
	public: //2-arg constructor
		Distance(int ft, float in) : feet(ft), inches(in)	
	{
 		}	
	void getdist() //user input; non-const func
	{	
	cout << "\nEnter feet: "; cin >> feet;
	cout << "Enter inches: ";cin >> inches;
	}
	
	void showdist() const //display distance; const func
	{ cout << feet << " " << inches ; }
};
////////////////////////////////////////////////////////////////
int main()
{
const Distance football(300, 0);
 Distance footballobj(300, 0);
//football.getdist(); //ERROR: getdist() not const
footballobj.getdist();
cout << "football =" ;
football.showdist(); //OK
cout << endl;
return 0;
}
