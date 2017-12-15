#ifndef MERGESORT_H
#define MERGESORT_H

//*****************************************************************
// FILE:      mergesort.h
// AUTHOR:    Christopher Battisto
// LOGON ID:  Z1788103
// DUE DATE:  4/25/2017
// 
// PURPOSE:   Contains the declaration for the mergesort template 
//			  functions.
//*****************************************************************

#include <iostream>
#include <vector>

//Function prototypes
template <class T> void mergeSort(std::vector<T>& , bool (*compare)(const T&, const T&));
template <class T> void mergeSort(std::vector<T>& , int , int , bool (*compare)(const T&, const T&));
template <class T> void merge(std::vector<T>& , int , int , int , bool (*compare)(const T&, const T&));


/***************************************************************
mergeSort()
Use:  This function should sort the items in the vector set using 
* the merge sort algorithm.
Parameters: vector<T>& set, bool (*compare)(const T&, const T&)
Returns: Nothing
***************************************************************/
template <class T>
void mergeSort(std::vector<T>& set, bool (*compare)(const T&, const T&)) {
	mergeSort(set, 0, set.size()-1, compare);
};

/***************************************************************
mergeSort()
Use:  This function divides a vector into two subvectors, sorts 
* them, and then merges the two sorted subvectors.
Parameters: vector<T>& set, int low, int high, 
* bool (*compare)(const T&, const T&)
Returns: Nothing
***************************************************************/
template <class T>
void mergeSort(std::vector<T>& set, int low, int high, bool (*compare)(const T&, const T&)) {
	int mid;
   
   if (low < high)
      {
      mid = (low + high) / 2;
      
      // Divide and conquer
      
      mergeSort(set, low, mid, compare);
      mergeSort(set, mid+1, high, compare);
      
      // Combine
      merge(set, low, mid, high, compare);
      }
};	

/***************************************************************
merge()
Use:  This function merges two sorted subvectors
Parameters: vector<T>& set, int low, int mid, int high, 
* bool (*compare)(const T&, const T&)
Returns: Nothing
***************************************************************/
template <class T>
void merge(std::vector<T>& set, int low, int mid, int high, bool (*compare)(const T&, const T&)) {
	// Create temporary vector to hold merged subvectors
   std::vector<T> temp(high - low + 1);

   int i = low;      // Subscript for start of left sorted subvector
   int j = mid+1;    // Subscript for start of right sorted subvector
   int k = 0;        // Subscript for start of merged vector

   // While not at the end of either subvector
   while (i <= mid && j <= high)
      {
      if (compare(set[j], set[i]))
         {
         //Copy element j of set into element k of temp
         temp[k]=set[j];
         j++;
         k++;
         }
      else
         {
         //Copy element i of set into element k of temp
         temp[k]=set[i];
         i++;
         k++;
         }
      }

   // Copy over any remaining elements of left subvector
   while (i <= mid)
      {
      //Copy element i of set into element k of temp
      temp[k]=set[i];
      i++;
      k++; 
      }

   // Copy over any remaining elements of right subvector
   while (j <= high)
      {
      //Copy element j of set into element k of temp
      temp[k]=set[j];
      j++; 
      k++;
      }

   // Copy merged elements back into original vector
   for (i = 0, j = low; j <= high; i++, j++)
      //Copy element i of temp into element j of set
      set[j]=temp[i];
};      
#endif
