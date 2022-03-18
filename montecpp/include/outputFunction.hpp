#pragma once

#include <functional>
#include <stdexcept>

#include "simulatorFunction.hpp"
#include "types.hpp"

class OutputFunction : public SimulatorFunction {
   public:
    OutputFunction(std::string _name, std::vector<std::string> _inputNames,
                   const std::function<double(const std::vector<double>&)> _outputFunction)
        : inputNames{_inputNames}, numInputs{_inputNames.size()}, SimulatorFunction(_name, _outputFunction){};

    std::vector<std::string> inputNames;
    const size_t numInputs;

   private:
};