#include "Treasure.h"

Treasure::Treasure() :
Card(TREASURE),
m_coinsInTreasure(COINS_IN_TREASURE)
{

}

void Treasure::applyEncounter(Player& player) const
{
    player.addCoins(m_coinsInTreasure);
    printTreasureMessage();
}