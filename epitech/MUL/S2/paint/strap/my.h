/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** my
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System/Time.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Transform.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <fcntl.h>
#include <time.h>
#include <math.h>

#ifndef MY_H_
    #define MY_H_

enum e_gui_state {
    NONE = 0,
    HOVER,
    PRESSED,
    RELEASED
};

typedef struct window_s {
    sfRenderWindow *window;
    sfEvent event;
} window_t;

typedef struct button_s {
    sfRectangleShape *rect;
    int (*click_button)(window_t *window, struct button_s **button);
    int (*press_button)(window_t *window, struct button_s **button);
    enum e_gui_state state;
} button_t;


#endif /* !MY_H_ */
