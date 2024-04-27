#include "PerlinNoise.h"
#include <cmath>
#include "../math/Vector2f.h"

float Interpolate(float a, float b, float weight, InterpolationType type) {
    if (weight < 0.0)
        return a;
    if (weight > 1.0)
        return b;

    switch (type) {
        case InterpolationType::Linear:
            return (b - a) * weight + a;
        case InterpolationType::SmoothStep:
            return (b - a) * (3.0f - weight * 2.0f) * weight * weight + a;
        case InterpolationType::SmootherStep:
            return (b - a) * ((weight * (weight * 6.0f - 15.0f) + 10.0f) * weight * weight * weight) + a;
    }

    return 0.0f;
}

Vector2f RandomGradient(int x, int y) {
    // No precomputed gradients mean this works for any number of grid coordinates
    const unsigned w = 8 * sizeof(unsigned);
    const unsigned rotationWidth = w / 2;
    unsigned a = x, b = y;

    a *= 3284157443;
    b ^= a << rotationWidth | a >> (w - rotationWidth);
    b *= 1911520717;
    a ^= b << rotationWidth | b >> (w - rotationWidth);
    a *= 2048419325;

    float random = a * (3.14159265 / ~(~0u >> 1)); // in [0, 2*Pi]

    Vector2f vector;
    vector.x = std::cos(random);
    vector.y = std::sin(random);
    return vector;
}

float DotGridGradient(int ix, int iy, float x, float y) {
    Vector2f gradient = RandomGradient(ix, iy);

    float dx = x - (float) ix;
    float dy = y - (float) iy;

    return dx * gradient.x + dy * gradient.y;
}