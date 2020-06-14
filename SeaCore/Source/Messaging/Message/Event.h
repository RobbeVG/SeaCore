#pragma once
#include "../Message.h"

//namespace sea_core
//{
//	namespace MessagingMessages
//	{
//		class Event : public Message
//		{
//		public:
//			Event(const Sender* const pSender, Receiver* const pDestination, unsigned int eventIndex)
//				: Message(MessageType::Event, pSender, pDestination, sizeof(unsigned int), alignof(unsigned int)),
//				  m_EventIndex(eventIndex)
//			{}
//
//			const void* GetData() const override { return static_cast<const void*>(&m_EventIndex); }
//			unsigned int GetEventIndex() const { return m_EventIndex; };
//			
//		private:
//			unsigned int m_EventIndex;
//		};
//	}
//}