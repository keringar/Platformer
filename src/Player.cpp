#include "Player.h"
#include "Graphics.h"

namespace player_constants {
    const float WALK_SPEED = 0.2f;
}

Player::Player() {
    //ctor
}

Player::Player(Graphics &graphics, float x, float y) :
    AnimatedSprite(graphics, "assets/sprites/MyChar.png", 0, 0, 16, 16, x, y, 100) {
    graphics.loadImage("assets/sprites/MyChar.png");

    this->setupAnimations();
    this->playAnimation("RunRight");
}

void Player::setupAnimations() {
    this->addAnimation(3, 0, 0, "RunLeft", 16, 16, Vector2(0,0));
    this->addAnimation(3, 0, 16, "RunRight", 16, 16, Vector2(0,0));
    this->addAnimation(1, 0, 0, "IdleLeft", 16, 16, Vector2(0,0));
    this->addAnimation(1, 0, 16, "IdleRight", 16, 16, Vector2(0,0));
}

void Player::update(float elapsedTime) {
    this->_x += this->_dx * elapsedTime;
    this->_y += this->_dy * elapsedTime;

    AnimatedSprite::update(elapsedTime);
}

void Player::draw(Graphics &graphics) {
    AnimatedSprite::draw(graphics, this->_x, this->_y);
}

void Player::animationDone(std::string currentAnimation) {}

void Player::moveLeft() {
    this->_dx = -player_constants::WALK_SPEED;
    this->playAnimation("RunLeft");
    this->_facing = LEFT;
}

void Player::moveRight() {
    this->_dx = player_constants::WALK_SPEED;
    this->playAnimation("RunRight");
    this->_facing = RIGHT;
}

void Player::moveUp(){
    this->_dy = -player_constants::WALK_SPEED;
    //this->playAnimation("RunUp");
    this->_facing = UP;
}

void Player::moveDown(){
    this->_dy = player_constants::WALK_SPEED;
    //this->playAnimation("RunDown");
    this->_facing = DOWN;
}

void Player::stopMovingX() {
    this->_dx = 0;

    this->playAnimation(this->_facing == RIGHT ? "IdleRight" : "IdleLeft");
}

void Player::stopMovingY(){
    this->_dy = 0;
}
