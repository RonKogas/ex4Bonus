#ifndef PITFALL_H_
#define PITFALL_H_
#include "Card.h"

const int HP_DAMAGE = 10;

class Pitfall : public Card
{
public:
    /**
     * @brief Construct a new Pitfall object
     * 
     */
    Pitfall();
    /**
     * @brief Destroy the Pitfall object
     * 
     */
    ~Pitfall()=default;
    /**
     * @brief reduce 10 HP for every non-rogue
     * player
     * 
     * @param player 
     */
    void applyEncounter(Player& player) const override;
private:
    int m_damage;
};



#endif /*PITFALL_H_*/