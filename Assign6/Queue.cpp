#include "Queue.h"
#include <iostream>
#include <ostream>
#include <iomanip>
#include <stdexcept>

//*****************************************************************
// FILE:      Queue.cpp
// AUTHOR:    Christopher Battisto
// LOGON ID:  Z1788103
// DUE DATE:  4/11/2017
// 
// PURPOSE:   Contains the class implementation of Queue.h
//*****************************************************************

using std::cout;
using std::ostream;

/***************************************************************
Queue()
Use: This is the default constructor of the Queue class.
* It sets the queue arraySize and queue arrayCapacity to 0 and the queue 
* array pointer to nullptr.
Parameters: None
Returns: Nothing
***************************************************************/
Queue::Queue() {
	arrayCapacity=0;
	arraySize=0;
	queueArray=nullptr;
	frontSub=0;
	backSub=arrayCapacity-1;
}

/***************************************************************
~Queue()
Use: This is the destructor of the queue array.  It deletes the
* memory allocated for the array.
Parameters: None
Returns: Nothing
***************************************************************/	
Queue::~Queue() {
	delete[] queueArray;
	queueArray=nullptr;
}

/***************************************************************
Queue()
Use: This is the copy constructor of the queue array.
Parameters: const int* other
Returns: Nothing
***************************************************************/
Queue::Queue(const Queue& other) {
	arraySize=other.arraySize;
	arrayCapacity=other.arrayCapacity;
	if (arrayCapacity==0)
		queueArray=nullptr;
	else {
		//allocate new array
		queueArray=new int[arrayCapacity];	
		//copy each element
		for (unsigned int i=0; i<arrayCapacity; i++)
			queueArray[i]=other.queueArray[i];
	}		
}

/***************************************************************
Queue()
Use: This is the copy assignment operator of the queue array.
Parameters: const Queue& object
Returns: Nothing
***************************************************************/	
Queue& Queue::operator=(const Queue& other) {
	//check for self-assignment
	if (this==&other)
		return *this;
	else {
		delete[] queueArray;
		queueArray=nullptr;
		arraySize=other.arraySize;
		arrayCapacity=other.arrayCapacity;
		if (arrayCapacity==0)
			queueArray=nullptr;
		else
			queueArray=new int[arraySize];
		for (unsigned int i=0; i<arrayCapacity; i++) {
			queueArray[i]=other.queueArray[i];
		}
		return *this;
	}	
}

/***************************************************************
operator<<()
Use: This is the output operator function of the queue array.
Parameters: ostream& lhs, rhs
Returns: Output of the array
***************************************************************/
ostream& operator<<(ostream& lhs, const Queue& rhs) {
	size_t current, i;
	for (current=rhs.frontSub, i=0; i<rhs.arraySize; ++i) {
		// Print queue element at subscript i
		lhs << rhs.queueArray[current] << ' ';
		// Increment i, wrapping around to front of queue array if necessary     
		current = (current + 1) % rhs.arrayCapacity;
	}
	return lhs;	
}	

/***************************************************************
clear()
Use: This is the clear method of the queue array.
Parameters: Nothing
Returns: Nothing
***************************************************************/
void Queue::clear() {
	arraySize=0;
	backSub=arrayCapacity-1;
	frontSub=0;
}

/***************************************************************
arraySize()
Use: This method returns the queueArray arraySize
Parameters: Nothing
Returns: arraySize
***************************************************************/
size_t Queue::size() const {
	return arraySize;
}

/***************************************************************
arrayCapacity()
Use: This method returns the queueArray arrayCapacity
Parameters: Nothing
Returns: arrayCapacity
***************************************************************/
size_t Queue::capacity() const{
	return arrayCapacity;
}

/***************************************************************
empty()
Use: This method returns true if the array is 0
Parameters: Nothing
Returns: boolean
***************************************************************/	
bool Queue::empty() const {
	if (arraySize==0)
		return true;
	else
		return false;
}

/***************************************************************
front()
Use: This method checks if the queue is empty and throws an
* exception.  If not, it returns the front element of the array
Parameters: Nothing
Returns: int frontElement
***************************************************************/
int Queue::front() const {
	int frontElement;
	if (empty()==true)
		throw std::underflow_error("Queue underflow error");
	else {
		frontElement=queueArray[frontSub];
		return frontElement;
	}	
}

/***************************************************************
back()
Use: This method checks if the queue is empty and throws an
* exception.  If not, it returns the back element of the array
Parameters: Nothing
Returns: int frontElement
***************************************************************/
int Queue::back() const {
	int backElement;
	if (empty()==true)
		throw std::underflow_error("Queue underflow error");
	else {
		backElement=queueArray[backSub];
		return backElement;
	}	
}

/***************************************************************
reserve()
Use: This method reserves additional arrayCapacity for the queue array
* to the new arrayCapacity passed in
Parameters: arraySize_t n
Returns: Nothing
***************************************************************/
void Queue::reserve(size_t n) {
	if (n<=arraySize) {}
		//dont do anything, break out of method
	else {
		int* tempArray=new int[n];
		int currentFrontSub=frontSub;
		for (unsigned int i=0; i<arrayCapacity; i++) { 
			tempArray[i]=queueArray[currentFrontSub];
			currentFrontSub=(currentFrontSub + 1) % arrayCapacity;
		}
		frontSub=0;
		backSub=arraySize-1;
		arrayCapacity=n;
		//delete queue array
		delete[] queueArray;
		//set queue array ptr to temp array ptr
		queueArray=new int[n];
		queueArray=tempArray;
	}
}	

/***************************************************************
push()
Use: This method pushes a new element into the queue array
Parameters: int item
Returns: Nothing
***************************************************************/
void Queue::push(int item) {
	//test if queue is full, call reserve if it is
	if (arraySize==arrayCapacity) {
		if (arrayCapacity==0) {
			reserve(1);
		}
		else {
			reserve(arrayCapacity * 2);
		}
	}
		//insert new item
		backSub=(backSub+1) % arrayCapacity;
		queueArray[backSub]=item;
		arraySize++;
	
}

/***************************************************************
pop()
Use: This method pops the top element from the queue array
Parameters: Nothing
Returns: Nothing
***************************************************************/			
void Queue::pop() {
	if (empty()==true)
		throw std::underflow_error("Queue underflow error");
	else {
		frontSub=(frontSub+1) % arrayCapacity;
		arraySize--;
	}
}
