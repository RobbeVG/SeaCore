#include "SeaCore_pch.h"
#include "TextureRenderer.h"
#include "../Transform.h"
#include "../../Graphics/Texture2D.h"


sea_core::TextureRenderer::TextureRenderer(const std::string& fileName)
	: m_pTexture(nullptr)
{
	SetTexture(fileName);
}

sea_core::TextureRenderer::TextureRenderer(const Texture2D* pTexture)
	: m_pTexture(pTexture)
{
}

void sea_core::TextureRenderer::Render() const
{	
	const glm::vec3 location = GetParent()->GetTransform()->GetPosition();
	Renderer::GetInstance().RenderTexture(*m_pTexture, location.x, location.y);
}

void sea_core::TextureRenderer::SetTexture(const std::string& filename)
{
	//if (m_pTexture)
	SetTexture(ResourceManager::GetInstance().Textures().Load(filename));
}

void sea_core::TextureRenderer::SetTexture(const Texture2D* pTexture)
{
	m_pTexture = pTexture;
}

const sea_core::Texture2D* sea_core::TextureRenderer::GetTexture() const
{
	return m_pTexture;
}
