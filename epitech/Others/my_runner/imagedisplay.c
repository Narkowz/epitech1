/*
** EPITECH PROJECT, 2018
** display_an_image
** File description:
** 
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Rect.h>

int main()
{
    sfVideoMode mode = {1920, 1000, 64};
    sfRenderWindow *window;
    sfTexture *background;
    sfTexture *runner;
    //sfTexture *spike;
    sfTexture *run;
    sfSprite *sprite;
    sfSprite *sprite_runner;
    //sfSprite *sprite_spike;
    sfSprite *sprite_run;
    sfEvent event;
    sfVector2f move_forward = {5,0};
    sfVector2f move_backward = {-5,0};
    sfVector2f jump = {0,-5};
    sfFloatRect hitbox_runner = sfSprite_getGlobalBounds(sprite_runner);
    //sfFloatRect hitbox_spike = sfSprite_getGlobalBounds(sprite_spike);

    
    window = sfRenderWindow_create(mode, "my_runner", sfClose, NULL);
    if (!window)
        return (84);
    background = sfTexture_createFromFile("./images/Background.jpg", NULL);
    if (!background)
        return (84);
    runner = sfTexture_createFromFile("./images/Walk (1).png", NULL);
    if (!runner)
        return (84);
    //spike = sfTexture_createFromFile("./images/Spike.png", NULL);
    //if (!spike)
    //    return (84);
    run = sfTexture_createFromFile("./images/Run.jpg", NULL);
    if (!run)
        return (84);

    sprite = sfSprite_create();
    sprite_runner = sfSprite_create();
    //sprite_spike = sfSprite_create();
    sprite_run = sfSprite_create();

    sfSprite_setTexture(sprite, background, sfTrue);
    sfSprite_setTexture(sprite_runner, runner, sfTrue);
    //sfSprite_setTexture(sprite_spike, spike, sfTrue);
    sfSprite_setTexture(sprite_run, run, sfTrue);

    sfSprite_scale(sprite_runner, (sfVector2f){0.2, 0.2});
    sfSprite_setPosition(sprite_run, (sfVector2f){0, 900});
    //sfSprite_setPosition(sprite_runner, (sfVector2f){50, 830});
    
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }

        if (sfKeyboard_isKeyPressed(sfKeyD)) {
            sfSprite_move(sprite_runner, move_forward);
            sfTexture_destroy(runner);
            runner = sfTexture_createFromFile("./images/Walk (1).png", NULL);
            sfSprite_setTexture(sprite_runner, runner, sfTrue);
        }
        if (sfKeyboard_isKeyPressed(sfKeyQ)) {
            sfSprite_move(sprite_runner, move_backward);
        }
        if (sfKeyboard_isKeyPressed(sfKeyS)) {
            sfSprite_move(sprite_runner, (sfVector2f){0, 5});    
        }
        if (sfKeyboard_isKeyPressed(sfKeyZ)) {
            sfSprite_move(sprite_runner, (sfVector2f){0, -5});
        }
        if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
            sfRenderWindow_destroy(window);    
        }

        //sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_drawSprite(window, sprite_run, NULL);
        sfRenderWindow_drawSprite(window, sprite_runner, NULL);
        sfRenderWindow_display(window);
    }

    sfSprite_destroy(sprite);
    sfSprite_destroy(sprite_runner);
    //sfSprite_destroy(sprite_spike);
    sfSprite_destroy(sprite_run);
    sfTexture_destroy(background);
    sfRenderWindow_destroy(window);

    return (0);
}
