#include "endHelp.h"

void initBuff(bufferInfo list[])
{
	for (int i = 0; i < TOTALBUFF; i++)
	{
		list[i].num = 0;
		list[i].numOfWords = 0;
		strcpy(list[i].words, "N/A");
	}
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

bool history(bufferInfo list[], int lineNum, int n)
{
	lineNum = (lineNum % TOTALBUFF) - 1;
	if (lineNum == -1)
		lineNum = TOTALBUFF - 1;
	int i = n;
	for( i; i > 0; i--)
	{
		if (strcmp(list[i].words, "N/A") != 0 && list[i].num > 0)
			if (lineNum - i < 0)
			{
				write(1, list[(TOTALBUFF) + lineNum - i].words, strlen(list[(TOTALBUFF) + lineNum - i].words));
				write(1, "\n", 1);
			}
			else
			{
				write(1, list[lineNum - i].words, strlen(list[lineNum - i].words));
				write(1, "\n", 1);
			}
	}
	return true;
}
