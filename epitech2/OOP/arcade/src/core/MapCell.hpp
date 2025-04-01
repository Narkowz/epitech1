/*
** EPITECH PROJECT, 2025
** arcade
** File description:
** MapCell
*/

#pragma once

class MapCell
{
    public:
        enum class CellColor
        {
            WHITE,
            RED,
            LIGHT_GREEN,
            BLUE,
            GREEN,
            DEFAULT,
            MAGENTA,
        };

        MapCell(char c, CellColor color) : _c(c), _color(color) {}
        char _c;
        CellColor _color;
};
