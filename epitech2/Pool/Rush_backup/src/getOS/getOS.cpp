/*
** EPITECH PROJECT, 2025
** getOS.cpp
** File description:
** getOS
*/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <fstream>
#include <sstream>
#include "getOS.hpp"
#include "../../MyGKrellm.hpp"

int getOS()
{
    const char* os = std::getenv("OSTYPE");                                     // Récupère la variable d'environnement OSTYPE
    if (os == nullptr) {                                                        // Si la variable n'existe pas
        char buffer[128];                                                       // Créer un buffer de 128 octets
        FILE* fp = popen("uname", "r");                                         // Ouvre un flux de commande pour obtenir le nom de l'OS
        if (fp == nullptr) { 
            std::cerr << "Impossible d'obtenir le nom de l'OS." << std::endl;   // Si on ne peut pas ouvrir le flux, on affiche une erreur
            return 1; 
        }
        if (fgets(buffer, sizeof(buffer), fp) != nullptr)                       // Si on peut lire le nom de l'OS
            os = buffer;                                                        // On stocke le nom de l'OS dans la variable os
        fclose(fp);                                                             // On ferme le flux
    }

    os = os ? os : "";                                                          // Si os est nul, on le remplace par une chaine vide
    size_t len = std::strlen(os);                                               // On récupère la taille de la chaine
    if (len > 0 && os[len - 1] == '\n')                                         // Si le dernier caractère est un retour à la ligne
        const_cast<char*>(os)[len - 1] = '\0';                                  // On le remplace par un caractère nul
    if (std::strcmp(os, "Darwin") == 0)                                         // Si le nom de l'OS est "Darwin" (MacOS)
        return MACOS;                                                           // On retourne 0
    else if (std::strcmp(os, "Linux") == 0)                                     // Si le nom de l'OS est "Linux"
        return LINUX;                                                           // On retourne 1
    else                                                                        // Sinon
        return ERROR;                                                           // On retourne 84
}
