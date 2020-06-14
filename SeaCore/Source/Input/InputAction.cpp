#include "SeaCore_pch.h"
#include "InputAction.h"

bool InputAction::operator==(const InputAction& other) const
{
	return m_ActionId == other.m_ActionId;
}

bool InputAction::operator<(const InputAction& other) const
{
	return m_ActionId < other.m_ActionId;
}
