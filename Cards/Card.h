#ifndef CARD_H_
#define CARD_H_

#include <string>
#include <ostream>
#include "../utilities.h"
#include "../Players/Player.h"
#include "../Players/Fighter.h"
#include "../Players/Rogue.h"
#include "../Players/Wizard.h"


//enum class CardType {Vempire, Goblin, Dragon, Merchant, Treasure, Pitfall, Barfight, Fairy};

class Card
{
public:
    /**
     * @brief Construct a new Card object
     * all other cards inherite from here
     * 
     * @param type 
     */
    Card(std::string type);
    /**
     * @brief Destroy the Card object
     * 
     */
    virtual ~Card()=default;
    /**
     * @brief apply on player changes according to card definition
     * 
     * @param player 
     */
    virtual void applyEncounter(Player& player) const = 0;
    /**
     * @brief Get the Type of the card.
     * ("Goblin", "Barfight" etc)
     * 
     * @return std::string that represent the type
     */
    std::string getType() const;
    /**
     * @brief prints given card info to given ostream
     *  wrapping for print
     * @return std::ostream& 
     */
    friend std::ostream& operator<<(std::ostream&, const Card&);
    /**
     * @brief prints this card info to given ostream
     * 
     * @return std::ostream& 
     */
    virtual std::ostream& print(std::ostream&) const;
private:
    std::string m_type;
    
};


#endif /* CARD_H_ */