#ifndef MYSTICFACTORIES_CAMERA_H
#define MYSTICFACTORIES_CAMERA_H

class Camera {
private:
    int x, y;
public:
    Camera();
    ~Camera();
    void Update();
    void Render();
    void Move(int pX, int pY);
    void SetX(int pX) { x = pX; }
    void SetY(int pY) { y = pY; }
    [[nodiscard]] int GetX() const { return x; }
    [[nodiscard]] int GetY() const { return y; }
    [[nodiscard]] int GetRelativeX(int pX) const { return pX - x; }
    [[nodiscard]] int GetRelativeY(int pY) const { return pY - y; }

    [[nodiscard]] bool IsVisible(int pX, int pY, int width, int height) const;

    void SetPosition(int pX, int pY);
};

#endif //MYSTICFACTORIES_CAMERA_H
