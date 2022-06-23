#include "Rogue.h"

using std::string;
const string ROGUE = "Rogue";

Rogue::Rogue(const string name) :
        Player(name)
{}

string Rogue::getJob() const {
    return ROGUE;
}

Rogue& Rogue::addCoins(const int coinsToAdd) {
    if (coinsToAdd > 0) {
        m_coins += 2*coinsToAdd;
    }
    return *this;
}