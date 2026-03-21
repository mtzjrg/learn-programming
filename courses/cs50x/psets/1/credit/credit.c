#include <cs50.h>
#include <stdio.h>

int count_digits(long card_number);
bool checksum(long card_number);
string identify_card(long card_number, int digits);

int main(void)
{
	string card_type = "INVALID";
	long card_number = get_long("Number: ");

	int digits = count_digits(card_number);
	if (digits == 13 || digits == 15 || digits == 16)
		if (checksum(card_number))
			card_type = identify_card(card_number, digits);

	puts(card_type);
	return 0;
}

int count_digits(long c)
{
	int n = 0;
	for (int i = 0; i < c; c /= 10)
		n++;
	return n;
}

bool checksum(long c)
{
	int even_sums = 0, odd_sums = 0;
	for (int i = 0, idx = 0; i < c; c /= 10, idx++)
	{
		int n = c % 10;
		if ((idx % 2) != 0)
		{
			n *= 2;
			if (n > 9)
			{
				int tmp = (n % 10) + 1;
				odd_sums += tmp;
			}
			else
				odd_sums += n;
		}
		else
			even_sums += n;
	}

	int checksum = (even_sums + odd_sums) % 10;
	if (checksum == 0)
		return true;
	return false;
}

string identify_card(long c, int d)
{
	int id1, id2;
	for (int i = 0, j = d; i < c; c /= 10, j--)
	{
		if (j == 2)
			id2 = c % 10;
		else if (j == 1)
			id1 = c % 10;
	}

	string bank = "INVALID";
	switch (d)
	{
		case 13:
			if (id1 == 4)
				bank = "VISA";
			break;
		case 15:
			if (id1 == 3 && (id2 == 4 || id2 == 7))
				bank = "AMEX";
			break;
		case 16:
			if (id1 == 4)
				bank = "VISA";
			else if (id1 == 5)
				if (id2 > 0 && id2 < 6)
					bank = "MASTERCARD";
			break;
	}

	return bank;
}
