#ifndef __griddrawer
#define __griddrawer

using std::cout, std::ostream, std::vector, std::shuffle;

class GridDrawer {

    public:
        void draw( const vector<unsigned> & grid );
        GridDrawer( unsigned xSize, unsigned ySize);
        
    private:

        unsigned xSize;
        unsigned ySize;
        
        inline const unsigned toInx( unsigned x, unsigned y);
        inline const position fromInx( unsigned inx);
        inline void fromInx( unsigned inx, position & pos);
};

#endif
