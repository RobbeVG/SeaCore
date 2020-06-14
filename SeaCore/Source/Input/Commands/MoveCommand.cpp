#include "SeaCore_pch.h"
#include "MoveCommand.h"

#include <Box2D/Common/b2Math.h>
#include <Box2D/Dynamics/b2Body.h>


#include "Time/Time.h"

sea_core::MoveCommand::MoveCommand(RigidBody* pRigidBody, b2Vec2 displacement, float speed)
	: m_pRigidBody(pRigidBody)
	, m_Displacement(displacement)
	, m_Speed(speed)
{
}

void sea_core::MoveCommand::Execute()
{
	b2Vec2 displacement(m_Speed * m_Displacement.x, m_Speed * m_Displacement.y);
	displacement *= Time().GetFixedDeltaTime();
	
	b2Body* pBody = m_pRigidBody->GetBody();

	pBody->ApplyLinearImpulse(displacement, pBody->GetPosition(), true);
	//pBody->SetTransform(pBody->GetPosition() + displacement, 0.0f);
}
