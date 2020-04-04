#include "MiniginPCH.h"
#include "Broadcaster.h"
#include "../BaseComponent.h"

void sea_core::Broadcaster::Send(const unsigned int message) const
{
	for (BaseComponent* const component : m_Components)
	{
		if (component != nullptr)
			component->ReceiveMessage(message);
	}
}

void sea_core::Broadcaster::EraseComponent(BaseComponent* pMessageComponent)
{
	m_Components.erase(pMessageComponent);
}

void sea_core::Broadcaster::AddComponent(BaseComponent* pMessageComponent)
{
	m_Components.insert(pMessageComponent);
}
