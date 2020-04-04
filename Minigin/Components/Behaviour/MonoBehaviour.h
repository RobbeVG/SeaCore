#pragma once
#include "BehaviourComponent.h"

namespace sea_core
{
	//https://jacksondunstan.com/articles/3992
	
	class MonoBehaviour : public BehaviourComponent
	{
	public:
		explicit MonoBehaviour(const char* broadcasterName);
	protected:
		virtual void OnDisable() {}
		virtual void OnEnable() {}
		virtual void OnCollisionEnter() {}
		virtual void OnCollisionExit() {}
		virtual void OnBeginPlay() {}
		virtual void Update(const float deltaSeconds) override = 0;
		
	private:
		void ReceiveMessage(const unsigned message) override final;
	};
}
 