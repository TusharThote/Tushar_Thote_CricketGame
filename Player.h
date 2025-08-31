#ifndef _PLAYER_H_
#define _PLAYER_H_

#pragma once
#include "Person.h"

class Player : public Person {
public:
    Player();
    Player(std::string name);
    virtual std::string PlayerCategory() = 0;
    std::string GetName();
};

#endif
