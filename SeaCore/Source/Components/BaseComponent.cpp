#include "SeaCore_pch.h"
#include "BaseComponent.h"
#include "Messaging/BroadcastTracker.h"


sea_core::BaseComponent::BaseComponent()
	: m_pParent(nullptr)
	, m_pBroadcaster(nullptr)
{
}

void sea_core::BaseComponent::BroadcastMessage(const unsigned int message) const
{
	if (m_pBroadcaster)
		m_pBroadcaster->Broadcast(message);
}