#pragma once
#include "../BaseComponent.h"

namespace sea_core
{
	class BehaviourComponent : public BaseComponent
	{
	protected:
		BehaviourComponent();
	public:
		virtual ~BehaviourComponent() = default;
		void inline UpdateComponent(const float deltaSeconds) override final;
		void SetEnabled(bool enabled);
		
	protected:
		virtual void Update(const float deltaSeconds) = 0;
		
	private:
		void AttachToContainer(std::vector<BaseComponent*>& components, std::vector<RendererComponent*>&) override final { components.push_back(this);  }
		bool m_IsEnabled;
	};
}
