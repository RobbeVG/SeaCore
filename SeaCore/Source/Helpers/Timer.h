#pragma once
#include "EnumHelpers.h"

namespace sea_core
{
	enum class TimerFlags : unsigned char
	{
		None = 0,
		Enabled = 1,
		Loop = 2,
		Reverse = 4
	};
	ENUM_FLAGS(TimerFlags);

	class Timer
	{
	public:
		explicit Timer(const float totalTime = 1.0f);

		void Reset() { m_CurrentTime = 0.0f; };
		void Update(const float deltaTime);
		void SetEnabled(const bool value) { m_Flags &= ~TimerFlags::Enabled; m_Flags |= TimerFlags(value); }
		void SetLoop(const bool value) { m_Flags &= ~TimerFlags::Loop; m_Flags |= TimerFlags(value << 1); }
		void SetReverse(const bool value) { m_Flags &= ~TimerFlags::Reverse; m_Flags |= TimerFlags(value << 2); }

		bool IsEnded() const { return m_CurrentTime > m_TotalTime || m_CurrentTime < 0.0f; };
		bool IsEnabled() const { return (m_Flags & TimerFlags::Enabled) == TimerFlags::Enabled; }
		bool IsLooped() const { return (m_Flags & TimerFlags::Loop) == TimerFlags::Loop; }
		bool IsReversed() const { return (m_Flags & TimerFlags::Reverse) == TimerFlags::Reverse; }
		float GetPercentage() const;

	private:
		TimerFlags m_Flags;

		float m_CurrentTime;
		float m_TotalTime;
	};
}
