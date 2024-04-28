#include "Random.h"

Random::Random(unsigned int pSeed) : seed(pSeed) {
    generator.seed(seed);
}

Random::Random() : seed(0) {
    generator.seed(seed);
}

void Random::SetSeed(unsigned int pSeed) {
    seed = pSeed;
    generator.seed(seed);
}

int Random::Next() {
    return std::uniform_int_distribution<int>()(generator);
}

int Random::Next(int min, int max) {
    return std::uniform_int_distribution<int>(min, max)(generator);
}

float Random::NextFloat() {
    return Random::NextFloat(0.0f, 1.0f);
}

float Random::NextFloat(float min, float max) {
    return std::uniform_real_distribution<float>(min, max)(generator);
}

Random Random::Global = Random();