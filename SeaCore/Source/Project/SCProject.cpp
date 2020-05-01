#include "SeaCore_pch.h"
#include "SCProject.h"

sea_core::SCProject::SCProject(const ProjectSettings& projectSettings)
	: m_FixedDeltaTime(0.2f)
	, m_ProjectSettings(projectSettings)
{
}
