#pragma once
struct SDL_Texture;
struct SDL_Rect;

namespace sea_core
{
	/**
	 * Simple RAII wrapper for an SDL_Texture
	 */
	class Texture2D
	{
	public:
		SDL_Texture* GetSDLTexture() const;
		explicit Texture2D(SDL_Texture* texture);
		explicit Texture2D(SDL_Texture* texture, const SDL_Rect& src);
		~Texture2D();

		Texture2D(const Texture2D &) = delete;
		Texture2D(Texture2D &&) = delete;
		Texture2D & operator= (const Texture2D &) = delete;
		Texture2D & operator= (const Texture2D &&) = delete;


		int GetWidth() const;
		int GetHeight() const;
		
	private:
		SDL_Texture* m_pTexture;

		size_t m_TextureId;
		
		int m_Width;
		int m_Height;
	};
}
