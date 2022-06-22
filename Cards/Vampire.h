#ifndef VAMPIRE_H_
#define VAMPIRE_H_

#include "Battle.h"

const int VAMPIRE_FORCE = 10;
const int VAMPIRE_LOOT = 2;
const int VAMPIRE_DAMAGE = 10;
const int VAMPIRE_FORCE_DAMAGE = 1;

class Vampire : public Battle
{
public:
    /**
     * @brief Construct a new Vampire object
     * 
     */
    Vampire();
    /**
     * @brief Destroy the Vampire object
     * 
     */
    ~Vampire() = default;
    /**
     * @brief print Vampire's info to given ostream
     * 
     * @return std::ostream& 
     */
    std::ostream& print(std::ostream&) const override;
    /**
     * @brief give loot to player
     * 
     */
    void applyWin(Player&) const override;
    /**
     * @brief decrese 1 force
     * and 10 HP from player
     * 
     */
    void applyLoss(Player&) const override;


private:
    int m_damage; 
    int m_forceDamage;
};



#endif /*VAMPIRE_H_*/