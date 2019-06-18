/*
Program Name:	shell
Programmer:		Mikhail Mayers
Date:			1/16/2019
IDE:			MS Visual Studio Enterprise 2015/mingw32
Purpose:	A basic operating system shell.	                                 */

#include "shellFunc.h"
void main()
{
	bufferInfo bufferInfoList[5];
	initBuff(bufferInfoList);
	int lineNum = 1;
	char buff[MAXCHAR];
	while (1) {
		printf("%d > ", lineNum);
		fgets(buff, MAXCHAR, stdin);
		if(strlen(buff) > 1)
			buff[strlen(buff) - 1] = '\0';
		if(useCondition(checkCondition(buff), buff, lineNum, bufferInfoList)== true)
		lineNum++;
	};
}
