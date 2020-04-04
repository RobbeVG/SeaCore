#include "MiniginPCH.h"
#include "RenderComponent.h"

sea_core::RenderComponent::RenderComponent()
    : m_IsEnabled(true)
	, m_IsVisible(true)
{
}

void sea_core::RenderComponent::Update(const float deltaSeconds)
{
	if (m_IsEnabled)
		UpdateRender(deltaSeconds);
}

void sea_core::RenderComponent::Render(const float deltaSeconds) const
{
	if (m_IsEnabled && m_IsVisible)
		DerivedRender(deltaSeconds);
}
