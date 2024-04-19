#ifndef BG_H
#define BG_H
#include"Game.h"
#include "Texturemanager.h"
class bg
{
    public:
        bg();
        virtual ~bg();
        void render();
        void updateforward(int characterX);
        void updatebackward(int characterX);
        void clean();
        int getxpos();
        void setpos(int x);
        void setAnimate(bool animateFlag);
        void setAnimationSpeed(int speed);
        void resetAnimation();
        void updateAnimation();

    private:
        SDL_Texture* sanf;
        SDL_Rect src , des ;
        int xpos;
        int frameWidth;
        int numberOfFrames;
        int currentFrame;
        int animationSpeed;
        Uint32 lastFrameTime;
        bool animate;
        int speed;

};

#endif // BG_H
