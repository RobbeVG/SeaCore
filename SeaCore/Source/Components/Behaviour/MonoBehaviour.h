#pragma once
#include "BehaviourComponent.h"

namespace sea_core
{
	//https://jacksondunstan.com/articles/3992
	
	class MonoBehaviour : public BehaviourComponent
	{
	public:
		explicit MonoBehaviour();
		virtual ~MonoBehaviour() override = default;
		
	protected:
		virtual void OnDisable() {}
		virtual void OnEnable() {}
		virtual void OnCollisionEnter() {}
		virtual void OnCollisionExit() {}
		virtual void Start() {}
		virtual void Update(const float deltaSeconds) override = 0;
		virtual void FixedUpdate() {}
		virtual void LateUpdate() {}

		
	private:
		void ReceiveMessage(const unsigned message) override final;
	};
}
 