#include "SeaCore_pch.h"
#include "BehaviourComponent.h"

sea_core::BehaviourComponent::BehaviourComponent()
	: m_IsEnabled(true)
{
	//m_pBroadcaster = new Broadcaster(this);
}

void sea_core::BehaviourComponent::UpdateComponent()
{
	if (m_IsEnabled)
		Update();
}

void sea_core::BehaviourComponent::SetEnabled(const bool enabled)
{
	m_IsEnabled = enabled;
	//if (m_IsEnabled != enabled)
	//{
		//BroadcastMessage(enabled? Convert(Messages::MonoBehaviour::OnEnable) : Convert(Messages::MonoBehaviour::OnDisable));
	//}
}
