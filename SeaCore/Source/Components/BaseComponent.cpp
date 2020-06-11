#include "SeaCore_pch.h"
#include "BaseComponent.h"
//#include "Messaging/Broadcaster.h"


void sea_core::BaseComponent::SetParent(GameObject* pParent)
{
	m_pParent = pParent;
}

void sea_core::BaseComponent::AttachToParent(GameObject* pParent)
{
	SetParent(pParent);
	pParent->AddComponent(this);
}

sea_core::BaseComponent::BaseComponent()
	: m_pParent(nullptr)
	//, m_pBroadcaster(nullptr)
{
}

//void sea_core::BaseComponent::BroadcastMessage(const unsigned int message) const
//{
//	//if (m_pBroadcaster)
//	//	m_pBroadcaster->Broadcast(message);
//}