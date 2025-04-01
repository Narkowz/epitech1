/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** Links
*/

#pragma once

#include <memory>

#include "NanoTekSpice/Component/IComponent.hpp"

namespace NanoTekSpice {
    class IComponent;
    
    class Links {
        public:
            Links(std::shared_ptr<NanoTekSpice::IComponent> src, int srcPin, std::shared_ptr<NanoTekSpice::IComponent> dst, int dstPin);
            ~Links();
            std::pair<std::shared_ptr<NanoTekSpice::IComponent>, int> getOtherComponent(std::string &name);
            int getSrcPin() const { return _srcPin; }
            int getDstPin() const { return _dstPin; }
            std::shared_ptr<NanoTekSpice::IComponent> getSrc() const { return _src; }
            std::shared_ptr<NanoTekSpice::IComponent> getDst() const { return _dst; }
        private:
            std::shared_ptr<NanoTekSpice::IComponent> _src;
            int _srcPin;
            std::shared_ptr<NanoTekSpice::IComponent> _dst;
            int _dstPin;
    };
}
