//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Gelo123321 - 2016. +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <iostream>
#include "Game.h"

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char *argv[])
{
	AllocConsole();
	SetConsoleTitle("Debug Console");
	freopen("CON", "w", stdout);

	Uint32 frameStart, frameTime;

	std::cout << "TheConfigManager init attempt...\n";

	TheConfigManager::Instance()->load();
	int width = TheConfigManager::Instance()->get("width");
	int height = TheConfigManager::Instance()->get("height");
	bool fullscreen = TheConfigManager::Instance()->get("fullscreen");

	std::cout << "TheGame init attempt...\n";

	if (TheGame::Instance()->init("The four images one word", 100, 100, width, height, fullscreen))
	{
		while (TheGame::Instance()->running())
		{
			frameStart = SDL_GetTicks();

			TheGame::Instance()->handleEvents();
			TheGame::Instance()->update();
			TheGame::Instance()->render();

			frameTime = SDL_GetTicks() - frameStart;

			if (frameTime < DELAY_TIME)
			{
				SDL_Delay((int)(DELAY_TIME - frameTime));
			}
		}
	}
	else
	{
		std::cout << "TheGame init failure - " << SDL_GetError() << "\n";
		return -1;
	}

	std::cout << "TheGame closing...\n";
	TheGame::Instance()->clean();

	return 0;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++