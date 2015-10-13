#ifndef GRAPHICS_H
#define GRAPHICS_H

/*  Graphics class
 *  Covers all renderer methods or
 *  related things such as a window
 */

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <map>
#include <string>

struct SDL_Window;
struct SDL_Renderer;

class Graphics {
public:
    Graphics();
    ~Graphics();

    /**SDL_Surface* loadImage
     * Loads an image into the _spriteSheets map if it doesn't already exist
     * returns the image from the map whether or not it was loaded
     */
    SDL_Surface* loadImage(const std::string &filePath);

    /**void BlitSurface
     * Draws a texture to a certain part of the screen
     */
    void blitSurface(SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);

    /** void flip
     *  Renders everything to the screen
     */
    void flip();

    /** void clear
     *  Clears the screen
     */
    void clear();

    /** SDL_Renderer* getRenderer
     *  returns the renderer
     */

    SDL_Renderer* getRenderer() const;
private:
    SDL_Window* _window;
    SDL_Renderer* _renderer;

    std::map<std::string, SDL_Surface*> _spriteSheets;
};

#endif // GRAPHICS_H
