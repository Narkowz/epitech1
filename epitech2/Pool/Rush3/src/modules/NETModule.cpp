/*
** EPITECH PROJECT, 2025
** ncursesDisplay.cpp
** File description:
** ncursesDisplay
*/

#include "NETModule.hpp"
#include <iostream>
#include <sstream>
#include <array>
#include <memory>
#include <stdexcept>
#include <string>
#include <ifaddrs.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstdlib>
#include <fstream>

namespace Krell {
    NETModule::NETModule() : _name("Network") {}

    void NETModule::updateData()
    {
        _ipAddress = getEthernetIpAddress();
        _networkInterface = getNetworkInterface();
        _ipAddressWifi = getWifiIpAddress();
        _packets = getPackets();

    }

    std::string NETModule::getName() const
    {
        return _name;
    }

    std::string NETModule::getData() const
    {
        std::stringstream ss;
        ss << "IP Address (Ethernet):  " << _ipAddress << "\n";
        ss << "IP Address (Wi-Fi):  " << _ipAddressWifi << "\n";
        ss << "Network Interface:  " << _networkInterface << "\n";
        ss << "Packets Received:  " << _packets << "\n";
        return ss.str();
    }
};

    std::string Krell::NETModule::getIpAddress(const std::string& interface)
    {
        struct ifaddrs *interfaces = nullptr;
        struct ifaddrs *ifa = nullptr;
        std::string ipAddress = "";

        if (getifaddrs(&interfaces) == 0) {
            for (ifa = interfaces; ifa != nullptr; ifa = ifa->ifa_next) {
                if (ifa->ifa_addr->sa_family == AF_INET) {
                    if (interface == ifa->ifa_name) {
                        char ip[INET_ADDRSTRLEN];
                        inet_ntop(AF_INET, &((struct sockaddr_in*)ifa->ifa_addr)->sin_addr, ip, INET_ADDRSTRLEN);
                        ipAddress = std::string(ip);
                        break;
                    }
                }
            }
            freeifaddrs(interfaces);
        }
        return ipAddress.empty() ? "N/A" : ipAddress;
    }

    std::string Krell::NETModule::getEthernetIpAddress() 
    {
        #ifdef __APPLE__
            return getIpAddress("en0");
        #elif  __linux__
            return getIpAddress("eth0"); // Interface Ethernet par défaut sur Linux
        #endif
    }

    //macOs
    std::string Krell::NETModule::getWifiIpAddress()
    {
        #ifdef __APPLE__ 
            return getIpAddress("en1");
        #elif  __linux__
            return getIpAddress("wlan0");
        #endif
    }


    std::string Krell::NETModule::getNetworkInterface()
    {
        struct ifaddrs *interfaces = nullptr;
        struct ifaddrs *ifa = nullptr;
        std::string networkInterface = "";

        if (getifaddrs(&interfaces) == 0) {
            for (ifa = interfaces; ifa != nullptr; ifa = ifa->ifa_next) {
                if (ifa->ifa_addr->sa_family == AF_INET && 
                    (std::string(ifa->ifa_name) == "en0" || std::string(ifa->ifa_name) == "wlan0")) {
                    networkInterface = ifa->ifa_name;
                    break;
                }
            }
            freeifaddrs(interfaces);
        }
        return networkInterface;
    }

    std::string Krell::NETModule::getMacReceivedPackets()
    {
        static unsigned long long previousPackets = 0;
        std::string command = "netstat -i | grep en0 | awk '{print $7}'";  
        char buffer[128];
        unsigned long long currentPackets = 0;

        FILE* fp = popen(command.c_str(), "r");
        if (fp != nullptr) {
            if (fgets(buffer, sizeof(buffer), fp) != nullptr) {
                try {
                    currentPackets = std::stoull(buffer);
                } catch (...) {
                    return "Error reading packets";
                }
            }
            pclose(fp);
        }

        unsigned long long diff = (currentPackets > previousPackets) ? (currentPackets - previousPackets) : 0;
        previousPackets = currentPackets;

        return std::to_string(diff);
    }

    std::string Krell::NETModule::getMacSentPackets()
    {
        static unsigned long long previousPackets = 0;
        std::string command = "netstat -i | grep en0 | awk '{print $10}'";  
        char buffer[128];
        unsigned long long currentPackets = 0;

        FILE* fp = popen(command.c_str(), "r");
        if (fp != nullptr) {
            if (fgets(buffer, sizeof(buffer), fp) != nullptr) {
                try {
                    currentPackets = std::stoull(buffer);
                } catch (...) {
                    return "Error reading packets";
                }
            }
            pclose(fp);
        }

        unsigned long long diff = (currentPackets > previousPackets) ? (currentPackets - previousPackets) : 0;
        previousPackets = currentPackets;

        return std::to_string(diff);
    }

    std::string Krell::NETModule::getLinuxReceivedPackets()
    {
        static unsigned long long previousPackets = 0;
        std::ifstream file("/proc/net/dev");
        std::string line;
        unsigned long long currentPackets = 0;

        if (file.is_open()) {
            while (std::getline(file, line)) {
                if (line.find("eth0") != std::string::npos) {
                    std::istringstream ss(line);
                    std::string iface;
                    ss >> iface >> currentPackets;
                    break;
                }
            }
            file.close();
        }

        unsigned long long diff = (currentPackets > previousPackets) ? (currentPackets - previousPackets) : 0;
        previousPackets = currentPackets;

        return std::to_string(diff);
    }

    std::string Krell::NETModule::getLinuxSentPackets()
    {
        static unsigned long long previousPackets = 0;
        std::ifstream file("/proc/net/dev");
        std::string line;
        unsigned long long currentPackets = 0;

        if (file.is_open()) {
            while (std::getline(file, line)) {
                if (line.find("eth0") != std::string::npos) {
                    std::istringstream ss(line);
                    std::string iface;
                    unsigned long long temp;  
                    ss >> iface >> temp >> temp >> temp >> temp >> temp >> temp >> temp >> currentPackets;
                    break;
                }
            }
            file.close();
        }

        unsigned long long diff = (currentPackets > previousPackets) ? (currentPackets - previousPackets) : 0;
        previousPackets = currentPackets;

        return std::to_string(diff);
    }

    std::string Krell::NETModule::getPackets()
    {
        #ifdef __APPLE__
            return getMacReceivedPackets() + " Packets Sent: " + getMacSentPackets();
        #elif __linux__ 
            return getLinuxReceivedPackets() + " Packets Sent: " + getLinuxSentPackets();
        #endif
    }
