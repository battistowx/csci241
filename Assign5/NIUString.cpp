#include "NIUString.h"
#include <iostream>
#include <string.h>
#include <ostream>
#include <iomanip>

//*****************************************************************
// FILE:      NIUString.cpp
// AUTHOR:    Christopher Battisto
// LOGON ID:  Z1788103
// DUE DATE:  3/28/2017
// 
// PURPOSE:   Contains the class implementation of NIUString.h
//*****************************************************************

using std::cout;
using std::ostream;

/***************************************************************
NIUString()
Use: This is the default constructor of the NIUString class.
* It initializes a new NIUString object to an empty string with
* a capacity of 0.
Parameters: None
Returns: Nothing
***************************************************************/
NIUString::NIUString() {
	strSize=0;
	strCapacity=0;
	arrayPtr=nullptr;
}

/***************************************************************
NIUString()
Use: This is the alternate constructor of the NIUString class.
Parameters: const char* other
Returns: Nothing
***************************************************************/
NIUString::NIUString(const char* other) {
	strSize=strlen(other);
	strCapacity=strSize;
	if (strCapacity==0)
		arrayPtr=nullptr;
	else
		arrayPtr=new char[strCapacity];	
	strcpy(arrayPtr, other);
}

/***************************************************************
NIUString()
Use: This is the copy constructor of the NIUString class.
Parameters: const NIUString& other
Returns: Nothing
***************************************************************/	
NIUString::NIUString(const NIUString& other) {
	strSize=other.size();
	strCapacity=other.strCapacity;
	if (strCapacity==0)
		arrayPtr=nullptr;
	else
		arrayPtr=new char[strCapacity];
	if (strlen(other.arrayPtr)!=0) {
		//insert for loop for copying array
		for (unsigned int i=0; i<strSize; i++) {
			arrayPtr[i]=other.arrayPtr[i];
		}
	}
}

/***************************************************************
~NIUString()
Use: This is the destructor of the NIUString class.
Parameters: Nothing
Returns: Nothing
***************************************************************/		
NIUString::~NIUString() {
	clear();
}

/***************************************************************
operator=()
Use: This is the copy operator of the NIUString class.
Parameters: const NIUString& other
Returns: *this
***************************************************************/				
NIUString& NIUString::operator=(const NIUString& other) {
	//check for self-assignment
	if (this==&other)
		return *this;
	else {
		clear();
		strSize=other.strSize;
		strCapacity=other.strCapacity;
		if (strCapacity==0)
			arrayPtr=nullptr;
		else
			arrayPtr=new char[strSize];
		for (unsigned int i=0; i<strCapacity; i++) {
			arrayPtr[i]=other.arrayPtr[i];
		}
		return *this;
	}	
}

/***************************************************************
operator=()
Use: This is the copy operator of the NIUString class.
Parameters: const NIUString& other
Returns: *this
***************************************************************/		 
NIUString& NIUString::operator=(const char* other)	{
	clear();
	strSize=strlen(other);
	strCapacity=strSize;
	//same method as above,use strcpy
	if (strCapacity==0)
		arrayPtr=nullptr;
	else
		arrayPtr=new char[strSize];
	strcpy(arrayPtr, other);
	return *this;
}

/***************************************************************
capacity()
Use: This method returns the string capacity
Parameters: Nothing
Returns: size_t string capacity
***************************************************************/	
size_t NIUString::capacity() const {
	return strCapacity;
}

/***************************************************************
size()
Use: This method returns the string size
Parameters: Nothing
Returns: size_t string size
***************************************************************/	
size_t NIUString::size() const {
	return strSize;
}

/***************************************************************
empty()
Use: This method returns true if the string size is 0
Parameters: Nothing
Returns: boolean
***************************************************************/	
bool NIUString::empty() const {
	if (strSize==0)
		return true;
	else
		return false;
}
/***************************************************************
clear()
Use: This method sets the string size and capacity to 0, then 
* deletes the string array and sets the array pointer to 0.
Parameters: Nothing
Returns: Nothing
***************************************************************/	
void NIUString::clear() {
	strSize=0;
	strCapacity=0;
	delete[] arrayPtr;
	arrayPtr=nullptr;
}

/***************************************************************
reserve()
Use: This method modifies an object's string capacity without
* changing its size or contents of the string array.
Parameters: size_t n
Returns: Nothing
***************************************************************/
void NIUString::reserve(size_t n) {
	if (n<strSize || n==strCapacity) {}
		//dont do anything, break out of method
	else {
		strCapacity=n;
		char* tempArray;
		if (strCapacity==0)
			tempArray=nullptr;	
		else {
			//allocate array of char and copy contents
			tempArray=new char[n];
			for (unsigned int i=0; i<n; i++) 
				tempArray[i]=arrayPtr[i];
		}
		//delete string array
		delete[] arrayPtr;
		//set string array ptr to temp array ptr
		arrayPtr=new char[n];
		arrayPtr=tempArray;
	}

}

/***************************************************************
operator==()
Use: This method checks if the characters stored in the string
* array of the NIUString object.
Parameters: const NIUString& rhs
Returns: boolean
***************************************************************/		
bool NIUString::operator==(const NIUString& rhs) const {
	if (rhs.strSize!=this->strSize)
		return false;
	else {
		for (unsigned int i=0; i<rhs.strSize; i++) {
			if (rhs[i]!=arrayPtr[i])
				return false;
			}
		}
	return true;
}

/***************************************************************
operator==()
Use: This method returns true if the characters stored in the 
* string array of the object that was called are the same as the 
* characters in rhs.
Parameters: const char* rhs
Returns: boolean
***************************************************************/
bool NIUString::operator==(const char* rhs) const {
	if (strlen(rhs)!=strSize)
		return false;
	else {
		if (strncmp(rhs, arrayPtr, strlen(rhs))!=0)
		return false;
	}
	return true;
}

/***************************************************************
operator[]()
Use: This method returns the element pos of the string array
Parameters: size_t pos
Returns: const char& element pos
***************************************************************/
const char& NIUString::operator[](size_t pos) const {
	return arrayPtr[pos];
}

/***************************************************************
operator[]()
Use: This method returns the element pos of the string array
Parameters: size_t pos
Returns: const char& element pos
***************************************************************/	
char& NIUString::operator[](size_t pos) {
	return arrayPtr[pos];
}	

/***************************************************************
operator<<()
Use: This method prints each item in the object array
Parameters: ostream& lhs, NIUString rhs
Returns: Nothing
***************************************************************/
std::ostream& operator<<(ostream& lhs, const NIUString& rhs) {
	for (unsigned int i=0; i<rhs.strCapacity; i++) 
		lhs<<rhs[i];
	return lhs;
}	
/***************************************************************
operator==()
Use: This method tests if the characters of the C string passed
* in as lhs are the same as the chars stored in the object array
* as rhs.
Parameters: const char* lhs, const NIUString& rhs
Returns: boolean
***************************************************************/
bool operator==(const char* lhs, const NIUString& rhs) {
	for (unsigned int i=0; i<rhs.strCapacity; i++) {
		if (rhs[i]!=lhs[i])
			return false;
	}
	return true;
}

