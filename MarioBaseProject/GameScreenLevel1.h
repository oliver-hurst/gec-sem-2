#pragma once
#include "GameScreen.h"
#include "Texture2D.h"
#include "commons.h"
#include <SDL.h>
#include "characterMario.h"
#include "characterLuigi.h"
#include "levelmap.h"

class GameScreenLevel1 : GameScreen
{
private:
	Texture2D* m_backround_texture;
	bool SetUpLevel1();
	Character* steven;
	Character* matt;
	void SetLevelMap();
	levelmap* m_level_map;

public:
	GameScreenLevel1(SDL_Renderer* renderer);
	~GameScreenLevel1();

	void Render() override;
	void Update(float deltaTime, SDL_Event e) override;



};

