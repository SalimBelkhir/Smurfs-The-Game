/*#ifndef BGSLIDING_H
#define BGSLIDING_H
#include "Texturemanager.h"
#include "Gameobject.h"
#include "Game.h"
class Bgsliding : public Gameobject
{
    public:
        Bgsliding(const char* texturesheet, int x, int y);
        virtual ~Bgsliding();
        void Drawbg();
        void updatebg(Gameobject* smurf);
        void updateslide();

    private:
        int backgroundOffset =0 ;
        SDL_Texture* bg ;

};

#endif // BGSLIDING_H
*/
