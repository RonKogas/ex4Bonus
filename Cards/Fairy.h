#ifndef FAIRY_H_
#define FAIRY_H_
#include "Card.h"

const int HP_TO_INCRESE = 10;

class Fairy : public Card
{
public:
    /**
     * @brief Construct a new Fairy object
     * 
     */
    Fairy();
    /**
     * @brief Destroy the Fairy object
     * 
     */
    ~Fairy()=default;
    /**
     * @brief if player is wizard, give him 10 HP
     * 
     * @param player 
     */
    void applyEncounter(Player& player) const override;
private:
    int m_HPToIncrese;
};

#endif /*FAIRY_H_*/