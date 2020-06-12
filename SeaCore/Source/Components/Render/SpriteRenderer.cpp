#include "SeaCore_pch.h"
#include "SpriteRenderer.h"

#include "Components/Transform.h"
#include "Graphics/Texture2D.h"
#include "Time/Time.h"

sea_core::SpriteRenderer::SpriteRenderer(const std::string& fileName, SpriteRendererDesc& desc)
	: TextureRenderer(fileName)
	, m_ClipHeight(desc.ClipHeight)
	, m_ClipWidth(desc.ClipWidth)
	, m_NrTotalClipRows(unsigned int(GetTexture()->GetWidth() / m_ClipWidth))
	, m_NrTotalClipCols(unsigned int(GetTexture()->GetHeight() / m_ClipHeight))
	, m_StartColumn(desc.StartColumn)
	, m_StartRow(desc.StartRow)
	, m_EndColumn(desc.EndColumn)
	, m_EndRow(desc.EndRow)
	, m_NrFramesPerSec(desc.NrFramesPerSec)
	, m_Flip(desc.Flip)
{
}

void sea_core::SpriteRenderer::Update()
{
	m_AnimTime += Time().GetDeltaTime();
	if (m_AnimTime >= 1.0f / float(m_NrFramesPerSec)) // Goes to next row, checks if at end.
	{
		if (m_AnimFrameRow == m_EndRow && m_AnimFrameColumn == m_EndColumn)
		{
			m_AnimFrameRow = m_StartRow;
			m_AnimFrameColumn = m_StartColumn;
		}
		else if (m_AnimFrameColumn == m_NrTotalClipCols)
		{
			m_AnimFrameColumn = 0;
			m_AnimFrameRow++;
		}
		else
		{
			m_AnimFrameColumn++;
		}
		m_AnimTime = 0;
	}
}

void sea_core::SpriteRenderer::Render() const
{
	const glm::vec3 location = GetParent()->GetTransform()->GetPosition();
	const glm::vec3 scale = GetParent()->GetTransform()->GetScale();

	const SDL_Rect src({
		int(m_AnimFrameColumn * m_ClipWidth),
		int(m_AnimFrameRow * m_ClipHeight),
		int(m_ClipWidth),
		int(m_ClipHeight)
	});	
	//(, GetTexture()->GetHeight() + ((m_AnimFrameRow + 1) * m_ClipHeight), m_ClipWidth, m_ClipHeight);

	Renderer::GetInstance().RenderTexture(*GetTexture(), src, location.x, location.y);
}