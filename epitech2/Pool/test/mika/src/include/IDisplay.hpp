/*
** EPITECH PROJECT, 2025
** IDisplay.hpp
** File description:
** IDisplay
*/

#ifndef IDISPLAY_HPP_
#define IDISPLAY_HPP_

#include <vector>
#include <memory>
#include "IModule.hpp"

namespace Krell {
    class IDisplay {
    public:
        virtual ~IDisplay() = default; // Destructeur virtuel
        virtual void display(const std::vector<std::shared_ptr<IModule> >& modules) = 0; // Affiche les modules
        virtual void handleEvents() = 0; // Gère les événements (clavier, souris, etc.)
    };
}

#endif /* !IDISPLAY_HPP_ */
