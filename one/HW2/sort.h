/*
Header Name: sort.h
Programmer:		Mikhail Mayers
Date:			10/16/2018
IDE:			minGW, git, and atom
Purpose:	just helpful functions to make my life easier	                                */
#ifndef SORT_HELPER_H
#define SORT_HELPER_H
#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "insertionsort.h"
#include "bubblesort.h"
#include "selectionsort.h"

  void inOrderArray(int array[],int numOfIndex);
  void randomArray(int array[],int numOfIndex);
  void backwardArray(int array[],int numOfIndex);
  void printArray(int array[],int numOfIndex);
  void printData(int array[]);
  bool inOrder(int one, int two);
  bool allInOrder(int anArray[], int size);
  void switch1and2(int * one, int * two);





  //======================================================================================
  //
  // Function: inOrderArray
  // Description: give it an array, and it puts numbers in order
  // Arguments: the array and the size of the array
  // Return value: it's void, but it fills the array by reference
  //
  //======================================================================================
void inOrderArray(int array[],int numOfIndex)
{
  for (int i = 0; i < numOfIndex; i++)
  		array[i] = i;
};

//======================================================================================
//
// Function: randomArray
// Description: give it an array, and it puts numbers in random order
// Arguments: the array and the size of the array
// Return value: it's void, but it fills the array by reference
//
//======================================================================================
void randomArray(int array[],int numOfIndex)
{
  srand(50);
for (int i = 0; i < numOfIndex; i++)
{
  array[i] = rand() % numOfIndex;
}

};


//======================================================================================
//
// Function: backwardArray
// Description: give it an array, and it puts numbers in backward order
// Arguments: the array and the size of the array
// Return value: it's void, but it fills the array by reference
//
//======================================================================================
void backwardArray(int array[],int numOfIndex)
{
  int decrement = numOfIndex - 1;
  	for (int i = 0; i < numOfIndex; i++)
  		array[i] = decrement--;
};

//======================================================================================
//
// Function: printArray
// Description: give it an array, and it prints it out(used to test)
// Arguments: the array and the size of the array
// Return value: just prints numbers
//
//======================================================================================
void printArray(int array[],int numOfIndex)
{
for (int i = 0; i < numOfIndex; i++)
  {
    printf("%d ", array[i]);
  }
    printf("\n" );
};
//======================================================================================
//
// Function: printData
// Description: give it an array specific to assignment and it gives you
//              a description of the data
// Arguments: the array
// Return value: just prints
//
//======================================================================================
void printData(int arr[])
{

    printf("Type: Selection--------------------------------------------------------\n");
	  printf(" Forward     Compares: %d      Swaps: %d      Total: %d \n", arr[1], arr[2], arr[0]);
		printf(" Backward    Compares: %d      Swaps: %d      Total: %d \n", arr[4], arr[5], arr[3]);
		printf(" Random      Compares: %d      Swaps: %d      Total: %d \n\n", arr[7], arr[8], arr[6]);
    printf("Type: Bubble-------------------------------------------------------- \n");
  	printf(" Forward     Compares: %d      Swaps: %d      Total: %d \n", arr[10], arr[11], arr[9]);
    printf(" Backward    Compares: %d      Swaps: %d      Total: %d \n", arr[13], arr[14], arr[12]);
  	printf(" Random      Compares: %d      Swaps: %d      Total: %d \n\n", arr[16], arr[17], arr[15]);
    printf("Type: Insertion----------------------------------------------------------- \n");
  	printf(" Forward     Compares: %d      Shifts: %d      Removes: %d      Inserts: %d      Total: %d \n", arr[19], arr[20], arr[21], arr[22], arr[18]);
    printf(" Backward    Compares: %d      Shifts: %d      Removes: %d      Inserts: %d      Total: %d \n", arr[24], arr[25], arr[26], arr[27], arr[23]);
  	printf(" Random      Compares: %d      Shifts: %d      Removes: %d      Inserts: %d      Total: %d \n", arr[29], arr[30], arr[31], arr[32], arr[28]);
};
//======================================================================================
//
// Function:      in order
// Description:   checks if individual things are in order
// Arguments:     two ints
// Return value:  bool, true if successful
//
//======================================================================================

bool inOrder(int one, int two)
{
	if (one <= two)
		return true;
	return false;
};
//======================================================================================
//
// Function:      allInOrder
// Description:   checks order
// Arguments:     an array and size
// Return value:  bool, true if in order
//
//======================================================================================

bool allInOrder(int anArray[], int size)
{
	for (int x = 0; x < size - 1; x++)
	{
		if (inOrder(anArray[x], anArray[x + 1])==false)
			return false;
	}
	return true;
};

//======================================================================================
//
// Function:      switch1and2
// Description:   just swaps two numbers
// Arguments:     two ints
// Return value:  none
//
//======================================================================================

void switch1and2(int * one, int * two)
{
	int hold;

  hold = * two;
	*two = *one;
	*one = hold;

};
#endif
