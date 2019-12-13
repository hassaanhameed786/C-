#include<iostream>
#include "train12.h"
#include<fstream>
using namespace std;
int main()
{
	cout <<"\t\t=================================================\n";
	cout <<"\t\t|                                               |\n";
	cout <<"\t\t|      -------------------------------          |\n";
	cout <<"\t\t|       TRAIN Tracking & RERS. SYSTEM           |\n";
	cout <<"\t\t|      -------------------------------          |\n";
	cout <<"\t\t|                                               |\n";
	cout <<"\t\t|                                               |\n";
	cout <<"\t\t|                                               |\n";
	cout <<"\t\t|              BROUGHT TO YOU BY                |\n";
	cout <<"\t\t|           |  Muhammad Hassan |                |\n";
	cout <<"\t\t|                                               |\n";
	cout <<"\t\t=================================================\n\n\n";
	avlimplementation b;
	string firstname;
	string lastname;
	 
	string cell_no;
	string email;
	string post;	//rank of the post
	int id;	
	string null;
ifstream infile("railway.txt");

while(!infile.eof()){
	infile>>id;
	getline(infile,null,',');
	getline(infile,firstname,',');
	getline(infile,lastname,',');
	getline(infile,cell_no,',');
	getline(infile,email,',');
	getline(infile,post,'\n');
	b.root=b.insertion(b.root,id,firstname,lastname,cell_no,email,post);
}

char ch ,y;	

do{
	cout<<"*********************************************************************************"<<endl;
	cout <<"\n1.Insertion\n2.Deletion\n3.Search\n4.Update\n5.Print" <<endl;
	cout<<"*********************************************************************************"<<endl;
	
	cin >>ch;
	switch(ch){
		
		
		cout<<"Enter a input";
		case '1':system("cls"); 
		{
				string fname,lname,Emal,Pst,cellno;
			int ID;
			cout<<" Enter a firstname : " <<endl;
			cin >>fname;
			cout<<" Enter a lastname : " <<endl;
			cin >>lname;
			cout<<" Enter a email : " <<endl;
			cin >>Emal;
			cout<<" Enter a post : " <<endl;
			cin >>Pst;
			cout<<" Enter a cell number : " <<endl;
			cin >>cellno;
			cout<<" Enter a ID : " <<endl;
			cin >>ID;
			
			b.root=b.insertion(b.root,ID,fname,lname,cellno,Emal,Pst);
			break;
		}
		case '2':system("cls"); 
			int n;
			cout<<"Enter ID For Deletion " <<endl;
			cin>>n;
			b.root=b.deletion_in_avl(b.root,n);
			break;
		case '3':system("cls"); 
			int id;
			cout << "Enter a Id  to Search The Staff" <<endl;
			cin >>n;	
			b.Search_Staff_Member(id);
			break;
		case '4':system("cls"); 
			int ID;
			{cout<<" Enter ID Which u want to update : " <<endl;
			cin >>ID;
					string fname,lname,Emal,Pst,cellno;
			
			cout<<" Enter a  new firstname : " <<endl;
			cin >>fname;
			cout<<" Enter a  new lastname : " <<endl;
			cin >>lname;
			cout<<" Enter a new email : " <<endl;
			cin >>Emal;
			cout<<" Enter a new post : " <<endl;
			cin >>Pst;
			cout<<" Enter a new cell number : " <<endl;
			cin >>cellno;			
			b.Update_Staff_firstname( ID,fname,lname,cellno,Emal,Pst);
			}
			break;
		case '5':system("cls"); 
			cout<<"Print Data"<<endl;
			b.pre_order(b.root);
			break;
		case '6':system("cls");
			exit(1);
			break;
		 default:system("cls"); 
			
			cout<<"Incorrect Choice"<<endl;
			break;
}
}
while(ch);

}



		
	

