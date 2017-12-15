#ifndef STACK_H
#define STACK_H

//*****************************************************************
// FILE:      Stack.h
// AUTHOR:    Christopher Battisto
// LOGON ID:  Z1788103
// DUE DATE:  4/18/2017
// 
// PURPOSE:   Contains the declaration for the Node structure and
//			  Stack class.
//*****************************************************************

#include <iostream>
#include <ostream>
#include <stdexcept>

template <class T>
struct Node {
	//pointer to a node
	Node<T>* next;
	//template parameter type
	T item;
	//constructor method
	Node(const T& = T(), Node<T>* next = nullptr);
};

//alternate constructor for node
template <class T>
Node<T>::Node(const T& newItem, Node<T>* newNext) {
	next=newNext;
	item=newItem;
};
	
//forward declaration of Stack template class
template <class T>
class Stack;

//forward declaration of operator<< template function
template <class T>
std::ostream& operator<<(std::ostream&, const Stack<T>&);

//template class Stack definition
template <class T>
class Stack {
	
	private:
		//pointer to a node
		Node<T>* stkTop;
		//stack size
		size_t stkSize;
		
	public:
		//default constructor
		Stack<T>();
		//destructor
		~Stack<T>();
		//copy constructor
		Stack(const Stack<T>&);
		//assignment operator
		Stack<T>& operator=(const Stack<T>&);
		//clear method
		void clear();
		//return size
		size_t size() const;
		//tests if stack is empty
		bool empty() const;
		//returns reference to a constant item of the template parameter type
		T& top() const;
		//insert item at top of the stack
		void push(const T&);
		//pop item from top of the stack
		void pop();
		// friend declaration for the template function
		friend std::ostream& operator<< <>(std::ostream&, const Stack<T>&);
	
};

/***************************************************************
Stack()
Use:  The constructor sets stkTop to nullptr and sets the
*  stack size to 0.
Parameters: None
Returns: Nothing
***************************************************************/
template <class T>
Stack<T>::Stack() {
	stkTop=nullptr;
	stkSize=0;
};

/***************************************************************
~Stack()
Use:  This is the destructor of the Stack class.  It calls the
* clear method.
Parameters: None
Returns: Nothing
***************************************************************/
template <class T>
Stack<T>::~Stack() {
	clear();
};

/***************************************************************
Stack()
Use:  This is the copy constructor of the Stack class.
Parameters: Const Stack& other
Returns: Nothing
***************************************************************/
template <class T>	
Stack<T>::Stack(const Stack<T>& other) {
	stkTop=nullptr;
	//make pointers for copying
	Node<T>* ptr, *newNode, *last = nullptr;
	for (ptr = other.stkTop; ptr != nullptr; ptr = ptr->next) {
		//allocate node
		newNode = new Node<T>(ptr->item);
		if (last == nullptr)
			stkTop = newNode;
		else
			last->next = newNode;
		last = newNode;
	}
	stkSize=other.stkSize;
};

/***************************************************************
operator=()
Use:  This is the copy assignment operator of the Stack class.
Parameters: Const Stack& other
Returns: Stack& object
***************************************************************/
template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other) {
	//check for self assignment
	if (this != &other) {
		clear();
		//make pointers for copying
		Node<T>* ptr, *newNode, *last = nullptr;
		for (ptr = other.stkTop; ptr != nullptr; ptr = ptr->next) {
			//allocate node
			newNode = new Node<T>(ptr->item);
			if (last == nullptr)
				stkTop = newNode;
			else
				last->next = newNode;
			last = newNode;
		}
		stkSize=other.stkSize;
	}
	return *this;
};

/***************************************************************
operator<<()
Use:  This is the output overload function of the Stack class.
Parameters: ostream output, stack& object
Returns: Output stream
***************************************************************/
template <class T>		
std::ostream& operator<<(std::ostream& lhs, const Stack<T>& rhs) {
	//create temp ptr
	Node<T>* ptr;
	//output each node item
	for (ptr = rhs.stkTop; ptr != nullptr; ptr = ptr->next)
		lhs << ptr->item << ' ';
	return lhs;
};

/***************************************************************
clear()
Use:  This is the clear method of the Stack class.  It deletes
* the nodes allocated previously.
Parameters: None
Returns: Nothing
***************************************************************/
template <class T>
void Stack<T>::clear() {
	while(empty() != true)
		pop();
};

/***************************************************************
size()
Use:  This method returns the size of the stack.
Parameters: None
Returns: size_t size
***************************************************************/
template <class T>
size_t Stack<T>::size() const {
	return stkSize;
};

/***************************************************************
empty()
Use:  This method tests if the stack is empty
Parameters: None
Returns: size_t size
***************************************************************/
template <class T>
bool Stack<T>::empty() const {
	if (stkSize==0)
		return true;
	else
		return false;
};

/***************************************************************
top()
Use:  This returns a reference to the constant item of the template
* parameter type
Parameters: None
Returns: T itemRef
***************************************************************/	
template <class T>	
T& Stack<T>::top() const {
	return stkTop->item;
};

/***************************************************************
push()
Use:  This method pushes an item of constant parameter type to 
* the top of the stack.
Parameters: const T& data
Returns: Nothing
***************************************************************/
template <class T>
void Stack<T>::push(const T& data) {
	Node<T>* newNode = new Node<T>(data, stkTop);
	stkTop = newNode;
	stkSize++;
};

/***************************************************************
pop()
Use:  This method removes an item from the top of the stack.
Parameters: None
Returns: Nothing
***************************************************************/
template <class T>
void Stack<T>::pop() {
	if (empty() == true)
		throw std::underflow_error("Stack underflow error");
	Node<T>* delNode = stkTop;
	stkTop = stkTop->next;
	delete delNode;
	stkSize--;
};		
		
#endif
