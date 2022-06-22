#ifndef DRAGON_H_
#define DRAGON_H_
#include "Battle.h"

const int DRAGON_FORCE = 25;
const int DRAGON_LOOT = 1000;


class Dragon : public Battle
{
public:
    /**
     * @brief Construct a new Dragon object
     * 
     */
    Dragon();
    /**
     * @brief Destroy the Dragon object
     * 
     */
    ~Dragon() = default;
    /**
     * @brief print Dragon card info
     * wrapped by '<<' operator
     * 
     * @return std::ostream& 
     */
    std::ostream& print(std::ostream&) const override;
    /**
     * @brief give the player loot and level up
     * 
     */
    void applyWin(Player&) const override;
    /**
     * @brief set player's hP to 0
     * 
     */
    void applyLoss(Player&) const override;


private:
};




#endif /*DRAGON_H_*/