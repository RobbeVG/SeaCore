#pragma once
#include "BehaviourComponent.h"
namespace sea_core
{
	//https://jacksondunstan.com/articles/3992
	
	class MonoBehaviour : public BehaviourComponent
	{
	protected:
		void UpdateBehaviour(const float deltaSeconds) override;

		
	};
}
