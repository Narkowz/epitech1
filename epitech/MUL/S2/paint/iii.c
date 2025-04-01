#include <SFML/Graphics.h>
#include <stdlib.h>

typedef struct {
    sfRectangleShape* shape;
    sfText* text;
} MenuItem;

typedef struct {
    sfRectangleShape* shape;
    sfText* text;
    MenuItem* items;
    int itemCount;
    sfBool isOpen;
} DropDownMenu;

typedef struct {
    sfRenderWindow* window;
    DropDownMenu fileMenu;
    DropDownMenu editMenu;
    DropDownMenu helpMenu;
} MenuBar;

void initializeMenuItem(MenuItem* item, const char* text, sfVector2f position, sfVector2f size, sfFont* font) {
    item->shape = sfRectangleShape_create();
    sfRectangleShape_setSize(item->shape, size);
    sfRectangleShape_setPosition(item->shape, position);

    item->text = sfText_create();
    sfText_setString(item->text, text);
    sfText_setFont(item->text, font);
    sfText_setCharacterSize(item->text, 20);
    sfText_setPosition(item->text, (sfVector2f){position.x + 5, position.y + 5});
}

void initializeDropDownMenu(DropDownMenu* menu, const char* menuText, sfVector2f position, sfVector2f size, int itemCount, const char** itemTexts, sfFont* font) {
    menu->shape = sfRectangleShape_create();
    sfRectangleShape_setSize(menu->shape, size);
    sfRectangleShape_setPosition(menu->shape, position);

    menu->text = sfText_create();
    sfText_setString(menu->text, menuText);
    sfText_setFont(menu->text, font);
    sfText_setCharacterSize(menu->text, 20);
    sfText_setPosition(menu->text, (sfVector2f){position.x + 5, position.y + 5});

    menu->items = (MenuItem*)malloc(itemCount * sizeof(MenuItem));
    menu->itemCount = itemCount;

    for (int i = 0; i < itemCount; ++i) {
        sfVector2f itemPosition = {position.x, position.y + size.y + (i * 30)};
        initializeMenuItem(&menu->items[i], itemTexts[i], itemPosition, (sfVector2f){size.x, 30}, font);
    }

    menu->isOpen = sfFalse;
}

void drawMenu(sfRenderWindow* window, DropDownMenu* menu) {
    sfRenderWindow_drawRectangleShape(window, menu->shape, NULL);
    sfRenderWindow_drawText(window, menu->text, NULL);

    if (menu->isOpen) {
        for (int i = 0; i < menu->itemCount; ++i) {
            sfRenderWindow_drawRectangleShape(window, menu->items[i].shape, NULL);
            sfRenderWindow_drawText(window, menu->items[i].text, NULL);
        }
    }
}

void cleanupMenu(DropDownMenu* menu) {
    sfRectangleShape_destroy(menu->shape);
    sfText_destroy(menu->text);

    for (int i = 0; i < menu->itemCount; ++i) {
        sfRectangleShape_destroy(menu->items[i].shape);
        sfText_destroy(menu->items[i].text);
    }

    free(menu->items);
}

void cleanupMenuBar(MenuBar* menuBar) {
    cleanupMenu(&menuBar->fileMenu);
    cleanupMenu(&menuBar->editMenu);
    cleanupMenu(&menuBar->helpMenu);

    sfRenderWindow_destroy(menuBar->window);
}

int main() {
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow* window = sfRenderWindow_create(mode, "CSFML Menu Bar", sfDefaultStyle, NULL);

    sfFont* font = sfFont_createFromFile("assets/Roboto-Medium.ttf"); // Replace with your font file path

    const char* fileMenuItems[] = {"New File", "Open File", "Save File"};
    const char* editMenuItems[] = {"Pencil Tool", "Eraser Tool"};
    const char* helpMenuItems[] = {"About", "Help"};

    MenuBar menuBar;
    menuBar.window = window;

    initializeDropDownMenu(&menuBar.fileMenu, "File", (sfVector2f){0, 0}, (sfVector2f){80, 30}, 3, fileMenuItems, font);
    initializeDropDownMenu(&menuBar.editMenu, "Edit", (sfVector2f){90, 0}, (sfVector2f){80, 30}, 2, editMenuItems, font);
    initializeDropDownMenu(&menuBar.helpMenu, "Help", (sfVector2f){180, 0}, (sfVector2f){80, 30}, 2, helpMenuItems, font);

    while (sfRenderWindow_isOpen(window)) {
        sfEvent event;
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
            else if (event.type == sfEvtMouseButtonPressed) {
                sfVector2f mousePos = {event.mouseButton.x, event.mouseButton.y};
                sfFloatRect boundsfile = sfRectangleShape_getGlobalBounds(menuBar.fileMenu.shape);
                sfFloatRect boundsedit = sfRectangleShape_getGlobalBounds(menuBar.editMenu.shape);
                sfFloatRect boundshelp = sfRectangleShape_getGlobalBounds(menuBar.helpMenu.shape);

                // Toggle the drop-down menus if clicked
                menuBar.fileMenu.isOpen = sfFloatRect_contains(&boundsfile, mousePos.x, mousePos.y);
                menuBar.editMenu.isOpen = sfFloatRect_contains(&boundsedit, mousePos.x, mousePos.y);
                menuBar.helpMenu.isOpen = sfFloatRect_contains(&boundshelp, mousePos.x, mousePos.y);
            }
        }


        sfRenderWindow_clear(window, sfWhite);

        // Draw the menu bar
        drawMenu(window, &menuBar.fileMenu);
        drawMenu(window, &menuBar.editMenu);
        drawMenu(window, &menuBar.helpMenu);

        sfRenderWindow_display(window);
    }

    cleanupMenuBar(&menuBar);
    sfFont_destroy(font);

    return 0;
}
