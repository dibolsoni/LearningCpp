#include "MonsterGenerator.h"

#include <iostream>

void MonsterGenerator::create()
{
    static std::vector<std::string> names{"Able", "Sikct", "Zweot", "Quert", "Lytk"};
    static std::vector<std::string> roars{"Arrrrghh!!", "Zoooowe!!!", "Glup!", "Yaaaahh!", "Ohhhww!!", "Kuahh!!"};

    int monster_length = Monster::Type::MAX_TYPE;
    int types_num = Random::get(0, monster_length);
    int names_num = Random::get(0, 6);
    int roars_num = Random::get(0, 6);
    Monster::Type type{static_cast<Monster::Type>(types_num)};
    Monster monster{type, names[names_num], roars[roars_num], Random::get(50,180)};
    monster_list.push_back(monster);
}

void MonsterGenerator::print() const 
{
    for(size_t i{0}; i < monster_list.size(); i++)
    {
        monster_list[i].say();
    }
}