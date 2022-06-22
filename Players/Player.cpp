#include "Player.h"
#include "../utilities.h"
#include <string>

using std::string;
using std::ostream;

const int MAX_LEVEL = 10;
const int DEFAULT_COINS = 10;
const int MAX_NAME_CHARS = 15;
const int DEFAULT_FORCE = 5;
const int DEFAULT_MAX_HP = 100;

Player::Player(const string name) :
        m_name(name),
        m_level(1),
        m_force(DEFAULT_FORCE),
        m_maxHP(DEFAULT_MAX_HP),
        m_HP(DEFAULT_MAX_HP),
        m_coins(DEFAULT_COINS)
{
    if(name.length() > MAX_NAME_CHARS) {
        throw InvalidPlayerName();
    }
    for (char i : name) {
        if (!isalpha(i)) {
            throw InvalidPlayerName();
        }
    }
}

void Player::printInfo(ostream& out) const
{
    return printPlayerDetails(out, m_name, this->getJob(), m_level, m_force, m_HP, m_coins);
}

const string Player::getName() const
{
    return m_name;
}

Player& Player::levelUp() {
    if (m_level < MAX_LEVEL) {
        m_level += 1;
    }
    return *this;
}

int Player::getLevel() const {
    return m_level;
}

Player& Player::buff(const int forceToIncrease) {
    if(forceToIncrease > 0) {
        m_force += forceToIncrease;
    }
    return *this;
}

Player& Player::decreaseForce(const int forceToDecrease)
{
    if (forceToDecrease > 0) {
        if(m_force - forceToDecrease > 0) {
            m_force -= forceToDecrease;
        } else {
            m_force = 0;
        }
    }
    return *this;
}

int Player::getHP() const
{
    return m_HP;
}

Player& Player::heal(const int HPToIncrease) {
    if(HPToIncrease > 0) {
        if(m_HP + HPToIncrease <= m_maxHP) {
            m_HP += HPToIncrease;
        } else {
            m_HP = m_maxHP;
        }
    }
    return *this;
}

Player& Player::damage(const int HPToDecrease) {
    if(HPToDecrease > 0) {
        if(m_HP - HPToDecrease >= 0) {
            m_HP -= HPToDecrease;
        } else {
            m_HP = 0;
        }
    }
    return *this;
}

bool Player::isKnockedOut() const {
    return !m_HP;
}

Player& Player::addCoins(const int coinsToAdd) {
    if (coinsToAdd > 0) {
        m_coins += coinsToAdd;
    }
    return *this;
}

bool Player::pay(const int coinsToPay) {
    if((coinsToPay >= 0) && (m_coins - coinsToPay >= 0)) {
        m_coins -= coinsToPay;
        return true;
    } else if (coinsToPay < 0){
        return true;
    } else {
        return false;
    }
}

int Player::getAttackStrength() const {
    return m_force + m_level;
}

int Player::getCoins() const {
    return m_coins;
}

ostream& operator<<(ostream& out, const Player& player)
{
    player.printInfo(out);
    return out;
}