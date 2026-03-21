#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

bool valid_argc(int count);
bool valid_arg(string arg);
void cipher(string plaintext, unsigned int key);

int main(int argc, string argv[])
{
	if (!valid_argc(argc) || !valid_arg(argv[1]))
	{
		puts("Usage: ./caesar key");
		return 1;
	}

	string text = get_string("plaintext:  ");
	cipher(text, atoi(argv[1]));
	printf("ciphertext: %s\n", text);

	return 0;
}

bool valid_argc(int n)
{
	const int MAX_ARGC = 2;
	if (n != MAX_ARGC)
		return false;
	return true;
}

bool valid_arg(string s)
{
	for (int i = 0; s[i] != '\0'; i++)
		if (!isdigit(s[i]))
			return false;
	return true;
}

void cipher(string s, unsigned int n)
{
	for (int i = 0; s[i] != '\0'; i++)
		if (isalpha(s[i]))
		{
			if (isupper(s[i]))
				s[i] = ((s[i] - 'A') + n) % 26 + 'A';
			else
				s[i] = ((s[i] - 'a') + n) % 26 + 'a';
		}
}
