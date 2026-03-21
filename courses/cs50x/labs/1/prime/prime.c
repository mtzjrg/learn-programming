#include <cs50.h>
#include <math.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
	int min;
	do
	{
		min = get_int("Minimum: ");
	}
	while (min < 1);

	int max;
	do
	{
		max = get_int("Maximum: ");
	}
	while (min >= max);

	for (int i = min; i <= max; i++)
	{
		if (prime(i))
		{
			printf("%i\n", i);
		}
	}
}

bool prime(int number)
{
	// Edge cases
	if (number < 2)
		return false;
	if (number == 2)
		return true;
	if (number % 2 == 0)
		return false;

	// If number has a divisor greater than sqrt(number), it must also have a
	// corresponding divisor less than sqrt(number), so we only need to check
	// divisibility up to the sqrt(number). Ex: number == 97, limit = 9.
	// After handling edge cases, all primes are odd, so step increases by 2
	// instead of 1, cutting loops by half.
	int limit = (int) sqrt(number);
	for (int i = 3; i <= limit; i += 2)
		if (number % i == 0)
			return false;
	return true;
}
