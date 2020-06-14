#pragma once
#include "SendAndReceiveInterface.h"

/*
 * Connections = 0?
 * Receiver is invalid due to remove
 *
 * Some channels could have more connections then receivers.
 * This functionality was not necessary yet so I left it out
 */

namespace sea_core
{
	//class Channel : public Sender
	//{

	//};

	typedef Sender Channel;

	
	//{
	//protected:
	//	Channel() = default;

	//public:
	//	inline const std::unordered_set<const Receiver*>& GetConnections() const { return m_Connections; }
	//	
	//protected:
	//	virtual void AddConnection(const Receiver* const pReceiver) { assert(pReceiver == nullptr); m_Connections.insert(pReceiver); }
	//	virtual void RemoveConnection(const Receiver* const pReceiver) { m_Connections.erase(pReceiver); }
	//	
	//	std::unordered_set<const Receiver*> m_Connections; //error C2338: The C++ Standard forbids containers of const elements because allocator<const T> is ill-formed :: std::unordered_set<const Receiver* const>
	//};
}
