#pragma once
#include <queue>
#include "SendAndReceiveInterface.h"

namespace sea_core
{
	class Endpoint : public Receiver
	{
	public:
		explicit Endpoint() = default;
		void ReceiveMessage(Message* pMessage) override { m_pMessages.push(pMessage); };
		std::queue<Message*>& GetMessages() { return m_pMessages; };

	private:
		std::queue<Message*> m_pMessages;
	};
}
