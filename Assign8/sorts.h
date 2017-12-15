#ifndef SORTS_H
#define SORTS_H

//*****************************************************************
// FILE:      sorts.h
// AUTHOR:    Christopher Battisto
// LOGON ID:  Z1788103
// DUE DATE:  4/25/2017
// 
// PURPOSE:   Contains the declaration for the sorts template functions.
//*****************************************************************

#include <iostream>
#include <fstream>
#include <vector>

//Function prototypes:
template <class T> void buildList(std::vector<T>& , const char* );
template <class T> void printList(const std::vector<T>& , int , int);
template <class T> bool lessThan(const T& , const T& );
template <class T> bool greaterThan(const T& , const T& );


/***************************************************************
buildList()
Use:  This function opens a file and puts the items into a vector
Parameters: vector<T>& set, const char* fileName
Returns: Nothing
***************************************************************/
template <class T>
void buildList(std::vector<T>& set, const char* fileName) {
	T item;
	std::ifstream infile;
	infile.open(fileName, std::ios::in);
	//check if file failed to open
    if (infile.fail()) {
        std::cout<<"input file did not open"<<std::endl;
        exit(-1);
    }
    //read and insert items
    while(!infile.eof()) {
		set.push_back(item);
		for (int i=0; i<(int)set.size(); i++)
			infile>>set[i];
	}
	infile.close();
};

/***************************************************************
printList()
Use:  This function prints the items stored in a vector
Parameters: const vector<T>& set, int itemWidth, int numPerLine
Returns: Nothing
***************************************************************/	
template <class T>
void printList(const std::vector<T>& set, int itemWidth, int numPerLine) {
	for (int i=0; i<(int)set.size(); i++) {
		for (int j=0; j<numPerLine; j++) {
			std::cout<<std::setw(itemWidth);
			std::cout<<set[i];
		}
	std::cout<<"\n";
	}
};		

/***************************************************************
lessThan()
Use:  This function tests if item1 is less than item2.
Parameters: const T& item1, const T& item2
Returns: bool
***************************************************************/
template <class T>
bool lessThan(const T& item1, const T& item2) {
	if (item1>item2)
		return false;
	return true;		
};

/***************************************************************
greaterThan()
Use:  This function tests if item1 is greater than item2.
Parameters: const T& item1, const T& item2
Returns: bool
***************************************************************/
template <class T>
bool greaterThan(const T& item1, const T& item2) {
	if (item1<item2) 
		return false;
	return true;		
};

#endif
