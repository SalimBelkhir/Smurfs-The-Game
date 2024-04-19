#ifndef MAP_H
#define MAP_H
#include "game.h"

class Map
{
    public:

        Map();
        virtual ~Map();
        void LoadMap(int arr[20][25]);
        void DrawMap();

    private:
        SDL_Rect src , des ;
        SDL_Texture* emptyheart ;
        SDL_Texture* demiheart ;
        SDL_Texture* heart;
        int map1[20][25] ;

};

#endif // MAP_H
