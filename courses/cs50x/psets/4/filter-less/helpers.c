#include "helpers.h"
#include <cs50.h>
#include <math.h>

int row, col;

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
	for (row = 0; row < height; row++)
		for (col = 0; col < width; col++)
		{
			float avg =
				(image[row][col].rgbtRed + image[row][col].rgbtGreen + image[row][col].rgbtBlue) /
				3.0;
			int gray = round(avg);
			image[row][col].rgbtRed = gray;
			image[row][col].rgbtGreen = gray;
			image[row][col].rgbtBlue = gray;
		}
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
	for (row = 0; row < height; row++)
		for (col = 0; col < width; col++)
		{
			float sepiaRed = .393 * image[row][col].rgbtRed + .769 * image[row][col].rgbtGreen +
			                 .189 * image[row][col].rgbtBlue;
			if (sepiaRed > 255)
				sepiaRed = 255;
			float sepiaGreen = .349 * image[row][col].rgbtRed + .686 * image[row][col].rgbtGreen +
			                   .168 * image[row][col].rgbtBlue;
			if (sepiaGreen > 255)
				sepiaGreen = 255;
			float sepiaBlue = .272 * image[row][col].rgbtRed + .534 * image[row][col].rgbtGreen +
			                  .131 * image[row][col].rgbtBlue;
			if (sepiaBlue > 255)
				sepiaBlue = 255;

			image[row][col].rgbtRed = round(sepiaRed);
			image[row][col].rgbtGreen = round(sepiaGreen);
			image[row][col].rgbtBlue = round(sepiaBlue);
		}
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
	for (row = 0; row < height; row++)
		for (int left = 0, right = width - 1; left < right; left++, right--)
		{
			RGBTRIPLE tmp = image[row][left];
			image[row][left] = image[row][right];
			image[row][right] = tmp;
		}
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
	// Create a copy of image
	RGBTRIPLE copy[height][width];
	for (row = 0; row < height; row++)
		for (col = 0; col < width; col++)
			copy[row][col] = image[row][col];

	for (row = 0; row < height; row++)
		for (col = 0; col < width; col++)
		{
			// Check if within bounds of image
			bool upper_row = row - 1 >= 0;
			bool lower_row = row + 1 <= height - 1;
			bool left_col = col - 1 >= 0;
			bool right_col = col + 1 <= width - 1;

			// Get totals for center row
			int redTotal = copy[row][col].rgbtRed;
			int greenTotal = copy[row][col].rgbtGreen;
			int blueTotal = copy[row][col].rgbtBlue;
			// Keep track of how many times we add to total
			float count = 1.0;
			if (left_col)
			{
				redTotal += copy[row][col - 1].rgbtRed;
				greenTotal += copy[row][col - 1].rgbtGreen;
				blueTotal += copy[row][col - 1].rgbtBlue;
				count++;
			}
			if (right_col)
			{
				redTotal += copy[row][col + 1].rgbtRed;
				greenTotal += copy[row][col + 1].rgbtGreen;
				blueTotal += copy[row][col + 1].rgbtBlue;
				count++;
			}

			// Get totals for upper row
			if (upper_row)
			{
				redTotal += copy[row - 1][col].rgbtRed;
				greenTotal += copy[row - 1][col].rgbtGreen;
				blueTotal += copy[row - 1][col].rgbtBlue;
				count++;
				if (left_col)
				{
					redTotal += copy[row - 1][col - 1].rgbtRed;
					greenTotal += copy[row - 1][col - 1].rgbtGreen;
					blueTotal += copy[row - 1][col - 1].rgbtBlue;
					count++;
				}
				if (right_col)
				{
					redTotal += copy[row - 1][col + 1].rgbtRed;
					greenTotal += copy[row - 1][col + 1].rgbtGreen;
					blueTotal += copy[row - 1][col + 1].rgbtBlue;
					count++;
				}
			}

			// Get totals for lower row
			if (lower_row)
			{
				redTotal += copy[row + 1][col].rgbtRed;
				greenTotal += copy[row + 1][col].rgbtGreen;
				blueTotal += copy[row + 1][col].rgbtBlue;
				count++;
				if (left_col)
				{
					redTotal += copy[row + 1][col - 1].rgbtRed;
					greenTotal += copy[row + 1][col - 1].rgbtGreen;
					blueTotal += copy[row + 1][col - 1].rgbtBlue;
					count++;
				}
				if (right_col)
				{
					redTotal += copy[row + 1][col + 1].rgbtRed;
					greenTotal += copy[row + 1][col + 1].rgbtGreen;
					blueTotal += copy[row + 1][col + 1].rgbtBlue;
					count++;
				}
			}

			// Update original image with rounded color avgs
			image[row][col].rgbtRed = round(redTotal / count);
			image[row][col].rgbtGreen = round(greenTotal / count);
			image[row][col].rgbtBlue = round(blueTotal / count);
		}
}
