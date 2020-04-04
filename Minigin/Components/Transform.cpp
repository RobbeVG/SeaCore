#include "MiniginPCH.h"
#include "Transform.h"

sea_core::Transform::Transform()
	: m_Position(0.0f, 0.0f, 0.0f)
{
}

sea_core::Transform::~Transform()
{
}

void sea_core::Transform::UpdateComponent(float)
{
}

void sea_core::Transform::SetPosition(float x, float y, float z)
{
	m_Position.x = x;
	m_Position.y = y;
	m_Position.z = z;
}
