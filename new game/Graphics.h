/**
  ******************************************************************************
  * @file     Graphics.h
  * @version 
  * @brief    �o���ɮ׭t�d�̩��h���ާ@�A�ݭn�ܩ_�Ǫ��U�ذʧ@�o�h�n��������
  *			  �u�|�s�b�@�ӡA���f�u�ݭnŪ��loadImage() & ø��void render()
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
 *		  ����{������&�ϧεe�����h
 */
class Graphics {
public:
	//Graphics();
	//~Graphics();

	static bool init();
	/* 
	 * ���J�Ϥ��ܺ޲z�w�A�n�w���Ϥ��]�i�H��
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


	// �Ϥ��޲z�w
	static std::map<std::string, SDL_Surface*> surface_list_;
	static std::map<std::string, SDL_Texture*> texture_list_;
};

#endif // GRAPHICS_H
