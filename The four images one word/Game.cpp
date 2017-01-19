//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Gelo123321 - 2016. +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "Game.h"
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Game* Game::s_pInstance = 0;

bool Game::init(const char * title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;

	// store the game width and height
	m_gameWidth = width;
	m_gameHeight = height;

	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	// attempt to initialise SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		cout << "SDL init success\n";
		// init the window
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (m_pWindow != 0) // window init success
		{
			cout << "window creation success\n";
			m_pRenderer = shared_ptr<SDL_Renderer>(SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC),
				[](SDL_Renderer* render) {SDL_DestroyRenderer(render); });

			if (m_pRenderer != 0) // renderer init success
			{
				cout << "renderer creation success\n";
				SDL_SetRenderDrawColor(m_pRenderer.get(), 0, 0, 0, 255);
			}
			else
			{
				cout << "renderer init fail\n";
				return false; // renderer init fail
			}
		}
		else
		{
			cout << "window init fail\n";
			return false; // window init fail
		}

		m_pSurfaceIcon = IMG_Load("resources//img//icon.png");

		if (!m_pSurfaceIcon)
		{
			cout << "icon load fail\n";
			return false; // icon load fail
		}

		SDL_SetWindowIcon(m_pWindow, m_pSurfaceIcon);

		m_pSurfaceCursor = IMG_Load("resources//img//cursor.png");

		if (!m_pSurfaceCursor)
		{
			cout << "cursor load fail\n";
			return false; // cursor load fail
		}

		m_pCursor = SDL_CreateColorCursor(m_pSurfaceCursor, 0, 0);

		if (!m_pCursor)
		{
			cout << "cursor set fail\n";
			return false; // cursor setfail
		}

		SDL_SetCursor(m_pCursor);
	}
	else
	{
		cout << "SDL init fail\n";
		return false; // SDL init fail
	}

	TheGameObjectFactory::Instance()->registerType("MenuButton", new MenuButtonCreator());
	TheGameObjectFactory::Instance()->registerType("AnimatedGraphic", new AnimatedGraphicCreator());
	TheGameObjectFactory::Instance()->registerType("LetterButton", new LetterButtonCreator());
	TheGameObjectFactory::Instance()->registerType("Word", new WordCreator());
	TheGameObjectFactory::Instance()->registerType("ScrollBar", new ScrollBarCreator());

	TheSoundManager::Instance()->load("resources//SFX//click.wav", "click", SOUND_SFX); // TODO move to better place ?
	TheSoundManager::Instance()->load("resources//music//background.mp3", "background", SOUND_MUSIC);
	int SFX_volume = TheConfigManager::Instance()->get("SFX_volume");
	int music_volume = TheConfigManager::Instance()->get("music_volume");
	TheSoundManager::Instance()->setVolumeSFX(SFX_volume);
	TheSoundManager::Instance()->setVolumeMusic(music_volume);

	std::cout << "TheGame::init success!\n";

	TheSoundManager::Instance()->playMusic("background", 1);
	
	m_pStateManager = new StateManager();
	m_pStateManager->changeState(new MainMenuState());


	m_bRunning = true; // everything inited successfully, start the main loop

	return true;
}


void Game::handleEvents()
{
	TheInputHandler::Instance()->update();
}

void Game::update()
{
	m_pStateManager->update();
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer.get());

	m_pStateManager->render();

	SDL_RenderPresent(m_pRenderer.get());
}

void Game::clean()
{
	cout << "cleaning game\n";

	TheInputHandler::Instance()->clean();

	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer.get());
	SDL_Quit();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++