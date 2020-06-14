#pragma once
#include "Components/Physics/RigidBody.h"
#include "Input/Command.h"

namespace sea_core
{
	class MoveCommand : public Command
	{
	public:
		MoveCommand(RigidBody* pRigidBody, b2Vec2 displacement, float speed);
		void SetDisplacement(const b2Vec2& vec) { m_Displacement = vec; }
		void SetSpeed(const float speed) { m_Speed = speed; }

	private:
		void Execute() override;

		
		RigidBody* m_pRigidBody;
		b2Vec2 m_Displacement; //[0,1]
		float m_Speed;
	};
}

