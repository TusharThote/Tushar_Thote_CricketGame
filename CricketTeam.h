#ifndef _CRICKETTEAM_H_
#define _CRICKETTEAM_H_

#pragma once
#include <string>
#include "Player.h"

class Batsman : public Player {
public:
    Batsman();
    Batsman(std::string name);
    std::string PlayerCategory() override;
};

class Bowler : public Player {
public:
    Bowler();
    Bowler(std::string name);
    std::string PlayerCategory() override;
};

class WicketKeeper : public Player {
public:
    WicketKeeper();
    WicketKeeper(std::string name);
    std::string PlayerCategory() override;
};

class Fielder : public Player {
public:
    Fielder();
    Fielder(std::string name);
    std::string PlayerCategory() override;
};

#endif