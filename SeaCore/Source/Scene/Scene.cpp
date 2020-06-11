#include "SeaCore_pch.h"
#include "Scene.h"
#include "SceneObject.h"

#include "Time/Time.h"

using namespace sea_core;

Scene::Scene(const std::string& name, unsigned int id)
	: m_Name(name)
	, m_Id(id)
	, m_LoadingState(LoadingState::NotLoaded)
{}

Scene::~Scene()
{
	//delete m_Time;
	for (SceneObject* object : m_Objects)
	{
		delete object;
	}
}

void Scene::Add(SceneObject* object)
{
	m_Objects.push_back(object);
}

void Scene::Start()
{
	for (auto& object : m_Objects)
	{
		object->Start();
	}
}

void Scene::FixedUpdate()
{
	for (auto& object : m_Objects)
	{
		object->FixedUpdate();
	}
}

void Scene::Update()
{
	for (auto& object : m_Objects)
	{
		object->Update();
	}
	for (auto& object : m_Objects)
	{
		object->LateUpdate();
	}
}

void Scene::Render(const Renderer* pRenderer) const
{
	pRenderer->Clear();
	
	for (const SceneObject* const& object : m_Objects)
	{
		object->Render();
	}

	pRenderer->Present();
}

