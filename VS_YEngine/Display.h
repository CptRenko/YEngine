#ifndef Y_DISPLAY_H
#define Y_DISPLAY_H

#include <SDL.h>

//Resolution of SDL window
#define WIN_WIDTH 1280
#define WIN_HEIGHT 720

#define HALF_SCREEN_X (WIN_WIDTH / 2)
#define HALF_SCREEN_Y (WIN_HEIGHT / 2)

class Display
{
private:
	SDL_Window* window;
	SDL_Renderer* render;
	uint32_t* colorBuffer; //Need 32 bit exactly for colorbuffer
	SDL_Texture* colorTexture = nullptr;
public:
	void Init();
	void DrawPixel(int _x, int _y, uint32_t color);
	void DrawRect(int _x, int _y, int width, int height, uint32_t color);
	void RenderColorBuffer(); //I need transform the color buffer to texture and after render that.
	void ResetColorBuffer(uint32_t color);
	void Render();
	void Shutdown();
};

#endif