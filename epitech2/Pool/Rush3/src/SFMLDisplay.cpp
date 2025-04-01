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
    SFMLDisplay::SFMLDisplay() : _window(sf::VideoMode(1000, 800), "MyGKrellm - SFML Display")
    {
        if (!_font.loadFromFile("src/Font.ttf")) { // Charge la police
            std::cerr << "Erreur lors du chargement de la police." << std::endl; // Affiche une erreur
            return;
        }

    }

    SFMLDisplay::~SFMLDisplay()
    {
        _window.close(); // Ferme la fenêtre
    }

    void SFMLDisplay::display(const std::vector<std::shared_ptr<IModule>>& modules)
    {
        _modules = modules; // Stocke les modules
        _window.clear(sf::Color::Black); // Efface la fenêtre
        drawModuleData(modules); // Affiche les données des modules
        _window.display(); // Affiche la fenêtre
    }

    void SFMLDisplay::handleEvents()
    {
        sf::Event event;
        while (_window.pollEvent(event)) { // Tant qu'il y a des événements
            if (event.type == sf::Event::Closed) { // Si la fenêtre est fermée
                _window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) { // Si un bouton de la souris est pressé
                if (event.mouseButton.button == sf::Mouse::Left) { // Si c'est le bouton gauche
                    sf::Vector2f mousePos = _window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y)); // Récupère la position de la souris
                    for (const auto& module : _modules) { // Pour chaque module
                        if (isModuleClicked(module, mousePos)) { // Si le module est cliqué
                            module->toggleExpanded(); // Change l'état d'expansion
                            break;
                        }
                    }
                }
            }
        }
    }

    bool SFMLDisplay::isModuleClicked(const std::shared_ptr<IModule>& module, const sf::Vector2f& mousePos)
    {
        if (!module) {
            std::cerr << "Erreur : module est un pointeur nul." << std::endl;
            return false;
        }
        sf::FloatRect moduleBounds(50.0f, _moduleYOffsets[module], 700.0f, 30.0f); // Crée un rectangle autour du module
        if (module->isExpanded()) { // Si le module est expandé
            std::string data = module->getData(); // Récupère les données du module
            moduleBounds.height += 25.0f * std::count(data.begin(), data.end(), '\n'); // Ajuste la hauteur du rectangle
        }
        return moduleBounds.contains(mousePos);
    }

    void SFMLDisplay::drawModuleData(const std::vector<std::shared_ptr<IModule>>& modules) 
    {
        float yOffset = 50.0f;
        _moduleYOffsets.clear();

        for (const auto& module : modules) { // Pour chaque module
            sf::Text text;
            text.setFont(_font); // Utilise la police
            text.setCharacterSize(20); // Taille du texte
            text.setFillColor(sf::Color::White); // Couleur du texte
            text.setString(module->getName() + ":"); // Affiche le nom du module
            text.setStyle(sf::Text::Bold); // Texte en gras
            text.setPosition(50.0f, yOffset); // Positionne le texte
            _window.draw(text); // Affiche le texte

            _moduleYOffsets[module] = yOffset; // Stocke la position du module

            if (module->isExpanded()) {
                std::istringstream iss(module->getData()); // Crée un flux à partir des données du module
                std::string line;
                float lineOffset = yOffset + 30.0f; // Décalage de la ligne

                while (std::getline(iss, line)) { // Pour chaque ligne des données
                    text.setString(line); // Affiche la ligne
                    text.setStyle(sf::Text::Regular);
                    text.setPosition(50.0f, lineOffset);
                    _window.draw(text);
                    lineOffset += 25.0f;
                }

                yOffset = lineOffset + 50.0f;
            } else
                yOffset += 50.0f;
        }
    }

}
