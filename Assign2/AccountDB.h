
#ifndef ACCOUNTDB_H
#define ACCOUNTDB_H
#include "CreditAccount.h"
#include <string>

//*****************************************************************
// FILE:      AccountDB.h
// AUTHOR:    Christopher Battisto
// DUE DATE:  2/16/2017
// 
// PURPOSE:   Contains the declaration for the AccountDB class.
//*****************************************************************

class AccountDB {
	
	private:
		//array of 20 CreditAccount objects:
		CreditAccount accountDatabase[20];
		//int that specifies number of CreditAccount objects in array
		int numAccounts;
		
	
	public:
		//default constructor
		AccountDB();
		//alternate constructor that takes a string that contains the name of an existing DB file
		AccountDB(std::string inputFile);	
		//print method
		void print();
		//sort array of CreditAccount objects
		void sortAccounts();
		//search for a specified account
		int searchForAccount(char[]);
		//process the transactions
		void processTransactions(std::string);
		
	
};

#endif

