#include <stdio.h>

float toCelsius(float fahr);

int main(void)
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;
	while (fahr <= upper)
	{
		celsius = toCelsius(fahr);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
	return 0;
}

float toCelsius(float f)
{
	return (5.0 / 9.0) * (f - 32.0);
}
