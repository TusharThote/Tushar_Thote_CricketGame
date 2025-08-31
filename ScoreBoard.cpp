#include "ScoreBoard.h"
#include "Umpire.h"

void ScoreBoard::AddPlayer(const std::string& name) {
    playerScores[name] = 0;
}

void ScoreBoard::UpdateScore(const std::string& name, int r) {
    runs += r;
    playerScores[name] += r;
}

void ScoreBoard::UpdateWicket(int count) {
    wickets += count;
}

void ScoreBoard::UpdateOver(int count) {
    overs += count;
}

void ScoreBoard::DisplayBoard() {
    std::cout << "Score: " << runs << "/" << wickets << " in " << overs << " overs\n\n";
    for (const auto& entry : playerScores) {
        std::cout << entry.first << " scored " << entry.second << " runs\n";
    }
}
