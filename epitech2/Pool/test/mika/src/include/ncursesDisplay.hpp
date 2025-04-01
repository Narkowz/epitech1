/*
** EPITECH PROJECT, 2025
** ncursesDisplay.hpp
** File description:
** ncursesDisplay
*/

#ifndef NCURSESDISPLAY_HPP_
#define NCURSESDISPLAY_HPP_

#include "IDisplay.hpp"
#include <ncurses.h>

#define GREEN 1
#define YELLOW 2
#define RED 3
#define BLUE 4

namespace Krell {
    class ncursesDisplay : public IDisplay {
    public:
        ncursesDisplay();
        ~ncursesDisplay();
        void display(const std::vector<std::shared_ptr<IModule> >& modules) override;
        void handleEvents() override;

    private:
        void initColors();
    };
}

#endif /* !NCURSESDISPLAY_HPP_ */
