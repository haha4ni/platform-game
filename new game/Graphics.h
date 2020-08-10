#ifndef GRAPHICS_H
#define GRAPHICS_H

//C include
#include <iostream>
#include <string>
#include <map>

//SDL include
#include <SDL.h>
#include <SDL_image.h>


/* 
 * @brief Holds all information dealing with graphics for the game
 *		  控制程式視窗&圖形畫面底層
 */
class Graphics {
public:
	//Graphics();
	//~Graphics();

	static bool init();
	/* 
	 * 載入圖片至管理庫
	 */
	static SDL_Surface* Graphics::loadImage(const std::string &filePath);

	//TODO void setBlendMode(SDL_BlendMode blending);
	/* void render
	 * Draws a texture to window
	 */
	static void render(SDL_Texture* texture, int x, int y, SDL_Rect* block, SDL_RendererFlip rotate);//TODO : Set alpha modulation 

	static SDL_Window* getWindow();
	static SDL_Renderer* getRenderer();
	static std::map<std::string, SDL_Surface*> spriteSheets_;
private:
	static SDL_Window* window;
	static SDL_Renderer* renderer;

	// Initialization function
	static SDL_Window* initWindow_();
	static SDL_Renderer* initRenderer_();
};

#endif // GRAPHICS_H
