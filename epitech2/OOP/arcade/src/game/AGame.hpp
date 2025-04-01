/*
** EPITECH PROJECT, 2025
** arcade
** File description:
** AGame
*/

#pragma once

#include <vector>
#include <utility>
#include <algorithm>
#include <filesystem>

#include "IGame.hpp"
#include "MapCell.hpp"

class AGame : public IGame
{
    protected:
        std::vector<std::vector<MapCell>> _map;
        std::vector<std::pair<std::string, std::string>> _bestScores;
        std::string _name;
        std::string _userName;
        bool _paused;
        bool _over;
        bool _running;
        float _lastUpdate;
        bool _isUpdated;
        const int WIDTH = 40;
        const int HEIGHT = 40;

        void _saveBestScore(const std::string &name, const std::string &score)
        {
            _over = true;
            _bestScores.push_back({name, score});
            std::sort(_bestScores.begin(), _bestScores.end(), [](const std::pair<std::string, std::string> &a, const std::pair<std::string, std::string> &b)
            {
                int scoreA = std::stoi(a.second);
                int scoreB = std::stoi(b.second);
                if (scoreA == scoreB)
                {
                    return a.first < b.first;
                }
                return scoreA > scoreB;
            });
            if (_bestScores.size() > 10)
            {
                _bestScores.pop_back();
            }
            std::filesystem::create_directory("scores");
            FILE *file = fopen(("scores/" + _name + ".txt").c_str(), "w");
            if (file == nullptr)
            {
                return;
            }
            for (const auto &score : _bestScores)
            {
                fprintf(file, "%s %s\n", score.first.c_str(), score.second.c_str());
            }
            fclose(file);
        }

    public:
        AGame(const std::string &name, const std::string &userName = "Undefined")
            : _name(name), _userName(userName), _paused(false), _over(false), _running(true), _lastUpdate(0), _isUpdated(false)
        {
            FILE *file = fopen(("scores/" + _name + ".txt").c_str(), "r");
            if (file == nullptr)
            {
                return;
            }
            for (int i = 0; i < 10; i++)
            {
                char name[100];
                char score[100];
                if (fscanf(file, "%s %s", name, score) != 2)
                {
                    break;
                }
                _bestScores.push_back({name, score});
            }
            fclose(file);
        }

        ~AGame() = default;

        virtual void update(float) override {}
        virtual void handleEvent(std::vector<Event>) override {}
        virtual void display(std::shared_ptr<IGraphical>) override {}
        bool isPaused() const final { return _paused; }
        void setPaused(bool paused) final { _paused = paused; }
        bool isOver() const final { return _over; }
        void restart() final { _over = false; _paused = false; _running = true; }
        bool isRunning() const final { return _running; }
        std::string getName() const final {return _name; }
};
