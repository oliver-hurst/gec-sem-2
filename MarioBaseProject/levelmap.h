#pragma once
#ifndef _LEVELMAP_H
#define _LEVELMAP_H
#include "constants.h"

class levelmap
{
public:
	levelmap(int map[MAP_HEIGHT][MAP_WIDTH]);
	~levelmap();

	int GetTileArt(unsigned int h, unsigned int w);

private:
	int** m_map;

};
#endif


