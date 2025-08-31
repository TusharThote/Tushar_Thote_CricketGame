#include "Umpire.h"
#include <iostream>
#include <limits>

Umpire::Umpire(const std::string& name) : name(name) {}

void Umpire::UmpireDecision() {
    std::cout << name << " makes a decision!\n\n" << std::endl;
}

void BattingTeam(int decision, std::string OppTeamName, std::string UserTeamName)
{
    if(decision == 1)
    {
        std::cout<<"\n\nTeam "<<UserTeamName<<" has completed the batting \n \n";
        std::cout<<"Team "<< UserTeamName<<" WON the Match by 10 Run \n\n";
        
    }
    else{
        std::cout<<"\n\nTeam "<<OppTeamName<<" has completed the batting \n \n";
        std::cout<<"Team "<< UserTeamName<<" LOOSE the Match by 10 Run \n\n";
    }
}

int Toss() {
    int choice;
    std::cout << "\n===== Let's take a Toss =====\n";
    std::cout << "Please choose 1 for Head & 2 for Tail: ";
    std::cin >> choice;

    // By default user wins
    std::cout << "\n **** You won the toss! **** \n" << std::endl;

    int decision;
    std::cout << "What do you want to do?\n";
    std::cout << "Enter 1 for Batting\n";
    std::cout << "Enter 2 for Bowling\n";
    std::cin >> decision;

    if (decision == 1) {
        std::cout << "You chose Batting first.\n\n";
    } else if (decision == 2) {
        std::cout << "You chose Bowling first.\n\n";
    } else {
        std::cout << "Invalid choice! Defaulting to Batting.\n\n";
    }
    return decision;
}