#include <SDL2/SDL.h>

#include "Game.h"

//Holds all information for main game loop

namespace {
const int FPS = 60;
const int MAX_FRAME_TIME = 6 * 1000 / FPS;
}

Game::Game() {
    SDL_Init(SDL_INIT_EVERYTHING);
    this->gameLoop();
}

Game::~Game() {
    //dtor
}

void Game::gameLoop() {
    Graphics graphics;
    SDL_Event event;

    this->_player = Player(graphics, 100, 100);

    int LAST_UPDATE_TIME = SDL_GetTicks(); //Gets time since sdl was startred
    //Starts game loop
    while(true) {
        input.beginNewFrame(); //Resets pressed and released keys once every frame

        if(SDL_PollEvent(&event)) { //Event handler
            if(event.type == SDL_KEYDOWN) {
                if(event.key.repeat == 0) { //Stops sdl from calling keydown on held keys
                    input.keyDownEvent(event);
                }
            } else if(event.type == SDL_KEYUP) {
                input.keyUpEvent(event);
            } else if(event.type == SDL_QUIT) { //SDL_Quit
                return;
            }
        }

        handleInput();

        //Gets frame time stored into ELAPSED_TIME_MS
        const int CURRENT_TIME_MS = SDL_GetTicks();
        int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
        this->update(std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME)); //Give update loop either ELAPSED_TIME_MS or MAX_FRAME TIME, depending on which is smaller
        LAST_UPDATE_TIME = CURRENT_TIME_MS;

        this->draw(graphics);
    }
}

void Game::draw(Graphics& graphics) {
    graphics.clear();

    this->_player.draw(graphics);

    graphics.flip();
}

void Game::update(float elapsedTime) {
    this->_player.update(elapsedTime);
}

void Game::handleInput(){
    //WASD
    if (input.isKeyHeld(SDL_SCANCODE_LEFT)){
        this->_player.moveLeft();
    }
    if (input.isKeyHeld(SDL_SCANCODE_RIGHT)){
        this->_player.moveRight();
    }
    if (input.isKeyHeld(SDL_SCANCODE_UP)){
        this->_player.moveUp();
    }
    if (input.isKeyHeld(SDL_SCANCODE_DOWN)){
        this->_player.moveDown();
    }

    //Handling double key
    if(!input.isKeyHeld(SDL_SCANCODE_LEFT) && !input.isKeyHeld(SDL_SCANCODE_RIGHT)){
        this->_player.stopMovingX();
    }
    if(!input.isKeyHeld(SDL_SCANCODE_UP) && !input.isKeyHeld(SDL_SCANCODE_DOWN)){
        this->_player.stopMovingY();
    }
}
