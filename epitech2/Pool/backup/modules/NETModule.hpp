/*
** EPITECH PROJECT, 2025
** ncursesDisplay.hpp
** File description:
** ncursesDisplay
*/

#ifndef NETWORKMODULE_HPP_
#define NETWORKMODULE_HPP_

#include "../include/IModule.hpp"
#include <string>
#include <vector>
#include <map>

namespace Krell {
    class NETModule : public IModule {
    public:
        NETModule();
        void updateData() override;
        std::string getName() const override;
        std::string getData() const override;

    private:
        std::string _name;
        std::string _ipAddress;
        std::string _networkInterface;
        std::string _downloadSpeed;
        std::string _uploadSpeed;
        std::string _ipAddressWifi;
        std::string _packets;
        std::map<std::string, unsigned long long> previousReceivedPackets;
        std::map<std::string, unsigned long long> previousSentPackets;
        
        std::string getIpAddress(const std::string& interface);
        std::string getEthernetIpAddress();
        std::string getWifiIpAddress();
        std::string getNetworkInterface();
        std::string getPackets();
        std::string getMacReceivedPackets();
        std::string getMacSentPackets();
        std::string getLinuxReceivedPackets();
        std::string getLinuxSentPackets();

    };
};

#endif /* !NETWORKMODULE_HPP_ */
