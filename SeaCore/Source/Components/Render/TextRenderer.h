#pragma once
#include "TextureRenderer.h"

namespace sea_core
{
	class Font;
	
	class TextRenderer final : public TextureRenderer
	{
	public:
		explicit TextRenderer(const std::string& text, const Font* font);
		~TextRenderer() override;
		
		//void Render() const override; -> Is the same as the textureRenderer
		void SetText(const std::string& text);
		
	private:
		Texture2D* CreateTextTexture() const;

//Data Members
		std::string m_Text;
		const Font* m_pFont;
	};
}

