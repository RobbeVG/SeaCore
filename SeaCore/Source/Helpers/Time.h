// ReSharper disable CppInconsistentNaming
#pragma once
#include <chrono>
#include <ctime>
#include "SeaCore.h"

namespace sea_core
{
	//Access variable to the current time!
	//Singleton was an option but would make it harder to read : GameTime::GetInstance().GetFramesPerSecond() - Time.GetFramesPerSecond()
	//Anonymous class
	
	static class
	{
		//		struct StartUpTime
		//		{
		//			std::time_t timeAtStartUp = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
		//			float timeSinceStartup = 0.0f;
		//		} m_StartUpTime;
		//#pragma region StartUpTime
		//		/*
		//		 * @Brief Get the time_t at the start of loading the project
		//		 */
		//		std::time_t GetTimeAtStartUp() const { return m_StartUpTime.timeAtStartUp; }
		//		/*
		//		 * @Brief Get passed time since the start of the project
		//		 */
		//		float GetTimeSinceStartup() const { return m_StartUpTime.timeSinceStartup; }
		//#pragma endregion 

		struct DeltaTime
		{
			float deltaTime = 0.0f;
			float fixedDeltaTime = 0.2f;
			float timeScale = 1.0f;
		} m_DeltaTime;

		struct FpsTime
		{
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
			float m_FpsTimer = 0.0f;
			short unsigned int m_FramesPerSecondsCounter = 0;
			short unsigned int m_FramesPerSeconds = 0;
		} m_FpsTime;

		float m_PercentageNextFrame = 0.0f;

	public:

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
	} Time;
}
