#include "SeaCore_pch.h"
#include "EdgeCollider.h"

#include <Box2D/Collision/Shapes/b2EdgeShape.h>

sea_core::EdgeCollider::EdgeCollider(const RigidBody* pRigidBody, const ColliderDesc& desc, const b2Vec2& pos1,
	const b2Vec2& pos2)
{
	b2EdgeShape shape;
	shape.Set(pos1, pos2);
	SetFixture(pRigidBody, desc, shape);
}

sea_core::EdgeCollider::EdgeCollider(const RigidBody* pRigidBody, const ColliderDesc& desc, const b2Vec2& ghost1,
	const b2Vec2& pos2, const b2Vec2& pos3, const b2Vec2& ghost4)
{
	b2EdgeShape shape;
	shape.m_hasVertex0 = true;
	shape.m_vertex0 = ghost1;
	shape.Set(pos2, pos3);
	shape.m_vertex3 = ghost4;
	shape.m_hasVertex3 = true;
	SetFixture(pRigidBody, desc, shape);
}
