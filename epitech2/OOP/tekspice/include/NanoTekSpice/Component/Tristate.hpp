/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** Tristate
*/

#pragma once

#include <iostream>

namespace NanoTekSpice {
    class Tristate {
        private:
            enum TristateValue {
                UNDEFINED = -1,
                TRUE = 1,
                FALSE = 0
            };
            TristateValue _value;
        public:
            Tristate(int value = -1);
            Tristate operator&(const Tristate &other) const;
            Tristate operator|(const Tristate &other) const;
            Tristate operator^(const Tristate &other) const;
            Tristate operator!() const;
            bool operator==(const Tristate &other) const;
            bool operator!=(const Tristate &other) const;
            void setValue(int value) { _value = static_cast<TristateValue>(value); }
            std::ostream& display(std::ostream& os) const;
    };

    std::ostream& operator<<(std::ostream& os, const Tristate &tristate);
}

