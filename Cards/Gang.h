#ifndef GANG_H_
#define GANG_H_

#include "Battle.h"
#include <vector>
#include <memory>
#include <map>
#include <string>
#include "Dragon.h"
#include "Goblin.h"
#include "Vampire.h"
#include "../Exception.h"

class Gang : public Card
{
public:
    /**
     * @brief Construct a new Gang object
     * 
     */
    Gang();
    /**
     * @brief Destroy the Gang object
     * 
     */
    ~Gang()=default;
    /**
     * @brief perform the battle with the monsters in the gang
     * apply changes on player according to battle result
     * 
     * @param player 
     */
    void applyEncounter(Player& player) const override;

    /**
     * @brief add given Battle card of monster to the gang
     *          (while creating the deck)
     * @param monster - string representing the monster type
     */
    void addMonster(std::string monster, int numOfLine);
    /**
     * @brief assignment operator
     * 
     * @return Gang& 
     */
    Gang& operator=(const Gang&);
private:
    std::vector<std::unique_ptr<Battle>> m_monsters; 
    /**
     * @brief insert unique_ptr holding Card with the type mentioned
     * 
     * @param vector 
     * @param monster 
     */
    void addMonsterToVector(std::vector<std::unique_ptr<Battle>>& vector, std::string monster);

};



#endif /*GANG_H_*/