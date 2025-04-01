/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** AComponent
*/

#include "NanoTekSpice/Component/AComponent.hpp"
#include "NanoTekSpice/Component/ComponentType.hpp"
#include "NanoTekSpice/Component/Tristate.hpp"

namespace NanoTekSpice {
    AComponent::AComponent(int nbPins, ComponentType type) : _nbPins(nbPins), _type(type)
    {
        _lastTick = -1;
        _outputs = std::map<int, Tristate>();
    }

    AComponent::~AComponent()
    {
    }

    bool AComponent::isOutput(int pinId) const
    {
        for (auto &output : _outputs) {
            if (output.first == pinId)
                return true;
        }
        return false;
    }

    void AComponent::addLink(int pin, Links *link)
    {
        _links[pin] = link;
    }

    void AComponent::setName(std::string name)
    {
        _name = name;
    }

    Tristate AComponent::getValue(int pinId) const
    {
        if (_outputs.find(pinId) != _outputs.end()) {
            return _outputs.at(pinId);
        }
        return Tristate();
    }

    void AComponent::setValue(Tristate value, int pinId)
    {
        if (_outputs.find(pinId) != _outputs.end()) {
            _outputs[pinId] = value;
        }
    }

    void AComponent::compute(int tick)
    {
        bool isSameTick = false;
        if (_lastTick == tick) {
            isSameTick = true;
        }
        if (_lastTick < tick) {
            _lastTick = tick;
        }
        simulate(tick, isSameTick);
    }

    Tristate AComponent::simulateLink(int nbPin, int tick, bool isSameTick) {
        Tristate val1 = Tristate();
        auto it = _links.find(nbPin);
        if (it != _links.end() && it->second != nullptr) {
            auto secondComponent = it->second->getOtherComponent(_name);
            if (!isSameTick) {
                secondComponent.first->compute(tick);
            }
            val1 = secondComponent.first->getValue(secondComponent.second);
        }
        return val1;
    }
}
