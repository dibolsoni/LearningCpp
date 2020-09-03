#include "Monster.h"

#include <string_view>
#include <iostream>

std::string_view Monster::getTypeString() const
{
    switch (this->m_type)
    {
    case Type::DRAGON:
        return "Dragon";
    case Type::GOBLIN:
        return "Goblin";
    case Type::OGRE:
        return "Ogre";
    case Type::SKELETON:
        return "Skeleton";
    case Type::TROLL:
        return "Troll";
    case Type::VAMPIRE:
        return "Vampire";
    case Type::ZOMBIE:
        return "Zombie";

    default:
        return "INVALID_MONSTER_ID";
    };
}

//void Monster::print() const
//{
//    std::cout << this->m_name << " the " << this->getTypeString() << " has " << m_hitpoints << " hitpoints  and says " << m_roar << '\n';
//
//}

void Monster::say() const
{
    std::cout << this->m_name << " the " << this->getTypeString() << " has " << m_hitpoints << " hitpoints  and says " << m_roar << '\n';
}
