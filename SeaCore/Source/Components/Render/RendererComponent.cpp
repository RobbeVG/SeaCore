#include "SeaCore_pch.h"
#include "RendererComponent.h"

#include "Time/Time.h"

sea_core::RendererComponent::RendererComponent()
    : m_IsEnabled(true)
	, m_IsVisible(true)
{
}

//void sea_core::RendererComponent::UpdateComponent()
//{
//	if (m_IsEnabled)
//		Update();
//}

void sea_core::RendererComponent::RenderComponent()
{
	if (m_IsEnabled && m_IsVisible)
		Render();
}
