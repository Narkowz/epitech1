/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** Circuit
*/

#pragma once

#include "File/ParsedCircuit.hpp"
#include "Component/AComponent.hpp"
#include "Links/Links.hpp"

#include "Component/IComponent.hpp"
#include "Component/TrueComponent.hpp"
#include "Component/FalseComponent.hpp"
#include "Component/AndComponent.hpp"
#include "Component/OrComponent.hpp"
#include "Component/XorComponent.hpp"
#include "Component/NotComponent.hpp"
#include "Component/InputComponent.hpp"
#include "Component/OutputComponent.hpp"
#include "Component/ClockComponent.hpp"
#include "Component/Nor4001.hpp"
#include "Component/Nand4011.hpp"
#include "Component/Xor4030.hpp"
#include "Component/Or4071.hpp"
#include "Component/And4081.hpp"
#include "Component/Not4069.hpp"
#include "Component/Adder4008.hpp"
#include "Component/FlipFlop4013.hpp"
#include "Component/Decade4017.hpp"
#include "Component/Counter4040.hpp"
#include "Component/Logger.hpp"
#include "Component/Decoder4514.hpp"
#include "Component/Register4094.hpp"
#include "Component/Selector4512.hpp"

#include <unordered_map>
#include <functional>
#include <memory>

namespace NanoTekSpice {
    class Circuit {
        public:
            Circuit(ParsedCircuit &parsedCircuit);
            ~Circuit() = default;

            void display();
            void simulate();
            void update(const std::string &name, const std::string &value);
            void loop();
            void endLoop();
            bool isLooping() const;

        private:
            void AddComponent(const std::string &name, ComponentType type);
            void AddLink(const std::string &src, int srcPin, const std::string &dst, int dstPin);
            std::unordered_map<std::string, std::shared_ptr<IComponent>> _components;
            std::vector<std::shared_ptr<Links>> _links;
            std::size_t _tick;
            bool _isLooping;
            std::function<std::shared_ptr<IComponent>()> getComponentConstructor(ComponentType type);
            
    };
}
