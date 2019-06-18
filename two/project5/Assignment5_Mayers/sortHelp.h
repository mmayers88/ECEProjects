/*
Header Name:	sortHelp.h
Programmer:		Mikhail Mayers
Date:			3/11/2019
IDE:			MS Visual Studio Code/ Cygwin
Purpose:		                                */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <sys/wait.h>

#define SIZEOFARRAY 64000
pthread_t p1, p2, p3, p4;

typedef struct arg_struct
{
	int *arg1;
	int *arg2;
	int *arg3;
	int size;
} arg_struct;

struct timeval startTime, endTime;

bool bubbleSort(int arr[]);
void switch1and2(int *one, int *two);
bool inOrder(int one, int two);
bool allInOrder(int anArray[], int size);
void randomArray(int array[], int numOfIndex);
bool everythingWorking(int fd, int part);
void printArray(int array[], int numOfIndex);
void splitArray(int *arr1[], int *arr2[], int offset);
void sortQuarters(int *arr1[], int *arr2[], int *arr3[], int *arr4[]);
void mergeHalves(int *arr1[], int *arr2[], int *arr3[], int *arr4[], int *arr5[], int *arr6[]);
void mergeFinal(int *arr1[], int *arr2[], int *arr3[]);
void merge(void *arguments);
void printTimeDiff();
bool bubbleSort2(int arr[]);
void err_sys(char *msg);
