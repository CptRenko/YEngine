#include "Display.h"
#include <iostream>

void Display::Init()
{
	int err = SDL_Init(SDL_INIT_EVERYTHING);

	if (err < 0)
	{
		std::cerr << "Error al inicializar SDL. Mensaje: " << SDL_GetError() << std::endl;
		return;
	}

	window = SDL_CreateWindow("YEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_BORDERLESS);

	if (!window)
	{
		std::cerr << "Error al crear ventana. Mensaje: " << SDL_GetError() << std::endl;
	}

	render = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

	if (!render)
	{
		std::cerr << "Error al inicializar SDL Renderer. Mensaje: " << SDL_GetError() << std::endl;
	}

	colorBuffer = new uint32_t[WIN_WIDTH * WIN_HEIGHT];

	colorTexture = SDL_CreateTexture(render, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STREAMING, WIN_WIDTH, WIN_HEIGHT);
}

vec2_t Display::Project(vec3_t v)
{

#if USE_PERSPECTIVE & USE_ORTHOGONAL
	#error No se puede usar USE_PERSPECTIVE Y USE_ORTHOGONAL al mismo tiempo;
#endif
	
	vec2_t vecProjected = { 0.0f ,0.0f };
#if USE_PERSPECTIVE
	//@TODO: I still need implement to a matrix projection
	//Perspective works with a frustrum; things more far are showing more little and things more close to the camera are show more big. 
	std::cout << "Uso perspectiva" << std::endl;
	vecProjected.x = v.x / v.z;
	vecProjected.y = v.y / v.z;

#elif USE_ORTHOGONAL
	std::cout << "Uso ortoghonal" << std::endl;
	vecProjected.x = v.x;
	vecProjected.y = v.y;
#endif

	return vecProjected;
}

void Display::DrawPixel(int _x, int _y, uint32_t color)
{
	//Check if the coordinates it's in the screen.
	if (_x >= 0 && _x < WIN_WIDTH && _y >= 0 && _y < WIN_HEIGHT)
	{
		colorBuffer[(WIN_WIDTH * _y) + _x] = color;
	}
}

void Display::DrawRect(int x, int y, int width, int height, uint32_t color)
{
	for (int _x = 0; _x < width; _x++)
	{
		for (int _y = 0; _y < height; _y++)
		{
			DrawPixel((_x + x), (_y + y), color);
		}
	}
}

void Display::RenderColorBuffer()
{
	SDL_UpdateTexture(
		colorTexture,
		NULL,
		colorBuffer,
		sizeof(uint32_t) * WIN_WIDTH //If i understand well... this is basically the  size in bytes for a row of the color buffer including padding
	);

	SDL_RenderCopy(render, colorTexture, NULL, NULL);
}

void Display::ResetColorBuffer(uint32_t color)
{
	for (int _x = 0; _x < WIN_WIDTH; _x++)
	{
		for (int _y = 0; _y < WIN_HEIGHT; _y++)
		{
			colorBuffer[(WIN_WIDTH * _y) + _x] = color;
		}
	}
}

void Display::Render()
{
	//DrawRect(HALF_SCREEN_X - 50, HALF_SCREEN_Y - 50, 50, 50, 0xFFFF0000); // Apply a offset from the half of the screenn

	RenderColorBuffer();
	ResetColorBuffer(0x00000000);
	SDL_RenderPresent(render);
}

void Display::Shutdown()
{
	delete[] colorBuffer;
	SDL_DestroyTexture(colorTexture);
	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(window);
}