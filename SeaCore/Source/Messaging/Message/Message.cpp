#include "SeaCore_pch.h"
#include "../Message.h"

#include "MessageBodyManager.h"

sea_core::Message::~Message()
{
	MessageBodyManager::GetInstance().DetachBody(*this);
}

sea_core::Message::Message(const Message& other)
	: m_Header(other.m_Header)
	, m_Body(nullptr)
{
	MessageBodyManager::GetInstance().AttachBody(*this, other);
}

sea_core::Message::Message(Message&& other) noexcept
	: m_Header(std::move(other.m_Header))
	, m_Body(other.m_Body)
{
	other.m_Body = nullptr;
}

sea_core::Message& sea_core::Message::operator=(const Message& other)
{
	if (&other != this)
	{
		m_Header = other.m_Header;
		MessageBodyManager::GetInstance().AttachBody(*this, other);
	}
	return *this;
}

sea_core::Message& sea_core::Message::operator=(Message&& other) noexcept
{
	if (&other != this)
	{
		m_Header = std::move(other.m_Header);
		m_Body = other.m_Body;
		other.m_Body = nullptr;
	}
	return *this;
}

void sea_core::Message::CreateEventMessage(const EventData& eventData)
{
	EventData* newData = new EventData{ eventData.type, eventData.state };
	MessageBodyManager::GetInstance().AttachBody(*this, MessageType::Event, newData, sizeof(EventData), alignof(EventData));
}
