#ifndef SANFOR_H
#define SANFOR_H
#include "Game.h"
#include "Gameobject.h"
#include "SDL2/SDL.h"
#include "Texturemanager.h"
#include <vector>
using namespace std;
class sanfor : public Gameobject {
public:
    sanfor(int x, int y); // Constructor
    ~sanfor(); // Destructor

    void load() ;
    void update();
    void render() ;

    void moveForward();
    void moveBackward();
    void jump();

private:
    SDL_Texture* smurf;
    vector<int> forwardAnim;
    vector<int> backwardAnim;
    vector<int> jumpingAnim;
    SDL_Rect srcRect, destRect;
    int frameWidth;
    int currentFrame;
    int frameDelay;
    Uint32 lastFrameTime;
    bool isMovingForward;
    bool isMovingBackward;
    bool isJumping;
    bool isFacingLeft;
    float jumpSpeed;
    bool isOnGround;
    float initialJumpVelocity;
    float gravity;
};

#endif // SANFOR_H
