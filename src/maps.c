#include "../headers/header.h"

// Static 2D array representing the game map
static const int map[MAP_NUM_ROWS][MAP_NUM_COLS] = {
    {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6},
    {6, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 6},
    {6, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 6, 0, 0, 0, 6, 0, 0, 0, 6},
    {6, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 6, 0, 7, 7, 0, 0, 0, 0, 6},
    {6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 7, 0, 6},
    {6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 6},
    {6, 0, 0, 0, 0, 0, 7, 7, 7, 0, 0, 1, 0, 0, 0, 0, 7, 7, 0, 6},
    {6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6},
    {6, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 1, 0, 6},
    {6, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 7, 0, 0, 0, 0, 1, 0, 6},
    {6, 0, 0, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6},
    {6, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6},
    {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6}
};

/**
 * DetectCollision - Checks for potential collisions with walls
 * during the player's movement.
 * @x: Next x-coordinate of the player.
 * @y: Next y-coordinate of the player.
 * 
 * Return: true if a collision is detected, false otherwise.
 */
bool DetectCollision(float x, float y)
{
    int mapGridX, mapGridY;

    // Check if the next position is outside the map boundaries
    if (x < 0 || x >= MAP_NUM_COLS * TILE_SIZE || 
        y < 0 || y >= MAP_NUM_ROWS * TILE_SIZE)
        return true; // Collision with the map boundary

    // Calculate the grid indices based on tile size
    mapGridX = floor(x / TILE_SIZE);
    mapGridY = floor(y / TILE_SIZE);

    // Return true if the grid cell contains a wall (non-zero value)
    return (map[mapGridY][mapGridX] != 0);
}

/**
 * isInsideMap - Checks if the coordinates are within the map boundaries.
 * @x: x-coordinate to check.
 * @y: y-coordinate to check.
 * 
 * Return: true if the coordinates are inside the map, false otherwise.
 */
bool isInsideMap(float x, float y)
{
    return (x >= 0 && x <= MAP_NUM_COLS * TILE_SIZE &&
            y >= 0 && y <= MAP_NUM_ROWS * TILE_SIZE);
}

/**
 * getMapValue - Retrieves the value at a specific position in the map.
 * @row: Row index of the map.
 * @col: Column index of the map.
 * 
 * Return: The value at the specified row and column in the map.
 */
int getMapValue(int row, int col)
{
    return (map[row][col]);
}

/**
 * renderMap - Renders the map on the screen using colored tiles.
 *
 * Each tile is drawn based on its value in the map array,
 * with walls rendered in white and empty spaces in black.
 */
void renderMap(void)
{
    int i, j, tileX, tileY;
    color_t tileColor;

    // Iterate over each tile in the map
    for (i = 0; i < MAP_NUM_ROWS; i++)
    {
        for (j = 0; j < MAP_NUM_COLS; j++)
        {
            tileX = j * TILE_SIZE; // Calculate x position of the tile
            tileY = i * TILE_SIZE; // Calculate y position of the tile

            // Determine the color based on whether the tile is a wall or empty space
            tileColor = map[i][j] != 0 ? 0xFFFFFFFF : 0x00000000;

            // Draw the tile on the minimap
            drawRect(
                tileX * MINIMAP_SCALE_FACTOR,
                tileY * MINIMAP_SCALE_FACTOR,
                TILE_SIZE * MINIMAP_SCALE_FACTOR,
                TILE_SIZE * MINIMAP_SCALE_FACTOR,
                tileColor
            );
        }
    }
}
