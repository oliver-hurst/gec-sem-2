#include "characterLuigi.h"
#include "Character.h"
#include <string>
using namespace std;
#include <SDL_mixer.h>


Mix_Music* L_music = nullptr;


characterLuigi::characterLuigi(SDL_Renderer* renderer, string imagepath, Vector2D start_position, levelmap* map) : Character(renderer, imagepath, start_position, map)
{

}
void characterLuigi::Update(float deltaTime, SDL_Event e)
{
	switch (e.type)
	{
	case SDL_KEYDOWN:
		switch (e.key.keysym.sym)
		{
		case SDLK_a:
			m_facing_direction = FACING_LEFT;
			m_moving_left = true;
			
			break;
		case SDLK_d:
			m_facing_direction = FACING_RIGHT;
			m_moving_right = true;
			
			break;
		case SDLK_SPACE:
			if (m_can_jump)
			{
				jump();
				//load music 
				loadmusic("music/jump.mp3");
				if (Mix_PlayingMusic() == 0)
				{
					Mix_PlayMusic(L_music, 0);
				}

			}
			break;
		}
		break;
	case SDL_KEYUP:
		switch (e.key.keysym.sym)
		{
		case SDLK_a:
			m_moving_left = false;
			break;
		case SDLK_d:
			m_moving_right = false;
			break;
		}
		break;
	}
	Character::Update(deltaTime, e);
}

void characterLuigi::loadmusic(string path)
{

	L_music = Mix_LoadMUS(path.c_str());
	if (L_music == nullptr)
	{
		//cout << " couldnt load file" << Mix_GetError() << endl;
	}
}
