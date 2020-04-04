#pragma once
#include <unordered_set>

namespace sea_core
{
	class BaseComponent;
	
	/*
	 * 
	 */
	class Broadcaster final
	{
	protected:
		explicit Broadcaster(const char* name);
	public:
		~Broadcaster() = default;
		
		void AddComponent(BaseComponent* pMessageComponent);
		void EraseComponent(BaseComponent* pMessageComponent);
		void Send(const unsigned int message) const;
		
	private:		
		std::unordered_set<BaseComponent*> m_Components;
	};
}
