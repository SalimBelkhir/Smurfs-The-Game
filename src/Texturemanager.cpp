#include "Texturemanager.h"
#include "Game.h"
//Texturemanager* Texturemanager::s_Instance = nullptr;

Texturemanager::Texturemanager() {}

SDL_Texture* Texturemanager::LoadTexture( const char* fileName) {
    SDL_Surface* surface = IMG_Load(fileName);
    if(surface == nullptr){
        cout << fileName << "couldn't load" <<endl;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, surface);
    SDL_FreeSurface(surface);

    return texture;
}

/*void Texturemanager::DrawFrame(string name, int x, int y, int width, int height, int row, int frame, SDL_RendererFlip flip) {
    SDL_Rect srcRect;
    srcRect.x = width * frame;
    srcRect.y = height * (row - 1);
    srcRect.w = width;
    srcRect.h = height;

    SDL_Rect destRect;
    destRect.x = x;
    destRect.y = y;
    destRect.w = width;
    destRect.h = height;

//    SDL_RenderCopyEx(Game::GetInstance()->GetRenderer(), m_TextureMap[name], &srcRect, &destRect, 0, NULL, flip);
}*/

void Texturemanager::Draw(SDL_Texture* tex , SDL_Rect src, SDL_Rect des){
    SDL_RenderCopy(Game::renderer,tex , &src , &des);
}

Texturemanager::~Texturemanager() {

}
