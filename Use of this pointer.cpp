#include<iostream>
using namespace std;
class shape
{
private:
 int size;
public:
shape fun()
{
this->size=3;
 return *this;
}
};
int main()
{
shape obj,obj1;
obj1=obj.fun();

system("pause");
}
