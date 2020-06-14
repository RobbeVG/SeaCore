#include "SeaCore_pch.h"
#include "Transform.h"

sea_core::Transform::Transform(GameObject* pParent)
	: m_Position(0.0f, 0.0f)
	, m_Scale(1.0f, 1.0f)
{
	BaseComponent::SetParent(pParent);
}

sea_core::Transform::~Transform()
{
}

void sea_core::Transform::SetPosition(float x, float y)
{
	m_Position.x = x;
	m_Position.y = y;
}

void sea_core::Transform::SetScale(float x, float y)
{
	m_Scale.x = x;
	m_Scale.y = y;
}

void sea_core::Transform::SetRotation(float degrees)
{
	m_RotationAngle = degrees;
}
