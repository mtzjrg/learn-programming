// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>

string replace(string input);

int main(int argc, string argv[])
{
	if (argc != 2)
	{
		printf("Usage: ./no-vowels [WORD]\n");
		return 1;
	}
	puts(replace(argv[1]));
	return 0;
}

string replace(string s)
{
	for (int i = 0; s[i]; i++)
	{
		switch (s[i])
		{
			case 'a':
				s[i] = '6';
				break;
			case 'e':
				s[i] = '3';
				break;
			case 'i':
				s[i] = '1';
				break;
			case 'o':
				s[i] = '0';
				break;
		}
	}
	return s;
}
