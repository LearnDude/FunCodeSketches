#pragma once

#include <functional>
#include <stdexcept>

#include "simulatorFunction.hpp"
#include "types.hpp"

class OutputFunction : SimulatorFunction {
   public:
    OutputFunction(std::string _name, std::vector<std::string> _inputNames,
                   const std::function<double(const std::vector<double>&)> _outputFunction)
        : inputNames{_inputNames}, numInputs{_inputNames.size()}, SimulatorFunction(_name, _outputFunction){};

    using SimulatorFunction::attachInputs;
    using SimulatorFunction::compute;
    using SimulatorFunction::data;
    using SimulatorFunction::name;
    using SimulatorFunction::samples;
    using SimulatorFunction::operator[];
    using SimulatorFunction::getData;

    std::vector<std::string> inputNames;
    const int numInputs;

   private:
};