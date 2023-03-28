#pragma once
#include "Character.h"
#include "levelmap.h"

class characterLuigi : public Character
{
public:
	characterLuigi(SDL_Renderer* renderer, string imagePath, Vector2D start_Position, levelmap* map);
	virtual void Update(float deltaTime, SDL_Event e);
};

