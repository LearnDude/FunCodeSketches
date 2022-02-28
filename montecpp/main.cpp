#include "inputFunction.hpp"
#include "outputFunction.hpp"
#include "simulator.hpp"

double f(std::vector<double> vec) { return vec[0] + vec[1]; };

int main() {
    DiscreteDist apples("apples", {1.0, 2.0, 3.0, 4.0}, {0.1, 0.11, 0.80, 1.0});
    NormalDist noise("noise", 2, 2);

    OutputFunction noisyApples("noisyApples", {"apples", "noise"}, f);

    MonteCarloSimulator mySim;
    mySim.attachInputs({&apples, &noise});
    mySim.attachInputs(&apples);
    mySim.attachOutputs(&noisyApples);
    mySim.compute(5);

    std::vector<SimulatorFunction*> john;

    SimulatorFunction a("a", [](const std::vector<double>& x) { return 2.0; });
    InputFunction b("b", randomDist_t::uniform0_1, [](double c) { return c; });

    john.emplace_back(&a);
    john.emplace_back(&b);
    john.emplace_back(&apples);
}