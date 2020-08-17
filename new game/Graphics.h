/**
  ******************************************************************************
  * @file     Graphics.h
  * @version 
  * @brief    這個檔案負責最底層的操作，需要很奇怪的各種動作這層要全部完成
  *			  只會存在一個，接口只需要讀圖loadImage() & 繪圖void render()
  ******************************************************************************
  */

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
	 * 載入圖片至管理庫，要預載圖片也可以用
	 */
	static SDL_Texture* loadImage(const std::string &filePath);
	static void freeOneImage(const std::string& filePath);
	static void freeAllImage();

	//TODO void setBlendMode(SDL_BlendMode blending);
	/* void render
	 * Draws a texture to window
	 */
	static void render(SDL_Texture* texture, int x, int y, SDL_Rect* block, SDL_RendererFlip rotate);//TODO : Set alpha modulation 

	static SDL_Window* getWindow();
	static SDL_Renderer* getRenderer();

private:
	static SDL_Window* window;
	static SDL_Renderer* renderer;
	// Initialization function
	static SDL_Window* initWindow_();
	static SDL_Renderer* initRenderer_();


	// 圖片管理庫
	static std::map<std::string, SDL_Surface*> surface_list_;
	static std::map<std::string, SDL_Texture*> texture_list_;
};

#endif // GRAPHICS_H
