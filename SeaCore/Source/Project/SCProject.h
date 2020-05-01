#pragma once
#include <string>

#include "Objects/GameObject.h"
#include "Scene/SceneManager.h"
#include "Scene/Scene.h"

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
	protected:
		explicit SCProject(const ProjectSettings& projectSettings);
		virtual ~SCProject() = default;

	public:
		virtual void Load() = 0;
		
	private:
		ProjectSettings m_ProjectSettings;
	};

}
