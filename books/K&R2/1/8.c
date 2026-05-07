#include <stdio.h>

int main(void)
{
	int c;
	int blanks = 0;
	int tabs = 0;
	int newlines = 0;
	while ((c = getchar()) != EOF)
	{
		if (c == ' ')
			++blanks;
		else if (c == '\t')
			++tabs;
		else if (c == '\n')
			++newlines;
	}

	printf("Number of blanks: %i\n", blanks);
	printf("Number of tabs: %i\n", tabs);
	printf("Number of newlines: %i\n", newlines);
	return 0;
}
