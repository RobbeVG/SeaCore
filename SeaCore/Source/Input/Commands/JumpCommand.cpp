#include "SeaCore_pch.h"
#include "JumpCommand.h"

#include <Box2D/Collision/b2Collision.h>
#include <Box2D/Dynamics/b2Body.h>
#include "Components/Physics/ColliderComponent.h"

sea_core::JumpCommand::JumpCommand(RigidBody* pRigidBody, ColliderComponent* pCollider, const float force)
	: m_Force(force)
	, m_pRigidBody(pRigidBody)
	, m_pCollider(pCollider)
{
}

void sea_core::JumpCommand::Execute()
{
	//b2RayCastInput input;
	//input.p1 = m_pRigidBody->GetBody()->GetPosition();
	//input.p2 = input.p1 + b2Vec2(0.0f, -20.0f);
	//input.maxFraction = 1.0f;
	//b2RayCastOutput output;
	//if (m_pCollider->GetFixture().RayCast(&output, input, 0))
	//{
		b2Body* pBody = m_pRigidBody->GetBody();
		
		pBody->ApplyLinearImpulse(b2Vec2(0.0f, m_Force), pBody->GetPosition(), true);
	//}
}
