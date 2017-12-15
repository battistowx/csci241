#ifndef NIUSTRING_H
#define NIUSTRING_H

//*****************************************************************
// FILE:      NIUString.h
// AUTHOR:    Christopher Battisto
// LOGON ID:  Z1788103
// DUE DATE:  3/28/2017
// 
// PURPOSE:   Contains the declaration for the NIUString class.
//*****************************************************************

#include <ostream>

class NIUString {
	
	private:
		char* arrayPtr;
		size_t strCapacity;
		size_t strSize;
		
	public:
		//default constructor
		NIUString();
		//alternate constructor
		NIUString(const char*);
		//copy constructor
		NIUString(const NIUString&);
		//destructor
		~NIUString();
		//overload assignment operator that assigns one object to another
		NIUString& operator=(const NIUString&);
		//overload assignment operator that assigns a C string to an 
		//NIU string object that called the method
		NIUString& operator=(const char*);
		//return string capacity
		size_t capacity() const;
		//return string size
		size_t size() const;
		//returns bool if the string size is 0
		bool empty() const;
		//sets string size and capacity to 0
		void clear();
		//modifies the objects string capacity without changing its size/contents
		void reserve(size_t);
		//overload logic operator that tests if chars in string are equal to called object
		bool operator==(const NIUString&) const;
		//overload operator that tests if chars are equal from passed character pointer
		bool operator==(const char*) const;
		//overload operators that return the element position of string array
		const char& operator[](size_t) const;
		char& operator[](size_t);
		//print function
		friend std::ostream& operator<<(std::ostream&, const NIUString&);
		//function that tests if characters in lhs are same to rhs
		friend bool operator==(const char*, const NIUString&);
		
};		

#endif
