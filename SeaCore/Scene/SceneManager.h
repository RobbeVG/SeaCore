#pragma once
#include "../Helpers/Singleton.h"
#include <vector>
#include <string>

namespace sea_core
{
	class Scene;
	class SceneManager final : public Singleton<SceneManager>
	{
	public:
		~SceneManager();
		
		Scene& CreateScene(const std::string& name);

		void Update(float deltaSecond);
		void Render(float deltaSecond);
	private:
		std::vector<Scene*> m_Scenes;
	};
}
