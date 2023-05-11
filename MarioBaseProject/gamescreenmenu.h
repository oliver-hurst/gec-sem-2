#pragma once
#include "Texture2D.h"
#include <SDL.h>
#include "GameScreen.h"

class gamescreenmenu : GameScreen
{
private:

	Texture2D* h_backround_texture;
	bool setupmenu();
	
public: 
	gamescreenmenu(SDL_Renderer* renderer);
	~gamescreenmenu();

	void Render() ;
	void Update(float deltaTime, SDL_Event e) ;
// load bacckround

};

