#include <SFML/Graphics.h>

int main()
{
    // Create a window
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow* window = sfRenderWindow_create(mode, "Pixel Drawing Example", sfClose, NULL);

    // Create a texture and sprite
    sfTexture* texture = sfTexture_create(800, 600);
    sfSprite* sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);

    // Create a pixel array
    sfUint8* pixels = (sfUint8*)malloc(800 * 600 * 4); // Each pixel has 4 components (RGBA)

    // Clear the pixel array to white
    for (int i = 0; i < 800 * 600 * 4; ++i)
    {
        pixels[i] = 255;
    }

    // Update the texture with the initial pixel data
    sfTexture_updateFromPixels(texture, pixels, 800, 600, 0, 0);

    // Variable to keep track of whether the left mouse button is currently pressed
    sfBool isMousePressed = sfFalse;

    // Size of the drawn pixels
    int pixelSize = 1;

    // Main loop
    while (sfRenderWindow_isOpen(window))
    {
        // Handle events
        sfEvent event;
        while (sfRenderWindow_pollEvent(window, &event))
        {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);

            // Handle mouse press event
            if (event.type == sfEvtMouseButtonPressed && event.mouseButton.button == sfMouseLeft)
            {
                isMousePressed = sfTrue;
            }

            // Handle mouse release event
            if (event.type == sfEvtMouseButtonReleased && event.mouseButton.button == sfMouseLeft)
            {
                isMousePressed = sfFalse;
            }

            // Handle size modification using the mouse wheel
            if (event.type == sfEvtMouseWheelScrolled)
            {
                pixelSize += event.mouseWheelScroll.delta;
                if (pixelSize < 1)
                    pixelSize = 1;
            }

            // Draw when the mouse is pressed and the mouse is moved
            if (isMousePressed && event.type == sfEvtMouseMoved)
            {
                int mouseX = event.mouseMove.x;
                int mouseY = event.mouseMove.y;

                // Update pixels in a square around the mouse position based on pixelSize
                for (int y = mouseY - pixelSize / 2; y < mouseY + pixelSize / 2; ++y)
                {
                    for (int x = mouseX - pixelSize / 2; x < mouseX + pixelSize / 2; ++x)
                    {
                        // Check boundaries
                        if (x >= 0 && x < 800 && y >= 0 && y < 600)
                        {
                            // Set the color of the pixel to black
                            int index = (y * 800 + x) * 4;
                            pixels[index] = 0;     // Red component
                            pixels[index + 1] = 255; // Green component
                            pixels[index + 2] = 0; // Blue component
                            pixels[index + 3] = 255; // Alpha component (transparency)
                        }
                    }
                }

                // Update the texture with the modified pixel data
                sfTexture_updateFromPixels(texture, pixels, 800, 600, 0, 0);
            }
        }

        // Clear the window
        sfRenderWindow_clear(window, sfWhite);

        // Draw the sprite
        sfRenderWindow_drawSprite(window, sprite, NULL);

        // Display the contents of the window
        sfRenderWindow_display(window);
    }

    // Clean up resources
    sfRenderWindow_destroy(window);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
    free(pixels);

    return 0;
}
