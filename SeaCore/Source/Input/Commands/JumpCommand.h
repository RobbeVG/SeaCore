#pragma once
#include "Input/Command.h"

namespace sea_core
{
	class RigidBody;
	class ColliderComponent;

	class JumpCommand : public Command
	{
	public:
		JumpCommand(RigidBody* pRigidBody, ColliderComponent* pCollider, float force);
		void Execute() override;
		
	private:
		float m_Force;
		RigidBody* m_pRigidBody;
		const ColliderComponent* m_pCollider;
	};
}
