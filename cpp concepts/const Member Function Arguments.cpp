#include <iostream>
using namespace std;
class Distance
{
private:
int feet;
float inches;
public:
Distance() : feet(0), inches(0.0)
{ }
Distance(int ft, float in) : feet(ft), inches(in)
{ }
void getdist()
{
cout << " Enter feet: "; cin >> feet;
cout << "Enter inches: "; cin >> inches;
}
void showdist() const //display distance
{ cout << feet << "  " << inches ; 
}
Distance add_dist (const Distance&) const;
};
Distance Distance::add_dist (const Distance& d2) const
{
Distance temp; //temporary variable
feet = 0;
d2.feet = 0;
temp.inches = inches + d2.inches;
if(temp.inches >= 12.0)
{
temp.inches -= 12.0;
temp.feet = 1;
}
temp.feet += feet + d2.feet;
return temp;
}

int main()
{
Distance dist1, dist3; //define two lengths
Distance dist2(11, 6.25); //define, initialize dist2
dist1.getdist(); //get dist1 from user
dist3 = dist1.add_dist(dist2); //dist3 = dist1 + dist2
//display all lengths
cout << "\ndist1 = "; dist1.showdist();
cout << "\ndist2 = "; dist2.showdist();
cout << "\ndist3 = "; dist3.showdist();
cout << endl;
return 0;
}

