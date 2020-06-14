#pragma once
#include <map>

#include "Helpers/Singleton.h"
#include "Channel.h"
//#include "Messaging/MessagingSystem.h"

namespace sea_core
{
	enum class MessagingSystems
	{
		GameObjects
	};
	
	class MessagingSystemsManager : public Singleton<MessagingSystemsManager>
	{
	public:


		void AddSystem(MessagingSystems type, Channel* pStartingChannel);
		void RemoveSystem(MessagingSystems type);

		static Channel* System(MessagingSystems type);
		
	private:
		std::map<MessagingSystems, Channel*> m_MessagingSystems;
	};
	
	typedef MessagingSystemsManager MSM;
}

