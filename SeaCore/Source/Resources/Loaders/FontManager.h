#pragma once
#include "BaseLoader.h"
#include "Graphics/Font.h"

class FontManager :  public BaseLoader<sea_core::Font>
{
public:
	FontManager();
	~FontManager();
	void SetFontSize(const unsigned int size) { m_FontSize = size; };

private:
	sea_core::Font* LoadContent(const std::string& path) override;

	unsigned int m_FontSize;
};

