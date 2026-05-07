#include <stdio.h>

int main(void)
{
	printf("Press [Enter] or [Ctrl-d]: ");
	printf("getchar != EOF: %i\n", getchar() != EOF);

	return 0;
}
