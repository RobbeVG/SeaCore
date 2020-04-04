#include "MiniginPCH.h"
#include "BaseComponent.h"
#include "Messaging/BroadcastManager.h"

//broadcasterName == ""? nullptr : BroadcastManager::GetInstance().GetBroadcaster(broadcasterName.c_str(), this)

sea_core::BaseComponent::BaseComponent()
	: m_pParent(nullptr)
	, m_pBroadcaster(nullptr)
{
}

void sea_core::BaseComponent::BroadcastMessage(const unsigned int message) const
{
	if (m_pBroadcaster)
		m_pBroadcaster->Send(message);
}

sea_core::GameObject* sea_core::BaseComponent::GetParent() const
{
	return m_pParent;
}
