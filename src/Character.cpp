/*#include "Character.h"

Character::Character(const Game &game,const char* title ,int x , int y ,int h , int w ,bool flip):

{

}

void Character::draw(){
    SDL_Rect rect ;
    rect.w = weight ;
    rect.h = height;
    rect.x = xpos;
    rect.y = ypos;

    SDL_SetRenderDrawBlendMode(Game::renderer,0,0,0,255);
    SDL_RenderFillRect(renderer,&rect);
}
void Character::events(){
    SDL_Event event ;
    if(SDL_PollEvents(&event)){
        if(event.type == SDL_KEYDOWN){

        }
    }
}*/
