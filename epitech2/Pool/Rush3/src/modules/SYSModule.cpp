/*
** EPITECH PROJECT, 2025
** SystemModule.cpp
** File description:
** SystemModule
*/

#include <fstream>
#include <sstream>
#include <thread>
#include <chrono>
#include <iomanip>
#include <string>
//#include <vector>
#include <unistd.h>
#include <cstring>
#include <cstdio>
#include <iostream>
#include "SYSModule.hpp"

namespace Krell {
    SYSModule::SYSModule() : _name("System"), _hostname("root") {}

    void SYSModule::updateData()
    {
        _hostname = getHostname();
        _username = getUsername();
        _os = getOs();
        _kernel = getDistribution();
    }

    std::string SYSModule::getName() const
    {
        return _name;
    }

    std::string getDateTime()
    {
        auto now = std::chrono::system_clock::now(); // get l'instant T
        std::time_t now_c = std::chrono::system_clock::to_time_t(now); // temps écoulé depuis le 1er janvier 70

        std::tm *tm_ptr = std::localtime(&now_c); // formatage local
        
        std::stringstream ss; // string ou on va stocker l'heaure
        ss << std::put_time(tm_ptr, "%Y-%m-%d %H:%M:%S"); // put time permet de formater l'heure comme on veut
        
        return ss.str(); // return l'heure formatée
    }

    std::string SYSModule::getData() const
    {
        std::ostringstream oss;
        oss << "Date & Hour: " << getDateTime() << std::endl;
        auto batteryStatus = getBatteryStatus();
        oss << "Battery: " << batteryStatus.first << " (" << batteryStatus.second << "%)" << std::endl;
        oss << "Hostname: " << _hostname << std::endl;
        oss << "Username: " << _username << std::endl;
        oss << "OS: " << _os << std::endl;
        oss << "Kernel: " << _kernel << std::endl;
        return oss.str();
    }

    std::string SYSModule::getHostname()
    {
        char hostname[500];
        gethostname(hostname, 500);
        return hostname;
    }

    std::string SYSModule::getUsername()
    {
        return getlogin();
    }

    std::string SYSModule::getOs()
    {
        std::string os;
        char buffer[128];
        FILE* fp = popen("uname", "r");
        if (fp == nullptr)
            return "ERROR";

        if (fgets(buffer, sizeof(buffer), fp) != nullptr)
            os = buffer;
        pclose(fp);
        if (!os.empty() && os.back() == '\n')
            os.pop_back();

        if (os == "Darwin")
            return "MacOS";
        else if (os == "Linux")
            return "Linux";
        else
            return "UNKNOWN OS";
    }

    #ifdef __linux__
    std::string SYSModule::getDistribution()
    {

        std::ifstream file("/etc/os-release");
        std::string line;
        std::string name;
        while (std::getline(file, line)) {
            if (line.find("PRETTY_NAME") != std::string::npos) {
                name = line.substr(line.find("\"") + 1);
                if (!name.empty() && name.back() == '"')
                    name.pop_back();
                break;
            }
        }
        file.close();
        std::string formattedName;
        int count = 0;
        for (size_t i = 0; i < name.length(); ++i) {
            formattedName += name[i];
            if (count == 0 && (i + 1) % 16 == 0) {
                formattedName += "\n\t     ";
                count++;
            }
        }
        return formattedName;
    }

    std::pair<std::string, int> SYSModule::getBatteryStatus() const
    {
        FILE* pipe = popen("upower -i $(upower -e | grep 'BAT') | grep -E \"state|percentage\"", "r");
        if (!pipe) return {"Unknown", -1};
    
        char buffer[128];
        std::string result;
        std::string state;
        int percentage = -1;
    
        while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
            result = buffer;
            std::istringstream iss(result);
            std::string key, value;
            iss >> key >> value;
    
            if (key == "state:")
                iss >> state;
            else if (key == "percentage:")
                iss >> percentage;
        }
        pclose(pipe);
        return {state, percentage};
    }

    #elif __APPLE__
    
        #include <iostream>
        #include <sys/utsname.h>

    std::string SYSModule::getDistribution()
    {
        std::string formattedName;
        struct utsname buffer;
        if (uname(&buffer) == 0)
            formattedName = buffer.release;
        else
            std::cerr << "Error retrieving system information." << std::endl;
        return formattedName;
    }

    std::pair<std::string, int> SYSModule::getBatteryStatus() const
    {
        FILE* pipe = popen("pmset -g batt | grep 'InternalBattery'", "r");
        if (!pipe) return {"Unknown", -1};

        char buffer[128];
        std::string result;
        std::string state;
        int percentage = -1;

        if (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
            result = buffer;
            std::istringstream iss(result);
            std::string token;

            while (iss >> token) {
                if (token.find("%") != std::string::npos)
                    percentage = std::stoi(token.substr(0, token.size() - 1));
                else if (token == "charging;" || token == "discharging;")
                    state = token.substr(0, token.size() - 1);
            }
        }
        pclose(pipe);

        return {state, percentage};
    }
    #endif

}
