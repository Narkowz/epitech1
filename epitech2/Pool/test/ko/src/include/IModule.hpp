/*
** EPITECH PROJECT, 2025
** Imodule.hpp
** File description:
** IModule
*/

#ifndef IMODULE_HPP_
#define IMODULE_HPP_

#include <string>

namespace Krell {
    class IModule {
    public:
        virtual ~IModule() = default; // Destructeur virtuel
        virtual void updateData() = 0; // Met à jour les données du module
        virtual std::string getName() const = 0; // Retourne le nom du module
        virtual std::string getData() const = 0; // Retourne les données du module
        virtual bool isExpanded() const = 0;
        virtual void toggleExpanded() = 0;
    };
}

#endif /* !IMODULE_HPP_ */
