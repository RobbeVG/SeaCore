#include "MiniginPCH.h"
#include "SpriteRenderer.h"
#include "../Transform.h"
#include "../../Graphics/Texture2D.h"


sea_core::SpriteRenderer::SpriteRenderer(const std::string& fileName)
{
	SetTexture(fileName);
}

void sea_core::SpriteRenderer::DerivedRender(const float) const
{	
	const glm::vec3 location = m_pParent->GetTransform()->GetPosition();
	Renderer::GetInstance().RenderTexture(*m_pTexture, location.x, location.y);
}

sea_core::SpriteRenderer::~SpriteRenderer()
{
	delete m_pTexture;
}

void sea_core::SpriteRenderer::SetTexture(const std::string& filename)
{
	m_pTexture = ResourceManager::GetInstance().LoadTexture(filename);
}