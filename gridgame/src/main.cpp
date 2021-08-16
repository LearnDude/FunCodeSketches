#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>
#include <string>

#include "gridgame.h"
#include "griddrawer.h"


using std::cout, std::cin, std::string;

int main() {

    unsigned xSize, ySize;

    cout << "Please input xSize and ySize of playing board\n xSize: ";
    cin >> xSize;
    cout << "\nySize: ";
    cin >> ySize;
    cout << "\n";

    GridGame game( xSize, ySize);

    string moveInput;
    const string wasd = "wasd";
    wincon gameStatus { wincon::inProgress};

    while ( gameStatus == wincon::inProgress )
    {
        game.draw();
    
        cout << "\nEnter your next move with wasd + return ";
        cin >> moveInput;

        if( wasd.find( moveInput) != -1 ){
            game.move( moveMap[ wasd] );
            gameStatus = game.checkWin();
        }
        else if ( wasd == "quit") {
            
            gameStatus = wincon::lose;
        }
        else {
            cout << "Illegal move, only use wasd keys.\n";
        }
    }

    if( gameStatus == wincon::win) {
        cout << "Congratulations, you won!";
    }

    cout << "Exiting game";
}