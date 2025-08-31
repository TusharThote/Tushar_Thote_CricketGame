#include "CricketTeam.h"
#include <iostream>
#include <memory>
#include <vector>
#include <limits>
#include "Match.h"
#include "Team.h"
#include "Player.h"
#include "Umpire.h"
#include "Config.h"

/***************************************************************************************
This function validates whether the user-entered values are within the allowed range.
If the value is not within the range, the user is asked to enter it again.
******************************************************************************************/
int GetValidatedInput(const std::string& msg, int min, int max) {
    int value;
    while (true) {
        std::cout << msg;
        if (std::cin >> value) {
            if (value >= min && value <= max) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // flush buffer
                return value;
            } else {
                std::cout << "Please enter a number between " << min << " and " << max << ".\n";
            }
        } else {
            std::cout << "Invalid input! Please enter a number.\n";
            std::cin.clear(); // reset fail state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard bad input
        }
    }
}

/***************************************************************************************
This function assigns a role to the player based on the user’s input.
******************************************************************************************/
std::unique_ptr<Player> Role(const std::string &name, int role)
{
    switch (role) {
        case 1: std::cout<<name<<" is a Batsman\n"; return std::make_unique<Batsman>(name);
        case 2: std::cout<<name<<" is a Bowler\n"; return std::make_unique<Bowler>(name);
        case 3: std::cout<<name<<" is a WicketKeeper\n"; return std::make_unique<WicketKeeper>(name);
        case 4: std::cout<<name<<" is a Fielder\n"; return std::make_unique<Fielder>(name);
        default: std::cout<<name<<" has given Invalid role\n"; return nullptr;
    }
}

/***************************************************************************************
This function creates the number of players (maximum 5) as requested by the user.
******************************************************************************************/
std::unique_ptr<Player> CreatePlayer() {
    std::string name;
    std::cout << "Enter player name: ";
    std::getline(std::cin, name);

    int role = GetValidatedInput(
        "Assign the Player Role:\n"
        "1. Batsman\n"
        "2. Bowler\n"
        "3. WicketKeeper\n"
        "4. Fielder\n"
        "Enter choice: ",
        1, 4);

    return Role(name, role);
}

/***************************************************************************************
This is our main entry point function
******************************************************************************************/
int main() {
    std::cout << "*********** WELCOME TO CRICKET GAME ********** " <<std::endl;

    std::vector<std::unique_ptr<Team>> teams;

    // Choose Opponent
    int choice = GetValidatedInput("Choose your opponent Team:\n1. India\n2. Pakistan\n3. Sri Lanka\nEnter choice: ", 1, 3);

    std::unique_ptr<Team> opponent;
    if (choice == 1) opponent = CreateIndiaTeam();
    else if (choice == 2) opponent = CreatePakistanTeam();
    else opponent = CreateSriLankaTeam();

    // Show Opponent
    opponent->DisplayPlayers();

    // Create User Team
    std::string teamName;
    std::cout << "Enter name for your Team: ";
    std::getline(std::cin, teamName);

    auto team = std::make_unique<Team>(teamName);

    int numPlayers = GetValidatedInput("Enter number of players for your team (1-5): ", 1, 5);

    for (int j = 0; j < numPlayers; j++) {
        std::cout << "\n--- Player " << j + 1 << " ---"<<std::endl;
        team->AddPlayer(CreatePlayer());
    }

    std::string opponentTeamName = opponent->GetName();
    std::string UserTeamName = team->GetName();

    teams.push_back(std::move(team));

    // Display user team
    std::cout << "\n===== Your Team =====\n";
    for (const auto& t : teams) {
        t->DisplayPlayers();
    }

    // Umpires
    int numUmpires = GetValidatedInput("Enter number of umpires (1-3): ", 1, 3);

    std::vector<std::unique_ptr<Umpire>> umpires;
    for (int i = 0; i < numUmpires; i++) {
        std::string umpName;
        std::cout << "Enter umpire " << i + 1 << " name: ";
        std::getline(std::cin, umpName);
        umpires.push_back(std::make_unique<Umpire>(umpName));
    }

    // Toss
    int decision = Toss();

    // Create Match
    auto match = std::make_unique<Match>(std::move(teams), std::move(umpires));
    match->play(std::move(opponent));

    BattingTeam(decision, opponentTeamName, UserTeamName);

    return 0;
}
