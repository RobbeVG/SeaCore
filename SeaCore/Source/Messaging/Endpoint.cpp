#include "SeaCore_pch.h"
#include "Endpoint.h"

#include "Message.h"

sea_core::Endpoint::~Endpoint()
{
	while (!m_pMessages.empty())
	{
		delete m_pMessages.front();
		m_pMessages.pop();
	}
}
