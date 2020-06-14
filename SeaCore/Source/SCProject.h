#pragma once
#include <string>

namespace sea_core
{
	struct ProjectSettings
	{
		struct WindowSettings
		{
			WindowSettings()
				: Width(1280)
				, Height(720)
				, Title("SeaCore Project")
			{}
			WindowSettings(const unsigned int width, const unsigned int height, const std::string& title)
				: Width(width)
				, Height(height)
				, Title(title)
			{}

			unsigned int Width;
			unsigned int Height;
			std::string Title;
		} windowSettings;
	};

	class SCProject
	{
	public:
		virtual ~SCProject() = default;
		
	protected:
		explicit SCProject(const ProjectSettings& projectSettings);

	public:
		virtual void Load() = 0;
		/**
		 * @brief Try and only use this for debugging.
		 */
		virtual void Update() {}
		
	private:
		ProjectSettings m_ProjectSettings;
	};
}