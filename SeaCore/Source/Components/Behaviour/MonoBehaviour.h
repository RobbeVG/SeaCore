#pragma once
#include "BehaviourComponent.h"
#include "../Physics/PhysicsComponent.h"

namespace sea_core
{
	//https://jacksondunstan.com/articles/3992
	
//DIAMOND PROBLEM
	class MonoBehaviour : public BehaviourComponent, public PhysicsComponent
	{
	public:
		explicit MonoBehaviour();
		virtual ~MonoBehaviour() override = default;

		virtual void UpdateComponent() override { HandleMessages(); BehaviourComponent::UpdateComponent(); }
		virtual void FixedUpdateComponent() override { PhysicsComponent::FixedUpdateComponent(); }
			
	protected:
		//Messages called functions
		virtual void OnStart() {}
		virtual void OnEnable() {}
		virtual void OnDisable() {}
		virtual void OnCollisionEnter() {}
		virtual void OnCollisionExit() {}

		//Base functions
		virtual void Update() override {}
		virtual void FixedUpdate() override {}
		virtual void LateUpdate() {}

	private:

		void SetParent(GameObject* pParent) override final;
		
		void HandleMessages();
	};
}
 