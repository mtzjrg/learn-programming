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
			bool upperRow = row - 1 >= 0;
			bool lowerRow = row + 1 <= height - 1;
			bool leftCol = col - 1 >= 0;
			bool rightCol = col + 1 <= width - 1;

			// Get totals for center row
			int redTotal = copy[row][col].rgbtRed;
			int greenTotal = copy[row][col].rgbtGreen;
			int blueTotal = copy[row][col].rgbtBlue;
			// Keep track of how many times we add to total
			float count = 1.0;
			if (leftCol)
			{
				redTotal += copy[row][col - 1].rgbtRed;
				greenTotal += copy[row][col - 1].rgbtGreen;
				blueTotal += copy[row][col - 1].rgbtBlue;
				count++;
			}
			if (rightCol)
			{
				redTotal += copy[row][col + 1].rgbtRed;
				greenTotal += copy[row][col + 1].rgbtGreen;
				blueTotal += copy[row][col + 1].rgbtBlue;
				count++;
			}

			// Get totals for upper row
			if (upperRow)
			{
				redTotal += copy[row - 1][col].rgbtRed;
				greenTotal += copy[row - 1][col].rgbtGreen;
				blueTotal += copy[row - 1][col].rgbtBlue;
				count++;
				if (leftCol)
				{
					redTotal += copy[row - 1][col - 1].rgbtRed;
					greenTotal += copy[row - 1][col - 1].rgbtGreen;
					blueTotal += copy[row - 1][col - 1].rgbtBlue;
					count++;
				}
				if (rightCol)
				{
					redTotal += copy[row - 1][col + 1].rgbtRed;
					greenTotal += copy[row - 1][col + 1].rgbtGreen;
					blueTotal += copy[row - 1][col + 1].rgbtBlue;
					count++;
				}
			}

			// Get totals for lower row
			if (lowerRow)
			{
				redTotal += copy[row + 1][col].rgbtRed;
				greenTotal += copy[row + 1][col].rgbtGreen;
				blueTotal += copy[row + 1][col].rgbtBlue;
				count++;
				if (leftCol)
				{
					redTotal += copy[row + 1][col - 1].rgbtRed;
					greenTotal += copy[row + 1][col - 1].rgbtGreen;
					blueTotal += copy[row + 1][col - 1].rgbtBlue;
					count++;
				}
				if (rightCol)
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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
	// Create copy of image
	RGBTRIPLE copy[height][width];
	for (row = 0; row < height; row++)
		for (col = 0; col < width; col++)
			copy[row][col] = image[row][col];

	for (row = 0; row < height; row++)
		for (col = 0; col < width; col++)
		{
			// Check if within bounds of image
			bool upperRow = row - 1 >= 0;
			bool lowerRow = row + 1 <= height - 1;
			bool leftCol = col - 1 >= 0;
			bool rightCol = col + 1 <= width - 1;

			// Center row
			int redGx = 0, redGy = 0;
			int greenGx = 0, greenGy = 0;
			int blueGx = 0, blueGy = 0;
			if (leftCol)
			{
				redGx += copy[row][col - 1].rgbtRed * -2;
				greenGx += copy[row][col - 1].rgbtGreen * -2;
				blueGx += copy[row][col - 1].rgbtBlue * -2;
			}
			if (rightCol)
			{
				redGx += copy[row][col + 1].rgbtRed * 2;
				greenGx += copy[row][col + 1].rgbtGreen * 2;
				blueGx += copy[row][col + 1].rgbtBlue * 2;
			}

			// Upper row
			if (upperRow)
			{
				redGy += copy[row - 1][col].rgbtRed * -2;
				greenGy += copy[row - 1][col].rgbtGreen * -2;
				blueGy += copy[row - 1][col].rgbtBlue * -2;
				if (leftCol)
				{
					redGx += copy[row - 1][col - 1].rgbtRed * -1;
					redGy += copy[row - 1][col - 1].rgbtRed * -1;
					greenGx += copy[row - 1][col - 1].rgbtGreen * -1;
					greenGy += copy[row - 1][col - 1].rgbtGreen * -1;
					blueGx += copy[row - 1][col - 1].rgbtBlue * -1;
					blueGy += copy[row - 1][col - 1].rgbtBlue * -1;
				}
				if (rightCol)
				{
					redGx += copy[row - 1][col + 1].rgbtRed;
					redGy += copy[row - 1][col + 1].rgbtRed * -1;
					greenGx += copy[row - 1][col + 1].rgbtGreen;
					greenGy += copy[row - 1][col + 1].rgbtGreen * -1;
					blueGx += copy[row - 1][col + 1].rgbtBlue;
					blueGy += copy[row - 1][col + 1].rgbtBlue * -1;
				}
			}

			// Lower row
			if (lowerRow)
			{
				redGy += copy[row + 1][col].rgbtRed * 2;
				greenGy += copy[row + 1][col].rgbtGreen * 2;
				blueGy += copy[row + 1][col].rgbtBlue * 2;
				if (leftCol)
				{
					redGx += copy[row + 1][col - 1].rgbtRed * -1;
					redGy += copy[row + 1][col - 1].rgbtRed;
					greenGx += copy[row + 1][col - 1].rgbtGreen * -1;
					greenGy += copy[row + 1][col - 1].rgbtGreen;
					blueGx += copy[row + 1][col - 1].rgbtBlue * -1;
					blueGy += copy[row + 1][col - 1].rgbtBlue;
				}
				if (rightCol)
				{
					redGx += copy[row + 1][col + 1].rgbtRed;
					redGy += copy[row + 1][col + 1].rgbtRed;
					greenGx += copy[row + 1][col + 1].rgbtGreen;
					greenGy += copy[row + 1][col + 1].rgbtGreen;
					blueGx += copy[row + 1][col + 1].rgbtBlue;
					blueGy += copy[row + 1][col + 1].rgbtBlue;
				}
			}

			// Sobel filter algorithm
			int edgeRed = round(sqrt(pow(redGx, 2.0) + pow(redGy, 2.0)));
			if (edgeRed > 255)
				edgeRed = 255;
			int edgeGreen = round(sqrt(pow(greenGx, 2.0) + pow(greenGy, 2.0)));
			if (edgeGreen > 255)
				edgeGreen = 255;
			int edgeBlue = round(sqrt(pow(blueGx, 2.0) + pow(blueGy, 2.0)));
			if (edgeBlue > 255)
				edgeBlue = 255;

			// Update pixel with edge values
			image[row][col].rgbtRed = edgeRed;
			image[row][col].rgbtGreen = edgeGreen;
			image[row][col].rgbtBlue = edgeBlue;
		}
}
