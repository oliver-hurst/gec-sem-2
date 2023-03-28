//Be grateful for humble beginnings, because the next level will always require so much more of you
#include <SDL.h>
#include<SDL_image.h>
#include<SDL_mixer.h>
#include"constants.h"
#include<iostream>
#include "Texture2D.h"
#include "commons.h"
#include "GameScreenManager.h"


using namespace std;

SDL_Window* g_window = nullptr;
SDL_Renderer* g_renderer = nullptr;
GameScreenManager* game_screen_manager;
Uint32 g_old_time;



//function prototypes
bool InitSDL();
void CLoseSDL();
bool Update();
void render();



int main(int argc, char* args[])
{
	if (InitSDL())
	{
		game_screen_manager = new GameScreenManager(g_renderer, SCREEN_LEVEL1);
		//set time
		g_old_time = SDL_GetTicks();

		

		bool quit = false;
		//game loop
		while (!quit)
		{
			render();
			quit = Update();
		}		
	}
	CLoseSDL;
	return 0;

}
bool Update()
{
	Uint32 new_time = SDL_GetTicks();
	//event handler
	SDL_Event e;
	SDL_PollEvent(&e);
	switch (e.type) 
	{
		//click x to quit
	case SDL_QUIT:
			return true;
			break;

	}
	game_screen_manager->Update((float)(new_time - g_old_time) / 1000.0f, e);
	g_old_time = new_time;
	return false;

}
bool InitSDL() 
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) 
	{
		cout << "SDL did not initalise. error" << SDL_GetError();
		return false();
	}
	else
	{
		//setup passed, create window
		g_window = SDL_CreateWindow("games engine creation",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH,
			SCREEN_HEIGHT,
			SDL_WINDOW_SHOWN);
		g_renderer = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
		if (g_renderer != nullptr)
		{
			//init png loading
			int imageFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imageFlags) & imageFlags))
			{
				cout <<" sdl image didnt initalise error" << IMG_GetError();
				return false;
			}
		}
		else 
		{
			cout << " renderer didnt initalisew error" << SDL_GetError();
			return false;
		}
			//did window get created?
		if (g_window == nullptr) 
		{
			//window failed
			cout << " window failed, error" << SDL_GetError();
			return false();
		}
	}
}

void render() 
{
	// cler the screen
	SDL_SetRenderDrawColor(g_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(g_renderer);
	game_screen_manager->Render();
		//update screen
	SDL_RenderPresent(g_renderer);
	
}

void CLoseSDL() 
{   
	// //releace the renderer
	SDL_DestroyRenderer(g_renderer);
	g_renderer = nullptr;
	//release window
	SDL_DestroyWindow(g_window);
	g_window = nullptr;
	//destroy game manager
	delete game_screen_manager;
	game_screen_manager = nullptr;
	//quit sdl subsystems
	IMG_Quit();
	SDL_Quit();

}