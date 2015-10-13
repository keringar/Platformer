#ifndef GAME_H
#define GAME_H

#include "Graphics.h"
#include "Player.h"
#include "Input.h"

class Game {
public:
    Game();
    ~Game();
private:
    void gameLoop();
    void draw(Graphics &graphics);
    void update(float elapsedTime);
    void handleInput();

    Player _player;
    Input input;
};

#endif // GAME_H
