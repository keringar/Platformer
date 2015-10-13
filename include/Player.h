#ifndef PLAYER_H
#define PLAYER_H

#include "AnimatedSprite.h"
#include "globals.h"

class Player : public AnimatedSprite {
public:
    Player();
    Player(Graphics &graphics, float x, float y);
    void draw(Graphics &graphics);
    void update(float elapsedTime);

    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void stopMovingX();
    void stopMovingY();

    virtual void animationDone(std::string currentAnimation);
    virtual void setupAnimations();
private:
    float _dx, _dy;

    Direction _facing;
};

#endif // PLAYER_H
