#pragma once
#include "../Helpers/Singleton.h"

#include "Loaders/FileManager.h"
#include "Loaders/FontManager.h"
#include "Loaders/TextureManager.h"

namespace sea_core
{
	//class Texture2D;
	//class Font;
	//class ResourceManager final : public Singleton<ResourceManager>
	//{
	//	Texture2D* LoadTexture(const std::string& file) const;
	//	Font* LoadFont(const std::string& file, unsigned int size) const;
	//	std::ifstream* LoadBinaryFile(const std::string& file) const;

	//private:
	//	friend class Singleton<ResourceManager>;
	//	ResourceManager() = default;
	//	std::string m_DataPath;

	//};

	class ResourceManager final : public Singleton<ResourceManager>
	{
	public:
		~ResourceManager();

		TextureManager& Textures() const { return *m_pTextures; }
		FontManager& Fonts() const { return *m_pFonts; }
		FileManager& Files() const { return *m_pFiles; }

	private:
		friend Singleton<ResourceManager>;
		ResourceManager();

		TextureManager* const m_pTextures;
		FontManager* const m_pFonts;
		FileManager* const m_pFiles;
	};

	
}
