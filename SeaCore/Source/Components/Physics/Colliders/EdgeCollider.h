#pragma once
#include "../ColliderComponent.h"
namespace sea_core
{
	class EdgeCollider : public ColliderComponent
	{
	public:
		EdgeCollider(const RigidBody* pRigidBody, const ColliderDesc& desc, const b2Vec2& pos1, const b2Vec2& pos2);
		EdgeCollider(const RigidBody* pRigidBody, const ColliderDesc& desc, const b2Vec2& ghost1, const b2Vec2& pos2, const b2Vec2& pos3, const b2Vec2& ghost4);
	};
}
