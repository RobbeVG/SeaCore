#include "MiniginPCH.h"
#include "RendererComponent.h"

sea_core::RendererComponent::RendererComponent()
    : m_IsEnabled(true)
	, m_IsVisible(true)
{
}

void sea_core::RendererComponent::UpdateComponent(const float deltaSeconds)
{
	if (m_IsEnabled)
		Update(deltaSeconds);
}

void sea_core::RendererComponent::RenderComponent(const float deltaSeconds) const
{
	if (m_IsEnabled && m_IsVisible)
		Render(deltaSeconds);
}
