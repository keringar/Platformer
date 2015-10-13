#include "Input.h"

//Called at begining of each frame to reset keys that are no longer relevant
void Input::beginNewFrame() {
    this->_pressedKeys.clear();
    this->_releasedKeys.clear();
}

//checks for key up event, adds to releasedkeys and heldkeys
void Input::keyUpEvent(const SDL_Event& event) {
    this->_releasedKeys[event.key.keysym.scancode] = true;
    this->_heldKeys[event.key.keysym.scancode] = false;
}

//handles keydown events, adds to pressedkeys and held keys
void Input::keyDownEvent(const SDL_Event& event) {
    this->_pressedKeys[event.key.keysym.scancode] = true;
    this->_heldKeys[event.key.keysym.scancode] = true;
}

//was key presed in current frame
bool Input::wasKeyPressed(SDL_Scancode key) {
    return this->_pressedKeys[key];
}

//Was a key released in current frame
bool Input::wasKeyReleased(SDL_Scancode key) {
    return this->_releasedKeys[key];
}

//Check if a key is held at this moment
bool Input::isKeyHeld(SDL_Scancode key) {
    return this->_heldKeys[key];
}
