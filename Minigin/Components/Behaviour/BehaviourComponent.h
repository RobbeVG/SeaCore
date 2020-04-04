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
		bool m_IsEnabled;
	};
}
