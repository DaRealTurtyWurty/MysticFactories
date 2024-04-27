#include "Camera.h"
#include "../Constants.h"

Camera::Camera() : x(0), y(0) {}

Camera::~Camera() = default;

void Camera::update() {

}

void Camera::render() {

}

void Camera::move(int pX, int pY) {
    this->x += pX;
    this->y += pY;
}

bool Camera::IsVisible(int pX, int pY, int width, int height) const {
    return pX + width > this->x && pX < this->x + SCREEN_WIDTH && pY + height > this->y && pY < this->y + SCREEN_HEIGHT;
}
