#ifndef QUEUE_H
#define QUEUE_H

//*****************************************************************
// FILE:      Queue.h
// AUTHOR:    Christopher Battisto
// LOGON ID:  Z1788103
// DUE DATE:  4/11/2017
// 
// PURPOSE:   Contains the declaration for the Queue class.
//*****************************************************************

#include <ostream>

class Queue {
	
	private:
		//pointer for first element of array
		int* firstElement;
		//pointer for dynamically allocated queue array
		int* queueArray;
		//size_t array size and capacity
		size_t arrayCapacity;
		size_t arraySize;
		//front/back subscripts
		int frontSub;
		int backSub;
		
	public:
		//default constructor
		Queue();
		//destructor
		~Queue();
		//copy constructor
		Queue(const Queue&);
		//copy assignment operator
		Queue& operator=(const Queue&);
		//clear method
		void clear();
		//return size
		size_t size() const;
		//return capacity
		size_t capacity() const;
		//returns if queue is empty
		bool empty() const;
		//tests if front is empty and returns exception statements
		int front() const;
		//tests if back is empty and throws exception statements
		int back() const;
		//push item into queue
		void push(int);
		//pop item from queue
		void pop();
		//reserve additional capacity for queue array
		void reserve(size_t);
		//output operator
		friend std::ostream& operator<<(std::ostream&, const Queue&);
		
};

#endif
