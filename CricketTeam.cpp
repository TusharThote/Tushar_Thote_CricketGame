#include <iostream>
#include "CricketTeam.h"

Batsman::Batsman():Batsman("UnKnownBatsman"){}

Batsman::Batsman(std::string name): Player(name) {}

std::string Batsman::PlayerCategory()
{
    return " is Batsman \n";
}

Bowler::Bowler():Bowler("UnKnownBowler"){}

Bowler::Bowler(std::string name): Player(name) {}

std::string Bowler::PlayerCategory()
{ 
    return " is Bowler \n"; 
}


WicketKeeper::WicketKeeper():WicketKeeper("UnKnownWicketKeeper"){}

WicketKeeper::WicketKeeper(std::string name): Player(name) {}

std::string WicketKeeper::PlayerCategory()
{ 
    return " is WicketKeeper \n"; 
}


Fielder::Fielder():Fielder("UnKnownFielder"){}

Fielder::Fielder(std::string name): Player(name) {}

std::string Fielder::PlayerCategory()
{ 
    return " is Fielder \n";
}