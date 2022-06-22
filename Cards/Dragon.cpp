#include "Dragon.h"
const int DRAGON_DAMAGE = 0;

Dragon::Dragon():
Battle("Dragon", DRAGON_FORCE, DRAGON_LOOT)
{

}

void Dragon::applyWin(Player& player) const
{
    player.levelUp();
    player.addCoins(m_loot);
}

void Dragon::applyLoss(Player& player) const
{
    player.damage(player.getHP());
}

std::ostream& Dragon::print(std::ostream& os) const
{
    printCardDetails(os, this->getType());
    printMonsterDetails(os, this->m_force, DRAGON_DAMAGE, this->m_loot, true);
    printEndOfCardDetails(os);
    return os;
}