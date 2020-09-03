#ifndef MONSTER_GENERATOR_H
#define MONSTER_GENERATOR_H

#include "Monster.h"
#include "../effolkronium/random.hpp"

#include <string>
#include <vector>
#include <cassert>


using Random = effolkronium::random_static;

class MonsterGenerator 
{
    std::vector<Monster> monster_list{};
    
public:
    MonsterGenerator()
    {}

    void create();

    void print() const;



};

#endif