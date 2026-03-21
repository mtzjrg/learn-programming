#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 8

int main(int argc, char *argv[])
{
	// Check for command line args
	if (argc != 2)
	{
		printf("Usage: ./read infile\n");
		return 1;
	}

	// Create buffer to read into
	// Buffer now takes 8 instead of 7 to account for newline from fgets
	char buffer[SIZE];

	// Create array to store plate numbers
	char *plates[SIZE];

	// Open file and check for NULL
	FILE *infile = fopen(argv[1], "r");
	if (infile == NULL)
		return 1;

	// Use fgets instead of fread
	for (int i = 0; i < SIZE && fgets(buffer, sizeof(buffer), infile); i++)
	{
		// Allocate memory for each plate, check for NULL
		plates[i] = malloc(strlen(buffer) + 1);
		if (plates[i] == NULL)
		{
			fclose(infile);
			return 1;
		}
		// Copy string from buffer to current index
		strcpy(plates[i], buffer);
	}

	// Print and free each plate
	for (int i = 0; i < SIZE; i++)
	{
		printf("%s", plates[i]);
		free(plates[i]);
	}

	// Close file before exiting
	fclose(infile);
	return 0;
}
