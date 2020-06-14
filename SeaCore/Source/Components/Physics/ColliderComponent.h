#pragma once
#include "PhysicsComponent.h"

#include <Box2D/Dynamics/b2Fixture.h>
#include "RigidBody.h"

namespace sea_core
{
	struct ColliderDesc
	{
		//The friction coefficient, usually in the range[0, 1].
		float friction = 0.2f;
		//The restitution(elasticity) usually in the range[0, 1].
		float restitution = 0.0f;
		//The density, usually in kg / m ^ 2.
		float density = 0.0f;
		// A sensor shape collects contact information but never generates a collision
		// response.
		bool isSensor = false;
		//Contact filtering data. 
		b2Filter filter;
	};
	
	class ColliderComponent : public PhysicsComponent
	{
	protected:
		explicit ColliderComponent() : m_pFixture(nullptr) {}
		inline void FixedUpdate() override {}

		void SetFixture(const RigidBody* pRigidBody, const ColliderDesc& desc, const b2Shape& pShape);		
		b2Fixture* m_pFixture;
	};
}

