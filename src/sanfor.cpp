#include "sanfor.h"

sanfor::sanfor(int x, int y) : Gameobject(nullptr, x, y),frameWidth(64), currentFrame(0), frameDelay(100), lastFrameTime(0),
                               isMovingForward(false), isMovingBackward(false), isJumping(false), isFacingLeft(false),
                               jumpSpeed(0), isOnGround(true), initialJumpVelocity(-10.0f), gravity(0.5f) {}

sanfor::~sanfor() {
    SDL_DestroyTexture(smurf);
}

void sanfor::load() {
    smurf = Texturemanager::LoadTexture("src/walkcycle.png");
    forwardAnim = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // Define animation frames
    backwardAnim = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0}; // Define backward animation frames
    jumpingAnim = {10, 11, 12, 13, 14}; // Define jumping animation frames
}

void sanfor::update() {
    Uint32 currentTime = SDL_GetTicks();
    // warning is talking about currentTime - lastFrameTime comparaison
    if (currentTime - lastFrameTime > frameDelay) {
        lastFrameTime = currentTime;

        if (isMovingForward) {
            currentFrame = (currentFrame + 1) % forwardAnim.size();
            srcRect.x = forwardAnim[currentFrame] * frameWidth;
        } else if (isMovingBackward) {
            currentFrame = (currentFrame + 1) % backwardAnim.size();
            srcRect.x = backwardAnim[currentFrame] * frameWidth;
        } else if (isJumping) {
            currentFrame = (currentFrame + 1) % jumpingAnim.size();
            srcRect.x = jumpingAnim[currentFrame] * frameWidth;
        } else {
            // Standing still
            currentFrame = 0;
            srcRect.x = 0;
        }
    }

    // Update position based on movement
    if (isMovingForward) {
        moveForward();
    } else if (isMovingBackward) {
        moveBackward();
    }

    // Update position based on jumping
    if (isJumping) {
        jump();
    }

    // Apply gravity
    if (!isOnGround) {
        destRect.y += jumpSpeed;
        jumpSpeed += gravity;
        // You might want to check for collision with ground here
        // For simplicity, let's assume the ground is at y = 400
        if (destRect.y >= 400) {
            destRect.y = 400;
            jumpSpeed = 0;
            isOnGround = true;
        }
    }
}

void sanfor::render() {
    SDL_RendererFlip flip = isFacingLeft ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
    SDL_RenderCopyEx(Game::renderer, smurf, &srcRect, &destRect, 0, nullptr, flip);
}

void sanfor::moveForward() {
    destRect.x += 2; // Adjust speed as needed
}

void sanfor::moveBackward() {
    destRect.x -= 2; // Adjust speed as needed
}

void sanfor::jump() {
    if (isOnGround) {
        isOnGround = false;
        jumpSpeed = initialJumpVelocity;
    }
}
