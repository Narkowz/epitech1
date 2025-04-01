/*
** EPITECH PROJECT, 2024
** create_screenshot.c
** File description:
** create_screenshot
*/

#include "../include/my_paint.h"

void create_screenshot(global_t *glob)
{
    sfTexture *text = sfTexture_create(1920, 1080);
    sfImage *screen;

    sfTexture_updateFromRenderWindow(text, glob->window, 0, 150);
    screen = sfTexture_copyToImage(glob->screen);
    if (glob->filename != NULL) {
        if (my_strncmp(".jpg", glob->filename, 4,
            my_strlen(glob->filename) - 4) != 4) {
            add_word_to_string(glob->filename, ".jpg", &glob->filename, NULL);
            }
    } else
        glob->filename = my_strdup("Screenshot.jpg");
    sfImage_saveToFile(screen, glob->filename);
    sfImage_destroy(screen);
    sfTexture_destroy(text);
    return;
}
