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

sea_core::TextureRenderer::~TextureRenderer()
{
	delete m_pTexture;
}

void sea_core::TextureRenderer::SetTexture(const std::string& filename)
{
	//if (m_pTexture)
	SetTexture(ResourceManager::GetInstance().LoadTexture(filename));
}

void sea_core::TextureRenderer::SetTexture(const Texture2D* pTexture)
{
	delete m_pTexture;
	m_pTexture = pTexture;
}

const sea_core::Texture2D* sea_core::TextureRenderer::GetTexture() const
{
	return m_pTexture;
}
