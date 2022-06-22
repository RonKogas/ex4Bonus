#ifndef TREASURE_H_
#define TREASURE_H_

#include "Card.h"

const int COINS_IN_TREASURE = 10;

class Treasure : public Card
{
public:
    /**
     * @brief Construct a new Treasure object
     * 
     */
    Treasure();
    /**
     * @brief Destroy the Treasure object
     * 
     */
    ~Treasure()=default;
    /**
     * @brief increase player coins by 10
     * 
     * @param player 
     */
    void applyEncounter(Player& player) const override;
private:
    int m_coinsInTreasure;
};

#endif /*TREASURE*/