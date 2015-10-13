#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H

#include <map>
#include <string>
#include <vector>

#include "Sprite.h"
#include "globals.h"

class Graphics;

//What does this need
class AnimatedSprite : public Sprite {
public:
    AnimatedSprite();
    AnimatedSprite(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY, int width, int height,
            float posX, float posY, float timeToUpdate);

    //Plays animation if not playing
    void playAnimation(std::string animation, bool once = false);

    //Update animaed sprite (timer)
    void update(int elapsedTime);

    //Draw sprite to screen
    void draw(Graphics &graphics, int x, int y);
protected:
    double _timeToUpdate;
    bool _currentAnimationOnce;
    std::string _currentAnimation;

    //Adds an animation to the map of animations for the sprite
    void addAnimation(int frames, int x, int y, std::string name, int width, int height, Vector2 offset);

    //Removes all animations attached to sprite
    void resetAnimations();

    //stops current animation
    void stopAnimation();

    //Changes visibility of animated sprite
    void setVisible(bool visible);

    //Whathappens when an animation finishes
    virtual void animationDone(std::string currentAnimation) = 0;

    //Required function that sets up all functions for a sprite
    virtual void setupAnimations() = 0;

private:
    std::map<std::string, std::vector<SDL_Rect> > _animations;
    std::map<std::string, Vector2> _offsets;

    unsigned int _frameIndex;
    double _timeElapsed;
    bool _visible;

};

#endif // ANIMATEDSPRITE_H
