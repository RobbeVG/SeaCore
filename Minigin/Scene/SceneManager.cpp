#include "MiniginPCH.h"
#include "SceneManager.h"
#include "../Base/Scene.h"

void sea_core::SceneManager::Update(float deltaSecond)
{
	for(auto& scene : m_Scenes)
	{
		scene->Update(deltaSecond);
	}
}

void sea_core::SceneManager::Render(float deltaSecond)
{
	for (const auto& scene : m_Scenes)
	{
		scene->Render(deltaSecond);
	}
}

sea_core::Scene& sea_core::SceneManager::CreateScene(const std::string& name)
{
	const auto scene = std::shared_ptr<Scene>(new Scene(name));
	m_Scenes.push_back(scene);
	return *scene;
}
