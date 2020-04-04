#pragma once
#include <unordered_map>
#include "Broadcaster.h"
#include "../../Helpers/Singleton.h"

namespace sea_core
{
	class BroadcastManager final : public Singleton<BroadcastManager>
	{
	public:
		Broadcaster* GetBroadcaster(const char* broadcastName, BaseComponent* pMessenger);
		~BroadcastManager();
		
	private:		
		std::unordered_map<size_t, Broadcaster*> m_Broadcasters;
	};
}
