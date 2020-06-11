#include "SeaCore_pch.h"
#include "Broadcaster.h"


#include <map>
#include <functional>

#include "Components/BaseComponent.h"


//sea_core::Broadcaster::Broadcaster(GameObject* object, const char* name)
//	: m_pReciter(nullptr)
//{
//	BroadcastTracker::GetInstance().AddBroadcaster(object, name, this);
//}

sea_core::Broadcaster::Broadcaster(BaseComponent* pReciter, bool subscribeOwn)
	: m_pReciter(pReciter)
{
	if (subscribeOwn)
		Subscribe(pReciter);
}

void sea_core::Broadcaster::Subscribe(BaseComponent* pListener)
{
	m_Subscribers.insert(pListener);
}

void sea_core::Broadcaster::UnSubscribe(BaseComponent* pListener)
{
	m_Subscribers.erase(pListener);
}

//void sea_core::Broadcaster::Broadcast(const unsigned message)
//{
//	for (BaseComponent* component : m_Subscribers)
//	{
//		if (component != nullptr)
//			component->ReceiveMessage(message);
//	}
//}
