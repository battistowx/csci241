#ifndef MONKEY_H
#define MONKEY_H
#include <string>

//*****************************************************************
// FILE:      Monkey.h
// AUTHOR:    Christopher Battisto
// LOGON ID:  Z1788103
// DUE DATE:  2/23/2017
// 
// PURPOSE:   Contains the declaration for the Monkey class.
//*****************************************************************

//declare constants
static const int NUMMONKEYS = 3;
static const int NUMDAYS = 7;

//class declaration
class Monkey {
	
	private:
		//array of names of the monkeys
		std::string monkeyNames[NUMMONKEYS]={"Curious George","Mojo","Marcel"};
		//2-d array of floats with pounds of food eaten each day
		float foodEaten[NUMMONKEYS][NUMDAYS];
	
	public:
		//reads txt file into the 2-d array
		Monkey();
		//gets name of monkey at specified index
		std::string getName(int);
		//prints report of food eaten
		void printArray();
		//gets total food eaten for all monkeys
		float totalFoodEaten();
		//returns average consumption for all monkeys
		float avgDailyConsumption();
		//returns average 7 day food consumption for specified monkey
		float avgDailyPerMonkey(int);
		//go through array and find greatest amount of food eaten and print name of monkey
		void mostEaten();
		
};		

#endif
