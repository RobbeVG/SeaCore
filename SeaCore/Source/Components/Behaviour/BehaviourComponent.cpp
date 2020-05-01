#include "SeaCore_pch.h"
#include "BehaviourComponent.h"
#include "Components/Messaging/Messages.h"

sea_core::BehaviourComponent::BehaviourComponent()
	: m_IsEnabled(true)
{
	m_pBroadcaster = new Broadcaster(this);
}

void sea_core::BehaviourComponent::UpdateComponent(const float deltaSeconds)
{
	if (m_IsEnabled)
		Update(deltaSeconds);
}

void sea_core::BehaviourComponent::SetEnabled(const bool enabled)
{
	m_IsEnabled = enabled;
	BroadcastMessage(enabled? unsigned int(Messages::MonoBehaviour::OnEnable) : unsigned int(Messages::MonoBehaviour::OnDisable));
}
