#pragma once


struct Vector2D
{
	float x;
	float y;

	Vector2D()  // Default constructor
	{
		x = 0;
		y = 0;
	}
	Vector2D(float inital_x, float inital_y) // Argument constructor
	{
		x = inital_x;
		y = inital_y;
	}
	Vector2D(const Vector2D& other) // Copy Constructor
	{
		x = other.x;
		y = other.y;
	}	
};

struct Rect2D
{
	float x;
	float y;
	float width;
	float height;

	Rect2D(float x_pos, float y_pos, float width, float height)
	{
		x = x_pos;
		y = y_pos;
		this->width = width;
		this->height = height;
	}
};
enum SCREENS
{
	SCREEN_INTRO,
	SCREEN_MENU,
	SCREEN_LEVEL1,
	SCREEN_LEVEL2,
	SCREEN_GAMEOVER,
	SCREEN_HIGHSCORES
};

enum FACING 
{
	FACING_LEFT,
	FACING_RIGHT
};


