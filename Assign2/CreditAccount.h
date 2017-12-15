#ifndef CREDIT_ACCOUNT_H
#define CREDIT_ACCOUNT_H
#include <cstring>

//*****************************************************************
// FILE:      CreditAccount.h
// AUTHOR:    Christopher Battisto
// LOGON ID:  Z1788103
// DUE DATE:  2/16/2017
// 
// PURPOSE:   Contains the declaration for the CreditAccount class.
//*****************************************************************


class CreditAccount {
	// Data members and method prototypes for the CreditAccount class go here
	private:
		char accountNumber[20]{};
		char customerName[21]{};
		double creditLimit;
		double accountBalance;
	
	public:
		//default constructor:
		CreditAccount();
		//alternate CreditAccount constructor:
		CreditAccount(char[], char[], double, double);
		//get and return account number
		char*  getAccountNumber();
		//get customer name
		char*  getName();
		//get credit limit
		double getLimit();
		//get the balance
		double getBalance();
		//process payment and return current balance
		void processPayment(double);
		//check if charge amount is greater than the credit limit
		bool processCharge(double);
		//print values of data members
		void print();
	
};

#endif
