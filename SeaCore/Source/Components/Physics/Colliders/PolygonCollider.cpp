#include "SeaCore_pch.h"
#include "PolygonCollider.h"

#include <Box2D/Collision/Shapes/b2PolygonShape.h>

sea_core::PolygonCollider::PolygonCollider(const RigidBody* pRigidBody, const ColliderDesc& desc,
	const std::vector<b2Vec2>& vertices)
{
	b2PolygonShape shape;
	shape.Set(vertices.data(), int(vertices.size()));
	SetFixture(pRigidBody, desc, shape);
}

sea_core::PolygonCollider::PolygonCollider(const RigidBody* pRigidBody, const ColliderDesc& desc, float halfWidth,
	float halfHeight)
{
	b2PolygonShape shape;
	shape.SetAsBox(halfWidth, halfHeight);
	SetFixture(pRigidBody, desc, shape);
}

sea_core::PolygonCollider::PolygonCollider(const RigidBody* pRigidBody, const ColliderDesc& desc, const float halfWidth,
                                           const float halfHeight, const b2Vec2& center, const float angle)
{
	b2PolygonShape shape;
	shape.SetAsBox(halfWidth, halfHeight, center, angle);
	SetFixture(pRigidBody, desc, shape);
}
