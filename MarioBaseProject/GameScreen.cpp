#include "GameScreen.h"
#include <SDL.h>
using namespace std;

//function prototypes
GameScreen::GameScreen(SDL_Renderer* renderer) 
{
	SDL_Renderer* m_renderer;
}

GameScreen::~GameScreen()
{
	m_renderer = nullptr;

}

void GameScreen::Render()
{
}

void GameScreen::Update(float deltaTime, SDL_Event e)
{
}
