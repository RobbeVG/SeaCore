#include "SeaCore_pch.h"
#include "Timer.h"

sea_core::Timer::Timer(const float totalTime)
	: m_Flags(TimerFlags::Enabled)
	, m_CurrentTime(0.0f)
	, m_TotalTime(totalTime)
{
}


void sea_core::Timer::Update(const float deltaTime)
{
	if ((m_Flags & (TimerFlags::Enabled | TimerFlags::Reverse)) == (TimerFlags::Enabled | TimerFlags::Reverse))
		m_CurrentTime -= deltaTime;
	else
		m_CurrentTime += deltaTime;
	
	if (IsEnded())
	{
		if (IsLooped())
			m_Flags ^= TimerFlags::Reverse;
		else
			SetEnabled(false);
	}
}

float sea_core::Timer::GetPercentage() const
{
	float percentage = m_CurrentTime / m_TotalTime;
	if (percentage > 1.0f)
		percentage = 1.0f;
	else if (percentage < 0.0f)
		percentage = 0.0f;
	return percentage;
}
