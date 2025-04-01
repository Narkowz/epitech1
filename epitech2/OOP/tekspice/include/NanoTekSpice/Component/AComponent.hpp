/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** IComponent
*/

#pragma once

#include <vector>
#include <memory>
#include <unordered_map>

#include "IComponent.hpp"
#include "Tristate.hpp"
#include "NanoTekSpice/Links/Links.hpp"

namespace NanoTekSpice {
    class AComponent : public IComponent {
        protected:
            int _nbPins;
            int _lastTick;
            std::map<int, Tristate> _outputs;
            ComponentType _type;
            std::unordered_map<int, Links*> _links;
            std::string _name;
            Tristate simulateLink(int nbPin, int tick, bool isSameTick = false);

        public:
            AComponent(int nbPins, ComponentType type = ComponentType::CT_UNDEFINED);
            ~AComponent();
            void setValue(Tristate value, int pinId) override;
            Tristate getValue(int pinId) const  override;
            int getNbPins() const override { return _nbPins; }
            void setName(std::string name) override;
            std::string getName() override { return _name; }
            ComponentType getType() const override { return _type; }

            bool isOutput(int pinId) const override;
            void addLink(int pin, Links *link) override;
            void compute(int tick) override;
    };
}
