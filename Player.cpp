#include "Player.h"
#include <iostream>

Player::Player() : Player("UnKnownPlayer") {}

Player::Player(std::string name) : Person(name) {}

std::string Player::GetName() {
    return GetPersonName();
}
