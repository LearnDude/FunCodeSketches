// #include "tableVisualizer.hpp"

// #include <fstream>
// #include <iostream>
// #include <string>

// #include "HTMLStubs.hpp"

// template<class dataType>
// bool TableVisualizer<dataType>::generateHTML(std::string _outputPath, std::string cssPath) {

//     using std::endl;

//     outputPath = _outputPath;
//     cssPath = _cssPath;

//     constexpr std::string_view tableHeader = "<table>";
//     constexpr std::string_view tableFooter = "</table>";

//     constexpr std::string_view rowStart = "<td>";
//     constexpr std::string_view rowEnd = "</td>";

//     constexpr std::string_view labelCellStart = "<th>";
//     constexpr std::string_view labelCellEnd = "</th>";

//     constexpr std::string_view cellStart = "<td>";
//     constexpr std::string_view cellEnd = "</td>";

//     std::cout << "Writing table to " << outputPath << endl;

//     std::fstream output;
//     std::ios_base::openmode bits = std::ios_base::out | std::ios_base::trunc | std::ios_base::fixed;
//     auto status = output.open(outputPath.c_str(), bits);
//     // process status

//     if(cssPath != "") {
//         std::fstream cssRead;
//         auto status = cssRead.open(cssPath.c_str(), std::ios_base::in);
//         std::string line;
//         while(std::getline(cssRead, line)) output << line;
//         cssRead.close();
//     }

//     output << Stubs::HTMLheader << tableHeader << endl;

//     if(!columnLabels.empty()) {
//         output << rowStart;
//         for(auto cell: columnLabels) output << labelCellStart << cell << labelCellEnd;
//         output << rowEnd << endl;
//     }

//     if(firstIndexIsRows) {
//         for(auto row: data) {
//             output << rowStart;
//             for(auto cell: row) output << cellStart << cell << cellEnd;
//             output << rowEnd << endl;
//         }
//     } else {
//         auto numRows = data.size();
//         auto numCols = data[0].size();
//         for(int r = 0; r < numRows; r++) {
//             output << rowStart;
//             for(int c = 0; c < numCols; c++) output << cellStart << data[c][r] << cellEnd;
//             output << rowEnd << endl;
//         }
//     }

//     output << tableFooter << endl << Stubs::HTMLfooter << endl;  // << std::end;

//     output.close();

//     std::cout << "Finished writing table" << endl;

//     return true;
// }