#include "characterLuigi.h"
#include "Character.h"
#include <string>
using namespace std;

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
