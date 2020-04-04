#include <MiniginPCH.h>

#include "GameObject.h"

#include "../Components/Transform.h"
#include "../Components/Render/RenderComponent.h"
#include "../Graphics/Renderer.h"
#include "../Graphics/Texture2D.h"
#include "../Resources/ResourceManager.h"

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
	for (const RenderComponent* renderComponent : m_RenderComponents)
	{
		delete renderComponent;
	}
}

void sea_core::GameObject::Update(const float deltaSeconds)
{
	for (BaseComponent* component : m_Components)
	{
		component->Update(deltaSeconds);
	}
}

void sea_core::GameObject::Render(const float deltaSeconds) const
{
	for (const RenderComponent* const renderComponent : m_RenderComponents)
	{
		renderComponent->Render(deltaSeconds);
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
