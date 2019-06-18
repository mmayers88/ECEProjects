#define MAXOFLIST_H
#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "maxOfList.h"



void main()
{
	int data[10] = {};

	inOrderArray(data, 10);
	printf("Original List: ");
	printArray(data, 10);
	printf("Largest Value: %d\n\n", max(data, 10));

	backwardArray(data, 10);
	printf("Original List: ");
	printArray(data, 10);
	printf("Largest Value: %d\n\n", max(data, 10));

	randomArray(data, 10);
	printf("Original List: ");
	printArray(data, 10);
	printf("Largest Value: %d\n\n", max(data, 10));

	getchar();
}

//======================================================================================
//
// Function: max
// Description: give it an array and it finds the largest number
// Arguments: the array and it's number of elements
// Return value: returns the maximum number in the array
//
//======================================================================================
int max(int list[], int n )
{
	static int maxNum = 0;
	if (n == 0)
	{
		maxNum = list[0];
		return maxNum;
	}
	else
	{
		if (list[n] > max(list, n - 1))
			maxNum = list[n];
	}
	return maxNum;
};
//======================================================================================
//
// Function: inOrderArray
// Description: give it an array, and it puts numbers in order
// Arguments: the array and the size of the array
// Return value: it's void, but it fills the array by reference
//
//======================================================================================
void inOrderArray(int array[], int numOfIndex)
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
void randomArray(int array[], int numOfIndex)
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
void backwardArray(int array[], int numOfIndex)
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
void printArray(int array[], int numOfIndex)
{
	for (int i = 0; i < numOfIndex; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
};
