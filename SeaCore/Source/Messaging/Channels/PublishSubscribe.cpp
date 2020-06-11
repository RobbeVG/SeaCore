#include "SeaCore_pch.h"
#include "PublishSubscribe.h"

void sea_core::MessagingChannel::PublishSubscribe::SendMessage(Message* pMessage)
{
	//TODO All messages are handled separately
	//Make them receive at the same time
	
	for (Receiver* pReceiver : m_pReceivers)
	{
		pReceiver->ReceiveMessage(pMessage);
	}
}
