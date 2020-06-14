#pragma once
#include "SendAndReceiveInterface.h"

namespace sea_core
{
	class MessageBodyManager;

	enum class MessageType : uint8_t
	{
		Event,
		Command,
		Document
	};

	struct EventData
	{
		unsigned short type;
		unsigned short state;
	};

	struct MessageHeader
	{
		MessageHeader(Sender* pSender, Receiver* pDestination)
			: pOrigin(pSender)
			, pDestination(pDestination)
		{}

		//const Sender* pOriginalOrigin;
		Sender* pOrigin;
		Receiver* pDestination;
	};

	class MessageBody
	{
	public:
		EventData* GetEventData() const { if (type == MessageType::Event) return static_cast<EventData*>(pData); return nullptr; };

		void* GetData() const { return pData; }
		
	private:
		friend MessageBodyManager;
		
		MessageBody(const MessageType type, void* pData, const unsigned int size, const unsigned int alignment)
			: type(type)
			, size(size)
			, alignment(alignment)
			, pData(pData)
		{}
		
		~MessageBody()
		{
			delete GetEventData();
		}

		MessageType type;
		unsigned int size;
		unsigned int alignment;
		void* const pData;
	};
}
