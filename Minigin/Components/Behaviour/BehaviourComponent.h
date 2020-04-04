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
		void inline Update(const float deltaSeconds) override final;

	protected:
		virtual void UpdateBehaviour(const float deltaSeconds) = 0;
		
	private:
		bool m_IsEnabled;
	};
}
