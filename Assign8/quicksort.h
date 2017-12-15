#ifndef QUICKSORT_H
#define QUICKSORT_H

//*****************************************************************
// FILE:      quicksort.h
// AUTHOR:    Christopher Battisto
// LOGON ID:  Z1788103
// DUE DATE:  4/25/2017
// 
// PURPOSE:   Contains the declaration for the quicksort template 
//			  functions.
//*****************************************************************

#include <iostream>
#include <vector>
#include <algorithm>

//Function prototypes
template <class T> void quickSort(std::vector<T>&, bool (*compare)(const T&, const T&));
template <class T> void quickSort(std::vector<T>& , int , int , bool (*compare)(const T&, const T&));
template <class T> int partition(std::vector<T>& , int , int , bool (*compare)(const T&, const T&));

/***************************************************************
quickSort()
Use:  This function sorts the vector items using the quicksort
* method.  It calls the recursive function of itself listed
* below.
Parameters: vector<T>& set, bool (*compare)(const T&, const T&)
Returns: Nothing
***************************************************************/
template <class T>
void quickSort(std::vector<T>& set, bool (*compare)(const T&, const T&)) {
	quickSort(set, 0, set.size()-1, compare);
};

/***************************************************************
quickSort()
Use:  This function performs the recursive calls to implement the
* quicksort algorithm.
Parameters: vector<T>& set, int start, int end, 
* bool (*compare)(const T&, const T&)
Returns: Nothing
***************************************************************/
template <class T>
void quickSort(std::vector<T>& set, int start, int end, bool (*compare)(const T&, const T&)) {
	int pivotPoint;
	if (start < end) {
		pivotPoint = partition(set, start, end, compare);     // Get the pivot point
        quickSort(set, start, pivotPoint - 1, compare);       // Sort first sublist
        quickSort(set, pivotPoint + 1, end, compare);         // Sort second sublist
	}
};

/***************************************************************
partition()
Use:  This function selects a pivot element and then partitions 
* the vector around the pivot.
Parameters: vector<T>& set, int start, int end, 
* bool (*compare)(const T&, const T&)
Returns: int pivotIndex
***************************************************************/	
template <class T>
int partition(std::vector<T>& set, int start, int end, bool (*compare)(const T&, const T&)) {
	int pivotIndex, mid;
	T pivotValue;
	mid = (start + end) / 2;
	//Swap elements start and mid of the vector
	std::swap(set[start], set[mid]);
	pivotIndex = start;
	pivotValue = set[start];
 
	for (int scan = start + 1; scan <= end; scan++) {
      if (compare(set[scan], pivotValue)){
         pivotIndex++;
         //Swap elements pivotIndex and scan of the vector
         std::swap(set[pivotIndex], set[scan]);
         }
      }

   //Swap elements start and pivotIndex of the vector
   std::swap(set[start], set[pivotIndex]);

	return pivotIndex;
};

#endif	
