#pragma once

#include <functional>

#include "types.hpp"

class SimulatorFunction {
   public:
    SimulatorFunction(std::string _name, const std::function<double(const std::vector<double>&)> _outputFunction)
        : name{_name}, samples{0}, outputFunction{_outputFunction}, inputValues{} {};

    std::vector<double> data;
    std::string name;
    int samples;

    void attachInputs(const std::vector<const std::vector<double>&>& _inputValues) {
        inputValues = _inputValues;
        samples = inputValues[0].size();
    }

    void compute(int _samples) {
        samples = _samples;
        data.reserve(samples);
        const int numInputs = inputValues.size();
        std::vector<double> inputs;
        inputs.reserve(numInputs);

        for(int r = 0; r != samples; ++r) {
            for(int c = 0; c != numInputs; ++c) inputs[c] = inputValues[c][r];
            data[r] = outputFunction(inputs);
        }
    }

    double operator[](int pos) { return data[pos]; };
    std::vector<double>& getData() { return data; };

   private:
    const std::function<double(const std::vector<double>&)> outputFunction;
    std::vector<const std::vector<double>&> inputValues;
};
