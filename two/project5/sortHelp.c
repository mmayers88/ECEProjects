/*
Class Name:		sortHelp.c
Programmer:		Mikhail Mayers
Date:			3/11/2019
IDE:			MS Visual Studio Code/ Cygwin
Purpose:		                                */
#include "sortHelp.h"

//======================================================================================
//
// Function: 		bubbleSort
// Description: 	bubblesort function, but only works with arrays a quarter of SIZEOFARRAY
// Arguments:		an array
// Return value:	Returns the same array in order
//
//======================================================================================
bool bubbleSort(int arr[])
{
	int max = SIZEOFARRAY / 4;
	int switches = 0;
	do
	{
		switches = 0;
		for (int x = 0; x < max - 1; x++)
		{
			if (inOrder(arr[x], arr[x + 1]) == false)
			{
				switch1and2(&arr[x], &arr[x + 1]);
				switches++;
			}
		}
	} while (switches > 0);
	return 1;
}
//======================================================================================
//
// Function: 		bubbleSort
// Description: 	bubblesort function, works with arrays of size defined SIZEOFARRAY
// Arguments:		an array
// Return value:	Returns the same array in order
//
//======================================================================================
bool bubbleSort2(int arr[])
{
	int switches = 0;
	do
	{
		switches = 0;
		for (int x = 0; x < SIZEOFARRAY - 1; x++)
		{
			if (inOrder(arr[x], arr[x + 1]) == false)
			{
				switch1and2(&arr[x], &arr[x + 1]);
				switches++;
			}
		}
	} while (switches > 0);
	return 1;
}
//======================================================================================
//
// Function:		switch1and2
// Description:		switches the order of two given integers
// Arguments:		two integers
// Return value:	the two integers in a new order
//
//======================================================================================
void switch1and2(int *one, int *two)
{
	int hold;

	hold = *two;
	*two = *one;
	*one = hold;
};
//======================================================================================
//
// Function:		inOrder
// Description:		checks if the first integer given is smaller or equal to the second
// Arguments:		two integers
// Return value:	boolean, true if in order or equal, false otherwise
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
		if (inOrder(anArray[x], anArray[x + 1]) == false)
		{
			printf("\nSort Failed\n");
			return false;
		}
	}
	printf("\nSort Complete\n");
	return true;
};
//======================================================================================
//
// Function:		randomArray
// Description:		populates a given array of a given size with random numbers
// Arguments:		and array and it's size
// Return value: 	N/A, populates the array
//
//======================================================================================
void randomArray(int array[], int numOfIndex)
{
	srand(numOfIndex);
	for (int i = 0; i < numOfIndex; i++)
	{
		array[i] = rand() % numOfIndex;
	}
};
//======================================================================================
//
// Function:		everythingWorking
// Description:		used for debugging.  prints to screen when failure
// Arguments:		the error code and a line number to notify the location of failure
// Return value:	N/A prints feedback to screen
//
//======================================================================================
bool everythingWorking(int fd, int part)
{
	if (fd != 0)
	{
		printf("\nfailure part: %d", part);
		exit(-1);
	}
	return 1;
};
//======================================================================================
//
// Function:		printArray
// Description:		prints a given array, used for debugging
// Arguments:		an array and the size of it's index
// Return value:	N/A just feedback to screen
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
//======================================================================================
//
// Function:		splitArray
// Description:		splits an array into quarter sizes, can set an offset for the starting
//					location of the original array
// Arguments:		the first array, an array a quart of it's size and an offset
// Return value:	N/A, returns a new smaller array
//
//======================================================================================
void splitArray(int *arr1[], int *arr2[], int offset)
{
	for (int i = 0; i < SIZEOFARRAY / 4; i++)
		arr2[i] = arr1[i + offset];
};
//======================================================================================
//
// Function:		sortQuarters
// Description:		uses the bubblesort to sort 4 arrays using threads
// Arguments:		4 arrays
// Return value:	N/A, the arrays back in order
//
//======================================================================================
void sortQuarters(int *arr1[], int *arr2[], int *arr3[], int *arr4[])
{
	int fd;
	fd = pthread_create(&p1, NULL, &bubbleSort, (void *)arr1);
	everythingWorking(fd, 1);
	fd = pthread_create(&p2, NULL, &bubbleSort, (void *)arr2);
	everythingWorking(fd, 2);
	fd = pthread_create(&p3, NULL, &bubbleSort, (void *)arr3);
	everythingWorking(fd, 3);
	fd = pthread_create(&p4, NULL, &bubbleSort, (void *)arr4);
	everythingWorking(fd, 4);
	fd = pthread_join(p1, NULL);
	everythingWorking(fd, 5);
	fd = pthread_join(p2, NULL);
	everythingWorking(fd, 6);
	fd = pthread_join(p3, NULL);
	everythingWorking(fd, 7);
	fd = pthread_join(p4, NULL);
	everythingWorking(fd, 8);
};
//======================================================================================
//
// Function:		mergeHalves
// Description:		Sets up the arrays(4) to be passed into merge function via threads
// Arguments:		4 arrays(arr1-4) to be mearged into 2(arr5,arr6)
// Return value:	N/A
//
//======================================================================================
void mergeHalves(int *arr1[], int *arr2[], int *arr3[], int *arr4[], int *arr5[], int *arr6[])
{
	int fd;

	arg_struct arguments1;
	arguments1.arg1 = arr1;
	arguments1.arg2 = arr2;
	arguments1.arg3 = arr5;
	arguments1.size = SIZEOFARRAY / 2;
	arg_struct arguments2;
	arguments2.arg1 = arr3;
	arguments2.arg2 = arr4;
	arguments2.arg3 = arr6;
	arguments2.size = SIZEOFARRAY / 2;
	pthread_create(&p1, NULL, merge, (void *)&arguments1);
	pthread_create(&p2, NULL, merge, (void *)&arguments2);
	fd = pthread_join(p1, NULL);
	everythingWorking(fd, 173);
	fd = pthread_join(p2, NULL);
	everythingWorking(fd, 175);
};
//======================================================================================
//
// Function:		mergeFinal
// Description:		Sets up the arrays(2) to be passed into merge function via thread
//					also sets the data for the size
// Arguments:		4 arrays(arr1, arr2) to be mearged into 2(arr3)
// Return value:	N/A
//
//======================================================================================
void mergeFinal(int *arr1[], int *arr2[], int *arr3[])
{
	int fd;

	arg_struct arguments1;
	arguments1.arg1 = arr1;
	arguments1.arg2 = arr2;
	arguments1.arg3 = arr3;
	arguments1.size = SIZEOFARRAY;
	pthread_create(&p1, NULL, merge, (void *)&arguments1);
	fd = pthread_join(p1, NULL);
	everythingWorking(fd, 173);
};
//======================================================================================
//
// Function:		merge
// Description:		merges 2 arrays into one array lowest to highest
// Arguments:		a void pointer that is actually a struct with 4 arguments (2 input
//					arrays, 1 output array and the size)
// Return value:	N/A; only the output sorted array
//
//======================================================================================
void merge(void *arguments)
{
	arg_struct *data = arguments;
	int index1 = 0;
	int index2 = 0;
	for (int x = 0; x < data->size;)
	{
		if (data->arg1[index1] <= data->arg2[index2] && index1 < data->size / 2 && index2 < data->size / 2)
		{
			data->arg3[x++] = data->arg1[index1++];
		}
		else
		{
			data->arg3[x++] = data->arg2[index2++];
		}
	}
	if (index1 <= (data->size / 2) - 1)
		data->arg3[data->size - 1] = data->arg1[index1];
	if (index2 <= (data->size / 2) - 1)
		data->arg3[data->size / 2 - 1] = data->arg2[index2];
}
//======================================================================================
//
// Function:		printTimeDiff(taken from Tom Schubert)
// Description:		prints out a difference in time when started
// Arguments:		none
// Return value:	outputs to screen
//
//======================================================================================
void printTimeDiff()
{
	int sec_diff, msec_diff;

	gettimeofday(&endTime, NULL);

	sec_diff = endTime.tv_sec - startTime.tv_sec;

	msec_diff = endTime.tv_usec - startTime.tv_usec;
	if (msec_diff < 0)
	{
		msec_diff += 1000000;
		sec_diff--;
	}

	printf("time elapsed: \n\t%4d sec\n\t%4d usec\n", sec_diff, msec_diff);
}
//======================================================================================
//
// Function:		err_sys(Taken from Tom Schubert)
// Description:		sends out an error code
// Arguments:		a message
// Return value:	prints the given message and exits
//
//======================================================================================
void err_sys(char *msg)
{
	fprintf(stderr, "%s %s\n", msg, strerror(errno));
	exit(-1);
};
