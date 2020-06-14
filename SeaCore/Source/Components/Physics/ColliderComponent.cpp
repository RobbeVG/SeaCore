#include "SeaCore_pch.h"
#include "ColliderComponent.h"

void sea_core::ColliderComponent::SetFixture(const RigidBody* pRigidBody, const ColliderDesc& desc, const b2Shape& pShape)
{
	b2FixtureDef def;
	def.shape = &pShape;
	def.density = desc.density;
	def.filter = desc.filter;
	def.friction = desc.friction;
	def.isSensor = desc.isSensor;
	def.restitution = desc.restitution;
	
	m_pFixture = pRigidBody->GetBody()->CreateFixture(&def);
}
