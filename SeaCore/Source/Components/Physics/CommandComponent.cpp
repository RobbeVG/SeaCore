#include "SeaCore_pch.h"
#include "CommandComponent.h"
#include "Components/Transform.h"
#include "Time/Time.h"

void sea_core::CommandComponent::Update()
{
	while (!m_Commands.empty())
	{
		m_Commands.front()->Execute();
		m_Commands.pop();
	}
}
