#include "characterMario.h"
#include "Character.h"
#include <string>
using namespace std;

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


