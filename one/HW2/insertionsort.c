//======================================================================================
//
// Function: insertionSort
// Description: it sorts the array with insertion sort
// Arguments: the data array, it's size, pointer to compares, pointer to shifts
//            , pointer to removals, pointer to inserts
// Return value: returns a total number integera;
//               shifts,compares,removals,inserts by reference
//
//======================================================================================
#include "insertionsort.h"


int  insertionSort(int Data[], int size, int* ncompares_ptr, int* nshifts_ptr, int* nremovals_ptr, int* ninsertions_ptr)
{
	int shiftCounter = 0;
	int compCounter = 0;
	int shifts = 0;
	int insertionCandidate = 0;
	int removes = 0;
	int inserts = 0;
	int insertCounter = 0;
	int removeCounter = 0;
	int selectLocation = 0;
#ifdef IS_VERBOSE
	printf("Initial Array: ");
	printArray(Data, size);
	printf("\n\n");
#endif

	for (int x = 1; x < size; x++)
	{
		shifts = 0;
		insertionCandidate = Data[x];
		removes++;
		for(int i= x-1; i >= 0; i--)
		{

			if (inOrder(Data[i], insertionCandidate) == false)
			{
				switch1and2(&Data[i], &Data[i + 1]);
#ifdef IS_VERBOSE
				printf("Items being SWITCHED: %d & %d \n", Data[i], Data[i + 1]);
#endif
				shifts++;
			}
			else
			{
				i = 0;
			}
#ifdef IS_VERBOSE
			printf("Items being COMPARED: %d & %d \n", Data[i], Data[x]);
#endif
			shiftCounter += shifts;
			compCounter++;
			inserts++;
		};
	}
	*nshifts_ptr = shiftCounter;
	*ncompares_ptr = compCounter;
	*nremovals_ptr = removes;
	*ninsertions_ptr = inserts;
#ifdef BS_VERBOSE
	printf("Items SWITCHED: %d \n", switchCounter);
	printf("Items COMPARED: %d \n", compCounter);
	printf("Total STEPS: %d \n", (switchCounter + compCounter));
#endif
#ifdef IS_VERBOSE
	printf("Final array: ");
	printArray(Data, size);
	printf("\n\n");
#endif
	return (shiftCounter + compCounter + removes + inserts); // will return the number of steps
}
