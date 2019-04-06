#include<iostream>
using namespace std;

class PointType{
private:
  int x;
  int y;
public:
  PointType()
  {
    x =0;
    y =0;
  }

  PointType(int X, int Y)
  {
    x = X;
    y = Y;

  }

  void setCordinate(int a, int b)
  {
    x = a;
    y = b;
    return;

  }

  //get funtions
  int Get_X()
  {
    return x;
  }

  int Get_Y()
  {
    return y;
  }

  //print fucction is here
  void print_Cordinates()
  {
    cout  << " X Cordiante is  " << x  << " Y cordinate is " <<  y  <<endl;
  }

};

class CricleType : public  PointType {

	private:
		int center;
		

public:
	int radius;

CricleType()
{
  //
  center = 0;
  radius = 0;
}
CricleType( int c, int r,int x, int y ) : PointType(x,y)
{
  center = c;
  radius = r;
}


//setter function of class Circle
void Set_center(int centr)
{
  center = centr;

}
void Set_radius(int rad)
{
  radius = rad;
}

//getter functions
int Get_Center()
{
  return center;
}
int Get_Radius()
{
  return radius;
}

double area()
{
  // PI r * r
  return 3.14 * radius * radius;
}

double circumference()
{
return 2 * 3.14 * radius;
}

void print_CricleType (){
  PointType :: print_Cordinates();
  cout << "Center of Circle " << center << "Radius  of Cirlce is  " << radius <<endl;
}

};

class cylinderType: public CricleType {

private:
  int base;
  int height;

public:

  // default contructor

  cylinderType()
  {
    base = 0 ;
    height = 0;
  }

//constructor with parameters
  cylinderType(int b, int h, int c , int r, int x, int y) : CricleType(c,r,x,y)
  {
    base = b ;
    height = h;

  }

  //setter function of class Cylinder
  void Set_base(int bas){
    base  = bas;
  }
  void Set_height(int heig) {
    height = heig;
  }

///getter Function of class Cylinder
int Get_base(){
  return base;
}

int Get_height(){
  return height;

}

double Volume_of_Cylinder()
{
  return CricleType :: area() * height;

}
double Surface_area_of_cylinder(){
  // Area = 2*PI*R*h + 2*PI* R*R
  return 2 *3.14 * radius * height + 2 * 3.14 * radius * radius * radius;
}
// print function of class Cylinder as

void Print_cylinderType()
{
  //here first we call the print function of class CricleType
  CricleType :: print_CricleType();
  //then we printing out the volume and surface  of the cylinder

}


};

int main()
{


  
CricleType obj(2,4,55,77);
obj.print_CricleType();

// calculate area and circumference of class CricleType
cout << "Area of circle is : " <<obj.area() << " "
<< "Circumference of cirlce is : " <<obj.circumference() <<endl;



}
