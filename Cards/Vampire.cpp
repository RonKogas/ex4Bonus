#include "Vampire.h"

Vampire::Vampire():
Battle("Vampire", VAMPIRE_FORCE, VAMPIRE_LOOT),
m_damage(VAMPIRE_DAMAGE),
m_forceDamage(VAMPIRE_FORCE_DAMAGE)
{

}

void Vampire::applyWin(Player& player) const
{
    player.levelUp();
    player.addCoins(m_loot);
}

void Vampire::applyLoss(Player& player) const
{
    player.damage(m_damage);
    player.decreaseForce(m_forceDamage);
}

std::ostream& Vampire::print(std::ostream& os) const
{
    printCardDetails(os, this->getType());
    printMonsterDetails(os,this->m_force, this->m_damage, this->m_loot, false);
    printEndOfCardDetails(os);
    return os;
}