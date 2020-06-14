#pragma once


#include "../Components/Transform.h"
#include "../Components/Render/RendererComponent.h"
#include "../Components/Physics/PhysicsComponent.h"
#include "../Components/Behaviour/MonoBehaviour.h"

namespace sea_core
{
	struct ComponentContainer
	{
		Transform* m_pTransform;
		std::vector<MonoBehaviour*> m_pMonoBehaviourComponents;
		std::vector<PhysicsComponent*> m_pPhysicsComponents;
		std::vector<RendererComponent*> m_pRendererComponents;

		//const Transform& GetTransform() const { return *m_pTransform; };
		//const std::vector<MonoBehaviour*>& GetMonoComponents() const { return m_pMonoBehaviourComponents; };
		//const std::vector<PhysicsComponent*>& GetPhysicsComponents() const { return m_pPhysicsComponents; };
		//const std::vector<RendererComponent*>& GetRenderComponents() const { return m_pRendererComponents; };
	};

}

