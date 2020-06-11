#pragma once
#include <deque>


namespace sea_core
{
	class Channel;
	class Sender;
	class Receiver;

	enum class MessageType : uint8_t
	{
		Command,
		Event,
		Document
	};

	struct MessageHeader
	{
		MessageHeader(const MessageType type, const Sender* pOrigin, Receiver* pDestination, const size_t size, const size_t alignment)
			: pOrigin(pOrigin)
			, pDestination(pDestination)
			, size(size)
			, alignment(alignment)
			, type(type)
		{}

		//const Sender* pOriginalOrigin;
		const Sender* pOrigin;
		std::deque<Channel*> pPassingChannels;
		Receiver* pDestination;

		//TODO Timestamp
		
		size_t size;
		size_t alignment;
		MessageType type;
	};

	
	class Message
	{
	protected:
		explicit Message(const MessageType type, const Sender* pSender, Receiver* pDestination, const size_t size, const size_t alignment)
			: m_Header(type, pSender, pDestination, size, alignment)
		{}
		
	public:
		virtual ~Message() = default;

		const MessageHeader& GetHeader() const { return m_Header; }
		void SetReceiver(Receiver* pReceiver) { m_Header.pDestination = pReceiver; };

		
		virtual const void* GetData() const = 0;
		virtual bool IsValid() const { return GetData() != nullptr;}
		
	protected:
		MessageHeader m_Header;
	};
}
