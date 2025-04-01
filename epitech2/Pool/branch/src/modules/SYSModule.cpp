/*
** EPITECH PROJECT, 2025
** SystemModule.cpp
** File description:
** SystemModule
*/

#include "SYSModule.hpp"

namespace Krell {
    SYSModule::SYSModule() : _name("System"), _hostname("root") {}

    void SYSModule::updateData() {
        _hostname = getHostname();
        _username = getUsername();
        _os = getOs();
        _kernel = getDistribution();
    }

    std::string SYSModule::getName() const
    {
        return _name;
    }

    std::string getDateTime() {
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
        const char* os = std::getenv("OSTYPE");
        if (os == nullptr) {
            char buffer[128];
            FILE* fp = popen("uname", "r");
            if (fp == nullptr) {
                std::cerr << "Impossible d'obtenir le nom de l'OS." << std::endl;
                return "ERROR";
            }
            if (fgets(buffer, sizeof(buffer), fp) != nullptr)
                os = buffer;
            fclose(fp);
        }

        os = os ? os : "";
        size_t len = std::strlen(os);
        if (len > 0 && os[len - 1] == '\n')
            const_cast<char*>(os)[len - 1] = '\0';
        if (std::strcmp(os, "Darwin") == 0)
            return "MacOS";
        else if (std::strcmp(os, "Linux") == 0)
            return "Linux";
        else
            return "ERROR";
    }

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

}
