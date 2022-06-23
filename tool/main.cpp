#include <iostream>
#include "../Mtmchkin.h"

using std::cout;
using std::endl;

int main() {
    try {
        Mtmchkin game("deck.txt");
        while (!game.isGameOver()) {
            game.playRound();
        }
        game.printLeaderBoard();
    } catch (const DeckFileNotFound& exp) {
        cout << exp.what() << endl;
    } catch (const DeckFileFormatError& exp) {
        cout << exp.what() << endl;
    } catch (const DeckFileInvalidSize& exp) {
        cout << exp.what() << endl;
    } catch (const std::exception& exp) {
        cout << exp.what() << endl;
    }
    return 0;
}
