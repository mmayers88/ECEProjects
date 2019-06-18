//======================================================================================
//
// Function: selectionSort
// Description: it sorts the array with selection sort
// Arguments: the data array, it's size & pointer to compares and swaps
// Return value: returns a total number integera;
//               compares and swaps by reference
//
//======================================================================================
#include "selectionsort.h"



int selectionSort(int arr[], int size, int* ncompares_ptr, int* nswaps_ptr)
{
	int switchCounter = 0;
	int compCounter = 0;
	int switches;
	int putBacks;
	int selectLocation = 0;
	int selectCandidate = 0;
#ifdef SS_VERBOSE
	printf("Initial array: ");
	printArray(arr, size);
	printf("\n\n");
#endif

	do
	{
		switches = 0;
		putBacks = 0;
		for (int x = selectLocation; x < size; x++)
		{
			if (arr[selectCandidate] > arr[x])
			{
				selectCandidate = x;
			}
#ifdef SS_VERBOSE
			printf("Items being COMPARED: %d & %d \n", arr[x], arr[selectCandidate]);
#endif
			compCounter++;
			}
		if (selectCandidate < size)
		{
			switch1and2(&arr[selectCandidate], &arr[selectLocation]);
#ifdef SS_VERBOSE
			printf("Items being SWITCHED: %d & %d \n", arr[selectCandidate], arr[selectLocation]);
#endif
			if (selectCandidate == selectLocation)
				putBacks++;
			switches++;
		}
		switchCounter = switchCounter + switches - putBacks ;
		selectLocation++;
		selectCandidate = selectLocation;
	} while (switches > 0);
	*nswaps_ptr = switchCounter;
	*ncompares_ptr = compCounter;
#ifdef SS_VERBOSE
	printf("Final array: ");
	printArray(arr, size);
	printf("\n\n");
#endif
	return (switchCounter + compCounter); // will return the number of steps
}
