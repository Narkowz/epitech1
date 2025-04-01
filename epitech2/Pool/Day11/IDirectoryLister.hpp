/*
** EPITECH PROJECT, 2025
** IDirectoryLister.hpp
** File description:
** IDirectoryLister
*/

#ifndef IDIRECTORYLISTER_HPP_
#define IDIRECTORYLISTER_HPP_

#include <string>
#include <exception>
#include <cstring>

class IDirectoryLister {
public:
    virtual ~IDirectoryLister() {}
    class OpenFailureException : public std::exception {
    private:
        std::string message;
    public:
        OpenFailureException()
        {
            message = std::strerror(errno);
        }
        const char* what() const noexcept override
        {
            return message.c_str();
        }
    };
    class NoMoreFileException : public std::exception {
    public:
        const char* what() const noexcept override
        {
            return "End of stream";
        }
    };
    virtual bool open(const std::string& path, bool hidden) = 0;
    virtual std::string get() = 0;
};

#endif /* !IDIRECTORYLISTER_HPP_ */
