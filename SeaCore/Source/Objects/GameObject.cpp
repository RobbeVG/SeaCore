#include <SeaCore_pch.h>

#include "GameObject.h"

#include "../Components/Transform.h"
#include "../Components/Render/RendererComponent.h"

sea_core::GameObject::GameObject()
	: m_Components()
{
	m_Components.push_back(new Transform());
}

sea_core::GameObject::~GameObject()
{
	for (BaseComponent* component : m_Components)
	{
		delete component;
	}
	for (const RendererComponent* renderComponent : m_RenderComponents)
	{
		delete renderComponent;
	}
}

void sea_core::GameObject::Update(const float deltaSeconds)
{
	for (BaseComponent* component : m_Components)
	{
		component->UpdateComponent(deltaSeconds);
	}
	for (RendererComponent* component : m_RenderComponents)
	{
		component->UpdateComponent(deltaSeconds);
	}
}

void sea_core::GameObject::Render(const float deltaSeconds) const
{
	for (const RendererComponent* const component : m_RenderComponents)
	{
		component->RenderComponent(deltaSeconds);
	}
	
	const auto pos = GetTransform()->GetPosition();
}

void sea_core::GameObject::SetPosition(const float x, const float y) const
{
	GetTransform()->SetPosition(x, y, 0.0f);
}

//Use attachToContainer for the correct component to appropriate container 
//void sea_core::GameObject::AddComponent(RenderComponent* pRenderComponent)
//{
//	m_RenderComponents.push_back(pRenderComponent);
//}
void sea_core::GameObject::AddComponent(BaseComponent* component)
{
	component->m_pParent = this;
	component->AttachToContainer(m_Components, m_RenderComponents);
}

sea_core::Transform* sea_core::GameObject::GetTransform() const
{
	return static_cast<Transform*>(m_Components.front());
}
