#include <iostream>
#include <vector>

#include "gridgame.h"
#include "griddrawer.h"

GridDrawer::GridDrawer( unsigned _xSize, unsigned _ySize): xSize { _xSize}, ySize { _ySize} {}

void GridDrawer::draw( const vector<unsigned> & grid ) {
    const unsigned xChars = 3 * xSize + 3 * (xSize -1) + 2 * 3;

    cout << "\nGameboard\n";

    // top line
    for( int c = 0; c < xChars; c++) {
        cout << '-';
    }

    cout << '\n';

    // Interior and bottom lines
    for( int y = 0; y < ySize; y++) {

        // left edge
        cout << "| ";

        // interior
        for( int x = 0; x < xSize - 1; x++) {
            cout << grid[ toInx( x, y)] << " | ";
        }

        // right edge
        cout << " |\n";

        // horizontal line

        cout << "|";
        for( int c = 1; c < xChars -1; c++) {
            cout << '-';
        }
        cout << "|\n";
    }


}


inline const unsigned GridDrawer::toInx( unsigned x, unsigned y) {
    return x + y * xSize;
}

inline const position GridDrawer::fromInx( unsigned inx) {
    position pos;
    pos.y = inx % xSize;
    pos.x = inx - pos.y * xSize; 
    return pos;
}

inline void GridDrawer::fromInx( unsigned inx, position & pos) {
    pos.y = inx % xSize;
    pos.x = inx - pos.y * xSize; 
}

        
