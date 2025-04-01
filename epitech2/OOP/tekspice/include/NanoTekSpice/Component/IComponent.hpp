/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** IComponent
*/

#pragma once

#include "ComponentType.hpp"
#include "Tristate.hpp"

namespace NanoTekSpice {
    class Links;
    class IComponent {
        public:
            IComponent() = default;
            ~IComponent() = default;
            virtual int getNbPins() const = 0;
            virtual bool isOutput(int) const = 0;
            virtual void compute(int tick) = 0;
            virtual void simulate(int tick, bool isSameTick) = 0;
            virtual Tristate getValue(int pinId) const = 0;
            virtual void setName(std::string) = 0;
            virtual std::string getName() = 0;
            virtual ComponentType getType() const = 0;
            virtual void setValue(Tristate tristate, int pinId) = 0;
            virtual void addLink(int, Links *) = 0;
    };
}
