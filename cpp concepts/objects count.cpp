#include <iostream>
using namespace std;
//----------------This Program Tell You How much  object created------//
class frozenheart
{
private:
static int count; //note: “declaration” only!
public:
frozenheart() //increments count when object created
{ count++; }
int getcount() //returns count
{ return count; }
};
//--------------------------------------------------------------
int frozenheart::count = 0; //*definition* of count
//--------------------------------------------------------------
int main()
{
frozenheart f1, f2, f3,f4,f5,f6,f7; //create three objects
cout << "count is "<< f1.getcount() << endl; //each object
cout << "count is " << f2.getcount() << endl; //sees the
cout << "count is " << f3.getcount() << endl; //same value
return 0;
}
