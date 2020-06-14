#pragma once
#include "Messaging/Message.h"

namespace sea_core
{
	namespace MessagingMessages
	{
		class Document : public Message
		{
		public:
			template<typename T>
			Document(const Sender* const pSender, Receiver* pDestination, const T& object)
				: Message(MessageType::Document, pSender, pDestination, sizeof(T), sizeof(T))
				, m_Data(new unsigned char[m_Header.size])
			{
				void* pBegin = static_cast<void*>(object);
				void* pEnd = pBegin + m_Header.size;
				std::copy(pBegin, pEnd, m_Data);
			}

			const void* GetData() const override { return m_Data; }

		private:
			unsigned char* m_Data;
		};
	}
}
