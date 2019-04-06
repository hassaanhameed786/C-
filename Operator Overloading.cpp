#include <iostream>
using namespace std;

class Distance {
	private:
		int feet;
		int inches;
	public:
		Distance() {
			feet = 0;
			inches = 0;
		}
		
		Distance(int f, int i) {
			feet = f;
			inches = i;
		}
		
		void setData() {
			cin >> feet >> inches;
		}
		
		void show() {
			cout << "Feet: " << feet << endl << "Inches: " << inches << endl;
		}
		
		bool operator < (const Distance &d1) {
			if(feet < d1.feet && inches < d1.inches ) return true;
			else return false;
		}
		
		Distance operator =(const Distance &D) {
			feet = D.feet;
			inches = D.inches;			
		}
		
		Distance operator +=(const Distance &d) {
			Distance d1;
			d1.feet = feet += d.feet;
			d1.inches = inches += d.inches;
		/*	if (inches >= 12) {
				d1.feet = feet += 1;
				d1.inches = inches -= 12;
				}
				*/
			return d1;
		}
		
		//post decrement
		Distance operator --(int x){
			feet--;
			inches--;
		}
		//pre decrement
		Distance operator --() {
			--feet;
			--inches;
		}
		//similarly pre and post Increment operator overloaded as above 
		
		friend ostream &operator<<( ostream &os, const Distance &D ) {
	        os << "F : " << D.feet << " I : " << D.inches << endl;
	        return os;
      	}

      	friend istream &operator >> ( istream  &in, Distance &D ) {
	        in >> D.feet >> D.inches;
	        return in;
      	}
};

int main() {
	
	Distance D1(10, 11), D2(12, 13), D3;
	cout << "Enter the value of the object: " << endl;
	cin >> D3;
	cout << "First Distance: " << D3;
	D3 += D1;
	cout << D3;
	D3--;
	cout << D1;
	D1 = D2;
	cout << D1;
	D1--;
	cout << D1;
	--D1;
	cout << D1;
//	cout << D3;	

}
