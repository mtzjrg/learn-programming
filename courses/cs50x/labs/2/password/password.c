// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

bool valid(string password);

int main(void)
{
	string password = get_string("Enter your password: ");
	if (valid(password))
	{
		printf("Your password is valid!\n");
	}
	else
	{
		printf("Your password needs at least one uppercase letter, lowercase letter, number and "
		       "symbol\n");
	}
}

bool valid(string password)
{
	// upper, lower, number, symbol
	bool flags[4] = {false};
	for (int i = 0; password[i]; i++)
	{
		// Alphanumerical characters (A, a, 1)
		if (isupper(password[i]))
			flags[0] = true;
		else if (islower(password[i]))
			flags[1] = true;
		else if (isdigit(password[i]))
			flags[2] = true;
		// Non-alphanumerical character (!)
		else if (isgraph(password[i]))
			flags[3] = true;
	}
	return flags[0] && flags[1] && flags[2] && flags[3];
}
