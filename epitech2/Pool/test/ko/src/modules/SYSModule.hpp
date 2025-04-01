/*
** EPITECH PROJECT, 2025
** SystemModule.hpp
** File description:
** SystemModule
*/

#ifndef SYSTEMMODULE_HPP_
#define SYSTEMMODULE_HPP_

#include "../include/IModule.hpp"

namespace Krell {
    class SYSModule : public IModule {
    public:
        SYSModule();
        void updateData() override;
        std::string getName() const override;
        std::string getData() const override;
        bool isExpanded() const override {
            return _isExpanded;
        }
        void toggleExpanded() override {
            _isExpanded = !_isExpanded;
        }

    private:
        std::string _name;
        std::string _hostname;
        std::string _username;
        std::string _os;
        std::string _kernel;

        std::string getHostname();
        std::string getUsername();
        std::string getOs();
        std::string getDistribution();
        bool _isExpanded = true;


    };
}

#endif /* !SYSTEMMODULE_HPP_ */
