#ifndef BATTLE_H_
#define BATTLE_H_


#include <string>
#include "Card.h"

class Battle: public Card
{
public:
    /**
     * @brief Construct a new Battle object
     * abstract battle card(goblin,dragon etc)
     * 
     * @param type 
     *  the type of the monster
     * @param force 
     *  the force of the monster
     * @param loot 
     *  the coins you get from killing it
     */
    Battle(std::string type, int force, int loot);
    /**
     * @brief Destroy the Battle object
     * 
     */
    ~Battle()=default;
    /**
     * @brief perform the battle with the monster
     * apply changes on player according to battle result
     * 
     * @param player 
     */
    void applyEncounter(Player& player) const override;
    /**
     * @brief apply on player the changes in case he wins
     * 
     * @param player 
     */
    virtual void applyWin(Player& player) const = 0;
    /**
     * @brief apply on player the changes in case he lose
     * 
     * @param player 
     */
    virtual void applyLoss(Player& player) const = 0;
    /**
     * @brief Get the Loot object
     * 
     * @return the loot
     */
    int getLoot() const;
    /**
     * @brief Get the Force object
     * 
     * @return the force 
     */
    int getForce() const;
protected:
    int m_force;
    int m_loot; 
};


#endif /* BATTLE_H_ */