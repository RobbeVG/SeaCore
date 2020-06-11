#include "SeaCore_pch.h"
#include "Transform.h"

sea_core::Transform::Transform(GameObject* pParent)
	: m_Position(0.0f, 0.0f, 0.0f)
{
	SetParent(pParent);
}

sea_core::Transform::~Transform()
{
}

void sea_core::Transform::SetPosition(float x, float y, float z)
{
	m_Position.x = x;
	m_Position.y = y;
	m_Position.z = z;
}
