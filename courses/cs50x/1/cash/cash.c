#include <cs50.h>
#include <stdio.h>

int get_change(void);
int get_coins(int change);

int main(void)
{
	printf("%d\n", get_coins(get_change()));
	return 0;
}

int get_change(void)
{
	int n;
	do
		n = get_int("Change owed: ");
	while (n < 0);
	return n;
}

int get_coins(int ch)
{
	const int QUARTER = 25;
	const int DIME = 10;
	const int NICKEL = 5;

	int c = 0;
	while (ch > 0)
	{
		if (ch >= QUARTER)
			ch -= QUARTER;
		else if (ch >= DIME)
			ch -= DIME;
		else if (ch >= NICKEL)
			ch -= NICKEL;
		else
			ch--;

		c++;
	}
	return c;
}
