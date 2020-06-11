#include "SeaCore_pch.h"

#include "PointToPoint.h"
#include <cassert>

sea_core::MessagingChannel::PointToPoint::PointToPoint(Receiver* pReceiver)
{
	SetReceiver(pReceiver);
}

void sea_core::MessagingChannel::PointToPoint::SetReceiver(Receiver* pReceiver)
{
	m_pReceiver = pReceiver;
	assert(pReceiver != nullptr); //TODO Change to logger 
}

//void sea_core::MessagingChannel::PointToPoint::ReceiveMessage(Message message) const
//{
//	SendMessage(message);
//}

void sea_core::MessagingChannel::PointToPoint::SendMessage(Message* message)
{
	m_pReceiver->ReceiveMessage(message);
}
