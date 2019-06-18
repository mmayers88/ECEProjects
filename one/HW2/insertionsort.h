/*
Header Name:	insertion
Programmer:		Mikhail Mayers
Date:			10/16/2018
IDE:			minGW, git, and atom
Purpose:	insertion declaration	    */
#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H
#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define IS_VERBOSE
int insertionSort(int arr[], int size, int* ncompares_ptr, int* nshifts_ptr, int* nremovals_ptr, int* ninsertions_ptr);

#endif
