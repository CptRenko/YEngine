#include "Game.h"
#include <iostream>

void Game::Init()
{
	yDisp.Init();
	isRunning = true;
}

void Game::Run()
{
	while (isRunning)
	{
		ProcessInput();
		yDisp.Render();
		Update();
	}
}

void Game::Update()
{

}

void Game::ProcessInput()
{
	SDL_Event sEvent;
	while (SDL_PollEvent(&sEvent))
	{
		switch (sEvent.type)
		{
			case SDL_QUIT:
				isRunning = false;
				break;

			case SDL_KEYDOWN:
				if (sEvent.key.keysym.sym == SDLK_ESCAPE)
				{
					isRunning = false;
				}
				break;
		}
	}
}

void Game::Shutdown()
{
	yDisp.Shutdown();
	SDL_Quit();
}