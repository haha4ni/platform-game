#ifndef GRAPHICS_H
#define GRAPHICS_H

/* Graphics class
 * Holds all information dealing with graphics for the game
 */

//C include
#include <iostream>
#include <string>
#include <map>

//SDL include
#include <SDL.h>
#include <SDL_image.h>

class Graphics {
public:
	Graphics();
	~Graphics();

	bool init();
	/* SDL_Surface* loadImage
	 * Loads an image into the _spriteSheets map if it doesn't already exist.
	 * As a result, each image will only ever be loaded once
	 * Returns the image from the map regardless of whether or not it was just loaded
	 */
	SDL_Surface* Graphics::loadImage(const std::string &filePath);

	//TODO void setBlendMode(SDL_BlendMode blending);
	/* void render
	 * Draws a texture to window
	 */
	void render(SDL_Texture* texture, int x, int y, SDL_Rect* block, SDL_RendererFlip rotate);//TODO : Set alpha modulation 

	SDL_Window* getWindow();
	SDL_Renderer* getRenderer();
	std::map<std::string, SDL_Surface*> spriteSheets_;
private:
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;

	// Initialization function
	SDL_Window* initWindow_();
	SDL_Renderer* initRenderer_();
};

#endif // GRAPHICS_H
