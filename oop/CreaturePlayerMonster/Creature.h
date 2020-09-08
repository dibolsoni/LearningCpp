#ifndef CREATURE_H
#define CREATURE_H

#include <string>

class Creature
{
    std::string c_name;
    char c_symbol;
    int c_health;
    unsigned int c_attack;
    unsigned int c_gold;

public:
    Creature(std::string name, char symbol, int health, unsigned int attack, unsigned int gold) 
        : c_name{name}, c_symbol{symbol}, c_health{health}, c_attack{attack}, c_gold{gold}
    {}

    inline std::string getName() const {return c_name; }
    inline char getSymbol() const {return c_symbol; }
    inline int getHealth() const {return c_health; }
    inline unsigned int getAttack() const {return c_attack; }
    inline unsigned int getGold() const {return c_gold; }
    inline bool isDead() const {return c_health < 1;}

    inline void reduceHealth(unsigned int by_num) {c_health -= by_num;}
    inline void addGold(int amount){c_gold += amount;}
    

};

#endif