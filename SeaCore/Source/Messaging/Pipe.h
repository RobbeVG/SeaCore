#pragma once
#include "SendAndReceiveInterface.h"

namespace sea_core
{
	class Pipe : public Receiver
	{
	public:
		explicit Pipe(Sender* const sender) : pSender(sender) {}

		inline void ReceiveMessage(Message* pMessage) override { pSender->SendMessage(pMessage); };
	private:
		Sender* pSender;
	};
	
}
