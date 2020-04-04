#include "SeaCore_pch.h"
#include "SceneManager.h"
#include "../Scene/Scene.h"

sea_core::SceneManager::~SceneManager()
{
	for (Scene* scene : m_Scenes)
	{
		delete scene;
	}
}

void sea_core::SceneManager::Update(float deltaSecond)
{
	for (auto& scene : m_Scenes)
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
	Scene* scene = new Scene(name);
	m_Scenes.push_back(scene);
	return *scene;
}
