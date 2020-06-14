#include "SeaCore_pch.h"
#include "TextRenderer.h"

#include <SDL.h>
#include <SDL_ttf.h>

#include "../Transform.h"

#include "../../Graphics/Texture2D.h"
#include "../../Graphics/Font.h"

sea_core::TextRenderer::TextRenderer(const std::string& text, const Font* font)
	: TextureRenderer(nullptr)
	, m_Text(text)
	, m_pFont(font)
{
	SetTexture(CreateTextTexture());
}

sea_core::TextRenderer::~TextRenderer()
{
	delete GetTexture(); //Text components are changing all the time no need for adding it to the TextureManager
}

void sea_core::TextRenderer::SetText(const std::string& text)
{
	if (m_Text == text)
		return;
	
	m_Text = text;
	Texture2D* pNewTexture = CreateTextTexture();
	
	delete GetTexture();
	SetTexture(pNewTexture);
}

sea_core::Texture2D* sea_core::TextRenderer::CreateTextTexture() const
{
	const SDL_Color color = { 255,255,255 }; // only white text is supported now
	const auto surf = TTF_RenderText_Blended(m_pFont->GetFont(), m_Text.c_str(), color);
	if (surf == nullptr)
	{
		throw std::runtime_error(std::string("Render text failed: ") + SDL_GetError());
	}
	const auto texture = SDL_CreateTextureFromSurface(Renderer::GetInstance().GetSDLRenderer(), surf);
	if (texture == nullptr)
	{
		throw std::runtime_error(std::string("Create text texture from surface failed: ") + SDL_GetError());
	}
	SDL_FreeSurface(surf);

	return new Texture2D(texture);
}
