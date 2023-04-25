#include "Character.h"
#include "texture2D.h"
#include "constants.h"
#include <string>
using namespace std;




void Character::MoveLeft(float deltaTime)
{
	m_facing_direction = FACING_LEFT;
	m_position.x -= deltaTime * MOVESPEED;
}

void Character::MoveRight(float deltaTime)
{
	m_facing_direction = FACING_RIGHT;
	m_position.x += deltaTime * MOVESPEED;
}

Character::Character(SDL_Renderer* renderer, string imagePath, Vector2D start_position, levelmap* level)
{
	m_current_level_map = level;
	m_moving_left = false;
	m_moving_right = false;
	m_facing_direction = FACING_RIGHT;

	m_renderer = renderer;
	m_position = start_position;
	m_texture = new Texture2D(m_renderer);
	if (!m_texture->LoadDFromFile(imagePath))
	{
		

	}
	

}

Character::~Character()
{
	m_renderer = nullptr;
}

void Character::jump()
{
	m_jump_force = INITAL_JUMP_FORCE;
	m_jumping = true;
	m_can_jump = false;
	
}
void Character::AddGravity(float deltaTime)
{
	if (m_position.y + 64 <= SCREEN_HEIGHT)
	{
		m_position.y += Gravity * deltaTime;
	}
	else
	{
		m_can_jump = true;
	}
}

void Character::Render()
{
	m_texture->Render(m_position, SDL_FLIP_NONE);
	if(m_facing_direction == FACING_RIGHT)
	{
		m_texture->Render(m_position, SDL_FLIP_NONE);
	}
	else 
	{
		m_texture->Render(m_position, SDL_FLIP_HORIZONTAL);
	}
}

void Character::Update(float deltaTime, SDL_Event e)
{

	int centralX_position = (int)(m_position.x + (m_texture->GetWidth() * 0.5)) / TILE_WIDTH;
	int foot_position = (int)(m_position.y + m_texture->GetHeight()) / TILE_HEIGHT;
	if (m_current_level_map->GetTileArt(foot_position, centralX_position) == 0) 
	{
		AddGravity(deltaTime);

	}
	else
	{
		//colided with ground, can jump again
		m_can_jump = true;
	}
	if (m_jumping)
	{
		m_position.y -= m_jump_force * deltaTime;

		m_jump_force -= JUMP_FORCE_DECRMENT * deltaTime;

		if (m_jump_force <= 0)
			m_jumping = false;

	}

	if (m_moving_right)
	{
		MoveRight(deltaTime);
	}
	else if (m_moving_left)
	{
		MoveLeft(deltaTime);
	}
}

void Character::SetPosition(Vector2D new_position)
{
	m_position = new_position; 
}

Vector2D Character::GetPosition()
{
	//return Vector2D();
	return m_position;
}

float Character::GetCollisionradius()
{
	m_collision_radius = 15.0f;
	return m_collision_radius;
}

