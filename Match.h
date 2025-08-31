#ifndef _MATCH_H_
#define _MATCH_H_
#pragma once

#include <vector>
#include <iostream>
#include <memory>
#include "Team.h"
#include "Umpire.h"
#include "ScoreBoard.h"

class Match {
private:
    std::vector<std::unique_ptr<Team>> teams;
    std::vector<std::unique_ptr<Umpire>> umpires;
    ScoreBoard scoreboard;
    int oversPlayed;
    int wicketsFallen;

public:
    Match(std::vector<std::unique_ptr<Team>>&& teams,
          std::vector<std::unique_ptr<Umpire>>&& umpires);

    void play(std::unique_ptr<Team> obj);
    ScoreBoard& getScoreBoard();
};

#endif
