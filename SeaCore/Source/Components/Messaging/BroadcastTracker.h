#pragma once
#include <unordered_map>
#include "Helpers/Singleton.h"
#include "Broadcaster.h"

namespace sea_core
{
	class GameObject;
	
	class BroadcastTracker final : public Singleton<BroadcastTracker>
	{
	public:
		Broadcaster* GetBroadcaster(BaseComponent*);
	private:
		friend class Broadcaster;
		bool AddBroadcaster(BaseComponent*, Broadcaster* pBroadcaster);


		std::unordered_map<BaseComponent*, Broadcaster*> m_Broadcasters;
	};
}
