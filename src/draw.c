#include "../headers/header.h"

/**
 * drawRect - Draws a filled rectangle on the screen.
 * @x: The x coordinate of the rectangle's top-left corner.
 * @y: The y coordinate of the rectangle's top-left corner.
 * @width: The width of the rectangle in pixels.
 * @height: The height of the rectangle in pixels.
 * @color: The color of the rectangle's pixels.
 */
void drawRect(int x, int y, int width, int height, color_t color)
{
    int i, j;

    // Loop through each pixel in the specified rectangle
    for (i = x; i < (x + width); i++)
    {
        for (j = y; j < (y + height); j++)
        {
            drawPixel(i, j, color); // Set the pixel color
        }
    }
}

/**
 * drawLine - Draws a line between two points on the screen.
 * @x0: The x coordinate of the starting point.
 * @y0: The y coordinate of the starting point.
 * @x1: The x coordinate of the ending point.
 * @y1: The y coordinate of the ending point.
 * @color: The color of the line's pixels.
 */
void drawLine(int x0, int y0, int x1, int y1, color_t color)
{
    float xIncrement, yIncrement, currentX, currentY;
    int i, longestSideLength, deltaX, deltaY;

    // Calculate differences and lengths
    deltaX = x1 - x0;
    deltaY = y1 - y0;
    longestSideLength = (abs(deltaX) >= abs(deltaY)) ? abs(deltaX) : abs(deltaY);

    // Calculate the increment values for each axis
    xIncrement = deltaX / (float)longestSideLength;
    yIncrement = deltaY / (float)longestSideLength;

    // Initialize current position
    currentX = x0;
    currentY = y0;

    // Draw the line pixel by pixel
    for (i = 0; i <= longestSideLength; i++)
    {
        drawPixel(round(currentX), round(currentY), color); // Set the pixel color
        currentX += xIncrement; // Move to the next pixel in x direction
        currentY += yIncrement; // Move to the next pixel in y direction
    }
}
