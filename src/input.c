#include "../headers/header.h"

/**
 * SDL_KEYDOWN_FUNC - Processes input when a key is pressed down.
 * @event: The SDL_Event union that contains information about the event.
 */
void SDL_KEYDOWN_FUNC(SDL_Event event)
{
    // Check for specific key presses and update player direction accordingly
    if (event.key.keysym.sym == SDLK_ESCAPE)
        GameRunning = false; // Exit the game when the Escape key is pressed
    if (event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_w)
        player.walkDirection = +1; // Move player forward
    if (event.key.keysym.sym == SDLK_DOWN || event.key.keysym.sym == SDLK_s)
        player.walkDirection = -1; // Move player backward
    if (event.key.keysym.sym == SDLK_RIGHT || event.key.keysym.sym == SDLK_d)
        player.turnDirection = +1; // Turn player right
    if (event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_a)
        player.turnDirection = -1; // Turn player left
}

/**
 * SDL_KEYUP_FUNC - Processes input when a key is released.
 * @event: The SDL_Event union that contains information about the event.
 */
void SDL_KEYUP_FUNC(SDL_Event event)
{
    // Reset player direction when the keys are released
    if (event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_w)
        player.walkDirection = 0; // Stop moving forward
    if (event.key.keysym.sym == SDLK_DOWN || event.key.keysym.sym == SDLK_s)
        player.walkDirection = 0; // Stop moving backward
    if (event.key.keysym.sym == SDLK_RIGHT || event.key.keysym.sym == SDLK_d)
        player.turnDirection = 0; // Stop turning right
    if (event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_a)
        player.turnDirection = 0; // Stop turning left
}

/**
 * handleInput - Processes keyboard input for the game.
 *
 * This function polls for events and delegates handling to
 * the appropriate key down or key up functions.
 */
void handleInput(void)
{
    SDL_Event event;

    // Poll for SDL events
    SDL_PollEvent(&event);

    // Check the type of event and handle accordingly
    if (event.type == SDL_QUIT)
        GameRunning = false; // Exit the game if the quit event is detected
    else if (event.type == SDL_KEYDOWN)
        SDL_KEYDOWN_FUNC(event); // Handle key down events
    else if (event.type == SDL_KEYUP)
        SDL_KEYUP_FUNC(event); // Handle key up events
}
