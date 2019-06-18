/*
Program Name: hw2
Programmer:		Mikhail Mayers
Date:			10/16/2018
IDE:			minGW, git, and atom
Purpose:	test out my other programs: insertionsort.c, bubblesort.c, selectionsort.c 	                                */
#define SORT_HELPER_H
#define SELECTIONSORT_H
#define INSERTIONSORT_H
#define BUBBLESORT_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sort.h"
#include "bubblesort.h"
#include "selectionsort.h"
#include "insertionsort.h"

const int SIZEOFARRAY = 50;


void main()
{
int Data[33] = {};
int selInOrder[SIZEOFARRAY];
int selRandOrder[SIZEOFARRAY];
int selBackOrder[SIZEOFARRAY];

inOrderArray(selInOrder,SIZEOFARRAY);
backwardArray(selBackOrder,SIZEOFARRAY);
randomArray(selRandOrder,SIZEOFARRAY);

Data[0]=selectionSort(selInOrder, SIZEOFARRAY, &Data[1], &Data[2]);
Data[3]=selectionSort(selBackOrder, SIZEOFARRAY, &Data[4], &Data[5]);
Data[6]=selectionSort(selRandOrder, SIZEOFARRAY, &Data[7], &Data[8]);
//---------------------------------------------------------------------

int bubbleInOrder[SIZEOFARRAY];
int bubbleRandOrder[SIZEOFARRAY];
int bubbleBackOrder[SIZEOFARRAY];

inOrderArray(bubbleInOrder,SIZEOFARRAY);
backwardArray(bubbleBackOrder,SIZEOFARRAY);
randomArray(bubbleRandOrder,SIZEOFARRAY);
Data[9]=bubbleSort(bubbleInOrder, SIZEOFARRAY, &Data[10], &Data[11]);
Data[12]=bubbleSort(bubbleBackOrder, SIZEOFARRAY, &Data[13], &Data[14]);
Data[15]=bubbleSort(bubbleRandOrder, SIZEOFARRAY, &Data[16], &Data[17]);


//--------------------------------------------------------------------
int inInOrder[SIZEOFARRAY];
int inRandOrder[SIZEOFARRAY];
int inBackOrder[SIZEOFARRAY];

inOrderArray(inInOrder,SIZEOFARRAY);
backwardArray(inBackOrder,SIZEOFARRAY);
randomArray(inRandOrder,SIZEOFARRAY);

Data[18]=insertionSort(inInOrder, SIZEOFARRAY, &Data[19], &Data[20], &Data[21], &Data[22]);
Data[23]=insertionSort(inBackOrder, SIZEOFARRAY, &Data[24], &Data[25], &Data[26], &Data[27]);
Data[28]=insertionSort(inRandOrder, SIZEOFARRAY, &Data[29], &Data[30], &Data[31], &Data[32]);
printf("Array size: %d\n\n", SIZEOFARRAY);
printData(Data);
  getch();
}
