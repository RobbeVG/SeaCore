#include "SeaCore_pch.h"
#include "CircleCollider.h"
#include <Box2D/Collision/Shapes/b2CircleShape.h>

sea_core::CircleCollider::CircleCollider(const RigidBody* pRigidBody, const ColliderDesc& desc, b2Vec2 center,
	float radius)
{
	b2CircleShape shape;
	shape.m_p = center;
	shape.m_radius = radius;

	SetFixture(pRigidBody, desc, shape);
}
