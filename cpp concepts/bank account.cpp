//bankAccount.h
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
using namespace std;

class bankAccount	//set the account number, retrieve the account number, retrieve the balance, deposit and withdraw money, print account information
{
public:
	bankAccount();				//sets account number and balance to zero as default;
	bankAccount(int, double, double, double);
	~bankAccount(){}
	void setAccountNum(int);	//sets account number
	int getAccountNum() const;			
	double getBalance() const;		
	void deposit(double);		//calculates deposit value
	void withdraw(double);		//calculates withdraw value
	void printAccountInfo() const;	//prints info

	void setBalance(double);
	

private:
	int accountNum;
	//double accountBalance;

protected:
	double accountBalance;
};

#endif


//bankAccount.cpp
#include "bankAccount.h"

bankAccount::bankAccount()
{
	accountNum = 0;
	accountBalance = 0;
};

bankAccount::bankAccount(int n, double b, double d, double w)
{
	setAccountNum(n);
	setBalance(b);
	deposit(d);
	withdraw(w);
};

void bankAccount::setAccountNum(int n)
{
	accountNum = n;
};

int bankAccount::getAccountNum() const
{
	return accountNum;
};

void bankAccount::setBalance(double b)
{
	accountBalance = b;
}
double bankAccount::getBalance() const
{
	return accountBalance;
};

void bankAccount::deposit(double d)
{
	if (d >= 0)
	{
		accountBalance += d;
	}
	else
	{
		cout << "The withdraw ammount is invalid. The withdraw ammount will be set to zero." << endl;
		d = 0;
		accountBalance += d;
	}
};		

void bankAccount::withdraw(double w)
{
	if (w >= 0)
	{
		accountBalance -= w;
	}
	else
	{
		cout << "The withdraw ammount is invalid. The withdraw ammount will be set to zero." << endl;
		w = 0;
		accountBalance -= w;
	}
};	

void bankAccount::printAccountInfo() const
{
	cout << "Account Number: " << accountNum << endl;
	cout << "Account Balance: " << accountBalance << endl;
};


//checkingAccount.h (derived class)
#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include <iostream>
#include "bankAccount.h"
using namespace std;

class checkingAccount : public bankAccount
{
public:
	checkingAccount();
	~checkingAccount(){}
	checkingAccount(int, double, double, double, double, double, double);
	void setInterest(double);
	void setminBalance(double);
	double getminBalance();
	void setServiceCharges(double);
	double getServiceCharges();
	void postInterest(); //verify if the balance is less than the minimum balance, write a check, withdraw (override the method of the base class), and print account information
	//void getInterest(double);
	void withdraw(double);
	void printAccountInfo() const;
	//void BalanceVerification();
	void CheckAmount(double);
private:
	double interest;
	double minBalance;
	double serviceCharges;
};

#endif



//checkingAccount.cpp (derived class definition)
#include "checkingAccount.h"

checkingAccount::checkingAccount() : bankAccount()
{
	interest = 0;
	minBalance = 0;
	serviceCharges = 0;
}
checkingAccount::checkingAccount(int n, double b, double d, double w, double i, double mb, double sc) : bankAccount(n, b, d, w)
{
	setInterest(i);
	setminBalance(mb);
	setServiceCharges(sc);
}
void checkingAccount::setInterest(double i)
{
	interest = i;
}
void checkingAccount::setminBalance(double mb)
{
	minBalance = mb;
}
double checkingAccount::getminBalance()
{
	return minBalance;
}
void checkingAccount::setServiceCharges(double sc)
{
	serviceCharges = sc;
}
double checkingAccount::getServiceCharges()
{
	return serviceCharges;
}
void checkingAccount::postInterest()
{
	accountBalance *= (1 + interest / 100);
	
} 
void checkingAccount::CheckAmount(double c)
{
	accountBalance -= c;
}
void checkingAccount::printAccountInfo() const
{
	cout << "Account Number: " << getAccountNum() << endl;
	cout << "Account Balance: " << getBalance() << endl;

	cout << "Minimum Balance: " << minBalance << endl;
	cout << "Interest: " << interest << endl;
	cout << "Service Charge: " << serviceCharges << endl;
	//cout << "Post Interest: " << 
};

void checkingAccount::withdraw(double w)
{
	accountBalance -= w;

	if ((accountBalance) < minBalance)
	{
		accountBalance -=serviceCharges;
	}
}


//main.cpp (testing)
#include "bankAccount.h"
#include "checkingAccount.h"

int main()
{
	checkingAccount Customer1;
	Customer1.setAccountNum(100584220);
	Customer1.setBalance(2500);
	Customer1.setServiceCharges(15);
	Customer1.setminBalance(350);
	Customer1.setInterest(5);
	
	Customer1.deposit(250);
	Customer1.withdraw(159.55);
	Customer1.CheckAmount(1000);
	Customer1.postInterest();
	Customer1.printAccountInfo();

	system("PAUSE");

	return 0;
}
