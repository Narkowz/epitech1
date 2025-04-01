/*
** EPITECH PROJECT, 2024
** tool_functions.c
** File description:
** tool_functions
*/

#include "../include/my_paint.h"

static void init_pixels(int x, int y, int index, global_t *glob)
{
    if (x >= 0 && x < 1920 && y >= 150 && y < 1080) {
        index = (y * 1920 + x) * 4;
        glob->pixels[index] = 0;
        glob->pixels[index + 1] = 0;
        glob->pixels[index + 2] = 0;
        glob->pixels[index + 3] = 255;
    }
}

void square_function(global_t *glob, sfVector2i m)
{
    int index;

    for (int y = m.y - glob->pixel_size / 2; y < m.y +
        glob->pixel_size / 2; y++) {
        for (int x = m.x - glob->pixel_size / 2; x < m.x +
            glob->pixel_size / 2; x++) {
            init_pixels(x, y, index, glob);
        }
    }
}

void circle_function(global_t *glob, sfVector2i m, int y, int index)
{
    int radius = glob->pixel_size / 2;

    for (int x = m.x - radius; x < m.x + radius; x++)
        if ((x - m.x) * (x - m.x) + (y - m.y) * (y - m.y) < radius * radius)
            init_pixels(x, y, index, glob);
}

void init_function(global_t *glob)
{
    sfVector2i m = sfMouse_getPositionRenderWindow(glob->window);
    int index;
    int radius = glob->pixel_size / 2;

    if (glob->state->square)
        square_function(glob, m);
    if (glob->state->circle) {
        for (int y = m.y - radius; y < m.y + radius; y++)
            circle_function(glob, m, y, index);
    }
    sfTexture_updateFromPixels(glob->screen, glob->pixels, 1920, 1080, 0, 0);
}

static void init_pixels_eraser(int x, int y, int index, global_t *glob)
{
    if (x >= 0 && x < 1920 && y >= 150 && y < 1080) {
        index = (y * 1920 + x) * 4;
        glob->pixels[index] = 255;
        glob->pixels[index + 1] = 255;
        glob->pixels[index + 2] = 255;
        glob->pixels[index + 3] = 255;
    }
}

void circle_function_eraser(global_t *glob, sfVector2i m, int y, int index)
{
    int radius = glob->pixel_size / 2;

    for (int x = m.x - radius; x < m.x + radius; x++)
        if ((x - m.x) * (x - m.x) + (y - m.y) * (y - m.y) < radius * radius)
            init_pixels_eraser(x, y, index, glob);
}

static void eraser_square(global_t *glob, sfVector2i m)
{
    int index;

    for (int y = m.y - glob->pixel_size / 2; y < m.y +
        glob->pixel_size / 2; y++) {
        for (int x = m.x - glob->pixel_size / 2; x < m.x +
            glob->pixel_size / 2; x++) {
            init_pixels_eraser(x, y, index, glob);
        }
    }
}

void eraser_function(global_t *glob)
{
    sfVector2i m = sfMouse_getPositionRenderWindow(glob->window);
    int index;
    int radius = glob->pixel_size / 2;

    if (glob->state->square)
        eraser_square(glob, m);
    if (glob->state->circle) {
        for (int y = m.y - radius; y < m.y + radius; y++)
            circle_function_eraser(glob, m, y, index);
    }
    sfTexture_updateFromPixels(glob->screen, glob->pixels, 1920, 1080, 0, 0);
}
