#ifndef MYSTICFACTORIES_RANDOM_H
#define MYSTICFACTORIES_RANDOM_H

#include <cctype>
#include <random>

class Random {
protected:
    using u32 = uint_least32_t;
    using engine = std::mt19937;
private:
    unsigned int seed;
    engine generator;
public:
    explicit Random(unsigned int pSeed);
    Random();
    void SetSeed(unsigned int pSeed);
    int Next();
    int Next(int min, int max);
    float NextFloat();
    float NextFloat(float min, float max);

    static Random Global;
};

#endif //MYSTICFACTORIES_RANDOM_H
