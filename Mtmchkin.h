#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_


#include <deque>
#include <list>
#include "Cards/Card.h"
#include "Players/Player.h"
#include <memory>


class Mtmchkin{

public:
    
    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    explicit Mtmchkin(const std::string &fileName);
    
    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();
    
    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;
    
    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;
    
	/*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;

private:
    std::deque<std::unique_ptr<Card>> m_deck;
    std::list<std::unique_ptr<Player>> m_actingPlayers;
    std::list<std::unique_ptr<Player>> m_losers;
    std::list<std::unique_ptr<Player>> m_winners;
    int m_numberOfRounds;

    /**
     * @brief populate m_deck according to sourcefile
     * 
     * @param sourceFile 
     */
    void initializeCardDeck(std::ifstream& sourceFile);
    /**
     * @brief add unique_ptr of card from given type
     * to m_deck
     * 
     * @param cardName - the type of the card ("Goblin","Pitfall" etc)
     * @param currentLine - the line in deck file
     */
    void addCardToDeck(const std::string cardName, const int currentLine);
    /**
     * @brief populate m_actingPlayer from the user
     * 
     */
    void initializePlayersList();
    /**
     * @brief Get the Team Size from user
     * 
     * @return int - number of players
     */
    int getTeamSize() const;
    /**
     * @brief add unique_ptr pointing to Player
     * with name and class given
     * 
     * @param name - name of player
     * @param job - Class of player ("Rogue","Wizard" etc)
     */
    void addPlayerToGame(const std::string name, const std::string job);
    
};
bool isNullptr(const std::unique_ptr<Player>& player);



#endif /* MTMCHKIN_H_ */
