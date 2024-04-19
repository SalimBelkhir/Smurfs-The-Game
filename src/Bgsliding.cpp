/*#include "Bgsliding.h"

Bgsliding::Bgsliding(const char* texturesheet, int x ,int y):Gameobject(texturesheet ,x , y)
{
    bg = Texturemanager::LoadTexture(texturesheet);
}

Bgsliding::~Bgsliding()
{}
void Bgsliding::Drawbg(){
    SDL_Rect bgRect = {0,0,4000,600};
    SDL_RenderCopy(Game::renderer, bg, NULL, &bgRect);
}
void Bgsliding::updatebg(Gameobject* smurf){
    SDL_Rect src = smurf->getsrc();
    if(src.x >=400){
        backgroundOffset += 10;
        if (backgroundOffset > 3600) {
            backgroundOffset = 3600;
        }
    } else {
        backgroundOffset = 0;
    }

    SDL_Rect adjustedBgRect = { -backgroundOffset, 0, 4000, 600 };
    SDL_RenderCopy(Game::renderer, bg, NULL, &adjustedBgRect);
}
*/

