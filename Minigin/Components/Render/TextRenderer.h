#pragma once
#include "../../Graphics/Font.h"
#include "RendererComponent.h"

namespace sea_core
{
	class TextRenderer final : public RendererComponent
	{
	public:
		explicit TextRenderer(const std::string& text, const Font* font);
		~TextRenderer() override;
		
		void Render(const float deltaSeconds) const override;
		void SetText(const std::string& text);
		
	private:
		void SetTextTexture();

//Data Members
		std::string m_Text;
		
		const Font* m_pFont;
		const Texture2D* m_pTexture;
	};
}

