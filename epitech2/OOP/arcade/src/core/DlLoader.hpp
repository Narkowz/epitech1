/*
** EPITECH PROJECT, 2025
** arcade
** File description:
** DlLoader
*/

#pragma once

#include <string>
#include <stdexcept>
#include <dlfcn.h>
#include <memory>

#include "IGame.hpp"
#include "IGraphical.hpp"

template <typename T>
class DLLoader
{
    private:
        void* handle;

    public:
        explicit DLLoader(const std::string& libPath)
        {
            handle = dlopen(libPath.c_str(), RTLD_NOW);
            if (!handle)
            {
                throw std::runtime_error("Library loading failed" + std::string(dlerror()));
            }
        }

        ~DLLoader()
        {
            if (handle)
            {
                dlclose(handle);
            }
        }

        T* getInstance(const std::string& symbol = "getInstance")
        {
            void* sym = dlsym(handle, symbol.c_str());
            if (!sym)
            {
                throw std::runtime_error("Symbol loading failed");
            }

            using CreateFunc = T* (*)();
            CreateFunc createInstance = reinterpret_cast<CreateFunc>(sym);

            T* instance = createInstance();
            if (!instance)
            {
                throw std::runtime_error("Failed to create instance of type " + std::string(typeid(T).name()));
            }
            return instance;
        }

        std::string getName(const std::string& symbol)
        {
            using FuncPtr = const char* (*)();

            FuncPtr func = (FuncPtr)dlsym(handle, symbol.c_str());

            if (!func)
            {
                throw std::runtime_error("Symbol loading failed");
            }
            return func();
        }
};
