#ifndef HEADER_H
#define HEADER_H

#include <SDL2/SDL.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdio.h>
#include <stdbool.h>
#include "upng.h"

/* Constants */

// Mathematical constants
#define PI 3.14159265f      // Value of Pi
#define TWO_PI 6.28318530f  // Value of 2 * Pi

// Game settings
#define TILE_SIZE 64                // Size of each tile in pixels
#define MINIMAP_SCALE_FACTOR 0.25f  // Scale factor for the minimap

// Screen dimensions based on the map size
#define SCREEN_WIDTH (MAP_NUM_COLS * TILE_SIZE)
#define SCREEN_HEIGHT (MAP_NUM_ROWS * TILE_SIZE)

// Field of View settings
#define FOV_ANGLE (60 * (PI / 180)) // Field of view angle in radians

// Raycasting settings
#define NUM_RAYS SCREEN_WIDTH            // Number of rays to cast
#define PROJ_PLANE ((SCREEN_WIDTH / 2) / tan(FOV_ANGLE / 2)) // Projection plane distance

// Frame settings
#define FPS 30                       // Frames per second
#define FRAME_TIME_LENGTH (1000 / FPS) // Frame time in milliseconds

// Map dimensions
#define MAP_NUM_ROWS 13 // Number of rows in the map
#define MAP_NUM_COLS 20 // Number of columns in the map

// Texture settings
#define NUM_TEXTURES 8 // Number of textures used in the game

// Color type definition
typedef uint32_t color_t;

/* Input Handling */

// Function to process user input
void handleInput(void);
extern bool isGameRunning; // Flag indicating if the game is currently running

/* Rendering Functions */

// Initializes the game window
bool initializeWindow(void);

// Cleans up and destroys the game window
void destroyWindow(void);

// Clears the color buffer with a specified color
void clearColorBuffer(color_t color);

// Renders the game scene
void renderGame(void);

// Displays the contents of the color buffer on the screen
void renderColorBuffer(void);

// Draws a single pixel at specified coordinates with a given color
void drawPixel(int x, int y, color_t color);

// Draws a rectangle at specified coordinates with a given width, height, and color
void drawRect(int x, int y, int width, int height, color_t color);

// Draws a line between two points with a specified color
void drawLine(int x0, int y0, int x1, int y1, color_t color);

/* Map Functions */

// Checks for collision with walls at specified coordinates
bool detectCollision(float x, float y);

// Verifies if the given coordinates are within the bounds of the map
bool isInsideMap(float x, float y);

// Renders the game map
void renderMap(void);

// Retrieves the value of a specific cell in the map
int getMapValue(int row, int col);

/* Player Structure and Functions */

// Struct representing the player character
typedef struct {
    float x;               // X coordinate of the player
    float y;               // Y coordinate of the player
    float width;           // Width of the player
    float height;          // Height of the player
    int turnDirection;     // Direction for turning (left/right)
    int walkDirection;     // Direction for walking (forward/backward)
    float rotationAngle;   // Current rotation angle of the player
    float walkSpeed;       // Speed of walking
    float turnSpeed;       // Speed of turning
} Player;

extern Player player; // Global instance of the player

// Moves the player based on input and time elapsed
void movePlayer(float deltaTime);

// Renders the player character on the screen
void renderPlayer(void);

/* Ray Structure and Functions */

// Struct representing a ray for raycasting
typedef struct {
    float rayAngle;        // Angle of the ray
    float wallHitX;       // X coordinate of the wall hit
    float wallHitY;       // Y coordinate of the wall hit
    float distance;       // Distance from the player to the wall
    bool wasHitVertical;  // Indicates if the ray hit a vertical wall
    int wallHitContent;   // Identifier for the wall hit content
} Ray;

extern Ray rays[NUM_RAYS]; // Array of rays used for rendering

// Calculates the distance between two points
float distanceBetweenPoints(float x1, float y1, float x2, float y2);

// Determines if the ray is facing up
bool isRayFacingUp(float angle);

// Determines if the ray is facing down
bool isRayFacingDown(float angle);

// Determines if the ray is facing left
bool isRayFacingLeft(float angle);

// Determines if the ray is facing right
bool isRayFacingRight(float angle);

// Casts rays in all directions
void castAllRays(void);

// Casts a single ray at a specified angle and strip ID
void castRay(float rayAngle, int stripId);

// Renders the rays on the screen
void renderRays(void);

// Calculates the intersection of horizontal rays
void horizontalIntersection(float rayAngle);

// Calculates the intersection of vertical rays
void verticalIntersection(float rayAngle);

/* Texture Structure and Functions */

// Struct representing a texture for wall rendering
typedef struct {
    int width;          // Width of the texture
    int height;         // Height of the texture
    color_t *textureBuffer; // Pointer to the texture data
    upng_t *upngTexture;    // Pointer to the UPNG texture data
} Texture;

Texture wallTextures[NUM_TEXTURES]; // Array of wall textures

// Loads wall textures from files
void loadWallTextures(void);

// Frees memory associated with wall textures
void freeWallTextures(void);

/* Wall Rendering Functions */

// Renders walls based on raycasted data
void renderWall(void);

#endif /* HEADER_H */

