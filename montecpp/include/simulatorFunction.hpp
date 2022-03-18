#pragma once

#include <functional>
#include <iostream>

#include "types.hpp"

class SimulatorFunction {
   public:
    SimulatorFunction(std::string _name, std::function<double(const std::vector<double>& row)> _outputFunction)
        : name{_name}, samples{0}, outputFunction{_outputFunction}, inputValues{nullptr} {};

    std::vector<double> data;
    std::string name;
    size_t samples;
    std::vector<const std::vector<double>*> inputValues;

    void attachInputs(std::vector<const std::vector<double>*> _inputValues) {
        inputValues = _inputValues;
        samples = inputValues[0]->size();
    }

    void compute() {
        std::cout << "SimF compute() " << inputValues.size() << std::endl;

        samples = inputValues[0]->size();
        std::cout << "Computing samples: " << samples << std::endl;
        data.clear();
        data.resize(samples);
        const int numInputs = inputValues.size();
        std::vector<double> inputs(numInputs);

        for(int r = 0; r != samples; ++r) {
            for(int c = 0; c != numInputs; ++c) inputs[c] = inputValues[c]->at(r);
            std::cout << r << std::endl;
            data[r] = outputFunction(inputs);
        }
    }

    double operator[](int pos) { return data[pos]; };
    std::vector<double>* getData() { return &data; };

   private:
    const std::function<double(const std::vector<double>& row)> outputFunction;
};
