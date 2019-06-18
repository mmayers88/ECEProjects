//======================================================================================
//
// Function: bubbleSort
// Description: it sorts the array with bubble sort
// Arguments: the data array, it's size & pointer to compares and swaps
// Return value: returns a total number integera;
//               compares and swaps by reference
//
//======================================================================================
#include "bubblesort.h"



int bubbleSort(int arr[], int size, int* ncompares_ptr, int* nswaps_ptr)
{

  #ifdef BS_VERBOSE
printf("Initial array: " );
printArray(arr,size);
printf("\n\n");
  #endif

  int switchCounter = 0;
	int compCounter = 0;
  int switches;
  int compares = 0;
	do
	{
		switches = 0;
		for (int x = 0; x < size-1 ; x++)
    {
      compares++;
      #ifdef BS_VERBOSE
        printf("Items being COMPARED: %d & %d \n",arr[x], arr[x+1] );
      #endif
			if (inOrder(arr[x], arr[x + 1])==false)
			{
				switch1and2(&arr[x], &arr[x + 1]);
				switches++;
        #ifdef BS_VERBOSE
          printf("Items being SWITCHED: %d & %d \n",arr[x], arr[x+1] );
        #endif
			}
    }
			compCounter += compares;
			switchCounter += switches;
	}while (switches > 0);


	* nswaps_ptr = switchCounter;
	* ncompares_ptr = compCounter;
  #ifdef BS_VERBOSE
    printf("Items SWITCHED: %d \n",switchCounter );
    printf("Items COMPARED: %d \n", compCounter);
    printf("Total STEPS: %d \n",(switchCounter+compCounter) );
  #endif
  #ifdef BS_VERBOSE
printf("Final array: " );
printArray(arr,size);
printf("\n\n");
  #endif
	return (switchCounter+compCounter); // will return the number of steps
}
