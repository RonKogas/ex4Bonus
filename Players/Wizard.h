#ifndef WIZARD_H
#define WIZARD_H

#include "Player.h"

class Wizard : public Player {
public:
    /**
     * C'tor of Wizard class.
     *
     * @param name - The name of the wizard.
     * @return
     *      A new instance of a Wizard.
    */
    Wizard(const std::string name);

    /**
    * @return
    *      string - the player job.
    */
    std::string getJob() const override;

    /**
    * Increasing the player HP.
    *
    * @param HPToIncrease - number of HP points to increase considering the maxHP value.
    * @return
    *      wizard reference.
    */
    Wizard& heal(const int HPToIncrease) override;

    /**
     * using the default copy C'tor, D'tor and assignment operator.
    */
    Wizard(const Wizard&) = default;
    ~Wizard() = default;
    Wizard& operator=(const Wizard& other) = default;
};

#endif //WIZARD_H
