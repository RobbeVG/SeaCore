#pragma once
#include <unordered_set>
#include "Messaging/Channel.h"

namespace sea_core
{
	namespace MessagingChannel
	{
		/*
		 * @Brief: A bus is capable of sending messages to all receivers if no receiver is specified.
		 * @Note: It sends one message to a receiver if a receiver is specified in the message.
		 */
		class Bus : public Channel
		{
		public:
			explicit Bus() = default;

		public:
			void Subscribe(Receiver* pReceiver) { m_pReceivers.insert(pReceiver); }
			void UnSubscribe(Receiver* pReceiver) { m_pReceivers.erase(pReceiver); }

			virtual void SendMessage(Message* pMessage) override;
		protected:
			std::unordered_set<Receiver*> m_pReceivers;
		};
	}
}
