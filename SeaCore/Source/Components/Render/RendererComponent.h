#pragma once
#include "../BaseComponent.h"
#include "../../Graphics/Renderer.h" //Include used in all derived objects

namespace sea_core
{
	class RendererComponent : public BaseComponent
	{
	protected:
		explicit RendererComponent();
	public:
		virtual ~RendererComponent() = default;
		void inline UpdateComponent(const float deltaSeconds) override final;
		void RenderComponent(const float deltaSeconds) const;

		void SetEnabled(bool const enabled) { m_IsEnabled = enabled; }
		
	protected:
		virtual void Render(const float deltaSeconds) const = 0;
		virtual void Update(const float) const {}
		virtual void ReceiveMessage(const unsigned) override {}
		
	private:
		inline void AttachToContainer(std::vector<BaseComponent*>&, std::vector<RendererComponent*>& renderComponents) override final { renderComponents.push_back(this); };
		
		bool m_IsEnabled;
		bool m_IsVisible;
	};	
}
