#pragma once
#include "../../Resources/ResourceManager.h"
#include "RenderComponent.h"

namespace sea_core
{
	class SpriteRenderer final : public RenderComponent
	{
	public:
		explicit SpriteRenderer(const std::string& fileName);
		virtual ~SpriteRenderer() override;

		virtual void DerivedRender(const float deltaSeconds) const override;
		void SetTexture(const std::string& filename);
		
	private:
		const Texture2D* m_pTexture;
	};
}

