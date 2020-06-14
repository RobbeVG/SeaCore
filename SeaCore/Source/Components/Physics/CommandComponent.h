#pragma once
#include <queue>

#include "ColliderComponent.h"
#include "Components/Behaviour/BehaviourComponent.h"
#include "PhysicsComponent.h"
#include "RigidBody.h"
#include "Input/Command.h"

namespace sea_core
{
	class CommandComponent : public BehaviourComponent
	{
	protected:
		void Update() override;
		
	public:
		CommandComponent() = default;
		void AddCommand(Command* pCommand) { m_Commands.push(pCommand); };

	private:
		std::queue<Command*> m_Commands;
	};
}
