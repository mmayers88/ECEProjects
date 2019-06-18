#include<stdio.h>

int numOfMoney(int valueOfMoney, int dollars, int *numDollars)
{
	// this function is helpful because you can just change the value of the money and where to store it. less typing
	*numDollars = (dollars / valueOfMoney);
	dollars -= ((*numDollars) * valueOfMoney);
	return dollars;
};
void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones)
{
	dollars = numOfMoney(20, dollars, twenties);
	dollars = numOfMoney(10, dollars, tens);
	dollars = numOfMoney(5, dollars, fives);
	dollars = numOfMoney(1, dollars, ones);
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

	pay_amount(price, twenties, tens, fives, ones);

	printf("\nTwenties: %d", *twenties);
	printf("\nTens: %d", *tens);
	printf("\nFives: %d", *fives);
	printf("\nones: %d", *ones);
	printf(" ");
  getch();
}
