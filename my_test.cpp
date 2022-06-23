
#include <functional>
#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include "Players/Player.h"
#include "Cards/Card.h"
#include "Mtmchkin.h"
#include "Cards/Vampire.h"
#include "Cards/Barfight.h"
#include "Cards/Dragon.h"
#include "Cards/Fairy.h"
#include "Cards/Goblin.h"
#include "Cards/Merchant.h"
#include "Cards/Pitfall.h"
#include "Cards/Treasure.h"
#include "Players/Rogue.h"
#include "Players/Wizard.h"
#include "Players/Fighter.h"
#include "Cards/Gang.h"
#include "Exception.h"
#include <algorithm>
#include <sstream>
#include <random>
#include <cstdio>
#include <fstream>
#include <cstring>

using std::unique_ptr;
using std::cout;
using std::cerr;
using std::string;
using std::fstream;
using std::istringstream;
using std::vector;


/* ---------------------------------------------------------------------------------------------- */
// --------------------------------       General Helper Functions          ------------------------------

void createTextFile(const string &filename, const string &input)
{
    std::ofstream file(filename);
    if(file){
        file << input;
    }
}

void GeneralGameSimulationTest(const string &tempDeckFilename, string input, string deck)
{
    //   init cin from file
    createTextFile(tempDeckFilename+".txt",deck);
    istringstream in(input);
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf());
    //std::ofstream outfile(tempDeckFilename+"out.txt");
    //std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    //std::cout.rdbuf(outfile.rdbuf());
    Mtmchkin game(tempDeckFilename+".txt");
 
    while(!game.isGameOver() && game.getNumberOfRounds() < 100){
        game.playRound();
        game.printLeaderBoard();
    }

    //bool res = compareFiles(tempDeckFilename+"out.txt", expectedOutputFileName);
	//outfile.close();
    std::cin.rdbuf(cinbuf);
    //std::cout.rdbuf(coutbuf);
    //deleteTextFile(tempDeckFilename+".txt");

}

void gang1Test()
{
    const string tmp_file("gang1_test_deck");
    string input("2\nJimmy Wizard\nPikachu Fighter");
    string deck("Goblin\nGang\nDragon\nVampire\nGang\nVampire\nGoblin\nDragon\nVampire\nEndGang\nEndGang\nVampire\nGoblin\nGoblin\nVampire\nGoblin");
    //string expectedOutputFilename("tests/dragonDen_test_expected.txt");
    GeneralGameSimulationTest(tmp_file, input, deck);
}
int main()
{
    Gang g1;
    //Gang g2;
    g1.addMonster("Vampire",1);
    g1.addMonster("Dragon",2);
    g1.printmonsters();
    std::cout<<std::endl<<std::endl;
    Gang g2(g1);
    g2.printmonsters();
    /*try{
    gang1Test();
    }
    catch(const std::exception& e)
    {
        std::cout<<e.what();
    }*/
}