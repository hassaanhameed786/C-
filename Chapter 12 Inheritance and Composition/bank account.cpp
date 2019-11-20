
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

