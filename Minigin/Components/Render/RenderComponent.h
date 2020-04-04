#pragma once
#include "../BaseComponent.h"
#include "../../Graphics/Renderer.h" //Include used in all derived objects

namespace sea_core
{
	class RenderComponent : public BaseComponent
	{
	protected:
		explicit RenderComponent();
	public:
		virtual ~RenderComponent() = default;
		void inline Update(const float deltaSeconds) override final;
		void inline Render(const float deltaSeconds) const;

		void SetEnabled(bool const enabled) { m_IsEnabled = enabled; }
		
	protected:
		virtual void DerivedRender(const float deltaSeconds) const = 0;
		virtual void UpdateRender(const float deltaSeconds) const = 0;
		virtual void ReceiveMessage(const unsigned) override {}
		
	private:
		inline void AttachToContainer(std::vector<BaseComponent*>&, std::vector<const RenderComponent*>& renderComponents) override final { renderComponents.push_back(this); };
		
		bool m_IsEnabled;
		bool m_IsVisible;
	};	
}
