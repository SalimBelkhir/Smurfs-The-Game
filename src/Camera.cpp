#include "Camera.h"

Camera::Camera(int screenWidth, int screenHeight)
    : screenWidth(screenWidth), screenHeight(screenHeight) {
    viewport.x = 0;
    viewport.y = 0;
    viewport.w = screenWidth;
    viewport.h = screenHeight;
}

Camera::~Camera() {}

void Camera::update(Gameobject* target) {
    // Center the camera on the target (player)
    viewport.x = target->getx() - screenWidth / 2;
    viewport.y = target->gety() - screenHeight / 2;

    // Clamp the camera position to prevent going out of bounds
    if (viewport.x < 0) {
        viewport.x = 0;
    }
    if (viewport.y < 0) {
        viewport.y = 0;
    }
    // Adjust these values based on your map size
    if (viewport.x > 800 - viewport.w) {
        viewport.x = 800 - viewport.w;
    }
    if (viewport.y > 600 - viewport.h) {
        viewport.y = 600 - viewport.h;
    }
}

SDL_Rect Camera::getViewport() const {
    return viewport;
}
