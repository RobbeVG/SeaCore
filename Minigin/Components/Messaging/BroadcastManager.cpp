#include "MiniginPCH.h"
#include "BroadcastManager.h"

// We want hash(s)!=hash(t) to be very likely, if s!=t
// That's the important part that you have to keep in mind.
// Using hashing will not be 100% deterministically correct, because two complete different strings might have the same hash (the hashes collide).
// However, in a wide majority of tasks this can be safely ignored as the probability of the hashes of two different strings colliding is still very small.
//
// https://cp-algorithms.com/string/string-hashing.html

sea_core::Broadcaster* sea_core::BroadcastManager::GetBroadcaster(const char* broadcastName, BaseComponent* pMessenger)
{
	const size_t id = std::hash<const char*>()(broadcastName);

	Broadcaster* pBroadcaster;
	const std::unordered_map<size_t, Broadcaster*>::const_iterator it = m_Broadcasters.find(id);
	if (it == m_Broadcasters.end()) //No broadcaster has been found
	{
		pBroadcaster = new Broadcaster();
		m_Broadcasters[id] = pBroadcaster;
	}
	else //Broadcaster has been found
	{
		pBroadcaster = (*it).second;
	}
	if (pMessenger)
		pBroadcaster->AddComponent(pMessenger);
	return pBroadcaster;
}

sea_core::BroadcastManager::~BroadcastManager()
{
	for (std::pair<size_t, Broadcaster*> broadcaster : m_Broadcasters)
	{
		delete broadcaster.second;
	}
}
