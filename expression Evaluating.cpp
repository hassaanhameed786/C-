#include<iostream>
#include<stack>
#include<string>

using namespace std;

bool checkBraces(stack<char> openinB, stack<char> closinB)
{
	while( openinB.empty() == false && closinB.empty() == false )
	{
		// check for each seprately 
	 	char openbraces = openinB.top();
	 	char closebraces = closinB.top();
	 	
	 	if(openbraces == '(' and openbraces != ')' )
	 		return false;
	 	if(openbraces == '{' and openbraces != '}' )
	 		return false;
	 	if(openbraces == '[' and openbraces != ']' )
	 		return false;
	 	
	 	openinB.pop();
	 	closinB.pop();
	 	
	 	
	}
	
	if(openinB.size() - closinB.size() !=0 )
	{
		return false;
	}
	return true;
}

bool getBraces(string str)
{
	stack<char> ob;		// opening braces
	stack<char> cb;		//closing braces
	
	char temp;
	int len = str.length();
	
	for(int i=0; i<len; i++)
		temp = str[i];
	
	
	if(temp == '(' or temp == '{' or temp == '[' )
	{
		ob.push(temp);
	}
	else if(temp == ')' or temp == '}' or temp == ']')
	{
		cb.push(temp);
		
	}
	return checkBraces(ob,cb);
}

int main()
{
	string s;
	s = "5 + (2 ^ 3)]{( 8 / 4)";
	
	cout << getBraces(s) << endl;
}
