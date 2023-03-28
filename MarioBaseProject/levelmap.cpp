#include "levelmap.h"

levelmap::levelmap(int map[MAP_HEIGHT][MAP_WIDTH])
{
	m_map = new int* [MAP_HEIGHT];
	for (unsigned int i = 0; i < MAP_HEIGHT; i++) 
	{
		m_map[i] = new int[MAP_WIDTH];
	}

	for (unsigned int i = 0; i < MAP_HEIGHT; i++) 
	{
		for (unsigned int j = 0; j < MAP_WIDTH; j++) 
		{
			m_map[i][j] = map[i][j];
		}
	}

}

levelmap::~levelmap()
{

	for (unsigned int i = 0; i < MAP_HEIGHT; i++) 
	{
		delete[]m_map[i];
	}
	delete[]m_map;
}

int levelmap::GetTileArt(unsigned int h, unsigned int w)
{

	if(h < MAP_HEIGHT && w< MAP_WIDTH)
	{
		return m_map[h][w];
	}
	return 0;
}
