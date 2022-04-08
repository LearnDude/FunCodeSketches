#pragma once

#include <functional>
#include <iostream>

#include "types.hpp"

class SimulatorFunction {
   public:
    SimulatorFunction(std::string _name, std::function<double(const std::vector<double>& row)> _outputFunction)
        : name{_name}, samples{0}, outputFunction{_outputFunction}, inputFunctions{} {};

    std::vector<double> data;
    std::string name;
    size_t samples;
    std::vector<SimulatorFunction*> inputFunctions;

    void attachInputs(std::vector<const SimulatorFunction*> _inputValues) {
        inputFunctions = _inputValues;
        samples = inputFunctions[0]->samples;
    }

    void compute() {
        std::cout << "SimF compute() " << samples << std::endl;

        samples = inputFunctions[0]->samples;
        std::cout << "Computing samples: " << samples << std::endl;
        data.clear();
        data.resize(samples);
        const int numInputs = inputFunctions.size();
        std::vector<double> inputRow(numInputs);

        for(int r = 0; r != samples; ++r) {
            for(int c = 0; c != numInputs; ++c) inputRow[c] = inputFunctions[c]->data[r];
            std::cout << r << std::endl;
            data[r] = outputFunction(inputRow);
        }
    }

    double operator[](int pos) { return data[pos]; };
    std::vector<double>* getData() { return &data; };

   private:
    const std::function<double(const std::vector<double>& row)> outputFunction;
};
