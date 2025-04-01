/*
** EPITECH PROJECT, 2025
** NcursesDisplay.hpp
** File description:
** NcursesDisplay
*/

#ifndef NCURSESDISPLAY_HPP_
#define NCURSESDISPLAY_HPP_

#include "IDisplay.hpp"
#include <ncurses.h>

namespace Krell {
    class NcursesDisplay : public IDisplay {
    public:
        NcursesDisplay();
        ~NcursesDisplay();
        void display(const std::vector<std::shared_ptr<IModule>>& modules) override;
        void handleEvents() override;

    private:
        void initColors();
    };
}

#endif /* !NCURSESDISPLAY_HPP_ */
