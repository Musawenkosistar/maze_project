#include "../headers/header.h"

bool GameRunning = false;  // Flag to control the game loop
int TicksLastFrame;        // Store the time of the last frame
player_t player;           // Player structure instance

/**
 * setup_game - Initializes player variables and loads wall textures.
 *
 * This function sets the initial position and properties of the player,
 * as well as prepares the wall textures for rendering.
 */
void setup_game(void)
{
    player.x = SCREEN_WIDTH / 2;           // Start player in the center of the screen
    player.y = SCREEN_HEIGHT / 2;
    player.width = 1;                       // Player width (for collision)
    player.height = 30;                     // Player height
    player.walkDirection = 0;               // Initial walking direction (stationary)
    player.walkSpeed = 100;                  // Speed at which the player moves
    player.turnDirection = 0;                // Initial turning direction (stationary)
    player.turnSpeed = 45 * (PI / 180);     // Turning speed in radians
    player.rotationAngle = PI / 2;          // Initial facing direction (pointing upwards)
    WallTexturesready();                     // Load wall textures for rendering
}

/**
 * update_game - Updates game state including delta time, player movement,
 *               and ray casting for visibility calculations.
 *
 * This function calculates the time elapsed since the last frame,
 * manages frame rate, and updates player position and raycasting.
 */
void update_game(void)
{
    float DeltaTime;  // Time elapsed since last frame
    int timeToWait = FRAME_TIME_LENGTH - (SDL_GetTicks() - TicksLastFrame); // Frame timing

    // Delay if necessary to maintain consistent frame rate
    if (timeToWait > 0 && timeToWait <= FRAME_TIME_LENGTH)
    {
        SDL_Delay(timeToWait);
    }

    DeltaTime = (SDL_GetTicks() - TicksLastFrame) / 1000.0f; // Calculate delta time in seconds
    TicksLastFrame = SDL_GetTicks(); // Update last frame tick count

    movePlayer(DeltaTime); // Update player position based on input
    castAllRays();         // Cast rays for rendering visibility
}

/**
 * render_game - Calls rendering functions to display the game on screen.
 *
 * This function clears the screen, renders walls, the map,
 * rays, and the player, then updates the display buffer.
 */
void render_game(void)
{
    clearColorBuffer(0xFF000000); // Clear the screen with a black color

    renderWall();  // Render wall textures
    renderMap();   // Render the game map
    renderRays();  // Render rays for visibility
    renderPlayer(); // Render the player

    renderColorBuffer(); // Present the rendered frame to the screen
}

/**
 * destroy_game - Cleans up resources before exiting the game.
 *
 * This function frees wall textures and destroys the game window
 * to prevent memory leaks.
 */
void destroy_game(void)
{
    freeWallTextures(); // Free any loaded wall textures
    destroyWindow();    // Destroy the window and clean up SDL
}

/**
 * main - The entry point of the game application.
 * Return: 0 on successful execution.
 */
int main(void)
{
    GameRunning = initializeWindow(); // Initialize the game window

    setup_game(); // Set up initial game state

    // Main game loop
    while (GameRunning)
    {
        handleInput();  // Process user input
        update_game();  // Update game state
        render_game();   // Render the current game state
    }
    
    destroy_game(); // Clean up resources before exiting
    return 0;       // Exit successfully
}
