#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>

#include "gridgame.h"
#include "griddrawer.h"


using std::cout, std::ostream, std::vector, std::shuffle;


GridGame::GridGame( unsigned _xSize, unsigned _ySize):
    xSize {_xSize},
    ySize {_ySize},
    drawer { GridDrawer( xSize, ySize)}
 {
    hole.x = 0;
    hole.y = 0;

    grid.reserve( xSize * ySize);  
    init();
    // drawer = GridDrawer( xSize, ySize);
}

void GridGame::draw() {
    drawer.draw( grid);
}

wincon GridGame::checkWin() {

    wincon winCheck { wincon::win};
    
    for( int i = 0; i < xSize * ySize; i++){
        if( grid[i] != i) winCheck = wincon::inProgress;
    }

    return winCheck;
}

void GridGame::init() {

    for( int i = 0; i < xSize * ySize; i++) grid[i] = i;

    std::random_device rd;
    std::mt19937 g(rd());
 
    shuffle( grid.begin(), grid.end(), g);

    auto zeroPos = std::find( grid.begin(), grid.end(), 0) - grid.begin();

    hole = fromInx( zeroPos);

}

moveStatus GridGame::move( direction dir) {

    if(     ( dir == direction::up && hole.y == 0) ||
            ( dir == direction::down && hole.y == xSize - 1) ||
            ( dir == direction::left && hole.x == 0) ||
            ( dir == direction::right && hole.x == ySize - 1)
            ){
             return moveStatus::illegalMove;
    }

    switch( dir) {
        case direction::up :
            grid[ toInx( hole.x, hole.y)] = grid[ toInx( hole.x, hole.y - 1)];
            grid[ toInx( hole.x, hole.y - 1)] = 0;
            break;
        
        case direction::down : 
            grid[ toInx( hole.x, hole.y)] = grid[ toInx( hole.x, hole.y + 1)];
            grid[ toInx( hole.x, hole.y + 1)] = 0;
            break;

        case direction::left : 
            grid[ toInx( hole.x, hole.y)] = grid[ toInx( hole.x - 1, hole.y)];
            grid[ toInx( hole.x - 1, hole.y)] = 0;
            break;

        case direction::right : 
            grid[ toInx( hole.x, hole.y)] = grid[ toInx( hole.x + 1, hole.y)];
            grid[ toInx( hole.x + 1, hole.y - 1)] = 0;
            break;

        default:
            cout << "Move unknown value";
    }

    return moveStatus::ok;
}


inline const unsigned GridGame::toInx( unsigned x, unsigned y) {
    return x + y * xSize;
}

inline const position GridGame::fromInx( unsigned inx) {
    position pos;
    pos.y = inx % xSize;
    pos.x = inx - pos.y * xSize; 
    return pos;
}

inline void GridGame::fromInx( unsigned inx, position & pos) {
    pos.y = inx % xSize;
    pos.x = inx - pos.y * xSize; 
}




int main() {

    cout << "Welcome to GridGame, input the playing field size \n, x:";


}