#include <stdio.h>
#define MAXLINE 100 /* maximum input line size */

/* changed getline to getLine to avoid stdio conflict */
int getLine(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
int main(void)
{
	int len;               /* current line length */
	int max;               /* maximum length seen so far */
	char line[MAXLINE];    /* current input line */
	char longest[MAXLINE]; /* longest line saved here */
	int c;
	int full;

	max = 0;
	while ((len = getLine(line, MAXLINE)) > 0)
	{
		/* if getline filled the buffer/overflowed, get rid of
		   the rest of the input so it doesn't get treated as
		   a subsequent lines. */
		if (len == MAXLINE - 1)
		{
			full = len;
			while ((c = getchar()) != EOF && c != '\n')
				full++;
			len = full;
		}

		if (len > max)
		{
			max = len;
			copy(longest, line);
		}
	}

	if (max > 0) /* there was a line */
		printf("\n%d\n%s", max, longest);
	return 0;
}

/* getline: read a line into s, return length */
int getLine(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;

	if (c == '\n')
	{
		s[i] = c;
		++i;
	}

	s[i] = '\0';
	return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
