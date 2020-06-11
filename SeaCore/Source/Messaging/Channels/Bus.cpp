#include "SeaCore_pch.h"
#include "Bus.h"

void sea_core::MessagingChannel::Bus::SendMessage(Message* pMessage)
{
	const MessageHeader& header = pMessage->GetHeader();
	if (header.pDestination == nullptr)
	{
		for (Receiver* pReceiver : m_pReceivers)
		{
			pMessage->SetReceiver(pReceiver);
			pReceiver->ReceiveMessage(pMessage);
		}
		return;
	}
	if (m_pReceivers.find(header.pDestination) != m_pReceivers.end())
		header.pDestination->ReceiveMessage(pMessage);
	//else
	//{
	//	//TODO INVALID
	//}
}
