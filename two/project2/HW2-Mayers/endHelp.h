/*
Header Name:	shellFunc
Programmer:		Mikhail Mayers
Date:			1/16/2019
IDE:			MS Visual Studio Enterprise 2015
Purpose:	Header file for shell.c. Contains all functions used to reduce clutter.	                                */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define FILEMAX 128
#define TOTALBUFF 9
#define MAXCHAR 1000

typedef struct bufferInfo
{
	int num;
	char words[MAXCHAR];
	int numOfWords;
}bufferInfo;

void initBuff(bufferInfo list[]);
bool savebuff(char buff[], int lineNum, bufferInfo list[]);
bool history(bufferInfo list[], int lineNum, int n);
