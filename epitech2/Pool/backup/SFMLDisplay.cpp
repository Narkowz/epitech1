/*
** EPITECH PROJECT, 2025
** SFMLDisplay.cpp
** File description:
** SFMLDisplay
*/

#include "SFMLDisplay.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <stdio.h>

namespace Krell {
    SFMLDisplay::SFMLDisplay() : _window(sf::VideoMode(1000, 800), "MyGKrellm - SFML Display") {
        if (!_font.loadFromFile("src/Font.ttf")) {
            std::cerr << "Erreur lors du chargement de la police." << std::endl;
        }
    }

    SFMLDisplay::~SFMLDisplay() {
        _window.close();
    }

    void SFMLDisplay::display(const std::vector<std::shared_ptr<IModule>>& modules) {
        _modules = modules;
        _window.clear(sf::Color::Black);
        drawModuleData(modules);
        _window.display();
    }

    void SFMLDisplay::handleEvents() {
    sf::Event event;
    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            _window.close();
        } else if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                //printf("test\n");
                // Récupère la position du clic
                sf::Vector2f mousePos = _window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
                //printf("x : %f y : %f\n", mousePos.x, mousePos.y);

                // Vérifie si un module est cliqué
                for (const auto& module : _modules) {
                        //printf("aAAA\n");
                    if (isModuleClicked(module, mousePos)) {
                        //printf("oui\n");
                        module->toggleExpanded(); // Masque/affiche les données du module
                        break;
                    }
                    //printf("non\n");
                }
            }
        }
    }
}

bool SFMLDisplay::isModuleClicked(const std::shared_ptr<IModule>& module, const sf::Vector2f& mousePos) {
    if (!module) {
        std::cerr << "Erreur : module est un pointeur nul." << std::endl;
        return false;
    }

    // Calcule la zone du module (titre + données si expandé)
    sf::FloatRect moduleBounds(50.0f, _moduleYOffsets[module], 700.0f, 30.0f); // Exemple de dimensions

    if (module->isExpanded()) {
        // Si le module est expandé, inclut les données dans la zone cliquable
        std::string data = module->getData(); // Crée une copie de la chaîne
        //std::cout << "Données du module : " << data << std::endl; // Debug
        moduleBounds.height += 25.0f * std::count(data.begin(), data.end(), '\n');
    }

    return moduleBounds.contains(mousePos);
}

    void SFMLDisplay::drawModuleData(const std::vector<std::shared_ptr<IModule>>& modules) {
    _window.clear(sf::Color::Black);

    float yOffset = 50.0f;
    _moduleYOffsets.clear(); // Réinitialise les positions des modules

    for (const auto& module : modules) {
        // Affiche le nom du module en gras
        sf::Text text;
        text.setFont(_font);
        text.setCharacterSize(20);
        text.setFillColor(sf::Color::White);
        text.setString(module->getName() + ":");
        text.setStyle(sf::Text::Bold);
        text.setPosition(50.0f, yOffset);
        _window.draw(text);

        // Stocke la position Y du module
        _moduleYOffsets[module] = yOffset;

        // Affiche les données du module si expandé
        if (module->isExpanded()) {
            std::istringstream iss(module->getData());
            std::string line;
            float lineOffset = yOffset + 30.0f; // Espacement après le titre

            while (std::getline(iss, line)) {
                text.setString(line);
                text.setStyle(sf::Text::Regular);
                text.setPosition(50.0f, lineOffset);
                _window.draw(text);
                lineOffset += 25.0f; // Espacement entre les lignes
            }

            yOffset = lineOffset + 50.0f; // Espacement entre les modules
        } else {
            yOffset += 50.0f; // Espacement entre les modules (sans données)
        }
    }

    _window.display();
}
}
