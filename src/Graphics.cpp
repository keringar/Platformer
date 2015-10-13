#include "Graphics.h"
#include "globals.h"

/*  Graphics class
 *  Covers all renderer methods or
 *  related things such as a window
 */

Graphics::Graphics() {
    SDL_CreateWindowAndRenderer(globals::SCREEN_WIDTH, globals::SCREEN_HEIGHT, 0, &this->_window, &this->_renderer);
    SDL_SetWindowTitle(this->_window, "Platformer");
}

Graphics::~Graphics() {
    SDL_DestroyWindow(_window);
}

SDL_Surface* Graphics::loadImage(const std::string& filePath) {
    if(this->_spriteSheets.count(filePath) == 0) { //If image isn't loaded yet
        this->_spriteSheets[filePath] = IMG_Load(filePath.c_str());
    }
    return this->_spriteSheets[filePath]; //alwas returns a SDL_Surface
}

void Graphics::blitSurface(SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle) {
    SDL_RenderCopy(this->_renderer, texture, sourceRectangle, destinationRectangle);
}

void Graphics::flip() {
    SDL_RenderPresent(this->_renderer);
}

void Graphics::clear() {
    SDL_RenderClear(this->_renderer);
}

SDL_Renderer* Graphics::getRenderer() const {
    return this->_renderer;
}
