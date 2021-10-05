
#include "collatz.hpp"

#include <chrono>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

#define SIMPLEVERSION
// #define MAPVERSION

// #define FORWARD_ORDER
#define REVERSE_ORDER

using std::cout;
using std::endl;
using std::map;
using std::pair;
using std::string;
using std::chrono::high_resolution_clock;

using ull = unsigned long long;
using valIterPair = pair<ull, unsigned int>;

constexpr ull maxn = 0xc00000000000000;
constexpr unsigned int maxIter = 1000000;
constexpr unsigned int interestingIter = 10;
constexpr unsigned int maxMapElements = 1;
constexpr ull startAt = 7579309213675935 + 2;  //931386509544713451
constexpr ull endAt = startAt - 4;

const string fileName = "itermap.csv";

const inline ull nextStep(ull n) {
    return (n & 1) ? n * 3 + 1 : n >> 1;
}

int main() {
    map<ull, unsigned int> storedResults;
    unsigned int mapElements = 0;
    valIterPair smallestElemInMap = {2, 1};
    storedResults.insert(smallestElemInMap);
    unsigned int smallestIterInMap = 0;
    valIterPair longestIter = {2, 1};

    high_resolution_clock timer;
    auto start = timer.now();

#ifdef FORWARD_ORDER
    for (ull startN = startAt; startN < endAt; startN += 2) {
#endif
#ifdef REVERSE_ORDER
        for (ull startN = startAt; startN > endAt; startN = startN - 2) {
#endif
            cout << endl
                 << "STARTN " << startN << endl;
            ull n = startN;
            unsigned int i = 0;

#ifdef SIMPLEVERSION
            while (n != 1 && i < maxIter && !(n & maxn)) {  // &&
                cout << "i:" << i << " n: " << n << " -> ";
                n = nextStep(n);
                i++;
            }
            cout << "i:" << i << " n: " << n << endl;
            cout << "Converged after " << i << " iterations" << endl;

#endif

#ifdef MAPVERSION

            while (n != 1 && i++ < maxIter && !(n & maxn)) {
                if (storedResults.count(n) == 0) {
                    n = nextStep(n);
                } else {
                    i += storedResults.find(n)->second;
                    n = 1;
                    break;
                }
            }

            if (mapElements < maxMapElements) {
                storedResults.insert(valIterPair{startN, i});
                mapElements++;
                if (i < smallestElemInMap.second) smallestElemInMap = {startN, i};

            } else if (i > smallestElemInMap.second) {
                // delete smallest iteration element and add the new one
                storedResults.erase(smallestElemInMap.first);
                storedResults.insert(valIterPair{startN, i});

                // find the element that now has the smallest interations
                smallestElemInMap = *storedResults.cbegin();
                for (auto e = storedResults.cbegin(); e != storedResults.cend(); ++e) {
                    if (e->second < smallestElemInMap.second) {
                        smallestElemInMap = *e;
                    }
                }
                cout << " Inserted n " << startN << " i " << i << " smallest element left " << smallestElemInMap.first << " " << smallestElemInMap.second << endl;
            }

#endif
            if (n & maxn) cout << "Exit to prevent overflow " << startN << " ended at " << std::hex << n << std::dec << endl;
            if (i >= maxIter) cout << "Reached max iterations " << startN << " iterations: " << i << endl;
            if (i >= interestingIter) {
                cout << "Iterations above threshold " << startN << " iterations: " << i << endl;
                if (i > longestIter.second) longestIter = {startN, i};
            }
        }

        auto end = timer.now();

        // if (n == 1) {
        //     cout << " converged after " << i << " iterations" << endl;
        // } else {
        //     cout << " didn't converge after " << i << "iterations\\n"

        //          << endl;
        //     return 0;
        // }

#ifdef MAPVERSION
        cout << "Map of longest iteration elements" << endl;
        for (auto e = storedResults.cbegin(); e != storedResults.cend(); ++e) {
            cout << "n " << e->first << " i " << e->second << endl;
        }
#endif

        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        cout << "Run took " << duration.count() << "ms" << endl;
        cout << "Longest iteration sequence " << longestIter.first << " iterations: " << longestIter.second << endl;

        ull n = longestIter.first;
        unsigned int i = 0;

        start = timer.now();

        while (n != 1 && i++ < maxIter) {  // && !(n & maxn)
            n = nextStep(n);
        }

        end = timer.now();
        auto longestDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        cout << "Took " << longestDuration.count() << "ns to compute" << endl;
        return 0;
    }

    unsigned int readMap(string & fileName, map<ull, unsigned int> & map) {
        std::ifstream file;
        string nLine;
        string iLine;
        std::stringstream nStream;
        std::stringstream iStream;
        ull n;
        unsigned int i;
        unsigned int elems = 0;

        file.open(fileName);

        if (file.is_open()) {
            while (getline(file, nLine) && getline(file, iLine)) {
                nStream << nLine;
                nStream >> n;
                iStream << iLine;
                iStream >> i;
                map.insert({n, i});
                elems++;
            }
            file.close();
        } else {
            cout << "Unable to open file";
        }

        cout << "Loaded map of longest iteration elements" << endl;
        for (auto e = map.cbegin(); e != map.cend(); ++e) {
            cout << "n " << e->first << " i " << e->second << endl;
        }
    }

    unsigned int saveMap(string & fileName, map<ull, unsigned int> & map) {
        std::ofstream file;
        string nLine;
        string iLine;
        std::stringstream nStream;
        std::stringstream iStream;
        ull n;
        unsigned int i;
        unsigned int elems = 0;

        file.open(fileName);

        // if (file.is_open()) {
        //     while (getline(file, nLine) && getline(file, iLine)) {
        //         nStream << nLine;
        //         nStream >> n;
        //         iStream << iLine;
        //         iStream >> i;
        //         map.insert({n, i});
        //         elems++;
        //     }
        //     file.close();
        // } else {
        //     cout << "Unable to open file";
        // }

        cout << "Loaded map of longest iteration elements" << endl;
        for (auto e = map.cbegin(); e != map.cend(); ++e) {
            cout << "n " << e->first << " i " << e->second << endl;
        }
    }