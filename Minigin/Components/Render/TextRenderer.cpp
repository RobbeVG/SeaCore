#include "MiniginPCH.h"
#include "TextRenderer.h"
#include "../Transform.h"

#include <SDL.h>
#include <SDL_ttf.h>

//#include <glm/detail/type_vec3.hpp>
#include "../../Graphics/Texture2D.h"
#include "../../Graphics/Font.h"

sea_core::TextRenderer::TextRenderer(const std::string& text, const Font* font)
	: m_Text(text)
	, m_pFont(font)
{
	SetTextTexture();
}

sea_core::TextRenderer::~TextRenderer()
{
	delete m_pTexture;
	delete m_pFont;
}

void sea_core::TextRenderer::DerivedRender(const float) const
{	
	const glm::vec3 location = m_pParent->GetTransform()->GetPosition();
	Renderer::GetInstance().RenderTexture(*m_pTexture, location.x, location.y);	
}

void sea_core::TextRenderer::SetText(const std::string& text)
{
	m_Text = text;
	SetTextTexture();
}

void sea_core::TextRenderer::SetTextTexture()
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
	delete m_pTexture;
	m_pTexture = new Texture2D(texture);
}
