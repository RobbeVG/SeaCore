#pragma once
#include "Helpers/Singleton.h"
#include <map>
#include <string>

namespace sea_core
{
	class Scene;
	
	class SceneManager final : public Singleton<SceneManager>
	{
	public:
		~SceneManager() override;
		
		Scene& CreateScene(const std::string& name);
		//void AddScene(Scene* pScene);
		Scene& GetActiveScene();
		Scene* GetScene(unsigned int id);
		
		bool ActivateNextScene();
		bool ActivatePreviousScene();		
		bool ActivateScene(unsigned int id);

		//void Swap(unsigned int idFirst, unsigned int idSecond);

	private:
		void SetActiveScene(Scene* pScene);
		
		std::map<unsigned int, Scene*> m_Scenes;
		Scene* m_ActiveScene = nullptr;
		

		unsigned int m_IdCounter = 0;
	};
}
