#pragma once
#include "../../Graphics/Font.h"
#include "RenderComponent.h"

namespace sea_core
{
	class TextRenderer final : public RenderComponent
	{
	public:
		explicit TextRenderer(const std::string& text, const Font* font);
		~TextRenderer() override;
		
		void DerivedRender(const float deltaSeconds) const override;
		void SetText(const std::string& text);
		
	private:
		void SetTextTexture();

//Data Members
		std::string m_Text;
		
		const Font* m_pFont;
		const Texture2D* m_pTexture;
	};
}

