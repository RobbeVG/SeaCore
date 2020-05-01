#include "SeaCore_pch.h"
#include "MonoBehaviour.h"

#include "Components/Messaging/Messages.h"


//https://stackoverflow.com/questions/44540747/what-is-the-difference-between-component-behaviour-and-monobehaviour-and-why-t


sea_core::MonoBehaviour::MonoBehaviour()
{
	m_pBroadcaster->Subscribe(this);
}

void sea_core::MonoBehaviour::ReceiveMessage(const unsigned message) 
{
	const Messages::MonoBehaviour enumMessage = Messages::MonoBehaviour(message);
	switch (enumMessage) {
		case Messages::MonoBehaviour::OnEnable:
			OnEnable();
			break;
		case Messages::MonoBehaviour::OnDisable:
			OnDisable();
			break;
		case Messages::MonoBehaviour::Start:
			Start();
			break;
		case Messages::MonoBehaviour::OnCollisionEnter:
			OnCollisionEnter();
			break;
		case Messages::MonoBehaviour::OnCollisionExit:
			OnCollisionExit();
			break;
		default:
			break;
	}
}
