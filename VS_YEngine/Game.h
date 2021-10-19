#ifndef Y_GAME_H
#define Y_GAME_H

#include "Display.h"

class Game
{
private:
	Display yDisp;
	bool isRunning = false;
	int oldTime = 0;
public:
	void Init(); //Init SDL services and set window and render
	void ProcessInput();
	void Run();
	void Update();
	void Shutdown(); //Destroy everything
};

#endif