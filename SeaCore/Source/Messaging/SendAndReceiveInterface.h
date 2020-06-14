#pragma once
#undef SendMessage

namespace sea_core
{
	class Message;
	
	class Receiver
	{
	public:
		virtual ~Receiver() = default;
		virtual inline void ReceiveMessage(Message* pMessage) = 0;
	protected:
		Receiver() = default;
	};

	class Sender
	{
	public:
		virtual ~Sender() = default;
		virtual inline void SendMessage(Message* pMessage) = 0;
	protected:
		Sender() = default;
	};
}

//template <typename MessageType>
//class Receiver
//{
//public:
//	template<typename MessageType>
//	using Inbox = std::vector<MessageType>;
//
//	virtual ~Receiver() = default;
//
//protected:
//	Receiver() = default;
//	//virtual void HandleMessage(MessageType message) = 0;
//	virtual void HandleMessages() = 0;
//	inline void ClearMessages() { m_Messages.clear(); }
//	const Inbox<MessageType>& GetMessages() const { return m_Messages; }
//
//private:
//	Inbox<MessageType> m_Messages;
//};
//
//template <typename MessageType>
//struct Message
//{
//	//void* m_Sender;
//	Receiver<MessageType>* m_Destination;
//	MessageType data;
//};