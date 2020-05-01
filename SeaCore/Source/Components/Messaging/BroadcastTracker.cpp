#include "SeaCore_pch.h"
#include "BroadcastTracker.h"
#include "BaseC"

// We want hash(s)!=hash(t) to be very likely, if s!=t
// That's the important part that you have to keep in mind.
// Using hashing will not be 100% deterministically correct, because two complete different strings might have the same hash (the hashes collide).
// However, in a wide majority of tasks this can be safely ignored as the probability of the hashes of two different strings colliding is still very small.
//
// https://cp-algorithms.com/string/string-hashing.html

sea_core::Broadcaster* sea_core::BroadcastTracker::GetBroadcaster(BaseComponent* pBaseComponent)
{
	const std::unordered_map<BaseComponent*, Broadcaster*>::const_iterator it = m_Broadcasters.find(pBaseComponent);
	if (it != m_Broadcasters.end()) //No broadcaster has been found
	{
		return (*it).second;
	}
	return nullptr;
}

bool sea_core::BroadcastTracker::AddBroadcaster(BaseComponent* pBaseComponent, Broadcaster* pBroadcaster)
{
	const std::unordered_map<BaseComponent*, Broadcaster*>::const_iterator it = m_Broadcasters.find(pBaseComponent);
	if (it == m_Broadcasters.end()) //No broadcaster has been found
	{
		m_Broadcasters[pBaseComponent] = pBroadcaster;
		return true;
	}

	//Should never hit in case it does throw???
	return false;
}
