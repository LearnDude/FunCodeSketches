#include <functional>
#include <iostream>
#include <string>
#include <vector>

#include "inputFunction.hpp"
#include "outputFunction.hpp"
#include "simulator.hpp"
#include "tableVisualizer.hpp"

using std::cout;
using std::string;
using std::string_view;
using std::vector;

class P {
   public:
    P(std::function<double(std::vector<double>& row)> _vec2dFunc) : vec2dFunc{_vec2dFunc} {};

    void compute() {
        std::vector<double> avec{0.5, 0.6};
        std::cout << vec2dFunc(avec);
        auto numInputs = inputValues.size();
        cout << numInputs << std::endl;
        auto samples = inputValues[0]->size();
        cout << samples << std::endl;
        data.resize(samples);
        std::vector<double> row(numInputs);
        for(int r = 0; r < samples; r++) {
            for(int c = 0; c < numInputs; c++) row[c] = (*inputValues[c])[r];
            data[r] = vec2dFunc(row);
        }
    };

    void addInputs(std::vector<double>* vecp) { inputValues.emplace_back(vecp); };

    std::vector<double> data;
    std::vector<std::vector<double>*> inputValues;
    std::function<double(std::vector<double>& row)> vec2dFunc;
};

class C : public P {
   public:
    C(std::function<double(double)> _d2dFunc)
        : d2dFunc{_d2dFunc}, P::P([_d2dFunc](std::vector<double>& row) { return _d2dFunc(row[0]); }){};

    std::function<double(double)> d2dFunc;
};

double ad2dFunc(double x) { return x; };

double avec2dFunc(const std::vector<double>& row) { return row[0] + row[1]; };

int main() {
    using std::cout;
    using std::string;
    using std::string_view;
    using std::vector;

    // C child(ad2dFunc);
    // std::vector<double> inputs{1., 2., 3.};
    // cout << "Adding inputs" << std::endl;
    // child.addInputs(&inputs);
    // cout << "Computing" << std::endl;
    // child.compute();
    // cout << "Returning" << std::endl;
    // return child.data[1];

    // DiscreteDist apples("apples", {1.0, 2.0, 3.0, 4.0}, {0.1, 0.11, 0.80, 1.0});
    // NormalDist noise("noise", 2, 2);

    vector<double> vec1{2.0, 3.2, 5.6};
    vector<double> vec2{1.3, 3.1, 0.1};

    int samples = 3;

    OutputFunction noisyBalls("noisyBalls", {"vec1", "vec2"}, avec2dFunc);

    std::vector<const std::vector<double>*> inp{&vec1, &vec2};
    noisyBalls.attachInputs(inp);
    cout << "compute main\n";
    noisyBalls.compute();

    for(int i = 0; i < 3; i++) cout << noisyBalls.data[i] << std::endl;

    // SimulatorFunction bs{"bs", g};

    // std::minstd_rand0 generator{std::random_device{}()};

    InputFunction noise("noise", randomDist_t::uniform0_1, ad2dFunc);

    // noise.compute(5);
    // cout << noise.data.size() << std::endl;
    // for(int i = 0; i < 3; i++) cout << noise.data[i] << std::endl;

    // OutputFunction noisyApples("noisyApples", {"apples", "noise"}, f);

    // MonteCarloSimulator mySim;
    // std::vector<InputFunction*> theInputs{&apples, &noise};
    // mySim.attachInputs(theInputs);
    // mySim.attachInputs({&apples, &noise});
    // mySim.attachInputs(&apples);
    // mySim.attachOutputs(&noisyApples);
    // mySim.compute(5);

    // vector<string> labels = {"blink", "blonk"};
    // vector<vector<int>> data = {{1, 2}, {3, 4}, {5, 6}};

    // TableVisualizer<int> table;
    // table.columnLabels = labels;
    // table.data = data;

    // string savePath = "./tablesave2.html";
    // string cssPath = "";

    // table.generateHTML(savePath, cssPath);

    // std::cout << "Hello world\n";
    // return 0;
}