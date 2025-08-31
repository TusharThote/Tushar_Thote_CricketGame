#include "Match.h"
#include <iostream>
#include <cstdlib>

Match::Match(std::vector<std::unique_ptr<Team>>&& teams,
             std::vector<std::unique_ptr<Umpire>>&& umpires)
    : teams(std::move(teams)), umpires(std::move(umpires)), oversPlayed(0), wicketsFallen(0) 
{
    for (auto& team : this->teams) {
        for (auto& player : team->GetPlayers()) {
            scoreboard.AddPlayer(player->GetName());
        }
    }
}

void Match::play(std::unique_ptr<Team> obj) {
    std::cout << "Match started between "<<teams[0]->GetName();
    std::cout << " and "<<obj->GetName()<< std::endl;

    for (auto& team : teams) {
        for (auto& player : team->GetPlayers()) {
            scoreboard.UpdateScore(player->GetName(), rand() % 100);
        }
    }

    oversPlayed = 20;
    wicketsFallen = 8;
    scoreboard.UpdateOver(oversPlayed);
    scoreboard.UpdateWicket(wicketsFallen);

    for (auto& umpire : umpires) {
        umpire->UmpireDecision();
    }

    scoreboard.DisplayBoard();
}

ScoreBoard& Match::getScoreBoard() {
    return scoreboard;
}
