#ifndef MYSTICFACTORIES_NOISE_H
#define MYSTICFACTORIES_NOISE_H

class Noise {
public:
    virtual ~Noise() = default;
    [[nodiscard]] virtual float Eval(float x) = 0;
    [[nodiscard]] virtual float Eval(float x, float y) = 0;
};

#endif //MYSTICFACTORIES_NOISE_H
