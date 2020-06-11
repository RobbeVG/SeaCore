#pragma once
#include "../BaseComponent.h"

namespace sea_core
{
	class BehaviourComponent : virtual public BaseComponent
	{
	protected:
		BehaviourComponent();
	public:
		virtual void UpdateComponent() override;
		virtual ~BehaviourComponent() = default;
		
		virtual void SetEnabled(bool enabled);
		bool IsEnabled() const { return m_IsEnabled; }
		
	protected:
		virtual void Update() = 0;
		virtual void OnStart() {}

	private:
		bool m_IsEnabled;
	};
}
