/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** Links
*/

#include "NanoTekSpice/Links/Links.hpp"
#include "NanoTekSpice/Component/IComponent.hpp"

namespace NanoTekSpice {
    Links::Links(std::shared_ptr<NanoTekSpice::IComponent> src, int srcPin,std::shared_ptr<NanoTekSpice::IComponent> dst, int dstPin) {
        _src = src;
        _srcPin = srcPin;
        _dst = dst;
        _dstPin = dstPin;
    }

    Links::~Links()
    {
    }

    std::pair<std::shared_ptr<NanoTekSpice::IComponent>, int> Links::getOtherComponent(std::string &name)
    {
        if (_src == nullptr || _dst == nullptr)
            return std::pair(nullptr, 0);
        std::string srcName = _src->getName();
        std::string dstName = _dst->getName();
        if (srcName == dstName) {
            if (_src->isOutput(_srcPin)) {
                return std::pair(_src, _srcPin);
            } else {
                return std::pair(_dst, _dstPin);
            }
        }
        if (srcName == name) {
            return std::pair(_dst, _dstPin);
        }
        return std::pair(_src, _srcPin);
    }
}
