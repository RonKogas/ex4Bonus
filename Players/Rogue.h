#ifndef Rogue_H
#define Rogue_H

#include "Player.h"

class Rogue : public Player {
public:
    /**
     * C'tor of Rogue class.
     *
     * @param name - The name of the player.
     * @return
     *      A new instance of a Rogue.
    */
    Rogue(const std::string name);

    /**
    * @return
    *      string - the player job.
    */
    std::string getJob() const override;

    /**
     * Adding coins the player.
     *
     * @param coinsToAdd - number of coins to add.
     * @return
     *      Rogue reference.
    */
    Rogue& addCoins(const int coinsToAdd) override;

    /**
     * using the default copy C'tor, D'tor and assignment operator.
    */
    Rogue(const Rogue&) = default;
    ~Rogue() = default;
    Rogue& operator=(const Rogue& other) = default;
};

#endif //Rogue_H
