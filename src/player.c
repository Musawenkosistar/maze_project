#include "../headers/header.h"

/**
 * movePlayer - Updates the player's position based on input and time elapsed.
 * @DeltaTime: Time elapsed since the last frame, used to calculate movement.
 *
 * This function adjusts the player's rotation angle and calculates the new 
 * position based on the walking direction and speed. If the new position 
 * does not result in a collision, the player's coordinates are updated.
 */
void movePlayer(float DeltaTime)
{
    float moveStep, newPlayerX, newPlayerY;

    // Update the player's rotation based on input
    player.rotationAngle += player.turnDirection * player.turnSpeed * DeltaTime;

    // Calculate the distance to move based on walking direction and speed
    moveStep = player.walkDirection * player.walkSpeed * DeltaTime;

    // Calculate the new position based on the current rotation angle
    newPlayerX = player.x + cos(player.rotationAngle) * moveStep;
    newPlayerY = player.y + sin(player.rotationAngle) * moveStep;

    // Update player's position if there is no collision at the new coordinates
    if (!DetectCollision(newPlayerX, newPlayerY))
    {
        player.x = newPlayerX;
        player.y = newPlayerY;
    }
}

/**
 * renderPlayer - Renders the player on the minimap.
 *
 * This function draws the player's current position as a rectangle 
 * on the minimap, using the player's dimensions and a predefined color.
 */
void renderPlayer(void)
{
    drawRect(
        player.x * MINIMAP_SCALE_FACTOR,  // X coordinate scaled for minimap
        player.y * MINIMAP_SCALE_FACTOR,  // Y coordinate scaled for minimap
        player.width * MINIMAP_SCALE_FACTOR,  // Width scaled for minimap
        player.height * MINIMAP_SCALE_FACTOR, // Height scaled for minimap
        0xFFFFFFFF  // Color (white)
    );
}
