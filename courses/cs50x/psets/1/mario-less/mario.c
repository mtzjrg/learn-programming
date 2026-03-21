#include <cs50.h>
#include <stdio.h>

int get_height(void);
void print_row(int height, int spaces);

int main(void)
{
	int height = get_height();
	for (int i = 0; i < height; i++)
		print_row(height, height - i - 1);
	return 0;
}

int get_height(void)
{
	const int MIN_HEIGHT = 1;
	int h = 0;

	while (h < MIN_HEIGHT)
		h = get_int("Height: ");
	return h;
}

void print_row(int h, int s)
{
	for (int i = 0; i < h; i++)
	{
		if (i >= s)
			printf("#");
		else
			printf(" ");
	}
	printf("\n");
}
