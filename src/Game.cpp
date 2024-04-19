#include "game.h"
#include "Texturemanager.h"
#include "Physique2D.h"
#include "Transforme.h"
#include "sanfor.h"
#include "Gameobject.h"
#include "Map.h"
#include "Camera.h"
#include "bg.h"
#include <SDL2/SDL_mixer.h>
using namespace std;
Game* Game::Instance = nullptr;
SDL_Renderer* Game::renderer = nullptr ;
Gameobject* player ;
Gameobject* smurf ;
SDL_Texture* mushroom;
bg* background;
Map* mapp;
SDL_Rect Smurfy;
sanfor* sanfor ;
Mix_Music* music;

Game::Game() {
}

Game::~Game() {
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
    int flags = 0;
    SDL_Init(SDL_INIT_AUDIO);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        cout << "subsystem initialized!" << endl;
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window) {
            cout << "Window created" << endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            cout << "Renderer created" << endl;
        }

        isRunning = true;
    } else {
        isRunning = false;
    }

    mushroom = Texturemanager::LoadTexture( "src/mush.png");
    player = new Gameobject("src/sm1.png", 0,0);
    player->setAnimate(false);
    smurf = new Gameobject("src/walkcycle2.png", 0,420);
    mapp = new Map;
    background = new bg;
    easy = Texturemanager::LoadTexture("src/easy.png");
    menubg = Texturemanager::LoadTexture("src/menu_bg.gif");
    startButtonTexture = Texturemanager::LoadTexture("src/Play_button.png");
    quitButtonTexture = Texturemanager::LoadTexture("src/quit_button.png");
    optionspage = Texturemanager::LoadTexture("src/option page.png");
    currentMenuState = MenuState::MAIN;
    music = Mix_LoadMUS("src/smurfmusic.mp3");
                if (music == nullptr) {
                cout<< "Failed to load music: " << Mix_GetError() << endl;
                    } else {
                    Mix_PlayMusic(music, -1); // -1 pour boucler infinment
            }
    inMenu = true;
int arr[20][25]=
{{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,3,2,1,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
mapp->LoadMap(arr);

}
void Game::handleEvents() {
    int xbg =background->getxpos();
    int x = smurf->getx();
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
    case SDL_QUIT:
        isRunning = false;
        break;
    case SDL_MOUSEBUTTONDOWN:
        if (inMenu) {
            int mouseX = event.button.x;
            int mouseY = event.button.y;
            if (mouseX >= startButtonRect.x-700 && mouseX <= startButtonRect.x + startButtonRect.w -700&&
                mouseY >= startButtonRect.y-350 && mouseY <= startButtonRect.y + startButtonRect.h-350) {
                inMenu = false;
                options_page=true;
                currentMenuState = MenuState::EASY;
                smurf->setpos(0);
            }
            else if (mouseX >= quitButtonRect.x&& mouseX <= quitButtonRect.x + quitButtonRect.w-700&&
                mouseY >= quitButtonRect.y +50&& mouseY <= quitButtonRect.y + quitButtonRect.h-300) {
                isRunning = false;
            }
        }
            break;

    case SDLK_ESCAPE:
            inMenu = true;
            currentMenuState = MenuState::MAIN;
            break;
            default:
            break;

    case SDL_KEYDOWN:
        switch (event.key.keysym.sym) {
        case SDLK_LEFT:
            if (x<100){
                x -= 0;
                smurf->setpos(x);
                smurf->setwalkbackward();
                background->setAnimationSpeed(15);
                background->updatebackward(x);
                background->setAnimate(true);
            }else{
                x -= 10;
                smurf->setpos(x);
                smurf->setwalkbackward();
                background->setAnimate(false);
            }
            if(xbg<10){
                background->setAnimate(false);
            }

            if(!smurf->isjumping()){
                smurf->setAnimate(true);
                smurf->setAnimationSpeed(5);
            }
            break;
        case SDLK_RIGHT:
            if(x<600){
                x += 10;
                smurf->setpos(x);
                smurf->setwalkforward();
                background->setAnimate(false);
            }else{
                x += 0;
                smurf->setpos(x);
                smurf->setwalkforward();
                background->setAnimationSpeed(55);
                background->updateforward(x);
                background->setAnimate(true);
            }
            if(xbg>3150){
                background->setAnimate(false);
            }
            if(!smurf->isjumping()){
                smurf->setAnimate(true);
                smurf->setAnimationSpeed(5);
            }

            break;
        case SDLK_SPACE:
            smurf->jump();
            smurf->setAnimationSpeed(150);
            smurf->setAnimate(false);
            break;
        case SDLK_ESCAPE:
            inMenu = true;
            currentMenuState = MenuState::MAIN;
            break;

        default:
            break;
        }
        break;
    case SDL_KEYUP:
        switch (event.key.keysym.sym) {
        case SDLK_LEFT:
            smurf->setAnimate(false);
            smurf->resetAnimation();
            break;
        case SDLK_RIGHT:
            smurf->setAnimate(false);
            smurf->resetAnimation();
            break ;
        default:
            break;
        }
        break;

    }
}

void Game::render() {
    SDL_RenderClear(renderer);
    SDL_Rect mushy = { 100, 100, 50, 50 };
    SDL_RenderCopy(renderer, mushroom, NULL, &mushy);
    background->render();
    player->render();
    smurf->render();
    mapp->DrawMap();
    if (inMenu) {
        // Render main menu
        SDL_RenderCopy(renderer, menubg , NULL , &menubgRect);
        SDL_RenderCopy(renderer, startButtonTexture, NULL, &startButtonRect);
        SDL_RenderCopy(renderer, quitButtonTexture, NULL, &quitButtonRect);
    } else {
        // Render game elements based on current mode
        switch (currentMenuState) {
            case MenuState::EASY:
                //SDL_RenderCopy(renderer,easy,NULL,&easyrect);
                options_page = false;
                break;
            case MenuState::MEDIUM:
                // Render for medium mode
                break;
            case MenuState::HARD:
                // Render for hard mode
                break;
            default:
                break;
        }
    }
    menubgRect = {0,0,800,600};
    easyrect ={0, 200, 800, 400};
    startButtonRect = { 200, 50, 800, 400 };
    quitButtonRect = { 200, 100, 800, 400 };
    SDL_RenderPresent(renderer);
    if(options_page){
        SDL_RenderCopy(renderer,optionspage,NULL,&optionpage);
    }
    optionpage = {0,0,800,600};
}

void Game::update() {
    player->update();
    smurf->update();
    }

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(mushroom);
    background->clean();
    Mix_FreeMusic(music);
    Mix_CloseAudio();
    SDL_Quit();
    cout << "game cleaned" << endl;
}
