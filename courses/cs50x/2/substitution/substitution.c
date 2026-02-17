#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

bool valid_argc(int count);
bool valid_arg(string argv);
void substitute(string plaintext, string key);

int main(int argc, string argv[])
{
	if (!valid_argc(argc))
	{
		puts("Usage: ./substitution key");
		return 1;
	}
	if (!valid_arg(argv[1]))
	{
		puts("Key must contain 26 characters.");
		return 1;
	}

	string text = get_string("plaintext:  ");
	substitute(text, argv[1]);
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
	int ALPHABET[26] = {0};

	int len = 0;
	for (int i = 0; s[i] != '\0'; i++, len++)
	{
		if (!isalpha(s[i]))
			return false;

		if (isupper(s[i]))
			ALPHABET[s[i] - 'A'] += 1;
		else
			ALPHABET[s[i] - 'a'] += 1;
	}

	if (len != 26)
		return 0;

	for (int i = 0; i < len; i++)
		if (ALPHABET[i] != 1)
			return false;
	return true;
}

void substitute(string s, string k)
{
	for (int i = 0; s[i] != '\0'; i++)
		if (isalpha(s[i]))
		{
			if (isupper(s[i]))
				s[i] = toupper(k[s[i] - 'A']);
			else
				s[i] = tolower(k[s[i] - 'a']);
		}
}
