/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 5
   PROGRAMMER: Chris Battisto
   LOGON ID:   Z1788103
   DUE DATE:   3/28/17

   FUNCTION:   This program tests the functionality of the NIUString
               class.
*********************************************************************/  

#include <iostream>
#include "NIUString.h"

using std::cout;
using std::endl;

int main()
   {
   cout << "Testing default constructor\n\n";

   const NIUString s1;
   
   cout << "s1: " << s1 << endl;   
   cout << "s1 size: " << s1.size() << endl;
   cout << "s1 capacity: " << s1.capacity() << endl;
   cout << "s1 is " << ((s1.empty()) ? "empty\n" : "not empty\n");
   cout << endl;
   
   cout << "Testing second constructor\n\n";
   
   NIUString s2 = "some text";
   
   cout << "s2: " << s2 << endl;   
   cout << "s2 size: " << s2.size() << endl;
   cout << "s2 capacity: " << s2.capacity() << endl;
   cout << "s2 is " << ((s2.empty()) ? "empty\n" : "not empty\n");
   cout << endl;
   
   cout << "Testing second constructor with long string\n\n";
   
   NIUString s3 = "This is a really long string, but all of it will still end up in the array - pretty neat, huh?";
   
   cout << "s3: " << s3 << endl;   
   cout << "s3 size: " << s3.size() << endl;
   cout << "s3 capacity: " << s3.capacity() << endl;
   cout << endl;

   cout << "Testing write form of subscript operator\n\n";
   
   s2[0] = 'S';
   s2[5] = 'T';
   cout << "s2: " << s2 << endl << endl;
      
   cout << "Testing read form of subscript operator\n\n";
   
   cout << "s2: ";
   for (size_t i = 0; i < s2.size(); i++)
      cout << s2[i];
   cout << endl << endl;

   cout << "Testing reserve() method\n\n";

   s2.reserve(9);

   cout << "s2: " << s2 << endl;   
   cout << "s2 size: " << s2.size() << endl;
   cout << "s2 capacity: " << s2.capacity() << endl;
   cout << "s2 is " << ((s2.empty()) ? "empty\n" : "not empty\n");
   cout << endl;
 
   s2.reserve(30);

   cout << "s2: " << s2 << endl;   
   cout << "s2 size: " << s2.size() << endl;
   cout << "s2 capacity: " << s2.capacity() << endl;
   cout << "s2 is " << ((s2.empty()) ? "empty\n" : "not empty\n");
   cout << endl;
 
   s2.reserve(15);

   cout << "s2: " << s2 << endl;   
   cout << "s2 size: " << s2.size() << endl;
   cout << "s2 capacity: " << s2.capacity() << endl;
   cout << "s2 is " << ((s2.empty()) ? "empty\n" : "not empty\n");
   cout << endl;
 
   s3.reserve(10);
  
   cout << "s3: " << s3 << endl;   
   cout << "s3 size: " << s3.size() << endl;
   cout << "s3 capacity: " << s3.capacity() << endl;
   cout << "s3 is " << ((s3.empty()) ? "empty\n" : "not empty\n");
   cout << endl;

   cout << "Testing equality operators\n\n";

   const NIUString s4 = "Some Text";
   
   cout << "s2 and s4 are " << ((s2 == s4) ? "equal\n" : "not equal\n");
   cout << "s3 and s4 are " << ((s3 == s4) ? "equal\n" : "not equal\n\n");
   
   cout << "s4 and \"Some Text\" are " << ((s4 == "Some Text") ? "equal\n" : "not equal\n");
   cout << "s4 and \"More Text\" are " << ((s4 == "More Text") ? "equal\n" : "not equal\n\n");
   
   cout << "\"Some Text\" and s4 are " << (("Some Text" == s4) ? "equal\n" : "not equal\n");
   cout << "\"More Text\" and s4 are " << (("More Text" == s4) ? "equal\n" : "not equal\n\n");

   cout << "Testing clear() method\n\n";

   s3.clear();
   
   cout << "s3: " << s3 << endl;   
   cout << "s3 size: " << s3.size() << endl;
   cout << "s3 capacity: " << s3.capacity() << endl;
   cout << "s3 is " << ((s3.empty()) ? "empty\n" : "not empty\n");
   cout << endl;

   cout << "Testing copy constructor\n\n";
   
   NIUString s5(s4);
   
   cout << "s5: " << s5 << endl;   
   cout << "s5 size: " << s5.size() << endl;
   cout << "s5 capacity: " << s5.capacity() << endl;
   cout << endl;

   cout << "Testing assignment operator\n\n";
   
   s3 = s5;

   cout << "s3: " << s3 << endl;   
   cout << "s3 size: " << s3.size() << endl;
   cout << "s3 capacity: " << s3.capacity() << endl;
   cout << endl;

   s3 = "a different string";

   cout << "s3: " << s3 << endl;   
   cout << "s3 size: " << s3.size() << endl;
   cout << "s3 capacity: " << s3.capacity() << endl;
   cout << endl;

   cout << "Testing self-assignment\n\n";

   s3 = s3;

   cout << "s3: " << s3 << endl;   
   cout << "s3 size: " << s3.size() << endl;
   cout << "s3 capacity: " << s3.capacity() << endl;
   cout << endl;

   cout << "Testing chained assignment\n\n";

   s3 = s2 = "Hello, world";

   cout << "s2: " << s2 << endl;
   cout << "s2 size: " << s2.size() << endl;
   cout << "s2 capacity: " << s2.capacity() << endl;
   cout << endl;

   cout << "s3: " << s3 << endl;
   cout << "s3 size: " << s3.size() << endl;
   cout << "s3 capacity: " << s3.capacity() << endl;
   cout << endl;

   //
   // Extra Credit
   //
   // This code will call the move constructor and move assignment
   // operator if they exist.
   //
   // If those move semantics methods are not implemented, this code
   // will call the copy constructor and copy assignment operator
   // instead. The output will be different in that case.
   //
   cout << "Extra Credit: Testing move constructor\n\n";

   NIUString s6 = std::move(s5);

   cout << "s6: " << s6 << endl;
   cout << "s6 size: " << s6.size() << endl;
   cout << "s6 capacity: " << s6.capacity() << endl;
   cout << "s6 is " << ((s6.empty()) ? "empty\n" : "not empty\n");
   cout << endl;

   cout << "s5: " << s5 << endl;
   cout << "s5 size: " << s5.size() << endl;
   cout << "s5 capacity: " << s5.capacity() << endl;
   cout << "s5 is " << ((s5.empty()) ? "empty\n" : "not empty\n");
   cout << endl;

   cout << "Extra Credit: Testing move assignment operator\n\n";

   s5 = std::move(s6);

   cout << "s5: " << s5 << endl;
   cout << "s5 size: " << s5.size() << endl;
   cout << "s5 capacity: " << s5.capacity() << endl;
   cout << "s5 is " << ((s5.empty()) ? "empty\n" : "not empty\n");
   cout << endl;

   cout << "s6: " << s6 << endl;
   cout << "s6 size: " << s6.size() << endl;
   cout << "s6 capacity: " << s6.capacity() << endl;
   cout << "s6 is " << ((s6.empty()) ? "empty\n" : "not empty\n");

   return 0;
   }
