#pragma once
#include "../../Resources/ResourceManager.h"
#include "RendererComponent.h"

namespace sea_core
{
	class TextureRenderer : public RendererComponent
	{
	public:
		explicit TextureRenderer(const std::string& fileName);
		~TextureRenderer() override;

		void SetTexture(const std::string& filename);

	protected:
		virtual void Render() const override;
		
		explicit TextureRenderer(const Texture2D* pTexture);
		void SetTexture(const Texture2D* pTexture);
		const Texture2D* GetTexture() const;
		
	private:
		const Texture2D* m_pTexture;
	};
}

