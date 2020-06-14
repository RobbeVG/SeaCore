#pragma once
#include "../ColliderComponent.h"
namespace sea_core
{
	class CircleCollider : public ColliderComponent
	{
	public:
		CircleCollider(const RigidBody* pRigidBody, const ColliderDesc& desc, b2Vec2 center, float radius);
	};
}

