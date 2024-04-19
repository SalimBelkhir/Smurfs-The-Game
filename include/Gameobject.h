#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SDL2/SDL.h>
#include "bg.h"
class Gameobject
{
    public:
        Gameobject(const char* texturesheet ,int x , int y);
        virtual ~Gameobject();
        void update() ;
        void render() ;
        int getx();
        int gety();
        void setpos(int x);
        SDL_Rect getsrc();
        void setsrc(SDL_Rect src);
        void setAnimate(bool animate);
        bool shouldAnimate();
        void setAnimationSpeed(int speed);
        void resetAnimation();
        void setwalkforward();
        void setwalkbackward();
        void jump();
        bool isjumping();
        bool var(int c);


    private:
        int xpos ;
        int ypos ;
        SDL_Texture* objTexture;
        SDL_Rect srcRect , desRect ;
        SDL_Renderer* renderer ;
        int frameWidth; // Width of each frame
        int numberOfFrames; // Number of frames in the animation
        int currentFrame; // Current frame index
        int animationSpeed; // Speed of animation
        Uint32 lastFrameTime;
        bool animate; // Flag to control animation
        int walkforwardpos ;


        void updateAnimation();
        bool canjump;
        int initialY;
        float yvel , gravity , jumpforce , jumpheight ;



};

#endif // GAMEOBJECT_H
