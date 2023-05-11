#pragma once
#include <SDL.h>

class GameScreen
{
protected:
	SDL_Renderer* m_renderer;
	SDL_Renderer* h_renderer;
	

public:
	GameScreen(SDL_Renderer* renderer);
	~GameScreen();
	virtual void Render();
	virtual void Update(float deltaTime, SDL_Event e);


};

