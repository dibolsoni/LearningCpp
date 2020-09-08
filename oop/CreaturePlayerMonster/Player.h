#ifndef PLAYER_H
#define PLAYER_H

#include "Creature.h"

#include <string>

class Player: public Creature
{
unsigned int p_level;

public:
    Player(std::string name)
        : Creature{name, '@', 10, 1, 0}, p_level{1}
    {}

    inline unsigned int getLevel() const {return p_level;}
    
    inline void levelUp() {p_level += 1;}
    inline bool hasWon(){return p_level >= 20;}
};

#endif