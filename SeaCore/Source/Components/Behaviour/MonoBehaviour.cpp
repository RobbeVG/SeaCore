#include "SeaCore_pch.h"
#include "MonoBehaviour.h"

#include "Messages.h"
#include "Messaging/Message/Event.h"
#include "Messaging/Endpoint.h"
//#include "Components/Messaging/Messages.h"


//https://stackoverflow.com/questions/44540747/what-is-the-difference-between-component-behaviour-and-monobehaviour-and-why-t


sea_core::MonoBehaviour::MonoBehaviour()
	: BehaviourComponent()
{
	m_Endpoint = new Endpoint();
}

//void sea_core::MonoBehaviour::SetEnabled(bool enabled)
//{
//	//if (m_IsEnabled != enabled)
//	//BehaviourComponent::SetEnabled(enabled);
//}

void sea_core::MonoBehaviour::SetParent(GameObject* pParent)
{
	GameObject* currentParent = GetParent();
	if (currentParent)
		currentParent->GetMonoBehaviourChannel()->UnSubscribe(m_Endpoint);
	BaseComponent::SetParent(pParent);
	pParent->GetMonoBehaviourChannel()->Subscribe(m_Endpoint);
}

void sea_core::MonoBehaviour::HandleMessages()
{
	std::queue<Message*>& messages = m_Endpoint->GetMessages();
	while (!messages.empty())
	{
		Message* pMessage = messages.front();
		if (pMessage->HasBody())
		{
			EventData* pEventData = pMessage->GetBody()->GetEventData();
			if (pEventData && (ConvertEnum<EventMessages::Types>(pEventData->type) == EventMessages::Types::MonoBehaviour))
			{
				switch (ConvertEnum<EventMessages::MonoBehaviour>(pEventData->state)) {
				case EventMessages::MonoBehaviour::OnEnable:
					OnEnable();
					break;
				case EventMessages::MonoBehaviour::OnDisable:
					OnDisable();
					break;
				case EventMessages::MonoBehaviour::OnStart:
					OnStart();
					break;
				case EventMessages::MonoBehaviour::OnCollisionEnter:
					OnCollisionEnter();
					break;
				case EventMessages::MonoBehaviour::OnCollisionExit:
					OnCollisionExit();
					break;
				default:
					break;
				}
			}
		}

		delete pMessage;
		messages.pop();
	}
}
