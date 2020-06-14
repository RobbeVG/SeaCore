// ReSharper disable CppInconsistentNaming
#pragma once
#include <chrono>
#include <ctime>
#include "Helpers/Singleton.h"

//#include "SeaCore.h"

namespace sea_core
{
	//Access variable to the current time!
	//Singleton was an option but would make it harder to read : GameTime::GetInstance().GetFramesPerSecond() - Time.GetFramesPerSecond()
	//Anonymous class

	class StaticTime : public Singleton<StaticTime>
	{
		struct DeltaTime
		{
			DeltaTime()
				: deltaTime(0.0f)
				, fixedDeltaTime(0.2f)
				, timeScale(1.0f)
			{}

			void SetDeltaTime(const float deltaT) { deltaTime = deltaT; }
			void SetTimeScale(const float timeS) { timeScale = timeS; }

			float deltaTime;
			float fixedDeltaTime;
			float timeScale;
		} m_DeltaTime;

		struct FpsTime
		{
			FpsTime()
				: m_FpsTimer(0.0f)
				, m_FramesPerSecondsCounter(0)
				, m_FramesPerSeconds(0)
			{}

			void UpdateFps(const float deltaTime)
			{
				m_FpsTimer += deltaTime;
				++m_FramesPerSecondsCounter;
				if (m_FpsTimer >= 1.0f)
				{
					m_FramesPerSeconds = m_FramesPerSecondsCounter;
					m_FramesPerSecondsCounter = 0;
					m_FpsTimer -= 1.0f;
				}
			}
			short unsigned int GetFramesPerSeconds() const { return m_FramesPerSeconds; }

		private:
			float m_FpsTimer;
			short unsigned int m_FramesPerSecondsCounter;
			short unsigned int m_FramesPerSeconds;
		} m_FpsTime;


		void SetPercentageNextFrame(const float percentageNextFrame) { m_PercentageNextFrame = percentageNextFrame; }
		float m_PercentageNextFrame = 0.0f;

	public:
		StaticTime() = default;

		static std::chrono::steady_clock::time_point Now() { return std::chrono::high_resolution_clock::now(); }

		//Getters
			// Delta Time
			/*
			 * @Brief Get Scaled DeltaTime
			 */
		float GetDeltaTime() const { return m_DeltaTime.deltaTime * m_DeltaTime.timeScale; }
		/*
		 * @Brief Get Scaled FixedDeltaTime
		 */
		float GetFixedDeltaTime() const { return m_DeltaTime.fixedDeltaTime * m_DeltaTime.timeScale; }
		/*
		 * @Brief Get Unscaled DeltaTime
		 */
		float GetUnscaledDeltaTime() const { return m_DeltaTime.deltaTime; }
		/*
		 * @Brief Get Unscaled FixedDeltaTime
		 */
		float GetUnscaledFixedDeltaTime() const { return m_DeltaTime.fixedDeltaTime; }
		/*
		 * @Brief Get time scale
		 */
		float GetTimeScale() const { return m_DeltaTime.timeScale; }

		// Fps Time
		/*
		 * @Brief Get the amount of FPS
		 */
		short unsigned int GetFramesPerSeconds() const { return m_FpsTime.GetFramesPerSeconds(); }

		// Excess Time
		/*
		 * @Brief Get the percentage into next frame. Mainly used for render
		 */
		float GetPercentageNextFrame() const { return m_PercentageNextFrame; }

		//Setters
			/*
			 * @Brief Set the time scale
			 */
		void SetTimeScale(const float timeScale = 1.0f) { m_DeltaTime.timeScale = timeScale; }

	private:
		friend class SeaCore;
	};
	
	struct
	{
	public:
		StaticTime& operator()() const { return StaticTime::GetInstance(); }
		//static StaticTime& Time() { return StaticTime::GetInstance(); };
	} Time;
}
