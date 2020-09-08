#include "Monster.h"

static const Creature Monster::getDefaultCreature(Monster::TYPE type)
{
  static std::array<Creature, static_cast<std::size_t>(Monster::TYPE::MAX_TYPES)> monsterData{
    { { "dragon", 'D', 20, 4, 100 },
      { "orc", 'o', 4, 2, 25 },
      { "slime", 's', 1, 1, 10 } }
  };
 
  return monsterData.at(static_cast<std::size_t>(type));
}