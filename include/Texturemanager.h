#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <string>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>

using namespace std;

class Texturemanager {
public:
   /*static Texturemanager* GetInstance() {
        return s_Instance = (s_Instance != nullptr) ? s_Instance : new Texturemanager();
    }*/

    Texturemanager();
    static SDL_Texture* LoadTexture( const char* fileName);
    static void Draw(SDL_Texture* tex,SDL_Rect src,SDL_Rect des);
    void DrawFrame(string name, int x, int y, int width, int height, int row, int frame, SDL_RendererFlip flip = SDL_FLIP_NONE);
    virtual ~Texturemanager();

private:
   // static Texturemanager* s_Instance;
};

#endif // TEXTUREMANAGER_H
