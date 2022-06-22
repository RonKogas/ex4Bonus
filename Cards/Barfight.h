#ifndef BARFIGHT_H_
#define BARFIGHT_H_
#include "Card.h"

static const int DAMAGE = 10;

class Barfight : public Card
{
public:
    /**
     * @brief Construct a new Barfight object
     * 
     */
    Barfight();
    /**
     * @brief Destroy the Barfight object
     * 
     */
    ~Barfight()=default;
    /**
     * @brief apply the Barfight on player
     * decrease 10 HP from non-fighter players
     * 
     * @param player 
     */
    void applyEncounter(Player& player) const override;
private:
    int m_damage;
};

#endif /*BARFIGHT_H_*/