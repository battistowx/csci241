#include <iostream>
#include <iomanip>
#include "AccountDB.h"
#include "CreditAccount.h"

//*****************************************************************
// FILE:      AccountDB.cpp
// AUTHOR:    Christopher Battisto
// LOGON ID:  Z1788103
// DUE DATE:  2/16/2017
// 
// PURPOSE:   Contains the class implementation of AccountDB.h
//*****************************************************************

using namespace std;

int main() {
	//create AccountDB object using alternate constructor
	AccountDB account("accounts"); 
	account.print();
	account.processTransactions("transactions.txt");
	account.print();
	return(0);
}
