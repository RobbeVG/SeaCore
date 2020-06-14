#include "SeaCore_pch.h"
#include "ChainCollider.h"

#include <Box2D/Collision/Shapes/b2ChainShape.h>

sea_core::ChainCollider::ChainCollider(const RigidBody* pRigidBody, const ColliderDesc& desc,
                                       const std::vector<b2Vec2>& vertices)
{
	b2ChainShape shape;
	shape.CreateChain(vertices.data(), int(vertices.size()));
	SetFixture(pRigidBody, desc, shape);
}

sea_core::ChainCollider::ChainCollider(const RigidBody* pRigidBody, const ColliderDesc& desc, const b2Vec2& ghostPrev,
	const std::vector<b2Vec2>& vertices, const b2Vec2& ghostNext)
{
	b2ChainShape shape;
	shape.SetPrevVertex(ghostPrev);
	shape.CreateChain(vertices.data(), int(vertices.size()));
	shape.SetNextVertex(ghostNext);
	SetFixture(pRigidBody, desc, shape);
}
