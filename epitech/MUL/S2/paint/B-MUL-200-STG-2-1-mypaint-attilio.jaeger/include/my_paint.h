/*
** EPITECH PROJECT, 2024
** my_paint.h
** File description:
** my_paint
*/

#include "my.h"
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
#include <X11/Xlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <fcntl.h>
#include <time.h>
#include <math.h>

#ifndef MY_PAINT_H_
    #define MY_PAINT_H_

typedef struct gui_s {
    sfRectangleShape *rect;
    sfTexture *tbrush;
    sfSprite *sbrush;
    sfRectangleShape *brush;
    sfTexture *teraser;
    sfSprite *seraser;
    sfRectangleShape *eraser;
    sfTexture *tup;
    sfSprite *sup;
    sfRectangleShape *size_up;
    sfTexture *tdown;
    sfSprite *sdown;
    sfRectangleShape *size_down;
    sfText *about;
    sfText *open;
    sfRectangleShape *aboutrect;
    sfRectangleShape *openrect;
    sfBool isabout;
    sfBool openisopen;
    sfRectangleShape *clip;
} gui_t;

typedef struct menu_s {
    sfFont *font;
    sfBool fisopen;
    sfRectangleShape *filerect;
    sfRectangleShape *new;
    sfRectangleShape *open;
    sfRectangleShape *save;
    sfBool eisopen;
    sfRectangleShape *editrect;
    sfRectangleShape *square;
    sfRectangleShape *circle;
    sfBool hisopen;
    sfRectangleShape *helprect;
    sfRectangleShape *about;
    sfRectangleShape *aled;
    sfText *filetxt;
    sfText *newtxt;
    sfText *opentxt;
    sfText *savetxt;
    sfText *edittxt;
    sfText *squaretxt;
    sfText *circletxt;
    sfText *helptxt;
    sfText *abouttxt;
    sfText *aledtxt;
} menu_t;

typedef struct state_s {
    sfBool brush;
    sfBool eraser;
    sfBool square;
    sfBool circle;
} state_t;

typedef struct aled_s {
    sfBool isaled;
    sfText *brush;
    sfText *up;
    sfText *down;
    sfText *eraser;
    sfText *edit;
    sfText *shape;
} aled_t;

typedef struct global_s {
    sfBool is_drawing;
    sfRenderWindow *window;
    sfEvent event;
    gui_t *gui;
    menu_t *menu;
    sfTexture *screen;
    sfUint8 *pixels;
    int pixel_size;
    state_t *state;
    sfSprite *sheet;
    aled_t *aled;
    const char *filepath;
    char *filename;
} global_t;

void print_usage(void);
void start_paint(global_t *glob);
void prepare_sheet(global_t *glob);
void handle_event(global_t *glob);
void free_everything(global_t *glob);
void init_gui(global_t *glob);
void create_screenshot(global_t *glob);
void init_function(global_t *glob);
void eraser_function(global_t *glob);
void hover_function(global_t *glob);
void event_click(global_t *glob);
void init_menu_bar(global_t *glob);
void init_file(global_t *glob);
void init_edit(global_t *glob);
void init_help(global_t *glob);
void draw_everything(global_t *glob);
void hover_file(global_t *glob, sfVector2i m);
void hover_help(global_t *glob, sfVector2i m);
void hover_edit(global_t *glob, sfVector2i m);
void coordonates_file(global_t *glob);
void coordonates_help(global_t *glob);
void coordonates_edit(global_t *glob);
void init_aled_wind(global_t *glob);

#endif /* !MY_PAINT_H_ */
