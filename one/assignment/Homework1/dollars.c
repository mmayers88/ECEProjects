#include<stdio.h>

int numOfMoney(int valueOfMoney, int dollars, int *numDollars)
{
	// this function is helpful because you can just change the value of the money and where to store it. less typing
	*numDollars = (dollars / valueOfMoney);
	dollars -= ((*numDollars) * valueOfMoney);
	return dollars;
};

void main() {

	int price = 0;

	printf("Show me the Money!\n$");
	scanf("%d", &price);
	int money[4] = { 0 };

	int *twenties = &money[0];
	int *tens = &money[1];
	int *fives = &money[2];
	int *ones = &money[3];

	price = numOfMoney(20, price, twenties);
	price = numOfMoney(10, price, tens);
	price = numOfMoney(5, price, fives);
	price = numOfMoney(1, price, ones);

	printf("\nTwenties: %d", *twenties);
	printf("\nTens: %d", *tens);
	printf("\nFives: %d", *fives);
	printf("\nones: %d", *ones);
	printf(" ");
  getch();
}
