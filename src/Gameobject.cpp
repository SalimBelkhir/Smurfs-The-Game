#include "Gameobject.h"
#include "Texturemanager.h"
#include "Game.h"
Gameobject::Gameobject(const char* texturesheet , int x , int y) {
    objTexture = Texturemanager::LoadTexture(texturesheet);
    xpos = x ;
    ypos = y ;
    frameWidth = 64; // Assuming each frame is 64 pixels wide
    numberOfFrames = 10; // Number of frames in your animation
    currentFrame = 0;
    animationSpeed = 5; // Adjust as needed

    animate = false;
    walkforwardpos = 0;
    canjump = true;
    initialY = y ;
    yvel =0.0f ;
    gravity = 0.2f ;
    jumpforce =-8.0f;
    jumpheight = 150.0f;

}

Gameobject::~Gameobject() {
    // Release resources
    SDL_DestroyTexture(objTexture);
}

void Gameobject::update() {
    //xpos++ ;
    //ypos++;

    if (animate) {
        Uint32 currentTime = SDL_GetTicks();
        Uint32 deltaTime = currentTime - lastFrameTime;

        if (deltaTime >= (1000 / animationSpeed)) {
            updateAnimation();
            lastFrameTime = currentTime;
        }
    }
    if(canjump){
        Uint32 currentTime = SDL_GetTicks();
        Uint32 deltaTime = currentTime - lastFrameTime;
        if (deltaTime >= (1000 / animationSpeed)) {
            yvel += gravity ;
            ypos += yvel ;
            lastFrameTime = currentTime;
        }
        if(ypos >= initialY){
            yvel = 0.0f;
            canjump = false ;
            ypos = initialY ;
        }
    }
    srcRect.h = 105;
    srcRect.w = frameWidth;
    srcRect.x = currentFrame*frameWidth;
    srcRect.y = walkforwardpos;

    desRect.x = xpos;
    desRect.y = ypos;
    desRect.w = srcRect.w * 2;
    desRect.h = srcRect.h * 2;
}

void Gameobject::render() {
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &desRect);
}

int Gameobject::getx(){
    return xpos ;
}
int Gameobject::gety(){
    return ypos ;
}
void Gameobject::setpos(int x){
    xpos=x;

}
SDL_Rect Gameobject::getsrc(){
    return srcRect ;
}

void Gameobject::setsrc(SDL_Rect src){
    srcRect.h=src.h;
    srcRect.w=src.w;
    srcRect.x=src.x;
    srcRect.y=src.y;
}
void Gameobject::updateAnimation() {
    // Update animation frame based on animation speed
    currentFrame++;
    if (currentFrame >= numberOfFrames) {
        currentFrame = 0; // Reset to first frame
    }
}

void Gameobject::setAnimate(bool animateFlag) {
    animate = animateFlag;
}

bool Gameobject::shouldAnimate() {
    return animate;
}
void Gameobject::setAnimationSpeed(int speed) {
    animationSpeed = speed;
}
void Gameobject::resetAnimation() {
    currentFrame = 0; // Reset to first frame
}
void Gameobject::setwalkforward(){
    walkforwardpos = 105 ;
}
void Gameobject::setwalkbackward(){
    walkforwardpos = 0 ;
}
void Gameobject::jump(){
    if(!canjump){
        yvel = jumpforce ;
        canjump = true ;
    }
}
bool Gameobject::isjumping(){
    if(ypos!=initialY){
        return true ;
    }
}
bool Gameobject::var(int c) {
    static int previousX = srcRect.x;
    bool isIncrementing = (srcRect.x > previousX);
    previousX = srcRect.x;
    return isIncrementing;
}
