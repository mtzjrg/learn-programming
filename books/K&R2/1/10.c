#include <stdio.h>

int main(void)
{
	int c, replaced;
	while ((c = getchar()) != EOF)
	{
		replaced = 0;
		if (c == '\t')
		{
			printf("\\t");
			replaced = 1;
		}
		if (c == '\b')
		{
			printf("\\b");
			replaced = 1;
		}
		if (c == '\\')
		{
			printf("\\\\");
			replaced = 1;
		}
		if (replaced == 0)
			putchar(c);
	}

	return 0;
}
