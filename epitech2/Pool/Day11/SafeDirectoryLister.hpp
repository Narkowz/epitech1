/*
** EPITECH PROJECT, 2025
** SafeDirectoryLister.hpp
** File description:
** SafeDirectoryLister
*/

#ifndef SAFEDIRECTORYLISTER_HPP_
#define SAFEDIRECTORYLISTER_HPP_

#include "IDirectoryLister.hpp"
#include <string>
#include <dirent.h>

class SafeDirectoryLister : public IDirectoryLister {
private:
    DIR* dir;
    bool showHidden;
    SafeDirectoryLister(const SafeDirectoryLister&) = delete;
    SafeDirectoryLister& operator=(const SafeDirectoryLister&) = delete;
    SafeDirectoryLister(SafeDirectoryLister&&) = delete;
    SafeDirectoryLister& operator=(SafeDirectoryLister&&) = delete;
public:
    SafeDirectoryLister();
    SafeDirectoryLister(const std::string& path, bool hidden);
    ~SafeDirectoryLister();
    bool open(const std::string& path, bool hidden) override;
    std::string get() override;
};

#endif /* !SAFEDIRECTORYLISTER_HPP_ */
