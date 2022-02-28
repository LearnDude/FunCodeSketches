#pragma once

#include "inputFunction.hpp"
#include "outputFunction.hpp"
#include "types.hpp"

class MonteCarloSimulator {
   public:
    void compute(int _samples) {
        samples = _samples;
        data.clear();

        for(auto input: inputs) {
            input->compute(samples);
            data.emplace_back(input->getData());
        }

        for(auto output: outputs) {
            output->attachInputs(assembleInputs(output));
            output->compute(samples);
            data.emplace_back(output->getData());
        }
    };

    void attachInputs(const InputFunction& addInput) { inputs.emplace_back(addInput); };

    void attachInputs(std::vector<InputFunction> addInputs) {
        for(auto inputF: addInputs) attachInputs(inputF);
    };

    void attachOutputs(const OutputFunction& addOutput) { outputs.emplace_back(addOutput); };

    void attachOutputs(const std::vector<const OutputFunction>& addOutputs) {
        for(auto outputF: addOutputs) attachOutputs(outputF);
    };

    int samples;
    std::vector<const std::vector<double>&> data;

   private:
    std::vector<DiscreteDist*> inputs;
    std::vector<OutputFunction*> outputs;

    std::vector<const std::vector<double>&> assembleInputs(OutputFunction* output) {
        std::vector<const std::vector<double>&> inputVectors;
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