#include "SeaCore_pch.h"
#include "Scene.h"

#include "../Objects/GameObject.h"

using namespace sea_core;

unsigned int Scene::m_IdCounter = 0;

Scene::Scene(const std::string& name) : m_Name(name) {}

Scene::~Scene()
{
	for (SceneObject* object : m_Objects)
	{
		delete object;
	}	
}

void Scene::Add(SceneObject* object)
{
	m_Objects.push_back(object);
}

void Scene::Update(float deltaSecond)
{
	for(auto& object : m_Objects)
	{
		object->Update(deltaSecond);
	}
}

void Scene::Render(float deltaSecond) const
{
	for (const auto& object : m_Objects)
	{
		object->Render(deltaSecond);
	}
}

