#include "Barfight.h"

Barfight::Barfight() :
Card("Barfight"),
m_damage(DAMAGE)
{

}

void Barfight::applyEncounter(Player& player) const
{
    Fighter* fighterPlayer=dynamic_cast<Fighter*>(&player);
    if(fighterPlayer!=nullptr)
    {
        printBarfightMessage(true);
        return;
    }
    delete fighterPlayer;
    printBarfightMessage(false);
    player.damage(m_damage);
}