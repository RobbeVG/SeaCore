#include "SeaCore_pch.h"
#include "SceneManager.h"
#include "Scene.h"
//#include "Helpers/Time.h"

//sea_core::SceneManager::SceneManager()
//	: m_ActiveScene(nullptr)
//	, m_IdCounter(0)
//{
//}

sea_core::SceneManager::~SceneManager()
{
	for (std::pair<const unsigned, Scene*> scene : m_Scenes)
	{
		delete scene.second;
	}
}

sea_core::Scene& sea_core::SceneManager::CreateScene(const std::string& name)
{
	const unsigned int id = m_IdCounter++;
	Scene* scene = new Scene(name, id);
	m_Scenes[id] = scene;
	return *scene;
}

//void sea_core::SceneManager::AddScene(Scene* pScene)
//{
//	if (!pScene)
//		return;
//	unsigned int currentId = pScene->GetId();
//	//Check if scene exist with this id?
//	GetScene()
//	
//}

/*
 * If no scene is active, thus none is created yet. Then create one yourself
 * 
 */
sea_core::Scene& sea_core::SceneManager::GetActiveScene()
{
	if (m_ActiveScene)
		return *m_ActiveScene;
	if (m_Scenes.empty())
		CreateScene("DefaultScene");
	SetActiveScene((*m_Scenes.begin()).second);
	return *m_ActiveScene;
}

bool sea_core::SceneManager::ActivateNextScene()
{
	return ActivateScene(GetActiveScene().GetId() + 1);
}

bool sea_core::SceneManager::ActivatePreviousScene()
{
	return ActivateScene(GetActiveScene().GetId() - 1);
}

bool sea_core::SceneManager::ActivateScene(const unsigned int id)
{
	if (Scene* scene = GetScene(id))
	{
		SetActiveScene(scene);
		return true;
	}
	return false;
}

void sea_core::SceneManager::SetActiveScene(Scene* pScene)
{
	m_ActiveScene = pScene;
	//Time.
	//Timem_pCurrentSceneTime = &pScene->GetTime();
}

sea_core::Scene* sea_core::SceneManager::GetScene(unsigned id)
{
	const std::map<unsigned int, Scene*>::const_iterator it = m_Scenes.find(id);
	if (it != m_Scenes.end())
		return (*it).second;
	return nullptr;
}
