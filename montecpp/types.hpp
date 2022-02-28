#pragma once

#include <functional>
#include <random>

typedef std::function<double(std::default_random_engine)> generatorFunction_t;

typedef std::vector<double> input_t;
typedef std::function<double(double)> d2dFunction_t;
typedef std::function<double(input_t)> many2dFunction_t;

enum class randomDist_t { uniform0_1, normal0_1, max };
