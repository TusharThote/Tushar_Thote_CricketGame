#ifndef _TEAM_H_
#define _TEAM_H_
#pragma once

#include <string>
#include <vector>
#include <memory>
#include "Player.h"

class Team {
private:
    std::string name;
    std::vector<std::unique_ptr<Player>> players;

public:
    Team(const std::string& name);

    void AddPlayer(std::unique_ptr<Player> player);
    const std::string& GetName() const;
    const std::vector<std::unique_ptr<Player>>& GetPlayers() const;
    void DisplayPlayers() const;
};

#endif
