#ifndef OBJECTGAME_H
#define OBJECTGAME_H

#include "Object.h"
#include "Transforme.h"
#include <string>
#include <SDL2/SDL.h>

using namespace std;

struct Properties {
public:
    Properties(string textureID, int x, int y, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE)
        : TextureID(textureID), X(x), Y(y), Width(width), Height(height), Flip(flip) {}

public:
    string TextureID;
    float X, Y;
    int Width, Height;
    SDL_RendererFlip Flip;
};

class ObjectGame : public Object {
public:
    ObjectGame(Properties* props)
    : m_Transform(new Transforme(props->X, props->Y)),
      m_TextureID(props->TextureID),
      m_Width(props->Width),
      m_Height(props->Height),
      m_Flip(props->Flip) {}


    virtual ~ObjectGame() {
        delete m_Transform;
    }

    virtual void Draw() = 0;
    virtual void Clean() = 0;
    virtual void Update(float dt) = 0;

protected:
    Transforme* m_Transform;
    string m_TextureID;
    int m_Width, m_Height;
    SDL_RendererFlip m_Flip;
};

#endif // OBJECTGAME_H
