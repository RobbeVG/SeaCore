#pragma once
#include <unordered_set>

namespace sea_core
{
	class BaseComponent;
	
	/*
	 * 
	 */
	class Broadcaster
	{
		friend class BroadcastManager;
		Broadcaster() = default; //Private constructor only the broadcast manager can create broadcaster
		void AddComponent(BaseComponent* pMessageComponent);
		void EraseComponent(BaseComponent* pMessageComponent);
		
	public:
		void Send(const unsigned int message) const;
	private:		
		std::unordered_set<BaseComponent*> m_Components;
	};
}
