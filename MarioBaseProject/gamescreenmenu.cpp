#include "gamescreenmenu.h"
#include<iostream>
#include "Texture2D.h"
#include "GameScreen.h"

bool gamescreenmenu::setupmenu()
{
	h_backround_texture = new Texture2D(h_renderer);
	if (!h_backround_texture->LoadDFromFile("images/test.bmp"))
	{
		std::cout << "failed to load backround texture" << std::endl;
		return false;

	}

	return false;
}

gamescreenmenu::gamescreenmenu(SDL_Renderer* renderer) : GameScreen(renderer)
{
	h_renderer = renderer;
	setupmenu();
}

gamescreenmenu::~gamescreenmenu()
{
	h_backround_texture = nullptr;
}

void gamescreenmenu::Render()
{
	h_backround_texture->Render(Vector2D(), SDL_FLIP_NONE);
}

void gamescreenmenu::Update(float deltaTime, SDL_Event e)
{
}
