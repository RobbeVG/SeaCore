#include "SeaCore_pch.h"
#include "../Messaging/Messages/MonoBehaviourMessages.h"
#include "MonoBehaviour.h"


//https://stackoverflow.com/questions/44540747/what-is-the-difference-between-component-behaviour-and-monobehaviour-and-why-t


sea_core::MonoBehaviour::MonoBehaviour(const char* broadcasterName)
{
	AssignBroadcaster(broadcasterName);
}

void sea_core::MonoBehaviour::ReceiveMessage(const unsigned message)
{
	const Messages::MonoBehaviour enumMessage = Messages::MonoBehaviour(message);
	switch (enumMessage) {
		case Messages::OnEnable:
			OnEnable();
			break;
		case Messages::OnDisable:
			OnDisable();
			break;
		case Messages::OnBeginPlay:
			OnBeginPlay();
			break;
		case Messages::OnCollisionEnter:
			OnCollisionEnter();
			break;
		case Messages::OnCollisionExit:
			OnCollisionExit();
			break;
		default: ;
	}
}
