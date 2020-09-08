#ifndef MONSTER_H
#define MONSTER_H

#include "Creature.h"
#include "../../effolkronium/random.hpp"
using Random = effolkronium::random_static;

#include <iostream>
#include <array>

class Monster: public Creature
{
public:
    enum TYPE{
        DRAGON,
        ORC, 
        SLIME,
        MAX_TYPES
    };
private:
    static const Creature getDefaultCreature(TYPE type)
    {
        static std::array<Creature, static_cast<std::size_t>(Monster::TYPE::MAX_TYPES)> monsterData{
            {
                { "dragon", 'D', 20, 4, 100 },
                { "orc", 'o', 4, 2, 25 },
                { "slime", 's', 1, 1, 10 } 
            }
        };
    
    return monsterData.at(static_cast<std::size_t>(type));
    }




public:
    Monster(TYPE monster_type)
    : Creature( this->getDefaultCreature(monster_type))
    {}

    static const TYPE getRandomMonster()
    {
        return static_cast<TYPE>(Random::get(0, static_cast<int>(TYPE::MAX_TYPES - 1)));
    }


};

#endif