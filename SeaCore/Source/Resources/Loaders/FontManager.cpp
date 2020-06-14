#include "SeaCore_pch.h"
#include "FontManager.h"

#include <SDL_ttf.h>

FontManager::FontManager()
	: m_FontSize(12)
{
	// load support for fonts, this takes a while!
	if (TTF_Init() != 0)
		throw std::runtime_error(std::string("Failed to load support for fonts: ") + SDL_GetError());
}

FontManager::~FontManager()
{
	for (const std::pair<size_t, sea_core::Font*> reference : m_References)
	{
		TTF_CloseFont(reference.second->GetFont());
	}
}

sea_core::Font* FontManager::LoadContent(const std::string& path)
{
	sea_core::Font* pFont = new sea_core::Font(path, m_FontSize);
	if (pFont == nullptr)
	{
		throw std::runtime_error(std::string("Failed to load font: ") + SDL_GetError());
	}
	return pFont;
}
