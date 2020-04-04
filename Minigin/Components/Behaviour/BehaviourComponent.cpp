#include "MiniginPCH.h"
#include "BehaviourComponent.h"

sea_core::BehaviourComponent::BehaviourComponent()
	: m_IsEnabled(true)
{
}

void sea_core::BehaviourComponent::Update(const float deltaSeconds)
{
	if (m_IsEnabled)
		UpdateBehaviour(deltaSeconds);
}
