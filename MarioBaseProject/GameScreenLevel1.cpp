#include "GameScreenLevel1.h"
#include<iostream>
#include "Texture2D.h"
#include "collisions.h"

bool GameScreenLevel1::SetUpLevel1()
{
	//set up player
	steven = new characterMario(m_renderer, "images/Mario.png", Vector2D(64, 330));
	//interduce luigi
	matt = new characterLuigi(m_renderer, "images/Luigi.png", Vector2D(64, 330));
	/*load texture*/
	m_backround_texture = new Texture2D(m_renderer);
	if (!m_backround_texture->LoadDFromFile("images/test.bmp"))
	{
		std::cout << "failed to load backround texture" << std::endl;
		return false;

	}
	m_level_map = nullptr;
	
}


GameScreenLevel1::GameScreenLevel1(SDL_Renderer* renderer) : GameScreen(renderer)
{
	m_renderer = renderer;
  SetUpLevel1();

}

GameScreenLevel1::~GameScreenLevel1()
{
	m_backround_texture = nullptr;
	delete matt;
	matt = nullptr;
}

void GameScreenLevel1::Render()
{

	//draw backround 
	m_backround_texture->Render(Vector2D(), SDL_FLIP_NONE);
	matt->Render();
	steven->Render();
	

}

void GameScreenLevel1::Update(float deltaTime, SDL_Event e)
{
	//update character
	matt->Update(deltaTime, e);
	steven->Update(deltaTime, e);
	if (collisions::Instance()->Circle(matt, steven))
	{
		cout << "hit" << endl;
	}
}

void GameScreenLevel1::SetLevelMap()
{
	int map[MAP_HEIGHT][MAP_WIDTH] = { { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
					  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
					  { 1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1 },
					  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
					  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
					  { 0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0 },
					  { 1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1 },
					  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
					  { 0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0 },
					  { 1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1 },
					  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
					  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
					  { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 } };
	if (m_level_map != nullptr) 
	{
		delete m_level_map;
    }

	m_level_map = new levelmap(map);

}

