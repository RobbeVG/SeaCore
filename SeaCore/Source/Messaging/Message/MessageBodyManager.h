#pragma once
#include <map>

#include "Helpers/Singleton.h"
#include "../Message.h"


/**
 * @brief Mapping the message data
 */

namespace sea_core
{
	class MessageBodyManager : public Singleton<MessageBodyManager>
	{
	public:
		~MessageBodyManager();
		
		void AttachBody(Message& message, const MessageType type, void* pData, const unsigned int size, const unsigned int alignment);
		void AttachBody(Message& message, const Message& otherBody);
		void DetachBody(Message& message);
		
	private:		
		std::map<MessageBody*, unsigned int> m_MessageDataReferences;
	};
}

