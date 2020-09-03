#ifndef MONSTER_H
#define MONSTER_H

#include <string_view>


class Monster
{
public:
    enum Type
    {
        DRAGON,
        GOBLIN,
        OGRE,
        ORC,
        SKELETON,
        TROLL,
        VAMPIRE,
        ZOMBIE,
        MAX_TYPE
    };

private:
    Type m_type{};
    std::string_view m_name{};
    std::string_view m_roar{};
    int m_hitpoints;

public:
    Monster(Type type, std::string_view name, std::string_view roar, int hitpoints)
        : m_type{type}, m_name{name}, m_roar{roar}, m_hitpoints{hitpoints}
    {}

    std::string_view getTypeString() const;

    //void print() const;
    void say() const;


};


#endif
