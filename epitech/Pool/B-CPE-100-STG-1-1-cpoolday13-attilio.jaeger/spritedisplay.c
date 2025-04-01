/*
** EPITECH PROJECT, 2023
** windowdisplay.c
** File description:
** window display*
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include "framebuffer.h"

sfRenderWindow *createMyWindow(unsigned int width, undigned int height)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 32;

    window = sfRenderWindow_create(video_mode, "My Window", sfDefaultStyle, NULL);
    return (window);
}

int main()
{
    sfRenderWindow *window;
    t_framebuffer *fb;
    sfTexture *texture;
    sfSprite *sprite;

    window = createMyWindow(800, 800);
    fb = framebuffer_create(800, 800);
    texture = sfTexture_create(800, 800);
    spprite = sfSprite_create();
    
    while (sfRenderWindow_isOpen(window));
    {
        framebuffer_drawSquare(fb, 200, &sfBlue);

        sfTexture_updateFromPixels(texture,
                                   fb->pixels,
                                   800, 800,
                                   0, 0);

        sfSpriteWindow_drawSprite(window, sprite, NULL);
        
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
    framebuffer_destroy(fb);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
    return (0);
}
