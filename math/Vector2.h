#ifndef MYSTICFACTORIES_VECTOR2_H
#define MYSTICFACTORIES_VECTOR2_H

class Vector2 {
public:
    int x;
    int y;

    bool operator==(const Vector2& other) const {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Vector2& other) const {
        return x != other.x || y != other.y;
    }

    bool operator<(const Vector2& other) const {
        return x < other.x || (x == other.x && y < other.y);
    }

    bool operator>(const Vector2& other) const {
        return x > other.x || (x == other.x && y > other.y);
    }

    Vector2 operator+(const Vector2& other) const {
        return {x + other.x, y + other.y};
    }

    Vector2 operator-(const Vector2& other) const {
        return {x - other.x, y - other.y};
    }

    Vector2 operator*(int scalar) const {
        return {x * scalar, y * scalar};
    }

    Vector2 operator/(int scalar) const {
        return {x / scalar, y / scalar};
    }
};

#endif //MYSTICFACTORIES_VECTOR2_H
