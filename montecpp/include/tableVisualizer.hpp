#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "HTMLStubs.hpp"

template<typename dataType>
class TableVisualizer {
   public:
    std::vector<std::string> columnLabels;
    std::vector<std::vector<dataType>> data;
    bool firstIndexIsRows = true;
    bool firstColumsIsSpecial = false;

    bool generateHTML(std::string _outputPath, std::string _cssPath) {
        using std::endl;

        outputPath = _outputPath;
        cssPath = _cssPath;

        constexpr std::string_view tableHeader = R"delimiter(
            <table>
            )delimiter";
        constexpr std::string_view tableFooter = R"delimiter(
            </table>
            )delimiter";

        constexpr std::string_view rowStart = R"delimiter(<tr>)delimiter";
        constexpr std::string_view rowEnd = R"delimiter(</tr>)delimiter";

        constexpr std::string_view labelCellStart = R"delimiter(<th>)delimiter";
        constexpr std::string_view labelCellEnd = R"delimiter(</th>)delimiter";

        constexpr std::string_view cellStart = R"delimiter(<td>)delimiter";
        constexpr std::string_view cellEnd = R"delimiter(</td>)delimiter";

        std::cout << "Writing table to " << outputPath << endl;

        std::fstream output;
        output.open(outputPath.c_str(), std::ios::out | std::ios::trunc);

        if(cssPath != "") {
            std::fstream cssRead;
            cssRead.open(cssPath.c_str(), std::ios_base::in);
            std::string line;
            while(std::getline(cssRead, line)) output << line;
            cssRead.close();
        }

        output << Stubs::HTMLheader << tableHeader << endl;

        if(!columnLabels.empty()) {
            output << rowStart;
            for(auto cell: columnLabels) output << labelCellStart << cell << labelCellEnd;
            output << rowEnd << endl;
        }

        if(firstIndexIsRows) {
            for(auto row: data) {
                output << rowStart;
                for(auto cell: row) output << cellStart << cell << cellEnd;
                output << rowEnd << endl;
            }
        } else {
            auto numRows = data.size();
            auto numCols = data[0].size();
            for(int r = 0; r < numRows; r++) {
                output << rowStart;
                for(int c = 0; c < numCols; c++) output << cellStart << data[c][r] << cellEnd;
                output << rowEnd << endl;
            }
        }

        output << tableFooter << endl << Stubs::HTMLfooter << endl;  // << std::end;

        output.close();

        std::cout << "Finished writing table" << endl;

        return true;
    }
    bool generateHTML() {
        if(outputPath != "") return generateHTML(outputPath);
        return false;
    };

   private:
    std::string css;
    std::string htmlPage;

    std::string cssPath;
    std::string outputPath;
    std::string csvColDelimiter;
    std::string csvRowDelimiter;

    std::vector<dataType>& makeRowfromCol(int row);
};
