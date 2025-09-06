#include "helpers.h"
#include <math.h>

// Convert image to grayscale/////////////////////////
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            BYTE avg =
                round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
        }
    }

    return;
}

// Reflect image horizontally/////////////////////////
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE Temp;
    int halfImage = (width / 2);

    // swaping pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < halfImage; j++)
        {
            Temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = Temp;
        }
    }
    return;
}

// Blur image/////////////////////////
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    BYTE avgBlue;
    BYTE avgGreen;
    BYTE avgRed;
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumBlue = 0;
            int sumGreen = 0;
            int sumRed = 0;
            int count = 0;

            // Looping in 3x3
            for (int i2 = -1; i2 <= 1; i2++)
            {
                for (int j2 = -1; j2 <= 1; j2++)
                {
                    int i3 = i + i2;
                    int j3 = j + j2;

                    // Skip if outside the image
                    if (i3 < 0 || i3 >= height || j3 < 0 || j3 >= width)
                        continue;

                    sumBlue += image[i3][j3].rgbtBlue;
                    sumGreen += image[i3][j3].rgbtGreen;
                    sumRed += image[i3][j3].rgbtRed;
                    count++;
                }
            }
            avgBlue = round((double) sumBlue / count);
            avgGreen = round((double) sumGreen / count);
            avgRed = round((double) sumRed / count);

            // Store blurred image in temp
            temp[i][j].rgbtBlue = avgBlue;
            temp[i][j].rgbtGreen = avgGreen;
            temp[i][j].rgbtRed = avgRed;
        }
    }
    // override the original array with temp
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
    return;
}
// Detect edges/////////////////////////
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            int GxBlueCount = 0;
            int GxGreenCount = 0;
            int GxRedCount = 0;
            int GyBlueCount = 0;
            int GyGreenCount = 0;
            int GyRedCount = 0;

            // Looping in 3x3
            for (int i2 = -1; i2 <= 1; i2++)
            {
                for (int j2 = -1; j2 <= 1; j2++)
                {
                    int i3 = i + i2;
                    int j3 = j + j2;
                    int Gx = j2, Gy = i2;

                    // if outside the image set color = black, not adding anything
                    if (i3 < 0 || i3 >= height || j3 < 0 || j3 >= width)
                        continue;

                    // applying Gx & Gy
                    if (i2 == 0)
                        Gx = j2 * 2;
                    GxBlueCount += image[i3][j3].rgbtBlue * Gx;
                    GxGreenCount += image[i3][j3].rgbtGreen * Gx;
                    GxRedCount += image[i3][j3].rgbtRed * Gx;
                    if (j2 == 0)
                        Gy = i2 * 2;
                    GyBlueCount += image[i3][j3].rgbtBlue * Gy;
                    GyGreenCount += image[i3][j3].rgbtGreen * Gy;
                    GyRedCount += image[i3][j3].rgbtRed * Gy;
                }
            }

            // calc edge strenght
            int EdgeStrengthBlue =
                round(sqrt(GxBlueCount * GxBlueCount + GyBlueCount * GyBlueCount));
            int EdgeStrengthGreen =
                round(sqrt(GxGreenCount * GxGreenCount + GyGreenCount * GyGreenCount));
            int EdgeStrengthRed =
                round(sqrt(GxRedCount * GxRedCount + GyRedCount * GyRedCount));

            // ensuring no value exceeds the max 255
            if (EdgeStrengthBlue > 255)
                EdgeStrengthBlue = 255;
            if (EdgeStrengthGreen > 255)
                EdgeStrengthGreen = 255;
            if (EdgeStrengthRed > 255)
                EdgeStrengthRed = 255;

            // saving in temp
            temp[i][j].rgbtBlue = EdgeStrengthBlue;
            temp[i][j].rgbtGreen = EdgeStrengthGreen;
            temp[i][j].rgbtRed = EdgeStrengthRed;
        }
    }

    // override the original array with temp
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
    return;
}
