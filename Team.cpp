#include <iostream>
#include "Team.h"

Team::Team(const std::string& name) : name(name) {}

void Team::AddPlayer(std::unique_ptr<Player> player) {
    players.push_back(std::move(player));
}

const std::string& Team::GetName() const {
    return name;
}

const std::vector<std::unique_ptr<Player>>& Team::GetPlayers() const {
    return players;
}

void Team::DisplayPlayers() const {
    std::cout << "Team: " << name << std::endl;
    std::cout << "---------------------------" << std::endl;

    int i = 1;
    for (const auto &player : players) {
        std::cout << i++ << ". " << player->GetName() << player->PlayerCategory() << std::endl;
    }
    std::cout << "---------------------------\n" << std::endl;
}