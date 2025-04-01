/*
** EPITECH PROJECT, 2025
** DirectoryLister.hpp
** File description:
** DirectoryLister
*/

#ifndef DIRECTORYLISTER_HPP_
#define DIRECTORYLISTER_HPP_

#include "IDirectoryLister.hpp"
#include <string>
#include <dirent.h>

class DirectoryLister : public IDirectoryLister {
private:
    DIR* dir;
    bool showHidden;
    DirectoryLister(const DirectoryLister&) = delete;
    DirectoryLister& operator=(const DirectoryLister&) = delete;
    DirectoryLister(DirectoryLister&&) = delete;
    DirectoryLister& operator=(DirectoryLister&&) = delete;
public:
    DirectoryLister();
    DirectoryLister(const std::string& path, bool hidden);
    ~DirectoryLister();
    bool open(const std::string& path, bool hidden) override;
    std::string get() override;
};

#endif /* !DIRECTORYLISTER_HPP_ */
