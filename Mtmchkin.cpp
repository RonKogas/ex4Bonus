#include "Mtmchkin.h"
#include <fstream>
#include <string>
#include <map>
#include <memory>

#include "Cards/Barfight.h"
#include "Cards/Battle.h"
#include "Cards/Dragon.h"
#include "Cards/Fairy.h"
#include "Cards/Goblin.h"
#include "Cards/Merchant.h"
#include "Cards/Pitfall.h"
#include "Cards/Treasure.h"
#include "Cards/Vampire.h"
#include "Cards/Gang.h"

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::string;
using std::getline;
using std::unique_ptr;

const string BARFIGHT = "Barfight";
const string DRAGON = "Dragon";
const string FAIRY = "Fairy";
const string GOBLIN = "Goblin";
const string MERCHANT = "Merchant";
const string PITFALL = "Pitfall";
const string TREASURE = "Treasure";
const string VAMPIRE = "Vampire";
const string FIGHTER = "Fighter";
const string ROGUE = "Rogue";
const string WIZARD = "Wizard";
const string GANG = "Gang";
const string END_GANG = "EndGang";
const string GENERIC_ERROR_MESSAGE = "Sorry, an error occurred";
const string SPACE_CHAR = " ";
const int MINIMUM_PLAYERS_ALLOWED = 2;
const int MAXIMUM_PLAYERS_ALLOWED = 6;
const int MIN_AMOUNT_OF_CARDS = 5;

const int WINNING_LEVEL = 10;
const int LOSING_HP = 0;


Mtmchkin::Mtmchkin(const std::string &fileName) {
    printStartGameMessage();
    ifstream sourceFile(fileName);
    if (!sourceFile) {
        throw DeckFileNotFound();
    }
    initializeCardDeck(sourceFile);
    initializePlayersList();
    m_numberOfRounds=0;
}

void Mtmchkin::initializeCardDeck(std::ifstream& sourceFile)
{
    string currentCard;
    unique_ptr<Gang> currentGang;
    bool inGang = false;
    int numOfCards = 0;
    int currentLine = 0;
    while (getline(sourceFile, currentCard)) {
        currentLine++;
        if(inGang && currentCard!=END_GANG)
        {
            currentGang->addMonster(currentCard,currentLine);
        }
        else if(inGang && currentCard==END_GANG)
        {
            m_deck.push_back(move(currentGang));
            inGang = false;
        }

        else if(!inGang && currentCard==GANG)
        {
            currentGang = unique_ptr<Gang>(new Gang());
            numOfCards++;
            inGang = true;
        }
        else
        {
            numOfCards++;
            addCardToDeck(currentCard, currentLine);
        }
    }
    if(inGang)
    {
        throw DeckFileFormatError(currentLine);
    }
    if (numOfCards < MIN_AMOUNT_OF_CARDS) {
        throw DeckFileInvalidSize();
    }
}

void Mtmchkin::addCardToDeck(const string cardName, const int currentLine) {
    
    std::map<string, std::unique_ptr<Card>> buildCardMap;
    buildCardMap[BARFIGHT] = unique_ptr<Card>(new Barfight());
    buildCardMap[DRAGON] = unique_ptr<Card>(new Dragon());
    buildCardMap[FAIRY] = unique_ptr<Card>(new Fairy());
    buildCardMap[GOBLIN] = unique_ptr<Card>(new Goblin());
    buildCardMap[MERCHANT] = unique_ptr<Card>(new Merchant());
    buildCardMap[PITFALL] = unique_ptr<Card>(new Pitfall());
    buildCardMap[TREASURE] = unique_ptr<Card>(new Treasure());
    buildCardMap[VAMPIRE] = unique_ptr<Card>(new Vampire());
    if (buildCardMap[cardName] == nullptr){
        throw DeckFileFormatError(currentLine);
    }
    return m_deck.push_back(move(buildCardMap[cardName]));
}

void Mtmchkin::initializePlayersList()
{
    int teamSize = getTeamSize();
    int playerCounter = 0;
    string userInput = "";
    printInsertPlayerMessage();
    while (playerCounter < teamSize) {
        try {
            cin.sync();
            getline(cin, userInput);
            string playerName = userInput.substr(0, userInput.find(SPACE_CHAR));
            string playerJob = userInput.substr(userInput.find(SPACE_CHAR) + 1);
            addPlayerToGame(playerName, playerJob);
        } catch (const InvalidPlayerName& nameException) {
            printInvalidName();
            continue;
        } catch (const InvalidClass& classException) {
            printInvalidClass();
            continue;
        } catch (...) {
            cout << GENERIC_ERROR_MESSAGE << endl;
        }
        playerCounter++;
        if (playerCounter < teamSize) {
            printInsertPlayerMessage();
        }
    }
}

int Mtmchkin::getTeamSize() const
{
    
    string userInput = "";
    int teamSize = 0;
    while (true) {
        printEnterTeamSizeMessage();
        getline(cin,userInput);
        if (!isdigit(userInput[0]) || userInput.length() != 1) {
            printInvalidTeamSize();
            continue;
        }
        teamSize = stoi(userInput);
        if (teamSize < MINIMUM_PLAYERS_ALLOWED || teamSize > MAXIMUM_PLAYERS_ALLOWED) {
            printInvalidTeamSize();
            continue;
        } else {
            break;
        }
    }
    return teamSize;
}

void Mtmchkin::addPlayerToGame(const string name, const string job) {
    std::map<string, std::unique_ptr<Player>> buildPlayerMap;
    buildPlayerMap[FIGHTER] = unique_ptr<Player>(new Fighter(name));
    buildPlayerMap[ROGUE] = unique_ptr<Player>(new Rogue(name));
    buildPlayerMap[WIZARD] = unique_ptr<Player>(new Wizard(name));
    if (buildPlayerMap[job] == nullptr){
        throw InvalidClass();
    }
    return m_actingPlayers.push_back(move(buildPlayerMap[job]));
}


void Mtmchkin::playRound()
{
    printRoundStartMessage(m_numberOfRounds+1);
    for(std::unique_ptr<Player>& player : m_actingPlayers)
    {
        printTurnStartMessage(player->getName());
        unique_ptr<Card> lastCard = move(m_deck.front());
        lastCard -> applyEncounter(*player);
        m_deck.push_back(move(lastCard));
        m_deck.pop_front();
        if(player->getLevel()==WINNING_LEVEL)
        {
            m_winners.push_back(move(player));
        }

        else if(player->getHP()==LOSING_HP)
        {
            m_losers.push_front(move(player));
        }
    }
    m_actingPlayers.remove_if(isNullptr);
    if(this->isGameOver())
    {
        printGameEndMessage();
    }
    m_numberOfRounds++;
}


void Mtmchkin::printLeaderBoard() const
{
    printLeaderBoardStartMessage();
    int ranking=1;
    
    for(const std::unique_ptr<Player>& player : m_winners)
    {
        printPlayerLeaderBoard(ranking++, *(player));
    }
    for(const std::unique_ptr<Player>& player : m_actingPlayers)
    {
        printPlayerLeaderBoard(ranking++, *(player));
    }
    for(const std::unique_ptr<Player>& player : m_losers)
    {
        printPlayerLeaderBoard(ranking++, *(player));
    }

}

 bool Mtmchkin::isGameOver() const
 {
    if(m_actingPlayers.size()==0)
    {
        return true;
    }
    return false;
 }

 int Mtmchkin::getNumberOfRounds() const
 {
    return m_numberOfRounds;
 }

 bool isNullptr(const unique_ptr<Player>& player)
 {
    if (player.get()==nullptr)
    {
        return true;
    }
    return false;    
 }
