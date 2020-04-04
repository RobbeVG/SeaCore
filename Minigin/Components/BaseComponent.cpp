#include "MiniginPCH.h"
#include "BaseComponent.h"
#include "Messaging/BroadcastManager.h"


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

void sea_core::BaseComponent::AssignBroadcaster(const std::string& broadcasterName)
{
	m_pBroadcaster = (broadcasterName.empty())? nullptr : BroadcastManager::GetInstance().GetBroadcaster(broadcasterName.c_str());
}

sea_core::GameObject* sea_core::BaseComponent::GetParent() const
{
	return m_pParent;
}
