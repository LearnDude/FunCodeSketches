#pragma once

#include <iostream>

#include "inputFunction.hpp"
#include "outputFunction.hpp"
#include "types.hpp"

class MonteCarloSimulator {
   public:
    MonteCarloSimulator() : samples{0} {};

    void compute(int _samples) {
        samples = _samples;
        data.clear();

        for(auto input: inputs) {
            input->compute(samples);
            data.emplace_back(input->getData());
        }

        for(auto output: outputs) {
            output->attachInputs(assembleInputs(output));
            output->compute();
            data.emplace_back(output->getData());
        }
    };

    void attachInputs(InputFunction* addInput) { inputs.emplace_back(addInput); };

    void attachInputs(std::vector<InputFunction*> addInputs) {
        for(InputFunction* inputF: addInputs) attachInputs(inputF);
    };

    void attachOutputs(OutputFunction* addOutput) { outputs.emplace_back(addOutput); };

    void attachOutputs(std::vector<OutputFunction*> addOutputs) {
        for(OutputFunction* outputF: addOutputs) attachOutputs(outputF);
    };

    void printData();

    size_t samples;
    std::vector<const std::vector<double>*> data;

   private:
    std::vector<InputFunction*> inputs;
    std::vector<OutputFunction*> outputs;

    std::vector<const std::vector<double>*> assembleInputs(const OutputFunction* output) {
        std::vector<const std::vector<double>*> inputVectors;
        const int len = inputs.size();
        for(auto inputToFind: output->inputNames) {
            bool foundIt = false;
            for(auto input: inputs) {
                if(inputToFind == input->name) {
                    inputVectors.emplace_back(input->getData());
                    foundIt = true;
                    break;
                }
            }
            if(foundIt == false) throw std::invalid_argument("Inputname not found in MonteCarloSimulator instance");
        }
        return inputVectors;
    };
};