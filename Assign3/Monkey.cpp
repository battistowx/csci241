#include "Monkey.h"
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip>

//*****************************************************************
// FILE:      Monkey.cpp
// AUTHOR:    Christopher Battisto
// LOGON ID:  Z1788103
// DUE DATE:  2/28/2017
// 
// PURPOSE:   Contains the class implementation of Monkey.h
//*****************************************************************

using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::setw;
using std::getline;

/***************************************************************
Monkey()
Use: This reads in the contents of monkeyfood.txt and stores each
value into the 2-d array foodEaten[][]
Parameters: None
Returns: Nothing
***************************************************************/
Monkey::Monkey() {
	//open file
	ifstream infile;
	infile.open("monkeyfood.txt", std::ios::in);
	//check if file failed to open
    if (infile.fail()) {
        cout<<"input file did not open"<<endl;
        exit(-1);
    }
    while(!infile.eof()) {
		for (int i=0; i<NUMMONKEYS; i++) {
			for (int j=0; j<NUMDAYS; j++) {
				infile>>foodEaten[i][j];
				}
			}
		}	
	infile.close();		
 };
 
/***************************************************************
getName()
Use: This method takes an integer index of the monkey name array
and returns the name of the monkey at that index.
Parameters: int of the index of the array
Returns: string of monkey's name
***************************************************************/
string Monkey::getName(int index) {
	return monkeyNames[index];
};

/***************************************************************
printArray()
Use: This method prints a report of food eaten for each monkey
Parameters: Nothing
Returns: Nothing
***************************************************************/	 
void Monkey::printArray() {
	for (int i=0; i<NUMMONKEYS; i++) {
		cout<<std::left<<setw(17)<<monkeyNames[i];
		for (int j=0; j<NUMDAYS; j++) {
			cout<<setw(7)<<std::fixed<<std::setprecision(2)<<foodEaten[i][j];
		}
	cout<<endl;
	}
};

/***************************************************************
totalFoodEaten()
Use: This method returns the total amount of food consumed by
all monkeys for the week
Parameters: Nothing
Returns: float of total amount of food eaten
***************************************************************/			
float Monkey::totalFoodEaten() {
	float foodAmt=0;
	for (int i=0; i<NUMMONKEYS; i++) {
		for (int j=0; j<NUMDAYS; j++) {
			foodAmt+=foodEaten[i][j];
		}
	}
	return foodAmt;
};				    

/***************************************************************
avgDailyConsumption()
Use: This method returns the average consumption of all monkeys
for the week.
Parameters: Nothing
Returns: float of average amount of food eaten
***************************************************************/    
float Monkey::avgDailyConsumption() {
	float totalEaten=totalFoodEaten();
	float avgFoodEaten=totalEaten / (NUMMONKEYS * NUMDAYS);
	return avgFoodEaten;
};

/***************************************************************
avgDailyPerMonkey()
Use: This method returns the average consumption of the specfied
monkey per week.
Parameters: int of the index for getting the specific monkey
Returns: float of average amount of food eaten
***************************************************************/
float Monkey::avgDailyPerMonkey(int index) {
	float avgFoodEaten;
	float totalEaten;
	for (int i=0; i<NUMDAYS; i++) {
		totalEaten+=foodEaten[index][i];
	}
	avgFoodEaten=totalEaten / NUMDAYS;
	return avgFoodEaten;
};
		
/***************************************************************
mostEaten()
Use: This method prints the name of the monkey who eats the 
greatest amount of food eaten during the week by any monkey on
one day.
Parameters: Nothing
Returns: Nothing
***************************************************************/	    
void Monkey::mostEaten() {
	int nameIndex=0;
	float food=0;
	float maxFood=foodEaten[0][0];
	for (int i=0; i<NUMMONKEYS; i++) {
		for (int j=0; j<NUMDAYS; j++) {
			food=foodEaten[i][j];
			//test if its greater than max
			if (food > maxFood) {
				nameIndex=i;
				maxFood=food;
			}
		}
	}
	cout<<getName(nameIndex)<<"	ate the most - "<<maxFood<<" pounds"<<endl;
};			
