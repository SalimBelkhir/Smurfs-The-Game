#ifndef GAME_H
#define GAME_H
#include <SDL2/SDL.h>
#include <iostream>
#include <SDL2/SDL_image.h>

using namespace std;
class Game {
public:
    Game();
    ~Game();
    static Game* GetInstance(){
        return Instance = (Instance != nullptr)? Instance : new Game();
    }
    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    void handleEvents();
    void update();
    void render();
    void clean();
    bool running() { return isRunning; }
    SDL_Renderer* GetRenderer(){return renderer;}
    static SDL_Renderer* renderer;

private:
    SDL_Window* window;
    SDL_Texture* texture;
    bool isRunning;
    SDL_Rect characterRect;
    static Game* Instance ;
    int characterSpeed;

    SDL_Texture* menubg ;
    SDL_Texture* easy;
    SDL_Texture* startButtonTexture;
    SDL_Texture* quitButtonTexture;
    SDL_Texture* optionspage;
    SDL_Rect optionpage;
    SDL_Rect easyrect;
    SDL_Rect menubgRect;
    SDL_Rect startButtonRect;
    SDL_Rect quitButtonRect;
    bool options_page ;
    bool inMenu;
    enum class MenuState { MAIN, EASY, MEDIUM, HARD };
    MenuState currentMenuState;
};

#endif // GAME_H
