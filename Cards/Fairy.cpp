#include "Fairy.h"

Fairy::Fairy():
Card("Fairy"),
m_HPToIncrese(HP_TO_INCRESE)
{

}

void Fairy::applyEncounter(Player& player) const 
{
    Wizard* wizardPlayer=dynamic_cast<Wizard*>(&player);
    if(wizardPlayer!=nullptr)
    {
        player.heal(this->m_HPToIncrese);
        printFairyMessage(true);
        return;
    }
    delete wizardPlayer;
    printFairyMessage(false);
}