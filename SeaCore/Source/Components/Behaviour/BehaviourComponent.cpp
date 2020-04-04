#include "SeaCore_pch.h"
#include "BehaviourComponent.h"
#include "../Messaging/Messages/MonoBehaviourMessages.h"

sea_core::BehaviourComponent::BehaviourComponent()
	: m_IsEnabled(true)
{
}

void sea_core::BehaviourComponent::UpdateComponent(const float deltaSeconds)
{
	if (m_IsEnabled)
		Update(deltaSeconds);
}

void sea_core::BehaviourComponent::SetEnabled(const bool enabled)
{
	m_IsEnabled = enabled;
	BroadcastMessage(enabled? Messages::MonoBehaviour::OnEnable : Messages::MonoBehaviour::OnDisable);
}
