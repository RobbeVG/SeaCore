#pragma once
#include "../../Resources/ResourceManager.h"
#include "RendererComponent.h"

namespace sea_core
{
	class SpriteRenderer final : public RendererComponent
	{
	public:
		explicit SpriteRenderer(const std::string& fileName);
		~SpriteRenderer() override;

		void Render(const float deltaSeconds) const override;
		void SetTexture(const std::string& filename);
		
	private:
		const Texture2D* m_pTexture;
	};
}

