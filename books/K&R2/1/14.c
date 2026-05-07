#include <stdio.h>

#define IN   1
#define OUT  0
#define SIZE 256

int main(void)
{
	int i, j, c;
	int ascii[SIZE];

	for (i = 0; i < SIZE; i++)
		ascii[i] = 0;

	while ((c = getchar()) != EOF)
		++ascii[c];

	printf("ASCII (Extended) Character Frequency\n");
	printf("------------------------------------\n");
	for (i = 0; i < SIZE; i++)
	{
		printf("%3i |", i);
		for (j = 0; j < ascii[i]; j++)
			putchar('#');
		putchar('\n');
	}

	return 0;
}
