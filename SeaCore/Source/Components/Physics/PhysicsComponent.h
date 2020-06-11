#pragma once
#include "Components/BaseComponent.h"

namespace sea_core
{
	class PhysicsComponent : virtual public BaseComponent
	{
	public:
		void FixedUpdateComponent() override { FixedUpdate(); }

	protected:
		virtual inline void FixedUpdate() = 0;
	};
}
