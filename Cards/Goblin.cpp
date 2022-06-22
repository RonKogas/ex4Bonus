#include "Goblin.h"


Goblin::Goblin():
Battle("Goblin", GOBLIN_FORCE, GOBLIN_LOOT),
m_damage(GOBLIN_DAMAGE)
{

}

void Goblin::applyWin(Player& player) const
{
    player.levelUp();
    player.addCoins(m_loot);
}

void Goblin::applyLoss(Player& player) const
{
    player.damage(m_damage);
}

std::ostream& Goblin::print(std::ostream& os) const
{
    printCardDetails(os, this->getType());
    printMonsterDetails(os, this->m_force, this->m_damage, this->m_loot, false);
    printEndOfCardDetails(os);
    return os;
}