#pragma once

#include <vector>
#include <functional>
#include "predicates.hpp"

class DomainAnalyzer {
    public:
    DomainAnalyzer(std::vector<const std::vector<double>*> _data, std::function<bool(std::vector<double>& row)> _predf ):
     data{_data}, predf{_predf} {};

    std::vector<const std::vector<double>*> data;
    std::vector< std::vector<double>> result;

    void compute() {
        numInputs = data.size();
        samples = data[0]->size();
        result.clear();
        std::vector<double> inputRow(numInputs);
        for( int r = 0; r < samples; r++) {
            for( int c = 0; c < numInputs; c++) inputRow[c] = (*data[c])[r];
            if( predf(inputRow)) result.emplace_back(inputRow);
        }
    };

    // Predicate pred;

    private:
    bool predfu();
    std::vector<std::string> labels;
    size_t samples;
    int numInputs;
    std::function<bool(std::vector<double>& row)> predf;


};