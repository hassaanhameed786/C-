#include<iostream>
using namespace std;

//-- polymorphism means that  a called to a mmember fucntion which called differnt fucntion exexcutes acc to type of objxt invokes
//--n#

class Student{
	private:
		int x,z,y,d;
	public:
		virtual void print(){
			cout << " print function of class Student " <<endl;
		}
};

class Topper:public Student{
		private:
		int x,z,y,d;
	public:
		void print(){
			cout << "Print function of class Topper" <<endl;
		}
};

class Average:public Student{
		private:
		int x,z,y,d;
	public:
		void print(){
			cout << "Print function of class Average" <<endl;
		}
	
};

void Polymoph_print(Student &s)  //---- here we use pointer also as a formal parameter
{
	s.print();
}

int main()
{
	Topper t;
	Average avg;
	
// --- calling a Polymoph_print( Student &s) fucntion
	Polymoph_print(t); 
	Polymoph_print(avg);

	
}
