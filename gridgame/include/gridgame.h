#ifndef __gridgame
#define __gridgame

#include<iostream>
#include<vector>
#include<map>


#include"griddrawer.h"

using std::cout, std::string, std::map, std::vector;

enum class direction {
    up,
    down,
    left,
    right
};

enum class wincon {
    win,
    lose,
    inProgress
};

enum class moveStatus {
    ok,
    illegalMove
};

map< string, direction> moveMap {
    { "w", direction::up},
    { "a", direction::left},
    { "s", direction::down},
    { "d", direction::right}
};

struct position { unsigned x; unsigned y;};


class GridGame {

    public:
        moveStatus move( direction dir);
        void draw();
        wincon checkWin();
        void init();

        position hole;

        GridGame( unsigned xSize, unsigned ySize);

    private:
        vector<unsigned> grid;
        const unsigned xSize;
        const unsigned ySize;
        GridDrawer drawer;
        inline const unsigned toInx( unsigned x, unsigned y);
        inline const position fromInx( unsigned inx);
        inline void fromInx( unsigned inx, position & pos);
};

#endif