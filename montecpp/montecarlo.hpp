#ifndef __montecarlo
#define __montecarlo

#include <functional>
#include <random>
#include <chrono>

#include <stdexcept>



// unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
// std::default_random_engine generator(seed);
// std::uniform_real_distribution<double> distribution(0,1);
// std::normal_distribution<double> distribution2(5.0,2.0);

// auto x = distribution(generator);

typedef std::function<double(std::default_random_engine)> generatorFunction_t;
typedef std::function<double(double)> d2dFunction;


class inputFunction 
{
public:
    inputFunction(d2dFunction f, generatorFunction_t rg, int samples):
        len{samples},generatorFunction{f}, distribution{rg},n{0},
        generator{std::chrono::system_clock::now().time_since_epoch().count()}
        { generate(samples);};

    inputFunction(std::function<double(double)> f, generatorFunction_t rg) { inputFunction(f,rg,0);};
    inputFunction(std::function<double(double)> f, int samples)
    { inputFunction(f, [](){std::uniform_real_distribution<double> distribution(0,1), 0);};
    // inputFunction( std::function<double(double)> f) {inputFunction(f, 0);};

    double generate() { return generatorFunction( distribution(generator));}

    double generate( int samples) { 
        if( samples == 0) return;
        data.reserve(samples);
        for( int i = 0; i < samples; i++) data[i] = generate();
        return 0;
        };
 
    int len;
    std::vector<double> data;
    
private:
    const std::default_random_engine generator;
    const std::function<double(double)> generatorFunction;
    const std::function<double(std::default_random_engine)> distribution;
    int n;
};

class discreteDist : inputFunction {
    public:
    discreteDist(std::vector<double> _datapoints, std::vector<double> _cumulativeProbs) : 
    datapoints{_datapoints}, cumulativeProbs{_cumulativeProbs} {
        if( datapoints.size() != cumulativeProbs.size()) throw std::invalid_argument("argument size mismatch");
        generatorFunction = [& ](double x) {
            const int len  = cumulativeProbs.size();
            for( int i = 0; i < len; i++) {
                if( x < cumulativeProbs[i]) return datapoints[i];
            }
            return (double)0;
        }
        inputFunction::inputFunction( generatorFunction, )




    }

    private:
    std::vector<double> datapoints;
    std::vector<double> cumulativeProbs;
    std::function<double(double)> generatorFunction;

}

// std::function<double<double> discreteDistFunction(vector<double> datapoints, vector<double> cumumativeProbs) {
//     return []<double>(double x) { // this should be done with upper_bound
//         const int len  = cumulativeProbs.size();
//         for( int i = 0; i < len; i++) {
//             if( x < cumulativeProbs.at(i)) return datapoints.at(i);
//         }
//         return 0;
//     }
// }



#endif