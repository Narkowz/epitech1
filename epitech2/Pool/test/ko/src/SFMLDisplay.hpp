/*
** EPITECH PROJECT, 2025
** SFMLDisplay.hpp
** File description:
** SFMLDisplay
*/

#ifndef SFMLDISPLAY_HPP_
#define SFMLDISPLAY_HPP_

#include "include/IDisplay.hpp"
#include <SFML/Graphics.hpp>
#include <memory>
#include <unordered_map>

namespace Krell {
    class SFMLDisplay : public IDisplay {
    public:
        SFMLDisplay();
        ~SFMLDisplay();
        void display(const std::vector<std::shared_ptr<IModule>>& modules) override;
        void handleEvents() override;

    private:
        sf::RenderWindow _window;
        sf::Font _font;

        void drawModuleData(const std::vector<std::shared_ptr<IModule>>& modules);
        bool isModuleClicked(const std::shared_ptr<IModule>& module, const sf::Vector2f& mousePos);
        std::vector<std::shared_ptr<IModule>> _modules;
        std::unordered_map<std::shared_ptr<IModule>, float> _moduleYOffsets;
    };
}

#endif /* !SFMLDISPLAY_HPP_ */
