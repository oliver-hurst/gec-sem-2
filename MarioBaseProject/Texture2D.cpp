#include "Texture2D.h"
#include <SDL_image.h>
#include <iostream>
#define _Texture2D_cpp

using namespace std;

Texture2D::Texture2D(SDL_Renderer* renderer)
{
	m_renderer = renderer;
}

Texture2D::~Texture2D()
{
	//free up memory
	Free();

	m_renderer = nullptr;


}

bool Texture2D::LoadDFromFile(std::string path)
{
	Free();
	m_texture = nullptr;
	// load image
	SDL_Surface* P_surface = IMG_Load(path.c_str());
	if (P_surface != nullptr)
	{
		//colour key the image to be transparent 
		SDL_SetColorKey(P_surface, SDL_TRUE, SDL_MapRGB(P_surface->format, 0, 0XFF, 0XFF));
		IMG_Load;
	}

	// create texture from pixals
	m_texture = SDL_CreateTextureFromSurface(m_renderer, P_surface);
	if (m_texture == nullptr)
	{
		
	}
	else 
	{
		m_width = P_surface->w;
		m_height = P_surface->h;
		
	}
	// remove the loaded surface now we have a texture 
	SDL_FreeSurface(P_surface);
	//return texture
	return m_texture != nullptr;
}

void Texture2D::Free()
{
	if (m_texture == nullptr)
	{
		m_width = 0;
		m_height = 0;
	}

}

void Texture2D::Render(Vector2D new_position, SDL_RendererFlip flip, double angle)
{
	//set where to render texture
	SDL_Rect renderLocation = { new_position.x,new_position.y, m_width, m_height };
	//render to screen
	SDL_RenderCopyEx(m_renderer, m_texture, NULL, &renderLocation, 0, NULL, flip);
}

