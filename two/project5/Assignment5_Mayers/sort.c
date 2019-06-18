/*
Program Name:	Sort
Programmer:		Mikhail Mayers
Date:			3/11/2019
IDE:			MS Visual Studio Code/ Cygwin
Purpose:		test bubbleSort using threads and just plain bubblesort                                 */
#include "sortHelp.h"

int main()
{
	int sec_diff, msec_diff, rc;
	//create array
	int *bubRandOrder[SIZEOFARRAY];
	int *quartArray1[SIZEOFARRAY / 4];
	int *quartArray2[SIZEOFARRAY / 4];
	int *quartArray3[SIZEOFARRAY / 4];
	int *quartArray4[SIZEOFARRAY / 4];
	int *halfArray1[SIZEOFARRAY / 2];
	int *halfArray2[SIZEOFARRAY / 2];
	int *sortedArray[SIZEOFARRAY];
	randomArray(bubRandOrder, SIZEOFARRAY);
	gettimeofday(&startTime, NULL);
	//break array up(create bounds)
	//	printArray(bubRandOrder, SIZEOFARRAY);		// original array
	splitArray(bubRandOrder, quartArray1, 0);
	splitArray(bubRandOrder, quartArray2, SIZEOFARRAY / 8);
	splitArray(bubRandOrder, quartArray3, SIZEOFARRAY / 4);
	splitArray(bubRandOrder, quartArray4, SIZEOFARRAY * 3 / 8);
	//sort quarters
	sortQuarters(quartArray1, quartArray2, quartArray3, quartArray4);
	//sort halves
	mergeHalves(quartArray1, quartArray2, quartArray3, quartArray4, halfArray1, halfArray2);
	//sort final
	mergeFinal(halfArray1, halfArray2, sortedArray);
	printf("\n4 Threaded Sort:\n");
	printTimeDiff();
	//printArray(sortedArray, SIZEOFARRAY);			// see sorted array

	//bubbleSort 1 thread
	int fd;
	gettimeofday(&startTime, NULL);
	//	printArray(bubRandOrder, SIZEOFARRAY);		// original aray
	fd = pthread_create(&p1, NULL, &bubbleSort2, (void *)bubRandOrder);
	everythingWorking(fd, 1);
	fd = pthread_join(p1, NULL);
	everythingWorking(fd, 5);
	allInOrder(bubRandOrder,SIZEOFARRAY);
	printf("\nSingle Threaded Sort:\n");
	printTimeDiff();
	//printArray(bubRandOrder, SIZEOFARRAY);		//sorted array

	return 0;
}
