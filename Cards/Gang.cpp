#include "Gang.h"


Gang::Gang():
Card("Gang")
{

}

void Gang::applyEncounter(Player& player) const
{
    int playerStrength = player.getAttackStrength();
    bool lostBattle = false;
    for(const std::unique_ptr<Battle>& monster : m_monsters)
    {    
        if(playerStrength >= monster->getForce() && !lostBattle)
        {
            player.addCoins(monster->getLoot());
        }
        else
        {
            monster->applyLoss(player);
            lostBattle=true;
        }
    }
    if(!lostBattle)
    {
        player.levelUp();
    }
}

void Gang::addMonster(std::string monster, int numOfLine)
{
    try
    {
        addMonsterToVector(m_monsters,monster);
    }
    catch(const InvalidPushToVector& pushError)
    {
        throw DeckFileFormatError(numOfLine);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

void Gang::addMonsterToVector(std::vector<std::unique_ptr<Battle>>& vector, std::string monster)
{
    std::map<std::string, std::unique_ptr<Battle>> monsterMap;
    monsterMap["Dragon"] = std::unique_ptr<Battle>(new Dragon());
    monsterMap["Goblin"] = std::unique_ptr<Battle>(new Goblin());
    monsterMap["Vampire"] = std::unique_ptr<Battle>(new Vampire());
    if (monsterMap[monster] == nullptr){
        throw InvalidPushToVector();
    }
    vector.push_back(std::move(monsterMap[monster]));
}

Gang& Gang::operator=(const Gang& gang)
{
    if(this==&gang)
    {
        return *this;
    }
    std::vector<std::unique_ptr<Battle>> newMonsters;
    try
    {
        for(const std::unique_ptr<Battle>& monster : gang.m_monsters)
        {
            addMonsterToVector(newMonsters, monster->getType());
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    m_monsters.clear();
    for(const std::unique_ptr<Battle>& monster : newMonsters)
    {
        addMonsterToVector(m_monsters, monster->getType());
    }
    return *this;
}