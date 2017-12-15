/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 1
   PROGRAMMER: Chris Battisto
   DUE DATE:   2/7/2017
 
   FUNCTION:   This program tests functions for manipulating C 
               strings.
*********************************************************************/

#include <iostream>
#include <cstring>
#include <cctype>
#include <ctype.h>
#include <stdio.h>

using std::cin;
using std::cout;
using std::endl;

// Add your function prototypes here
char* copy(char*, const char*, size_t);
char* reverseCopy(char*, const char*, size_t);
char* caseChangeCopy(char*, const char*, size_t);
char* replaceCopy(char*, const char*, char, char, size_t);
void read(char*, int);

int main()
   {
   const int WORDSIZE = 15;
   char words[][WORDSIZE] = {"cattywampus", "collywobbles", "Lickety Split", "Kerfuffle", "Lollygag", ""};
   char word[WORDSIZE];

   // Test the copy function
   cout << "Copy \"cattywampus\", should see \"cattywampus\".\n";
   copy(word, words[0], sizeof(word) - 1);
   cout << word << endl << endl;

   // Test the limit on the copy function
   cout << "Copy \"Supercalifragilisticexpialidocious\", should see \"Super\".\n";
   copy(word, "Supercalifragilisticexpialidocious", 5);
   cout << word << endl << endl;

   // Test the replaceCopy function
   cout << "Replace 'l' in \"collywobbles\" with 'b', should see \"cobbywobbbes\".\n";
   replaceCopy(word, words[1], 'l', 'b', sizeof(word) - 1);
   cout << word << endl << endl;

   // Test the limit on the replaceCopy function
   cout << "Replace 's' in \"Supercalifragilistic\" with 'd', should see \"duper\".\n";
   replaceCopy(word, "Supercalifragilistic", 'S', 'd', 5);
   cout << word << endl << endl;

   // Test the caseChangeCopy function
   cout << "Case change \"Lickety Split\", should see \"lICKETY sPLIT\".\n";
   caseChangeCopy(word, words[2], sizeof(word) - 1);
   cout << word << endl << endl;

   // Test the limit on the caseChangeCopy function
   cout << "Case change \"Supercalifragilistic\", should see \"sUPER\".\n";
   caseChangeCopy(word, "Supercalifragilistic", 5);
   cout << word << endl << endl;  
   
   // Test the reverseCopy function
   cout << "Reverse \"Kerfuffle\", should see \"elffufreK\"\n";
   reverseCopy(word, words[3], sizeof(word) - 1);
   cout << word << endl << endl;

   // Test the limit on the reverseCopy function
   cout << "Reverse \"triskaidekaphobia\", should see \"ohpakediaksirt\"\n";
   reverseCopy(word, "triskaidekaphobia", sizeof(word) - 1);;
   cout << word << endl << endl;

   cout << "Reverse \"Lollygag\", change case, and replace 'G' with 'Z', should see \"ZAZYLLOl\".\n";
   replaceCopy(caseChangeCopy(reverseCopy(word, words[4], sizeof(word) - 1), word, sizeof(word) - 1), word, 'G', 'Z', sizeof(word) - 1);
   cout << word << endl << endl;  

   cout << "Enter your entire name: ";
   read(words[5], sizeof(words[5]));
   cout << words[5] << endl << endl;  
   
   cout << "Reverse your name and change case.\n";
   cout << caseChangeCopy(reverseCopy(word, words[5], sizeof(word) - 1), word, sizeof(word) - 1) << endl; 

   return 0;
   }

// Add your function definitions here
char* copy(char* destination, const char* source, size_t num) {
	for (int i=0; i<num; i++) {
		destination[i]=source[i];
	}
	return destination;
};

char* reverseCopy(char* destination, const char* source, size_t num) {
	for (int i=num; i<0; i--) {
		destination[i]=source[i];
	}
	return destination;
};

char* replaceCopy(char* destination, const char* source, char target, char replace, size_t num) {
	for (int i=0; i<num; i++) {
		if (destination[i]=target)
		destination[i]=replace;
		else
		destination[i]=source[i];
	}
	return destination;
};

char* caseChangeCopy(char* destination, const char* source, size_t num) {
	char character[num];
	for (int i=0; i<num; i++) {
		character[i]=source[i];
		if (isupper(character[i])==true) {
			character[i]=tolower(character[i]);
			destination[i]=character[i];
		}
		else {
			character[i]=toupper(character[i]);
			destination[i]=character[i];
		}
	}
	return destination;
};

void read(char* destination, int n) {
	char myName[n];
	cout<<"Enter your entire name: ";
	std::cin.getline(myName,n);
	for (int i=0; i<n; i++) {
		destination[i]=myName[i];
	}
};
