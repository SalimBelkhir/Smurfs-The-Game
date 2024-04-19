#include "bg.h"

bg::bg()
{
    sanf = Texturemanager::LoadTexture( "src/bgmap.png");
    xpos = 0;
    src.x=0;
    src.y=0;
    src.w=800;
    src.h=600;
    des.x=xpos;
    des.y=0;
    des.w=800;
    des.h=600;
    frameWidth = 10;  // Assuming each frame width is the same as the window width
    numberOfFrames = 400;  // Number of frames in your animation
    currentFrame = 0;
    animationSpeed = 5;  // Adjust as needed
    lastFrameTime = 0;
    animate = false;

    xpos = 0;
    speed = 20;

}

bg::~bg()
{
}
void bg::updateforward(int characterX)
{
    if (animate) {
        Uint32 currentTime = SDL_GetTicks();
        Uint32 deltaTime = currentTime - lastFrameTime;

        if (deltaTime >= (1000 / animationSpeed)) {

            //xpos += speed;
            //setpos(xpos);


            if (characterX > (800 / 2)) {
                xpos += speed;
                setpos(xpos);
            }

            lastFrameTime = currentTime;
        }
    }
}
void bg::updatebackward(int characterX)
{
    if (animate) {
        Uint32 currentTime = SDL_GetTicks();
        Uint32 deltaTime = currentTime - lastFrameTime;

        if (deltaTime >= (1000 / animationSpeed)) {

            xpos -= speed;
            setpos(xpos);


            if (characterX > (800 / 2)) {
                xpos -= speed;
                setpos(xpos);
            }
            if(xpos>100){
                xpos += 0;
                setpos(xpos);
            }

            lastFrameTime = currentTime;
        }
    }
}
int bg::getxpos(){
    return xpos ;
}
void bg::setpos(int x){
    src.x=x;
}
void bg::render(){
    SDL_RenderCopy(Game::renderer, sanf, &src, &des);
}
void bg::clean(){
    SDL_DestroyTexture(sanf);
}
void bg::setAnimationSpeed(int speed)
{
    animationSpeed = speed;
}
void bg::setAnimate(bool animateFlag)
{
    animate = animateFlag;
}

/*void bg::render(){
    SDL_RenderCopy(Game::renderer, sanf, &src, &des);
}
void bg::clean(){
    SDL_DestroyTexture(sanf);
}

void bg::setpos(int x){
    src.x=x;
}

void bg::setAnimate(bool animateFlag)
{
    animate = animateFlag;
}

void bg::setAnimationSpeed(int speed)
{
    animationSpeed = speed;
}

void bg::resetAnimation()
{
    currentFrame = 0;
}

void bg::updateAnimation()
{
    currentFrame++;
    if (currentFrame >= numberOfFrames) {
        currentFrame = 0;
    }
}*/
