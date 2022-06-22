#ifndef MERCHANT_H_
#define MERCHENT_H_

#include "Card.h"
const int HP_PRICE = 5;
const int FORCE_PRICE = 10;

class Merchant : public Card
{
public:
    /**
     * @brief Construct a new Merchant object
     * 
     */
    Merchant();
    /**
     * @brief Destroy the Merchant object
     * 
     */
    ~Merchant()=default;
    /**
     * @brief offer player the products defined and apply changes on
     * player accordingly
     * 
     * @param player 
     */
    void applyEncounter(Player& player) const override;
private:
    int m_HPPrice;
    int m_forcePrice;
};

void HPPurchase(Player& player, int amountOfHP, int price);
void forcePurchase(Player& player, int amountOfForce, int price);
bool isDigit(char c);
#endif /*MERCHANT_H_*/