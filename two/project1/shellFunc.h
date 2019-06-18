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

#define TOTALBUFF 5
#define MAXCHAR 80

typedef struct bufferInfo
{
	int num;
	char words[MAXCHAR];
}bufferInfo;

void initBuff(bufferInfo list[]);
int checkCondition(char buff[]);
bool useCondition(int instruct, char buff[], int lineNum, bufferInfo list[]);
void failure();
bool savebuff(char buff[], int lineNum, bufferInfo list[]);
bool bang(bufferInfo list[], int num, int lineNum);
bool history(bufferInfo list[], int lineNum);
bool parse(char buff[]);
