/*
** EPITECH PROJECT, 2025
** nankoTekSpice
** File description:
** Tristate
*/

#include "NanoTekSpice/Component/Tristate.hpp"

namespace NanoTekSpice {
    Tristate::Tristate(int value)
    {
        switch (value) {
        case -1:
            _value = UNDEFINED;
            break;
        case 0:
            _value = FALSE;
            break;
        case 1:
            _value = TRUE;
            break;
        default:
            _value = UNDEFINED;
            break;
        }
    }

    bool Tristate::operator==(const Tristate &other) const {
        return _value == other._value;
    }

    bool Tristate::operator!=(const Tristate &other) const {
        return !(_value == other._value);
    }

    Tristate Tristate::operator&(const Tristate &other) const {
        if (_value == TRUE && other._value == TRUE) {
            return Tristate(TRUE);
        }
        if (_value == FALSE || other._value == FALSE) {
            return Tristate(FALSE);
        }
        return Tristate(UNDEFINED);
    }

    Tristate Tristate::operator|(const Tristate &other) const {
        if (_value == FALSE && other._value == FALSE) {
            return Tristate(FALSE);
        }
        if (_value == TRUE || other._value == TRUE) {
            return Tristate(TRUE);
        }
        return Tristate(UNDEFINED);
    }

    Tristate Tristate::operator^(const Tristate &other) const {
        if (_value == UNDEFINED || other._value == UNDEFINED) {
            return Tristate(UNDEFINED);
        }
        return Tristate(_value != other._value);
    }

    Tristate Tristate::operator!() const {
        switch (_value) {
            case UNDEFINED:
                return Tristate(UNDEFINED);
                break;
            case TRUE:
                return Tristate(FALSE);
                break;
            case FALSE:
                return Tristate(TRUE);
                break;
            default:
                return Tristate(UNDEFINED);
                break;
        }
    }

    std::ostream& Tristate::display(std::ostream& os) const
    {
        switch (_value) {
        case FALSE:
            os << "0";
            break;
        case TRUE:
            os << "1";
            break;
        case UNDEFINED:
            os << "U";
            break;
        default:
            break;
        }
        return os;
    }

    std::ostream& operator<<(std::ostream& os, const Tristate &tristate)
    {
        return tristate.display(os);
    }

}