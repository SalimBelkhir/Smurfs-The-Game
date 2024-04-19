/*#ifndef CHARACTER_H
#define CHARACTER_H
#include "Game.h"

class Character :public Game
{
    public:
        Character(const Game &game,const char* title ,int x , int y ,int h , int w ,bool flip);
        virtual ~Character();
        void draw();
        void events();

    private:
        int width , height;
        int xpos , ypos ;

};

#endif // CHARACTER_H*/
