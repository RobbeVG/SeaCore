#include "SeaCore_pch.h"
#include "Bus.h"

#include "Messaging/Message.h"
#include "Messaging/Message/MessageBodyManager.h"

//TODO Allocator for messages
void sea_core::MessagingChannel::Bus::SendMessage(Message* pMessage)
{
	MessageHeader& header = pMessage->GetHeader();

	header.pOrigin = this;
	
	if (header.pDestination == nullptr)
	{
		for (Receiver* pReceiver : m_pReceivers)
		{
			Message* pNewMessage = new Message(*pMessage);
			pNewMessage->GetHeader().pDestination = pReceiver;
			pReceiver->ReceiveMessage(pNewMessage);
		}
		delete pMessage;
	}
	else if (m_pReceivers.find(header.pDestination) != m_pReceivers.end())
	{
		//Passing the message further
		header.pDestination->ReceiveMessage(pMessage);
	}
	else
	{
		//TODO INVALID
		delete pMessage;

	}
}
