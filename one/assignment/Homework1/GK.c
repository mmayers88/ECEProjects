/*
Program Name:
Programmer:		Mikhail Mayers
Date:
IDE:			MS Visual Studio Enterprise 2015
Purpose:		                                 */

#include <stdio.h>

int decimate(int lesserUnit);




int main()
{
	int men = 0;
	int leaderOfTen = 0;
	int leaderOfHundred = 0;
	int leaderOfThousand = 0;
	int totalMen = 0;

	printf("How many men does Genghis Khan have? ");
	scanf("%d", &men);

	leaderOfTen = decimate(men);
	leaderOfHundred = decimate(leaderOfTen);
	leaderOfThousand = decimate(leaderOfHundred);

totalMen = leaderOfTen + leaderOfHundred + leaderOfThousand + men;
	printf("\nMen under Genghis Khan: %d", totalMen);
	printf(" \n");
	getch( );
	return 0;
}

int decimate(int lesserUnit)
{
	int higherUnit = 0;
	if ((lesserUnit / 10) >= 1)
		higherUnit = lesserUnit / 10;
	else if (lesserUnit % 10 != 0)
		higherUnit++;
	else
		return 0;

	return higherUnit;

}
