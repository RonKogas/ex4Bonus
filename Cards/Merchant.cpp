#include "Merchant.h"
#include <iostream>
#include <string>
const int NO_PURCHASE = 0;
const int ERROR_CODE = -1;
const char FIRST_DIGIT = '0';
const char LAST_DIGIT= '9';
const int HP_TYPE = 1;
const int FORCE_TYPE = 2; 

Merchant::Merchant() :
Card("Merchant"),
m_HPPrice(HP_PRICE),
m_forcePrice(FORCE_PRICE)
{

}

void Merchant::applyEncounter(Player& player) const
{
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(), player.getCoins());
    while(true)
    {
        try
        { 
            //std::cin.sync();
            std::string usersAnswer;
            std::getline(std::cin,usersAnswer,'\n');
            int chosenOption;
            //std::cout<<usersAnswer<<std::endl<<usersAnswer.length()<<std::endl<<isDigit(usersAnswer[0]);
            if(usersAnswer.length()>1||!isDigit(usersAnswer[0]))
            {
                chosenOption = ERROR_CODE;
            }
            else
            {
                chosenOption = std::stoi(usersAnswer);
            }
            
            if(chosenOption == 0)
            {
                printMerchantSummary(std::cout, player.getName(), chosenOption, NO_PURCHASE);
                return;
            }
            else if (chosenOption == 1)
            {
                HPPurchase(player, 1, m_HPPrice);
                return;
            }
            else if (chosenOption == 2)
            {
                forcePurchase(player, 1, m_forcePrice);
                return;
            }
            else
            {
                printInvalidInput();
            }
        }
        catch(std::exception& e)
        {
            std::cerr<<e.what();
        }
    }
}

void HPPurchase(Player& player, int amountOfHP, int price)
{
    if(player.getCoins()>=price)
    {
        player.pay(price);
        player.heal(amountOfHP);
        printMerchantSummary(std::cout, player.getName(), HP_TYPE, price);
    }
    else
    {
        printMerchantInsufficientCoins(std::cout);
        printMerchantSummary(std::cout, player.getName(), HP_TYPE, NO_PURCHASE);
    }
}

void forcePurchase(Player& player, int amountOfForce, int price)
{
    if(player.getCoins()>=price)
    {
        player.pay(price);
        player.buff(amountOfForce);
        printMerchantSummary(std::cout, player.getName(), FORCE_TYPE, price);
    }
    else
    {
        printMerchantInsufficientCoins(std::cout);
        printMerchantSummary(std::cout, player.getName(), FORCE_TYPE, NO_PURCHASE);
    }
}

bool isDigit(char c)
{
    if(c<=LAST_DIGIT&&c>=FIRST_DIGIT)
    {
        return true;
    }
    return false;
}
