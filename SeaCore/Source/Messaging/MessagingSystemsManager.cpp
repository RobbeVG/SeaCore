#include "SeaCore_pch.h"
#include "MessagingSystemsManager.h"

void sea_core::MessagingSystemsManager::AddSystem(const MessagingSystems type, Channel* pStartingChannel)
{
	if (m_MessagingSystems.find(type) == m_MessagingSystems.end())
		m_MessagingSystems[type] = pStartingChannel;
}

void sea_core::MessagingSystemsManager::RemoveSystem(MessagingSystems type)
{
	m_MessagingSystems.erase(type);
}

sea_core::Channel* sea_core::MessagingSystemsManager::System(const MessagingSystems type)
{
	return GetInstance().m_MessagingSystems.at(type);
}
