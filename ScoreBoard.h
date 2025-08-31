#ifndef _SCOREBOARD_H_
#define _SCOREBOARD_H_

#include <iostream>
#include <map>
#include <string>

class ScoreBoard {
    std::map<std::string, int> playerScores;
    int runs{0}, wickets{0}, overs{0};
public:
    void AddPlayer(const std::string& name);
    void UpdateScore(const std::string& name, int r);
    void UpdateWicket(int count = 1);
    void UpdateOver(int count = 1);
    void DisplayBoard();
};

#endif
