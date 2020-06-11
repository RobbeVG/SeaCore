#pragma once

#include "../Channel.h"
namespace sea_core
{
	namespace MessagingChannel
	{
		class PointToPoint : virtual public Channel
		{
		public:
			explicit PointToPoint() = default;
			explicit PointToPoint(Receiver* pReceiver);
			/*
			 * Sets the current receiver.
			 * If receiver is not found in the connections it will automatically be added to the connections
			 */
			void SetReceiver(Receiver* pReceiver);
			
		protected:
			virtual inline void SendMessage(Message* message) override;

			Receiver* m_pReceiver;
		};
	}
}
