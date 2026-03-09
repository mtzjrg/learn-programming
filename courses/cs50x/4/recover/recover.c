#include <cs50.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define DATA_BLOCK 512

int recover_jpgs(FILE *card);
FILE *create_jpg(int jpg_count);

int main(int argc, char *argv[])
{
	// Accept a single command-line argument
	if (argc != 2)
	{
		puts("Usage: ./recover FILE");
		return 1;
	}

	// Open the memory card
	FILE *card = fopen(argv[1], "r");
	if (card == NULL)
	{
		perror("fopen");
		return 1;
	}

	int result = recover_jpgs(card);
	fclose(card);
	return result;
}

int recover_jpgs(FILE *card)
{
	// Create a buffer for a block of data
	uint8_t buffer[DATA_BLOCK];
	FILE *img = NULL;
	int count = 0;

	// While there's still data left to read from the memory card
	while (fread(buffer, 1, DATA_BLOCK, card) == DATA_BLOCK)
	{
		// Check for jpg header
		bool is_jpg = buffer[0] == 0xFF && buffer[1] == 0xD8 && buffer[2] == 0xFF &&
		              (buffer[3] & 0xF0) == 0xE0;
		// Create JPEGs from the data
		if (is_jpg)
		{
			if (img != NULL)
				fclose(img);
			img = create_jpg(count++);
			if (img == NULL)
			{
				perror("fopen");
				return 1;
			}
		}

		if (img != NULL)
			fwrite(buffer, 1, DATA_BLOCK, img);
	}

	if (img != NULL)
		fclose(img);
	return 0;
}

FILE *create_jpg(int count)
{
	char filename[8];
	sprintf(filename, "%03i.jpg", count);
	return fopen(filename, "w");
}
