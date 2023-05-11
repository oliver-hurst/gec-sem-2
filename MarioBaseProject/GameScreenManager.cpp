#include "GameScreenManager.h"
#include "GameScreen.h"
#include "GameScreenLevel1.h"
#include "gamescreenmenu.h"
#include <string>
using namespace std;

GameScreenManager::GameScreenManager(SDL_Renderer* renderer, SCREENS startscreen)
{
	startscren = true;
	m_renderer = renderer;
	m_current_screen = nullptr;
	ChangeScreen(startscreen);
	
}

GameScreenManager::~GameScreenManager()
{
}

void GameScreenManager::Render()
{
	m_current_screen->Render();
}

void GameScreenManager::Update(float deltaTime, SDL_Event e)
{
	m_current_screen->Update(deltaTime, e);

	switch (e.type)
	{
	case SDL_KEYDOWN:
		switch (e.key.keysym.sym)
		{
		case SDLK_SPACE:
			if (startscren)
			{
				ChangeScreen(SCREEN_LEVEL1); 
			}
			break;
		}
	default:;
	}
	//get input to change screen

}

void GameScreenManager::ChangeScreen(SCREENS new_screen)
{
	if (m_current_screen != nullptr)
	{
		delete m_current_screen;
	}
	

	switch (new_screen)
	{
	case SCREEN_LEVEL1:
		GameScreenLevel1* tempscreen;
		tempscreen = new GameScreenLevel1(m_renderer);
		m_current_screen = (GameScreen*)tempscreen;
		tempscreen = nullptr;

		startscren = false;
		break;
	case SCREEN_MENU:
		gamescreenmenu* tempscreen2;
		tempscreen2 = new gamescreenmenu(m_renderer);
		m_current_screen = (GameScreen*)tempscreen2;
		tempscreen2 = nullptr;

		startscren = true;
		break;
	default:;

	}
}
