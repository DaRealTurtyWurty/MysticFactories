#ifndef MYSTICFACTORIES_CAMERA_H
#define MYSTICFACTORIES_CAMERA_H

class Camera {
private:
    int x, y;
public:
    Camera();
    ~Camera();
    void update();
    void render();
    void move(int pX, int pY);
    void setX(int pX) { x = pX; }
    void setY(int pY) { y = pY; }
    [[nodiscard]] int getX() const { return x; }
    [[nodiscard]] int getY() const { return y; }
    [[nodiscard]] int getX(int pX) const { return pX - x; }
    [[nodiscard]] int getY(int pY) const { return pY - y; }

    [[nodiscard]] bool IsVisible(int pX, int pY, int width, int height) const;
};

#endif //MYSTICFACTORIES_CAMERA_H
