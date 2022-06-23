#include "Fighter.h"

using std::string;
const string FIGHTER = "Fighter";

Fighter::Fighter(const string name) :
        Player(name)
{}

string Fighter::getJob() const {
    return FIGHTER;
}

int Fighter::getAttackStrength() const {
    return (m_force*2) + m_level;
}