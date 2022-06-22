#include "Card.h"
#include <string>

Card::Card(std::string type):
m_type(type)
{

}

std::string Card::getType() const
{
    return m_type;
}

std::ostream& operator<<(std::ostream& os, const Card& card) 
{
    return card.print(os);
}

std::ostream& Card::print(std::ostream& os) const
{
    printCardDetails(os, this->getType());
    printEndOfCardDetails(os);
    return os;
}