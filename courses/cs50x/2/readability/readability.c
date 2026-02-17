#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>

float get_level(string text);

int main(void)
{
	float grade_level = get_level(get_string("Text: "));
	if (grade_level >= 16)
		puts("Grade 16+");
	else if (grade_level < 1)
		puts("Before Grade 1");
	else
		printf("Grade %d\n", (int) round(grade_level));
	return 0;
}

float get_level(string s)
{
	int letters = 0;
	int words = 0;
	int sentences = 0;

	for (int i = 0, end_of_sentence = 0; s[i] != '\0'; i++)
	{
		if (s[i] == '.' || s[i] == '!' || s[i] == '?')
			end_of_sentence = 1;

		if (isalpha(s[i]))
			letters++;
		if (isspace(s[i]) || (!isspace(s[i]) && s[i + 1] == '\0'))
			words++;
		if ((end_of_sentence && isspace(s[i + 1])) || s[i + 1] == '\0')
		{
			sentences++;
			end_of_sentence = 0;
		}
	}

	return 0.0588 * (((float) letters / words) * 100) -
	       0.296 * (((float) sentences / words) * 100) - 15.8;
}
