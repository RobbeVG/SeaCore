#include "SeaCore_pch.h"
#include "Texture2D.h"
#include <SDL.h>

#include "Renderer.h"

sea_core::Texture2D::~Texture2D()
{
	SDL_DestroyTexture(m_pTexture);
}

int sea_core::Texture2D::GetWidth() const
{
	return m_Width;
}

int sea_core::Texture2D::GetHeight() const
{
	return m_Height;
}

SDL_Texture* sea_core::Texture2D::GetSDLTexture() const
{
	return m_pTexture;
}

sea_core::Texture2D::Texture2D(SDL_Texture* texture)
{
	m_pTexture = texture;
	SDL_QueryTexture(m_pTexture, nullptr, nullptr, &m_Width, &m_Height);
}

sea_core::Texture2D::Texture2D(SDL_Texture* texture, const SDL_Rect& src)
{
	SDL_Renderer* pRenderer = Renderer::GetInstance().GetSDLRenderer();

	SDL_Texture* pCurrentRenderTarget = SDL_GetRenderTarget(pRenderer);
	m_pTexture = SDL_CreateTexture(pRenderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, src.w, src.h);
	SDL_SetRenderTarget(pRenderer, m_pTexture);
	SDL_RenderCopy(pRenderer, texture, &src, NULL);
	SDL_SetRenderTarget(pRenderer, pCurrentRenderTarget);
	SDL_QueryTexture(m_pTexture, nullptr, nullptr, &m_Width, &m_Height);
}
