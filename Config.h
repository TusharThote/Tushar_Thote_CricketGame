#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <iostream>
#include <memory>
#include <vector>
#include "CricketTeam.h"
#include "Team.h"

// Create India Team
std::unique_ptr<Team> CreateIndiaTeam() {
    auto team = std::make_unique<Team>("India");
    team->AddPlayer(std::make_unique<Batsman>("Shubman Gill"));
    team->AddPlayer(std::make_unique<Batsman>("Virat Kohli"));
    team->AddPlayer(std::make_unique<Bowler>("Jasprit Bumrah"));
    team->AddPlayer(std::make_unique<WicketKeeper>("KL Rahul"));
    team->AddPlayer(std::make_unique<Fielder>("Hardik Pandya"));
    return team;
}

// Create Pakistan Team
std::unique_ptr<Team> CreatePakistanTeam() {
    auto team = std::make_unique<Team>("Pakistan");
    team->AddPlayer(std::make_unique<Batsman>("Babar Azam"));
    team->AddPlayer(std::make_unique<Batsman>("Mohammad Rizwan"));
    team->AddPlayer(std::make_unique<Bowler>("Shaheen Afridi"));
    team->AddPlayer(std::make_unique<WicketKeeper>("Sarfaraz Ahmed"));
    team->AddPlayer(std::make_unique<Fielder>("Shadab Khan"));
    return team;
}

// Create Sri Lanka Team
std::unique_ptr<Team> CreateSriLankaTeam() {
    auto team = std::make_unique<Team>("Sri Lanka");
    team->AddPlayer(std::make_unique<Batsman>("Kusal Mendis"));
    team->AddPlayer(std::make_unique<Batsman>("Angelo Mathews"));
    team->AddPlayer(std::make_unique<Bowler>("Lasith Malinga"));
    team->AddPlayer(std::make_unique<WicketKeeper>("Kumar Sangakkara"));
    team->AddPlayer(std::make_unique<Fielder>("Mahela Jayawardene"));
    return team;
}

#endif