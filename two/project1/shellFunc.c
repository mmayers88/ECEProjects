/*
Class Name:	shellFunc
Programmer:		Mikhail Mayers
Date:			1/16/2019
IDE:			MS Visual Studio Enterprise 2015
Purpose:	Keeps shell.c pretty.	                                */
#include "shellFunc.h"


void initBuff(bufferInfo list[])
{
	for (int i = 0; i < TOTALBUFF; i++)
	{
		list[i].num = 0;
		strcpy(list[i].words, "N/A");
	}
}

int checkCondition(char buff[])
{
	int buffInt = 0;
	char newBuffChar[MAXCHAR];
	char newBuff[MAXCHAR];
	strcpy(newBuff, buff);
	char * token = strtok(newBuff, " ");
	if (token[0] == '\n')
	{
		fflush(stdin);
		return 0;
	}
	if (token[0] == '!')
	{
		strcpy(newBuffChar, buff);
		for (int i = 0; i < strlen(newBuffChar); i++)
			newBuffChar[i] = newBuffChar[i + 1];
		buffInt = atoi(newBuffChar);
		if (buffInt > 0)//5 or less, greater than 1(making sure it's a number)
			return 1;
		else
			return 0;
	}
	if (strcmp(token, "parse") == 0)
	{
		token = strtok(NULL, " ");
		if (token != NULL)
			return 2;
		else
			return 0;
	}
	if (strcmp(token, "exit") == 0)
		return 3;
	else if (strcmp(token, "history") == 0)
		return 4;
	else
		return 5;
}
bool useCondition(int instruct, char buff[], int lineNum, bufferInfo list[])
{
	int buffInt;
	switch (instruct)
	{
	case 0:
		failure();
		break;
	case 1:
		for (int i = 0; i < strlen(buff); i++)
			buff[i] = buff[i + 1];
		buffInt = atoi(buff);
		if (bang(list, buffInt, lineNum) == true)
		{
			return true;
		}
		else
			failure();
		break;
	case 2:
		if (parse(buff) == true)
		{
			savebuff(buff, lineNum, list);
			return true;
		}
		else
			failure();
		break;
	case 3:
		printf("Bye...");
		exit(0);
		failure();
		break;
	case 4:
		if (history(list, lineNum) == true)
		{
			savebuff(buff, lineNum, list);
			return true;
		}
		else
			failure();
		break;
	case 5:
		savebuff(buff, lineNum, list);
		return true;
		break;
	}
	return false;
}

void failure()
{
	printf("invalid\n");
}

bool savebuff(char buff[], int lineNum, bufferInfo list[])
{
	if (lineNum > TOTALBUFF)
	{
		int numInList = lineNum%TOTALBUFF;
		if (numInList == 0)
			numInList = TOTALBUFF;
		list[(numInList)-1].num = lineNum;
		strcpy(list[(numInList)-1].words, buff);
	}
	else
	{
		list[(lineNum)-1].num = lineNum;
		strcpy(list[(lineNum)-1].words, buff);
	}
	return false;
}

bool bang(bufferInfo list[], int num, int lineNum)
{
	if (num < 0 || num >= lineNum) //out of bounds
	{
		return false;
	}
	if (lineNum <= TOTALBUFF && num < lineNum)
	{
		useCondition(checkCondition(list[num - 1].words), list[num - 1].words, lineNum, list);
		return true;
	}
	if (lineNum > TOTALBUFF && num < TOTALBUFF)
	{
		if (list[num - 1].num == num)
		{
			useCondition(checkCondition(list[num - 1].words), list[num - 1].words, lineNum, list);
			return true;
		}
	}
	int realNum = 0;
	if (lineNum > TOTALBUFF)
	{
		realNum = num%TOTALBUFF;
	}
	if (realNum == 0)
		realNum = TOTALBUFF;
	if (list[realNum - 1].num == 0 || num <= 0) // MAKE SURE IT'S IN THE LIST
	{
		return false;
	}

	if (list[realNum - 1].num == num)
	{
		useCondition(checkCondition(list[realNum - 1].words), list[realNum - 1].words, lineNum, list);
		return true;
	}
	return false;
}

bool history(bufferInfo list[], int lineNum)
{
	if (lineNum <= 1)
		return false;
	else
	{
		for (int i = 0; i < TOTALBUFF; i++)
		{
			if (strcmp(list[i].words, "N/A") != 0 && list[i].num > 0)
				printf("%s \n", list[i].words);
		}
		return true;
	}
}


bool parse(char buff[])
{
	char newBuff[MAXCHAR];
	strcpy(newBuff, buff);
	char * token = strtok(newBuff, " ");

	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, " ");
	}
	return true;
}
