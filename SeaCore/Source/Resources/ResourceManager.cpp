#include "SeaCore_pch.h"
#include "ResourceManager.h"

sea_core::ResourceManager::~ResourceManager()
{
	delete m_pTextures;
	delete m_pFonts;
	delete m_pFiles;
}

sea_core::ResourceManager::ResourceManager()
	: m_pTextures(new TextureManager())
	, m_pFonts(new FontManager())
	, m_pFiles(new FileManager())
{
}


//sea_core::Texture2D* sea_core::ResourceManager::LoadTexture(const std::string& file) const
//{
//	const auto fullPath = m_DataPath + file;
//	SDL_Texture* texture = IMG_LoadTexture(Renderer::GetInstance().GetSDLRenderer(), fullPath.c_str());
//	if (texture == nullptr) 
//	{
//		throw std::runtime_error(std::string("Failed to load texture: ") + SDL_GetError());
//	}
//	return new Texture2D(texture);
//}
//
//sea_core::Font* sea_core::ResourceManager::LoadFont(const std::string& file, unsigned int size) const
//{
//	return new Font(m_DataPath + file, size);
//}
//
//std::ifstream* sea_core::ResourceManager::LoadBinaryFile(const std::string& file) const
//{
//	auto reader = new std::ifstream();
//	reader->open(m_DataPath + file, std::ios::in | std::ios::binary);
//	if (reader->is_open())
//		return reader;
//
//	delete reader;
//	return nullptr;
//}
