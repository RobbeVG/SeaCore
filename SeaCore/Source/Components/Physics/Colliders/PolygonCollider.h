#pragma once
#include "../ColliderComponent.h"

namespace sea_core
{	
	class PolygonCollider : public ColliderComponent
	{
	public:
		explicit PolygonCollider(const RigidBody* pRigidBody, const ColliderDesc& desc, const std::vector<b2Vec2>& vertices);
		PolygonCollider(const RigidBody* pRigidBody, const ColliderDesc& desc, float halfWidth, float halfHeight);
		PolygonCollider(const RigidBody* pRigidBody, const ColliderDesc& desc, float halfWidth, float halfHeight, const b2Vec2& center, float angle);
	};
}
