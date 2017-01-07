//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Gelo123321 - 2016. +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef GAME_H
#define GAME_H

#include "GameObjectFactory.h"
#include "TextureManager.h"
#include "InputHandler.h"
#include "StateManager.h"

#include "MainMenuState.h"
#include "PlayState.h"

#include "Player.h"

#include <SDL.h>

#include <string>
#include <vector>
#include <memory>
#include <iostream>

using namespace std;
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class Game
{
public:
	static Game* Instance()
	{
		if (s_pInstance == 0) {
			s_pInstance = new Game();
			return s_pInstance;
		}

		return s_pInstance;
	}

	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void handleEvents();
	void update();
	void render();

	void clean();

	bool running() { return m_bRunning; }
	void quit() { m_bRunning = false; }

	shared_ptr<SDL_Renderer> getRenderer() const { return m_pRenderer; }
	SDL_Window* getWindow() const { return m_pWindow; }

	int getGameWidth() const { return m_gameWidth; }
	int getGameHeight() const { return m_gameHeight; }

	StateManager* getStateManager() { return m_pStateManager; }

private:
	static Game* s_pInstance;

	StateManager* m_pStateManager;

	std::vector<GameObject*> m_gameObjects;

	int m_currentFrame;

	SDL_Window* m_pWindow;
	shared_ptr<SDL_Renderer> m_pRenderer;

	int m_gameWidth;
	int m_gameHeight;

	bool m_bRunning;
	bool m_fullscreen;

	SDL_Cursor* m_pCursor;
	SDL_Surface* m_pSurfaceCursor;

	SDL_Surface* m_pSurfaceIcon;

	Game() {};

	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
};

typedef Game TheGame;

#endif
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++