#include "Pitfall.h"

Pitfall::Pitfall():
Card("Pitfall"),
m_damage(HP_DAMAGE)
{

}

void Pitfall::applyEncounter(Player& player) const
{
    Rogue* rougePlayer=dynamic_cast<Rogue*>(&player);
    if(rougePlayer!=nullptr)
    {
        printPitfallMessage(true);
        return;
    }
    delete rougePlayer;
    printPitfallMessage(false);
    player.damage(m_damage);
}