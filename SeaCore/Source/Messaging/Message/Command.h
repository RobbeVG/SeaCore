#pragma once
#include "../Message.h"
#include <functional>


//TODO expand to variadic arguments!
//https://stackoverflow.com/questions/16868129/how-to-store-variadic-template-arguments

namespace sea_core
{
	namespace MessagingMessages
	{
		//template<typename ReturnType, typename ... ArgTypes>
		//class CommandFunction;
		////typedef ReturnType(*)(ArgTypes);
		
		class Command : public Message
		{
			//static_assert(std::is_function_v<decltype(Function)>, "Command message needs a function as a parameter");
		public:
			Command(const Sender* const pSender, const Reader* const pDestination, void (*pFunction)())
				: Message(MessageType::Command, pSender, pDestination, sizeof(void (*)()), alignof(void (*)())),
				  m_pFunction(pFunction)
			{}

			const void* GetData() const override { return m_pFunction; }

			void Execute() const { m_pFunction(); }

		private:
			void (*m_pFunction)();
		};

	}
}