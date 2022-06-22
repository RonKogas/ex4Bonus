#ifndef GOBLIN_H_
#define GOBLIN_H_

#include "Battle.h"

const int GOBLIN_FORCE = 6;
const int GOBLIN_LOOT = 2;
const int GOBLIN_DAMAGE = 10;

class Goblin : public Battle
{
public:
    /**
     * @brief Construct a new Goblin object
     * 
     */
    Goblin();
    /**
     * @brief Destroy the Goblin object
     * 
     */
    ~Goblin() = default;
    /**
     * @brief print Goblin's info to given ostream
     * 
     * @return std::ostream& 
     */
    std::ostream& print(std::ostream&) const override;
    /**
     * @brief if player wins, give him loot and level up
     * 
     */
    void applyWin(Player&) const override;
    /**
     * @brief if player loses, decrease HP by 10
     * 
     */
    void applyLoss(Player&) const override;


private:
    int m_damage;
};




#endif /*GOBLIN_H_*/