#pragma once
#include <SDL.h>
#include "Helpers/Singleton.h"

struct SDL_Window;
struct SDL_Renderer;

namespace sea_core
{
	class Scene;
	class Texture2D;
	/**
	 * Simple RAII wrapper for the SDL renderer
	 */
	class Renderer final : public Singleton<Renderer>
	{
	public:
		void Init(SDL_Window* window);

		void Clear() const;
		void Present() const;
		void Destroy();

		void RenderTexture(const Texture2D& texture, float x, float y) const;
		void RenderTexture(const Texture2D& texture, const SDL_Rect& dst) const;
		void RenderTexture(const Texture2D& texture, const SDL_Rect& src, const SDL_Rect& dst) const;
		void RenderTexture(const Texture2D& texture, const SDL_Rect& src, float x, float y) const;
		
		//void RenderTexture(const Texture2D& texture, SDL_Rect dst);
		//void RenderTexture(const Texture2D& texture, SDL_Rect src, SDL_Rect dst);

		SDL_Renderer* GetSDLRenderer() const { return m_Renderer; }
	private:
		void RenderTexture(const Texture2D& texture, const SDL_Rect* src, SDL_Rect dst) const;
		SDL_Renderer* m_Renderer{};
	};
}

