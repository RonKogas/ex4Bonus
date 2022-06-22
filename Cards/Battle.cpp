#include "Battle.h"
#include "Card.h"


Battle::Battle(std::string type, int force, int loot):
Card(type),
m_force(force),
m_loot(loot)
{

}

void Battle::applyEncounter(Player& player) const
{
    int playerStrength = player.getAttackStrength();
    if(playerStrength >= m_force)
    {
        this->applyWin(player);
        printWinBattle(player.getName(), this->getType());
    }
    else
    {
        this->applyLoss(player);
        printLossBattle(player.getName(), this->getType());  
    }
}

int Battle::getLoot() const
{
    return m_loot;
}

int Battle::getForce() const
{
    return m_force;
}