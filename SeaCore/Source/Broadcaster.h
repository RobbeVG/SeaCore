#pragma once
#include <queue>
#include <unordered_set>

//#include <map>
//#include "Components/BaseComponent.h"

namespace sea_core
{
	class GameObject;
	class BaseComponent;
	
	/*
	 * 
	 */
	class Broadcaster //: public BaseComponent -> Would allow creation of broadcaster on a gameobject as a component
	{
	public:
		explicit Broadcaster(BaseComponent* pReciter, bool subscribeOwn = false);
		~Broadcaster() = default;

		//void UpdateComponent(const float) override { m_pReciter = nullptr; }
		
		void Subscribe(BaseComponent* pListener);
		void UnSubscribe(BaseComponent* pListener);
		void Broadcast(const unsigned int message);

	private:		
		std::unordered_set<BaseComponent*> m_Subscribers;
		std::queue<unsigned int> m_Messages;
		
		BaseComponent* const m_pReciter;
	};
}
