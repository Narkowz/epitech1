/*
** EPITECH PROJECT, 2025
** arcade
** File description:
** Event
*/

#pragma once

enum class EventType
{
    QUIT,
    KEY_PRESSED,
    KEY_RELEASED,
    SWITCH_GRAPHICS,
    UNDEFINED,
};

enum class KeyCode
{
    UP_ARROW,
    DOWN_ARROW,
    LEFT_ARROW,
    RIGHT_ARROW,
    SPACE,
    ENTER,
    UNDEFINED,
};

class Event
{
    protected:
        EventType _type;
        KeyCode _keyCode;

    public:
        Event(EventType type = EventType::UNDEFINED, KeyCode keyCode = KeyCode::UNDEFINED) {_type = type; _keyCode = keyCode;}
        KeyCode getKeyCode() const { return _keyCode; }
        EventType getType() const { return _type; }
};
