#include "SeaCore_pch.h"
#include "RigidBody.h"

#include "Physics/Physics.h"
#include "Components/Transform.h"

void sea_core::RigidBody::FixedUpdate()
{
	const b2Vec2 position = m_pBody->GetPosition();
	m_pTransform->SetPosition(position.x, position.y);
}

sea_core::RigidBody::RigidBody(Transform* pTransform, const RigidBodyDesc& desc)
	: m_pTransform(pTransform)
	, m_pBody(nullptr)
{
	b2BodyDef bodyDef;
	switch (desc.type) {
	case Static:
		bodyDef.type = b2_staticBody;
		break;
	case Kinematic: 
		bodyDef.type = b2_kinematicBody;
		break;
	case Dynamic:
		bodyDef.type = b2_dynamicBody;
		break;
	default: ;
	}
	bodyDef.linearVelocity = desc.linearVelocity;
	bodyDef.angularVelocity = desc.angularVelocity;
	bodyDef.linearDamping = desc.linearDamping;
	bodyDef.angularDamping = desc.angularDamping;
	bodyDef.allowSleep = desc.allowSleep;
	bodyDef.awake = desc.awake;
	bodyDef.fixedRotation = desc.fixedRotation;
	bodyDef.bullet = desc.bullet;
	bodyDef.active = desc.active;
	bodyDef.gravityScale = desc.gravityScale;
	
	m_pBody = Physics()->CreateBody(&bodyDef);
	m_pBody->SetTransform(pTransform->GetPosition(), 0.0f);
	//m_pBody->GetTransform().p. = ;
}
