#include "AccountDB.h"
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip>

//*****************************************************************
// FILE:      AccountDB.cpp
// AUTHOR:    Christopher Battisto
// DUE DATE:  2/16/2017
// 
// PURPOSE:   Contains the class implementation of AccountDB.h
//*****************************************************************

using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::setw;

/***************************************************************
AccountDB
Use: This is the default constructor of the AccountDB class
that assigns the number of accounts member to 0
Parameters: None
Returns: Nothing
***************************************************************/
AccountDB::AccountDB() {
	numAccounts=0;
};

/***************************************************************
AccountDB
Use: This is the alternate constructor of the AccountDB class 
which writes the account database file's data to the array
Parameters: dataFile: A string that specifies the data file to
be read
Returns: Nothing
***************************************************************/
AccountDB::AccountDB(string dataFile) {
	//open file
	ifstream infile;
	infile.open(dataFile.c_str(), std::ios::binary);
	//check if file failed to open
    if (infile.fail()) {
        cout<<"input file did not open"<<endl;
        exit(-1);
    }
	infile.read((char*) this, sizeof(AccountDB));
	sortAccounts();
    infile.close();
};

/***************************************************************
print
Use: This prints out the credit card account listing's data
members
Returns: Nothing
***************************************************************/
void AccountDB::print() {
	cout<<"\n**** Credit Card Account Listing ****\n"<<endl;
	for (int i=0; i<numAccounts; i++) {
		accountDatabase[i].print();
		cout<<"\n";
	}
	cout<<"\n";
};

/***************************************************************
sortAccounts
Use: This sorts the array of CreditAccount objects in ascending
order by account number using an insertion sort algorithm
Returns: Nothing
***************************************************************/
void AccountDB::sortAccounts() {
	int i, j;
	CreditAccount bucket;
	string bucketNumGrab;
	string acctNumGrab;
	for (i = 1; i < numAccounts; i++) {
		bucket=accountDatabase[i];
		//bucketNumGrab=bucket.getAccountNumber();
		//acctNumGrab=accountDatabase[j-1].getAccountNumber();
		for (j = i; (j > 0) && (strcmp(accountDatabase[j-1].getAccountNumber(), bucket.getAccountNumber())>0); j--) {
         	accountDatabase[j] = accountDatabase[j-1];
		accountDatabase[j] = bucket;
		}
	}
};

/***************************************************************
searchForAccount
Use: This searches for the CreditAccount object with the specifed
account number.
Returns: mid: an int of the account object with the
		       passed account number.
***************************************************************/
int AccountDB::searchForAccount(char searchNumber[]) {
	int low=0;
	int high=numAccounts - 1;
	int mid;
	//string acctNumGrab;
	while (low<=high) {
		mid=(low+high) / 2;
		//acctNumGrab=accountDatabase[mid].getAccountNumber();
		if (strcmp(searchNumber, accountDatabase[mid].getAccountNumber()) == 0)
		    return mid;
		if (strcmp(searchNumber, accountDatabase[mid].getAccountNumber()) < 0)
		    high=mid - 1;
		else
		    low=mid + 1;
	}
	return -1;
};

/***************************************************************
processTransactions
Use: This opens the specified transaction file for input and
prints report/column headers.
Returns: Nothing
***************************************************************/
void AccountDB::processTransactions(string dataFile) {
	//declare vars
	char timestamp[4];
	char acctNumber[21];
	char type;
	double amount;
	int acctIndex;
	double newBalance;
	//print report columns/headers
        cout<<"\n                       Transaction Report              \n "<<endl;
        cout<<setw(8)<<"Date";
	cout<<setw(14)<<"Account";
	cout<<setw(8)<<"Type";
	cout<<setw(16)<<"Amount";
	cout<<setw(30)<<"New Balance"<<endl;
	//open file
	ifstream infile;
	infile.open(dataFile, std::ios::in);
	//check if file failed to open
	if (infile.fail()) {
		cout<<"Input file did not open"<<endl;
		exit(-1);
	}
	//test conditions and print for each line in file
	while (!infile.eof()) {

		infile>>timestamp;
		//cout<<setw(8)<<std::left<<timestamp;
		infile>>acctNumber;
		//cout<<setw(14)<<acctNumber;
		infile>>type;
		infile>>amount;
		
		cout<<setw(8)<<std::left<<timestamp;
		cout<<setw(14)<<acctNumber;
		
		acctIndex=searchForAccount(acctNumber);
		
		if (acctIndex == -1) {
			cout<<setw(8)<<type;
			cout<<setw(16)<<std::right<<amount;
            cout<<setw(30)<<"*** Invaild Account Number ***"<<endl;
			
		}
		else {
			cout<<setw(8)<<type;
			cout<<setw(16)<<amount;
			if (type=='P') {
				accountDatabase[acctIndex].processPayment(amount);
				//test if balance is negative, print CR if so
				newBalance=accountDatabase[acctIndex].getBalance();
				if (newBalance<0) 
					cout<<setw(30)<<newBalance<<" CR"<<endl;
				
				else 
					cout<<setw(30)<<newBalance<<endl;
				
			}
			else {
				if (accountDatabase[acctIndex].processCharge(amount)) {
					newBalance=accountDatabase[acctIndex].getBalance();
					cout<<setw(30)<<newBalance<<endl;
				}
				else 
					cout<<setw(30)<<"*** Credit Limit Exceeded ***"<<endl;
				
			}
				
        }
        cout<<acctIndex<<endl<<endl;
		
	
}

//close the file
infile.close();
}










