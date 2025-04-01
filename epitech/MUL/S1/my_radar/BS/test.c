#include <SFML/Graphics.h>
#include <math.h>

int main() {
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow* window = sfRenderWindow_create(mode, "Rainbow Effect", sfDefaultStyle, NULL);

    sfRectangleShape* rectangle = sfRectangleShape_create();
    sfVector2f size = {800.f, 600.f};
    sfRectangleShape_setSize(rectangle, size);

    sfClock* clock = sfClock_create();
    sfTime elapsed;
    float hue = 0.0f;
    float saturation = 1.0f;
    float value = 1.0f;

    while (sfRenderWindow_isOpen(window)) {
        sfEvent event;
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }

        elapsed = sfClock_getElapsedTime(clock);
        float time = sfTime_asSeconds(elapsed);
        printf("time : %f\n", time);

        // Update hue value to create rainbow effect
        hue = fmodf(time * 5000, 360); // Adjust speed by changing the multiplier

        // Convert HSV to RGB
        sfColor color;
        color = sfColor_fromRGB((sfUint16)hue, (sfUint8)(saturation * 255), (sfUint8)(value * 255));

        // Set the color to the rectangle
        sfRectangleShape_setFillColor(rectangle, color);

        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawRectangleShape(window, rectangle, NULL);
        sfRenderWindow_display(window);
    }

    sfRectangleShape_destroy(rectangle);
    sfRenderWindow_destroy(window);
    sfClock_destroy(clock);

    return 0;
}
