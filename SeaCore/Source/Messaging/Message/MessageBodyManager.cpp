#include "SeaCore_pch.h"
#include "MessageBodyManager.h"


sea_core::MessageBodyManager::~MessageBodyManager()
{
	for (std::pair<MessageBody* const, unsigned> dataReference : m_MessageDataReferences)
	{
		delete dataReference.first;
	}
}

void sea_core::MessageBodyManager::AttachBody(Message& message, const MessageType type, void* pData, const unsigned size, const unsigned alignment)
{
	DetachBody(message);
	
	MessageBody* pBody = new MessageBody(type, pData, size, alignment);
	m_MessageDataReferences[pBody] = 1;
	message.m_Body = pBody;
}

void sea_core::MessageBodyManager::AttachBody(Message& message, const Message& otherBody)
{
	DetachBody(message);
	
	if (otherBody.HasBody())
	{
		MessageBody* pBody = otherBody.GetBody();
		m_MessageDataReferences[pBody]++;
		message.m_Body = pBody;
	}
}

void sea_core::MessageBodyManager::DetachBody(Message& message)
{
	if (message.HasBody())
	{
		MessageBody* pMessageBody = message.GetBody();
		m_MessageDataReferences[pMessageBody]--;

		if (m_MessageDataReferences[pMessageBody] <= 0)
		{
			m_MessageDataReferences.erase(pMessageBody);
			delete pMessageBody;
		}

		message.m_Body = nullptr;
	}
}
