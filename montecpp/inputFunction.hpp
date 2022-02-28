#pragma once

#include <functional>
#include <random>
#include <stdexcept>

#include "simulatorFunction.hpp"
#include "types.hpp"

class InputFunction : public SimulatorFunction {
   public:
    InputFunction(std::string _name, randomDist_t _distributionType, d2dFunction_t f)
        : uniform_0_1_dist{0.0, 1.0},
          normal_0_1_dist{0.0, 1.0},
          generator{std::random_device{}()},
          distributionType{_distributionType},
          SimulatorFunction::SimulatorFunction(_name,
                                               [&f](const std::vector<double>& randnum) { return f(randnum[0]); }){};

    void compute(int _samples) {
        samples = _samples;
        generate();
        SimulatorFunction::compute(samples);
    }

   private:
    std::uniform_real_distribution<double> uniform_0_1_dist;
    std::normal_distribution<double> normal_0_1_dist;
    std::minstd_rand0 generator;
    std::vector<double> randomData;
    const randomDist_t distributionType;

    constexpr double randDistribution() {
        switch(distributionType) {
            case randomDist_t::uniform0_1:
                return uniform_0_1_dist(generator);
                break;

            case randomDist_t::normal0_1:
                return normal_0_1_dist(generator);
                break;

            case randomDist_t::max:
            default:
                throw std::invalid_argument("Random distribution not supported");
                return 0.0;
        };
    }

    void generate() {
        randomData.reserve(samples);
        for(int i = 0; i != samples; ++i) randomData[i] = randDistribution();
    };
};

class DiscreteDist : public InputFunction {
   public:
    DiscreteDist(std::string _name, std::vector<double> _datapoints, std::vector<double> _cumulativeProbs)
        : datapoints{_datapoints},
          cumulativeProbs{_cumulativeProbs},
          len{_cumulativeProbs.size()},
          InputFunction::InputFunction(_name, randomDist_t::uniform0_1, generatorFunction){};

   private:
    std::vector<double> datapoints;
    std::vector<double> cumulativeProbs;
    const int len;
    d2dFunction_t generatorFunction = [_len = len, _datapoints = datapoints,
                                       _cumulativeProbs = cumulativeProbs](double randn) {
        for(int i = 0; i < _len; i++) {
            if(randn < _cumulativeProbs[i]) return _datapoints[i];
        }
        throw std::invalid_argument("Cumulative probability function overran 1.0");
    };
};

class NormalDist : public InputFunction {
   public:
    NormalDist(std::string _name, double _mean, double _stddev)
        : mean{_mean},
          stddev{_stddev},
          generatorFunction{[_stddev = stddev, _mean = mean](double randn) { return randn * _stddev + _mean; }},
          InputFunction::InputFunction(_name, randomDist_t::normal0_1, generatorFunction){};

   private:
    const double mean;
    const double stddev;
    d2dFunction_t generatorFunction;
};