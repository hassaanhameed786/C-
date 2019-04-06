#include<iostream>
using namespace std;

// ----   In diamond problem we use keyword virtual to hide the in betwwen classes
//		  inherited methods from parent class 
//-----   to avoid the abmiguity of diamond problem during the Inhertance                                            --------///


class Animal{
	private:
		int x,y,z;
	public:
		
		Animal(){
			cout << "Animal Constructor called " <<endl;
		}
		void function(){
			cout << "function  of Animal " <<endl;
	}
};
class Lion:virtual  public Animal{		//use virtual keyword to make Lion class virtual
	private:
		int w;
	public:
		Lion(){
			cout << "Constructor of Lion" <<endl;
			
		}
};

class Tiger: virtual public Animal{		//use virtual keyword to make Tiger class virtual
		private:
		int w;
	public:
		Tiger(){
			cout << "Constructor of Tiger" <<endl;
			
		}
};

class Big_Cat: public Tiger,Lion{
	
		public:
		Big_Cat(){
			cout << "Constructor of Big_Cat" <<endl;
			
		}
};

int main()
{

	Big_Cat B;
	B.function(); 	//	[Error] request for member 'function' is ambiguous
}
