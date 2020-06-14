#pragma once
#include "../ColliderComponent.h"

namespace sea_core
{
	class ChainCollider : public ColliderComponent
	{
	public:
		explicit ChainCollider(const RigidBody* pRigidBody, const ColliderDesc& desc, const std::vector<b2Vec2>& vertices);
		ChainCollider(const RigidBody* pRigidBody, const ColliderDesc& desc, const b2Vec2& ghostPrev, const std::vector<b2Vec2>& vertices, const b2Vec2& ghostNext);


		void SetLoop(bool loop) const;
	};
}
