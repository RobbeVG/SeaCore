#include <SeaCore_pch.h>
#include "GameObject.h"

#include "Components/Transform.h"
#include "Messages.h"
#include "Messaging/Message.h"
#include "Time/Time.h"

sea_core::GameObject::GameObject()
	: m_Components()
{
	m_pTransform = new Transform(this);

	m_pMonoBehaviourChannel = new MessagingChannel::Bus();
}

sea_core::GameObject::~GameObject()
{
	delete m_pTransform;
	for (BaseComponent* component : m_Components)
	{
		delete component;
	}
	delete m_pMonoBehaviourChannel;
}

void sea_core::GameObject::Update()
{
	for (BaseComponent* component : m_Components)
	{
		component->UpdateComponent();
	}

}

void sea_core::GameObject::LateUpdate()
{
	//for (BaseComponent* component : m_Components)
	//{
	//	component->LateUpdateComponent();
	//}
}

void sea_core::GameObject::Start()
{
	Message* pMessage = new Message(nullptr, nullptr);
	using namespace EventMessages;
	pMessage->CreateEventMessage(EventData{ ConvertEnum(Types::MonoBehaviour), ConvertEnum(MonoBehaviour::OnStart) });

	m_pMonoBehaviourChannel->SendMessage(pMessage);
	
	//m_pMonoBehaviourChannel->SendMessage(new MessagingMessages::Event(m_pMonoBehaviourChannel, nullptr, Messages::Convert(Messages::MonoBehaviour::OnStart)));
	
	//for (BaseComponent* component : m_Components)
	//{
	//	component->StartComponent();
	//}
}

void sea_core::GameObject::Render() const
{
	for (BaseComponent* component : m_Components)
	{
		component->RenderComponent();
	}
}

void sea_core::GameObject::FixedUpdate()
{
	for (BaseComponent* component : m_Components)
	{
		component->FixedUpdateComponent();
	}
}

void sea_core::GameObject::SetPosition(const float x, const float y) const
{
	GetTransform()->SetPosition(x, y);
}

//Use attachToContainer for the correct component to appropriate container 
//void sea_core::GameObject::AddComponent(RenderComponent* pRenderComponent)
//{
//	m_RenderComponents.push_back(pRenderComponent);
//}
void sea_core::GameObject::AddComponent(BaseComponent* component)
{
	if (m_Components.find(component) != m_Components.end())
		return;

	m_Components.insert(component);

	if (component->GetParent() != this)
		component->AttachToParent(this);
}

