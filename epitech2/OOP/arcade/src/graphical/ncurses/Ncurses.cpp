/*
** EPITECH PROJECT, 2025
** arcade
** File description:
** Ncurses
*/

#include <iostream>
#include <memory>

#include "Ncurses.hpp"

#define KEY_ESCAPE 27
#define KEY_SPACE ' '

static std::unique_ptr<Ncurses> graphical;

void __attribute__((constructor)) init()
{
    // std::cout << "Library ncurse initialized." << std::endl;
}

void __attribute__((destructor)) cleanup()
{
    graphical.reset();
    // std::cout << "Library ncurse cleaned up." << std::endl;
}

extern "C"
{
    const char *GraphicName()
    {
        return "Ncurses";
    }

    IGraphical *getInstance()
    {
        if (!graphical)
        {
            graphical = std::make_unique<Ncurses>();
        }
        return graphical.release();
    }
}

Ncurses::Ncurses()
{
    _window = initscr();
    if (_window == NULL)
    {
        std::cerr << "Error initializing ncurses" << std::endl;
        exit(84);
    }
    noecho();
    curs_set(0);
    keypad(_window, TRUE);
    nodelay(_window, TRUE);
    timeout(0);
    start_color();
    _gameBox = newwin(42, 84, 3, 4);
    init_color(5, 144, 238, 144);
    init_pair(0, COLOR_WHITE, COLOR_WHITE);
    init_pair(1, COLOR_RED, COLOR_RED);
    init_pair(2, COLOR_GREEN, COLOR_GREEN);
    init_pair(3, COLOR_BLUE, COLOR_BLUE);
    init_pair(4, 5, 5);
    init_pair(5, COLOR_BLACK, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_CYAN);
    wbkgd(_gameBox, COLOR_PAIR(3));

    // int maxY, maxX;
    // getmaxyx(_window, maxY, maxX);
    // if (maxY < 26 || maxX < 46) {
    //     std::cerr << "Terminal size too small. Requires at least 46x26." << std::endl;
    //     endwin();
    //     exit(84);
    // }
}

Ncurses::~Ncurses()
{
    if (_window)
    {
        delwin(_window);
    }
    if (_gameBox)
    {
        delwin(_gameBox);
    }
    endwin();
}

void Ncurses::render()
{
    wrefresh(_window);
    wrefresh(_gameBox);
}

void Ncurses::clear()
{
    wclear(_window);
    wclear(_gameBox);
}

void Ncurses::drawMap(const std::vector<std::vector<MapCell>> &cellMap)
{
    for (size_t y = 0; y < cellMap.size(); ++y)
    {
        for (size_t x = 0; x < cellMap[y].size(); ++x)
        {
            wattron(_gameBox, COLOR_PAIR((int)cellMap[y][x]._color));
            mvwprintw(_gameBox, y + 1, (x * 2) + 2, "%c", cellMap[y][x]._c);
            mvwprintw(_gameBox, y + 1, (x * 2) + 3, "%c", cellMap[y][x]._c);
            wattroff(_gameBox, COLOR_PAIR((int)cellMap[y][x]._color));
        }
    }
}

void Ncurses::drawTitle(const std::string &title)
{
    mvwprintw(_window, 1, 4, "%s", title.c_str());
}

std::vector<Event> Ncurses::getEvents()
{
    std::vector<Event> events;
    int key = wgetch(_window);
    switch (key)
    {
        case -1:
            break;
        case KEY_UP:
            events.push_back(Event(EventType::KEY_PRESSED, KeyCode::UP_ARROW));
            break;
        case KEY_DOWN:
            events.push_back(Event(EventType::KEY_PRESSED, KeyCode::DOWN_ARROW));
            break;
        case KEY_LEFT:
            events.push_back(Event(EventType::KEY_PRESSED, KeyCode::LEFT_ARROW));
            break;
        case KEY_RIGHT:
            events.push_back(Event(EventType::KEY_PRESSED, KeyCode::RIGHT_ARROW));
            break;
        case KEY_SPACE:
            events.push_back(Event(EventType::KEY_PRESSED, KeyCode::SPACE));
            break;
        case KEY_BTAB:
            events.push_back(Event(EventType::SWITCH_GRAPHICS));
            break;
        case KEY_ESCAPE:
            events.push_back(Event(EventType::QUIT));
            break;
        default:
            break;
    }
    return events;
}
