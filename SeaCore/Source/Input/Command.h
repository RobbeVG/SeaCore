#pragma once
#include <functional>
namespace sea_core
{
	class Command
	{
	public:
		virtual ~Command() = default;
		virtual void Execute() = 0;
	};
}
