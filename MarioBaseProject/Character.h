#pragma once
#include <SDL.h>
#include "commons.h"
#include <string>
#include "Texture2D.h"
#include "levelmap.h"
using namespace std;


class Character
{

	
protected:
	void jump();
	FACING m_facing_direction;
	SDL_Renderer* m_renderer;
	Vector2D m_position;
	Texture2D* m_texture;
	bool m_moving_left;
	bool m_moving_right;
	virtual void MoveLeft(float deltaTime);
	virtual void MoveRight(float deltaTime);
	bool m_jumping = false;
	bool m_can_jump = true;
	float m_jump_force = 0;
	float m_collision_radius;

public:
	Character(SDL_Renderer* renderer, string imagepath, Vector2D start_position, levelmap* map);
	~Character();
	virtual void AddGravity(float deltaTime);
	virtual void Render();
	virtual void Update(float deltaTime, SDL_Event e);
	void SetPosition(Vector2D new_position);
	Vector2D GetPosition();
	float GetCollisionradius();
	Rect2D GetCollisionBox() { return Rect2D(m_position.x, m_position.y, m_texture->GetWidth(), m_texture->GetHeight()); }

private:
	levelmap* m_current_level_map;


};