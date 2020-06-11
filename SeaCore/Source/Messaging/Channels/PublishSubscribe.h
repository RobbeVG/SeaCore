#pragma once
#include <unordered_set>
#include "../Channel.h"

namespace sea_core
{
	namespace MessagingChannel
	{
		class PublishSubscribe : virtual public Channel
		{
		public:
			void Subscribe(Receiver* pReceiver) { m_pReceivers.insert(pReceiver); }
			void UnSubscribe(Receiver* pReceiver) { m_pReceivers.erase(pReceiver); }

			virtual void SendMessage(Message* pMessage) override;
		protected:
			std::unordered_set<Receiver*> m_pReceivers;
		};
	}

}