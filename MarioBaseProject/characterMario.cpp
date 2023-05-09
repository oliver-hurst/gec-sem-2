#include "characterMario.h"
#include "Character.h"
#include <string>
using namespace std;
#include <SDL_mixer.h>

Mix_Music* M_music = nullptr;

characterMario::characterMario(SDL_Renderer* renderer, string imagePath,Vector2D start_Position, levelmap* map) : Character(renderer, imagePath, start_Position ,map)
{

}

void characterMario::Update(float deltaTime, SDL_Event e)
{

	switch (e.type)
	{
	case SDL_KEYDOWN:
		switch (e.key.keysym.sym)
		{
		case SDLK_LEFT:
			m_facing_direction = FACING_LEFT;
			m_moving_left = true;
			m_moving_right = false;
			break;
		case SDLK_RIGHT:
			m_facing_direction = FACING_RIGHT;
			m_moving_right = true;
			m_moving_left = false;
			break;
		case SDLK_UP:
			if (m_can_jump)
			{
				jump();
				//add sound 
				loadmusic("music/jump.mp3");
				if (Mix_PlayingMusic() == 0)
				{
					Mix_PlayMusic(M_music, +1);
				}
			}
			break;
		}
		break;
	case SDL_KEYUP:
		switch (e.key.keysym.sym)
		{
		case SDLK_LEFT:
			m_moving_left = false;
			break;
		case SDLK_RIGHT:
			m_moving_right = false;
			break;
		}
		break;
	}
	Character::Update(deltaTime, e);
}

void characterMario::loadmusic(string path)
{

	M_music = Mix_LoadMUS(path.c_str());
	if (M_music == nullptr)
	{
		//cout << " couldnt load file" << Mix_GetError() << endl;
	}
}


