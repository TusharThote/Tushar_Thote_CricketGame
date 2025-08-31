#ifndef _UMPIRE_H_
#define _UMPIRE_H_
#pragma once
#include <string>

void BattingTeam(int decision, std::string OppTeamName, std::string UserTeamName);
int Toss();

class Umpire {
private:
    std::string name;

public:
    Umpire(const std::string& name);
    void UmpireDecision();

    std::string GetName() const { return name; }
};

#endif
