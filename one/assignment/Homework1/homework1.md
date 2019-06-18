name: Mikhail Mayers
Class ECE 361

Question 1:
a.
  1) 11110
  2) 6401
b.
  1) Steps of a process to solve a specific problem.  
  2) An algorithm written for a computer.
c.
  80 ms
d.
  240 ms
e.
  1) T
  2) F
  3) F
  4) T
  5) T
  6) F
f.
  The big difference is that we can make changes to a project both with a CVCS and a DVCS, but with a DVCS you can commit local changes without committing them to the central shared system.
g.
  1) It means that the we saved a change we made to the program in the repository and it will be logged into a the version control history permanently.
  2) The staging area is where a modified project can be put before committing, so that you can commit multiple files at once.
  3) You use the staging area to add more than one file by git add [filename] and commit several at once. If you want to remove some file in the staging area you can use git reset[filename].
h.
  TO use the cloud, you must first have a bookmark to the cloud repository, so that your terminal can know where to send the files you've committed in your local repository. You can then push the files up to the cloud and pull them down if you make any commits up in the cloud.
i.
  A branch is a way to take your project in a new direction. The Idea being that if I have a simple project that works, and I would like to change the product to make it more user friendly, I can create branches and try different methods and keep the most user friendly without effecting the original if you make too many changes going down the wrong branch. You can essentially move backwards in versions if you find yourself in a hole.
j.
  1) 4
  2) (Question1-j-2.jpeg)The variables entered in the order 4,6, then 2. But stack operate as LIFO (last in first out) so order out will be 2, 6 then 4.

//====================================================================================================================
Question 2:

a.
# the issue is that the for loop only checks one place in the array and then exits.  I chose to change the function by using a do/while loop that looked for the a zero in the array and then exits
# I felt like using a do/while is the most efficient way to search because it has to search at least one point in the array and then exits immediatly when it finds a zero and returns the boolean of     # true, if it completes searching the array, then it returns false.
bool boolean_has_zero(int a[], int n)
{
	int i=0;
	do
	{
		if (a[i] == 0)
			return true;
		i++;
	} while (i <= n-1 );
	return false;
}

b.
# The Pointers need to have a * infront of them in order to take in data.

void avg_sum(double a[], int n, double *avg, double *sum)
{
	int i;
	*sum = 0.0;
	for (i = 0; i < n; i++)
		*sum += a[i];
	*avg = * sum / n;
};
//====================================================================================================================
c.
1.
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

// pointing all of the pointers to an array
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
	printf("\n");
}

2.
//=========================================================================================================================

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

// pointing all of the pointers to an array
	int *twenties = &money[0];
	int *tens = &money[1];
	int *fives = &money[2];
	int *ones = &money[3];

	pay_amount(price, twenties, tens, fives, ones);

	printf("\nTwenties: %d", *twenties);
	printf("\nTens: %d", *tens);
	printf("\nFives: %d", *fives);
	printf("\nones: %d", *ones);
	printf("\n");
}
