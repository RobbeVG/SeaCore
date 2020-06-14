#include "SeaCore_pch.h"
#include "TextureManager.h"

#include <SDL_image.h>

#include "Graphics/Renderer.h"

TextureManager::TextureManager()
{
	// load support for png and jpg, this takes a while!
	if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG)
	{
		throw std::runtime_error(std::string("Failed to load support for png's: ") + SDL_GetError());
	}

	if ((IMG_Init(IMG_INIT_JPG) & IMG_INIT_JPG) != IMG_INIT_JPG)
	{
		throw std::runtime_error(std::string("Failed to load support for jpg's: ") + SDL_GetError());
	}
}

sea_core::Texture2D* TextureManager::LoadContent(const std::string& path)
{
	SDL_Texture* texture = IMG_LoadTexture(sea_core::Renderer::GetInstance().GetSDLRenderer(), path.c_str());
	if (texture == nullptr)
	{
		throw std::runtime_error(std::string("Failed to load texture: ") + SDL_GetError());
	}
	return new sea_core::Texture2D(texture);
}
