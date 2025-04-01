/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** Circuit
*/

#include "NanoTekSpice/Circuit.hpp"
#include "Exception/CircuitException.hpp"
#include "Exception/RuntimeException.hpp"
#include "Exception/NanoTekSpiceException.hpp"
#include "Utils/ComponentTypeUtils.hpp"

#include <algorithm>

namespace NanoTekSpice {
    Circuit::Circuit(ParsedCircuit &parsedCircuit)
    {
        _tick = -1; // start at -1 to simulate the first tick
        for (auto component : parsedCircuit.getChipsets()) {
            AddComponent(component.second, component.first);
        }
        for (auto link : parsedCircuit.getLinks()) {
            AddLink(link.first.first, link.first.second, link.second.first, link.second.second);
        }
        _isLooping = false;
        simulate();
        return;
    }

    void Circuit::AddComponent(const std::string &name, ComponentType type)
    {
        if (_components.find(name) != _components.end())
            THROW_CIRCUIT_EXCEPTION("Component already exists");
        auto constructor = getComponentConstructor(type);
        if (constructor == nullptr) {
            return;
        }
        _components[name] = constructor();
        _components[name]->setName(name);
    }

    void Circuit::AddLink(const std::string &src, int srcPin, const std::string &dst, int dstPin)
    {
        if (_components.find(src) == _components.end() || _components.find(dst) == _components.end())
            THROW_CIRCUIT_EXCEPTION("Component not found");
        if (srcPin < 1 || dstPin < 1)
            THROW_CIRCUIT_EXCEPTION("Invalid pin number");
        if (_components[src]->getNbPins() <= srcPin || _components[dst]->getNbPins() <= dstPin)
            THROW_CIRCUIT_EXCEPTION("Invalid pin number: " + src + " " + std::to_string(srcPin) + " " + dst + " " + std::to_string(dstPin));
        if (_components[src]->isOutput(srcPin) + _components[dst]->isOutput(dstPin) != 1) {
            std::cout << _components[src]->isOutput(srcPin) << " " << _components[dst]->isOutput(dstPin) << std::endl;
            THROW_CIRCUIT_EXCEPTION("Invalid Input/Output link: " + src + " " + std::to_string(srcPin) + " " + dst + " " + std::to_string(dstPin));
        }
        std::shared_ptr<Links> link = std::make_shared<Links>(_components[src], srcPin, _components[dst], dstPin);
        _links.push_back(link);


        _components[src]->addLink(srcPin, link.get());
        _components[dst]->addLink(dstPin, link.get());
    }

    static const std::map<ComponentType, std::function<std::shared_ptr<IComponent>()>> typeToClass = {
        {CT_INPUT, []() { return std::make_shared<InputComponent>(); }},
        {CT_OUTPUT, []() { return std::make_shared<OutputComponent>(); }},
        {CT_TRUE, []() { return std::make_shared<TrueComponent>(); }},
        {CT_FALSE, []() { return std::make_shared<FalseComponent>(); }},
        {CT_CLOCK, []() { return std::make_shared<ClockComponent>(); }},
        {CT_AND, []() { return std::make_shared<AndComponent>(); }},
        {CT_OR, []() { return std::make_shared<OrComponent>(); }},
        {CT_XOR, []() { return std::make_shared<XorComponent>(); }},
        {CT_NOT, []() { return std::make_shared<NotComponent>(); }},
        {CT_LOGGER, []() { return std::make_shared<Logger>(); }},
        {CT_4001, []() { return std::make_shared<Nor4001>(); }},
        {CT_4011, []() { return std::make_shared<Nand4011>(); }},
        {CT_4030, []() { return std::make_shared<Xor4030>(); }},
        {CT_4071, []() { return std::make_shared<Or4071>(); }},
        {CT_4081, []() { return std::make_shared<And4081>(); }},
        {CT_4069, []() { return std::make_shared<Not4069>(); }},
        {CT_4008, []() { return std::make_shared<Adder4008>(); }},
        {CT_4013, []() { return std::make_shared<FlipFlop4013>(); }},
        {CT_4017, []() { return std::make_shared<Decade4017>(); }},
        {CT_4040, []() { return std::make_shared<Counter4040>(); }},
        {CT_4514, []() { return std::make_shared<Decoder4514>(); }},
        {CT_4094, []() { return std::make_shared<Register4094>(); }},
        {CT_4512, []() { return std::make_shared<Selector4512>(); }},
    };

    std::function<std::shared_ptr<IComponent>()> Circuit::getComponentConstructor(ComponentType type) {
        auto it = typeToClass.find(type);
        if (it == typeToClass.end()) {
            return nullptr;
        }
        return it->second;
    }

    void Circuit::display()
    {
        std::vector<std::string> inputName;
        for (auto &component : _components) {
            if (component.second && (component.second->getType() == CT_INPUT || component.second->getType() == CT_CLOCK))
                inputName.push_back(component.first);
        }
        std::sort(inputName.begin(), inputName.end());

        std::cout << "tick: "  << _tick << std::endl;
        std::cout << "input(s):" << std::endl;
        for (auto &component : inputName) {
            std::cout << "  " << component << ": " << _components[component]->getValue(1) << std::endl;
        }

        std::vector<std::string> outputName;
        for (auto &component : _components) {
            if (component.second && component.second->getType() == CT_OUTPUT)
                outputName.push_back(component.first);
        }
        std::sort(outputName.begin(), outputName.end());
    
        std::cout << "output(s):" << std::endl;
        for (auto &output : outputName) {
            std::cout << "  " << output << ": " << _components[output]->getValue(2) << std::endl;
        }
    }

    void Circuit::simulate()
    {
        _tick++;
        for (auto &component : _components) {
            if (component.second && (component.second->getType() == CT_OUTPUT || component.second->getType() == CT_LOGGER)) {
                component.second->compute(_tick);
            }
        }
    }

    void Circuit::update(const std::string &name, const std::string &value) {
        if (_components.find(name) == _components.end()) {
            THROW_RUNTIME_EXCEPTION("Component not found: {" + name + "}");
        }
        if (_components[name]->getType() != CT_INPUT && _components[name]->getType() != CT_CLOCK) {
            THROW_RUNTIME_EXCEPTION("Component is not an input");
        }
        if (value != "0" && value != "1" && value != "U") {
            THROW_RUNTIME_EXCEPTION("Invalid value");
        }
        Tristate newState = Tristate();
        if (value == "0" || value == "1") {
            value == "0" ? newState.setValue(0) : newState.setValue(1);
        }
        _components[name]->setValue(newState, 1);
    }

    void Circuit::loop()
    {
        _isLooping = true;
        while (_isLooping) {
            simulate();
            display();
        }
    }

    void Circuit::endLoop()
    {
        _isLooping = false;
    }

    bool Circuit::isLooping() const
    {
        return _isLooping;
    }   
}

