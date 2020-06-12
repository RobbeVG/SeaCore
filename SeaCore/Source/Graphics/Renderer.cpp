#include "SeaCore_pch.h"
#include "Renderer.h"
#include <SDL.h>


#include "Scene/SceneManager.h"
#include "Scene/Scene.h"

#include "Texture2D.h"

void sea_core::Renderer::Init(SDL_Window * window)
{
	m_Renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (m_Renderer == nullptr) 
	{
		throw std::runtime_error(std::string("SDL_CreateRenderer Error: ") + SDL_GetError());
	}
}

void sea_core::Renderer::Clear() const
{
	SDL_RenderClear(m_Renderer);
}

void sea_core::Renderer::Present() const
{
	SDL_RenderPresent(m_Renderer);
}

void sea_core::Renderer::Destroy()
{
	if (m_Renderer != nullptr)
	{
		SDL_DestroyRenderer(m_Renderer);
		m_Renderer = nullptr;
	}
}

void sea_core::Renderer::RenderTexture(const Texture2D& texture, const float x, const float y) const
{
	SDL_Rect dst;
	dst.x = static_cast<int>(x);
	dst.y = static_cast<int>(y);
	dst.w = texture.GetWidth();
	dst.h = texture.GetHeight();

	RenderTexture(texture, nullptr, dst);
}

void sea_core::Renderer::RenderTexture(const Texture2D& texture, const SDL_Rect& dst) const
{
	RenderTexture(texture, nullptr, dst);
}

void sea_core::Renderer::RenderTexture(const Texture2D& texture, const SDL_Rect& src, const SDL_Rect& dst) const
{
	RenderTexture(texture, &src, dst);
}

void sea_core::Renderer::RenderTexture(const Texture2D& texture, const SDL_Rect& src, const float x, const float y) const
{
	SDL_Rect dst;
	dst.x = static_cast<int>(x);
	dst.y = static_cast<int>(y);
	dst.w = src.w;
	dst.h = src.h;
	RenderTexture(texture, &src, dst);
}

void sea_core::Renderer::RenderTexture(const Texture2D& texture, const SDL_Rect* src, SDL_Rect dst) const
{
	dst.x -= dst.w / 2;
	dst.y -= dst.h / 2;
	
	SDL_RenderCopy(GetSDLRenderer(), texture.GetSDLTexture(), src, &dst);
}
