/*
Header Name:	selectionsort
Programmer:		Mikhail Mayers
Date:			10/16/2018
IDE:			minGW, git, and atom
Purpose:	selection declaration	    */
#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sort.h"

//#define SS_VERBOSE

int selectionSort(int arr[], int size, int* ncompares_ptr, int* nswaps_ptr);


#endif
