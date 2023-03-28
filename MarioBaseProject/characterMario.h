#pragma once
#include "levelmap.h"
#include "Character.h"
class characterMario : public Character
{
public:
	characterMario(SDL_Renderer* renderer, string imagePath, Vector2D start_Position, levelmap* map);
	virtual void Update(float deltaTime, SDL_Event e);
};


