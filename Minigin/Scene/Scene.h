#pragma once
#include "../Managers/SceneManager.h"

namespace sea_core
{
	class SceneObject;
	class Scene
	{
		friend Scene& SceneManager::CreateScene(const std::string& name);
	public:
		void Add(SceneObject* object);

		void Update(float deltaSecond);
		void Render(float deltaSecond) const;

		~Scene();
		Scene(const Scene& other) = delete;
		Scene(Scene&& other) = delete;
		Scene& operator=(const Scene& other) = delete;
		Scene& operator=(Scene&& other) = delete;

	private: 
		explicit Scene(const std::string& name);

		std::string m_Name;
		std::vector <SceneObject*> m_Objects;

		static unsigned int m_IdCounter; 
	};

}
