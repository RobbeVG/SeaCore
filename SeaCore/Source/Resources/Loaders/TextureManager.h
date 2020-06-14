#pragma once
#include <map>


#include "BaseLoader.h"
#include "Graphics/Texture2D.h"


class TextureManager final : public BaseLoader<sea_core::Texture2D>
{
public:
	TextureManager();
private:
	sea_core::Texture2D* LoadContent(const std::string& path) override;
};
