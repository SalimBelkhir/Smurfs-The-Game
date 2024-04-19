
#ifndef CAMERA_H
#define CAMERA_H

#include "Gameobject.h"
class Camera {
public:
    Camera();
    Camera(int screenWidth, int screenHeight);
    ~Camera();

    void update(Gameobject* target);
    SDL_Rect getViewport() const;

private:
    SDL_Rect viewport;
    int screenWidth;
    int screenHeight;
};

#endif
