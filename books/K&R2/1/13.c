#include <stdio.h>

#define IN  1
#define OUT 0
#define MAX 10 /* max word length */

int main(void)
{
	int i, j, c, wlen, state;
	int wlens[MAX];

	for (i = 0; i < MAX; i++)
		wlens[i] = 0;

	wlen = 0;
	state = IN;
	while ((c = getchar()) != EOF)
	{
		if (c == ' ' || c == '\t' || c == '\n')
		{
			state = OUT;
			if (wlen >= MAX)
				++wlens[MAX - 1];
			else if (wlen > 0 && wlen < MAX)
				++wlens[wlen - 1];
		}
		else if (state == OUT)
		{
			state = IN;
			wlen = 0;
		}
		++wlen;
	}

	for (i = 0; i < MAX; i++)
	{
		if (i == MAX - 1)
			printf("%2i+|", i + 1);
		else
			printf("%2i |", i + 1);

		for (j = 0; j < wlens[i]; j++)
			putchar('#');
		putchar('\n');
	}
	return 0;
}
