#pragma once

#include <functional>
#include <random>

typedef std::function<double(std::default_random_engine)> generatorFunction_t;

enum class randomDist_t { uniform0_1, normal0_1, max };
