#include "Monster.cpp"
#include "Monster.h"
#include "MonsterGenerator.h"
#include "MonsterGenerator.cpp"

#include <iostream>


int main()
{
    MonsterGenerator mg;
    mg.create();
    // mg.create();
    mg.print();
    // mg.create();
    return 0;
}
