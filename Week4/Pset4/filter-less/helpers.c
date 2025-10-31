#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) // indexing through height of image.
    {
        for (int j = 0; j < width; j++) // indexing through width of image.
        {
            int average_rgb =
                round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) /
                      3.0); // find average by adding original rgb divided by 3. Using .0 to not
                            // truncate the value. Do this with round() function. To use this
                            // function we need math.h. Must add first then divide by 3.
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue =
                average_rgb; // update rgb values
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed, sepiaGreen, sepiaBlue;

    // loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Compute sepia values
            sepiaRed = 0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen +
                       0.189 * image[i][j].rgbtBlue;
            sepiaGreen = 0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen +
                         0.168 * image[i][j].rgbtBlue;
            sepiaBlue = 0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen +
                        0.131 * image[i][j].rgbtBlue;

            // Keeps maximum at 255.
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            // update pixel with sepia values
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++) // we divide by 2
        {
            // swap the pixels with a temp variable
            // [width - j]
            {
                temp = image[i][j];
                image[i][j] = image[i][width - j];
                image[i][width - j] = temp;
            }
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of the image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float sum_red = 0, sum_green = 0, sum_blue = 0, sum_pixels = 0;
            for (int updated_i = i - 1; updated_i < i + 2; updated_i++)
            {
                for (int updated_j = j - 1; updated_j < j + 2; updated_j++)
                {
                    if (updated_i > 0 && updated_j > 0 && updated_i < height && updated_j < width)
                    {
                        sum_red += image[updated_i][updated_j].rgbtRed;
                        sum_green += image[updated_i][updated_j].rgbtGreen;
                        sum_blue += image[updated_i][updated_j].rgbtBlue;
                        sum_pixels++;
                    }
                }
            }
            copy[i][j].rgbtRed = round(sum_red / sum_pixels);
            copy[i][j].rgbtGreen = round(sum_green / sum_pixels);
            copy[i][j].rgbtBlue = round(sum_blue / sum_pixels);
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = copy[i][j];
        }
    }
    return;
}
