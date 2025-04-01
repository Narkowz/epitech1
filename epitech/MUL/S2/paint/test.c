#include <SFML/Graphics.h>

int main() {
    // Create a window
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow* window = sfRenderWindow_create(mode, "SFML Window", sfDefaultStyle, NULL);

    // Create a texture to store the content of the window
    sfTexture* texture = sfTexture_create(800, 600);

    // Create a sprite to display the texture
    sfSprite* sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);

    // Main loop
    while (sfRenderWindow_isOpen(window)) {
        // Process events
        sfEvent event;
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
        }

        // Draw something on the window (for example, a red rectangle)
        sfRenderWindow_clear(window, sfBlack);
        sfRectangleShape* rectangle = sfRectangleShape_create();
        sfRectangleShape_setSize(rectangle, (sfVector2f){100, 100});
        sfRectangleShape_setFillColor(rectangle, sfRed);
        sfRenderWindow_drawRectangleShape(window, rectangle, NULL);
        sfRenderWindow_display(window);

        // Update the texture with the contents of the window
        sfTexture_updateFromRenderWindow(texture, window, 0, 0);

        // Save the contents of the window as an image
        sfImage* image = sfTexture_copyToImage(texture);
        sfImage_saveToFile(image, "screenshot.png");
        sfImage_destroy(image);
    }

    // Cleanup
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    sfRenderWindow_destroy(window);

    return 0;
}
