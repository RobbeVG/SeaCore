#pragma once
#include "MessageConstructors.h"

namespace sea_core
{
	class MessageBodyManager;

	class Message
	{
	public:
		explicit Message(Sender* pSender, Receiver* pDestination)
			: m_Header(pSender, pDestination)
			, m_Body(nullptr)
		{
		}
		~Message();

		Message(const Message& other);
		Message(Message&& other) noexcept;
		Message& operator=(const Message& other);
		Message& operator=(Message&& other) noexcept;

		void CreateEventMessage(const EventData& eventData);
		//void CreateDocumentMessage();
		//void CreateCommandMessage();
		
	private:
		friend class MessageBodyManager;
		
		MessageHeader m_Header;
		MessageBody* m_Body;

	public:
		MessageHeader& GetHeader() { return m_Header; }
		bool HasBody() const { return m_Body; }
		/**
		 * @brief GetThe body of the message!
		 * @note Use Has body to check if the body exist!
		 */
		MessageBody* GetBody() const { return m_Body; }
	};
}
