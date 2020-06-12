#pragma once
#include "TextureRenderer.h"

namespace sea_core
{
	/**
	 * @note Rows and Cols start counting from 0 (Default of start values = 0)
	 * @note Height and Width is in pixel format
	 */
	struct SpriteRendererDesc
	{
		bool Flip = false;

		unsigned int ClipHeight = 0;
		unsigned int ClipWidth = 0;

		unsigned int StartColumn = 0;
		unsigned int StartRow = 0;

		unsigned int EndColumn = 1;
		unsigned int EndRow = 1;
		
		int NrFramesPerSec = 0;
	};

	/**
	 * @brief A sprite renderer class that allows multiple frames to be played
	 */
	class SpriteRenderer : public TextureRenderer
	{
	public:
		explicit SpriteRenderer(const std::string& fileName, SpriteRendererDesc& desc);

		void Update() override;
		void Render() const override;
		
		void SetFlip(bool value) { m_Flip = value; }
		void Flip() { m_Flip = !m_Flip; }
		
	private:
		const unsigned int m_ClipHeight;
		const unsigned int m_ClipWidth;

		const unsigned int m_NrTotalClipRows;
		const unsigned int m_NrTotalClipCols;
		
		const unsigned int m_StartColumn;
		const unsigned int m_StartRow;

		const unsigned int m_EndColumn;
		const unsigned int m_EndRow;

		const unsigned int m_NrFramesPerSec;
		float m_AnimTime;
		unsigned int m_AnimFrameColumn;
		unsigned int m_AnimFrameRow;

		bool m_Flip;
	};
}