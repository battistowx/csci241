#include "CreditAccount.h"
#include <iostream>

//*****************************************************************
// FILE:      CreditAccount.cpp
// AUTHOR:    Christopher Battisto
// LOGON ID:  Z1788103
// DUE DATE:  2/16/2017
// 
// PURPOSE:   Contains the class implementation of CreditAccount.h
//*****************************************************************

using std::cout;
using std::endl;

/***************************************************************
CreditAccount
Use: This is the default constructor of the CreditAccount class
that assigns its members to 0 or null.
Parameters: None
Returns: Nothing
***************************************************************/
CreditAccount::CreditAccount() {
	creditLimit=0;
	accountBalance=0;
	accountNumber[0]='\0';
	customerName[0]='\0';
};

/***************************************************************
CreditAccount
Use: This is the alternate constructor of the CreditAccount
class that takes new account details and uses it to create a new
CreditAccount object.
Parameters: -newAcct: passed character array of new account number
			-newCust: passed character array of new customer name
			-newlimit: passed double of credit limit
			-newBalance: passed double of the new account balance
Returns: Nothing
***************************************************************/
CreditAccount::CreditAccount(char newAcct[], char newCustName[], double newLimit, double newBalance) {
	//write new account to private account member
	strcpy(accountNumber, newAcct);
	//write new customer name to private customer name
	strcpy(customerName, newCustName);
	//assign new credit limit and new balance
	creditLimit=newLimit;
	accountBalance=newBalance;
};

/***************************************************************
getAccountNumber
Use: This returns the accountNumber member
Parameters: None
Returns: accountNumber
***************************************************************/
char* CreditAccount::getAccountNumber() {
	char* a=new char[21];
	strcpy(a, accountNumber); 
	return a;
};

/***************************************************************
getName
Use: This returns the customerName member
Parameters: None
Returns: customerName
***************************************************************/
char* CreditAccount::getName() {
	char* n=new char[20];
	strcpy(n, customerName);
	return n;
};

/***************************************************************
getLimit
Use: This returns the creditLimit member
Parameters: None
Returns: creditLimit
***************************************************************/
double CreditAccount::getLimit() {
	return creditLimit;
};

/***************************************************************
getBalance
Use: This returns the accountBalance member
Parameters: None
Returns: accountBalance
***************************************************************/
double CreditAccount::getBalance() {
	return accountBalance;
};

/***************************************************************
processPayment
Use: This takes the payment amount and subtracts it from the 
account balance.
Parameters: payAmt: This is a double of the amount paid
Returns: Nothing
***************************************************************/
void CreditAccount::processPayment(double payAmt) {
	accountBalance=accountBalance - payAmt;
};

/***************************************************************
processCharge
Use: This tests if the charge can be made by adding the charge
to the account balance and checking if it is greater than the 
credit limit of the account.  It returns a bool if the charge
can or can't be made
Parameters: chargeAmt: This is a double of the charge amount
Returns: Boolean
***************************************************************/
bool CreditAccount::processCharge(double chargeAmt) {
	double chargeTest=accountBalance + chargeAmt;
	if (chargeTest > creditLimit)
		return false;
	else {
		accountBalance=accountBalance + chargeAmt;
		return true;
	}	
};

/***************************************************************
print
Use: This prints out each member of the different CreditAccount
members for each object called.
Parameters: None
Returns: Nothing
***************************************************************/
void CreditAccount::print() {
	cout<<"Account Number: ";
	printf("%s", accountNumber);
	cout<<"\nName: ";
	printf("%s", customerName);
	cout<<"\nCredit Limit: $"<<creditLimit;
	cout<<"\nCurrent Balance: $";
	if (accountBalance < 0) {
		accountBalance=accountBalance * -1;
		cout<<accountBalance<<" CR\n";
	}
	else
		cout<<accountBalance<<endl;	
};

