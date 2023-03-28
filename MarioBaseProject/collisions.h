#pragma once
#include "commons.h"


class Character;

class collisions
{
private:
	collisions();
	static collisions* m_instance;

public:
	~collisions();

	static collisions* Instance();

	bool Circle(Character* Character1, Character* Character2);
	bool box(Rect2D rect1, Rect2D rect2);
};

