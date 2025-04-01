/*
** EPITECH PROJECT, 2025
** StupidUnitConverter.cpp
** File description:
** StupidUnitConverter
*/

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cmath>

int main(void)
{
    std::string line;
    while (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        double temperature;
        std::string scale;
        if (!(ss >> temperature >> scale))
            continue;
        if (scale == "Celsius") {
            double fahrenheit = (temperature * 9.0 / 5.0) + 32.0;
            std::cout << std::setw(16) << std::fixed << std::setprecision(3) << fahrenheit
                      << std::setw(16) << "Fahrenheit" << std::endl;
        } else if (scale == "Fahrenheit") {
            double celsius = 5.0 / 9.0 * (temperature - 32.0);
            std::cout << std::setw(16) << std::fixed << std::setprecision(3) << celsius
                      << std::setw(16) << "Celsius" << std::endl;
        }
    }
    return 0;
}