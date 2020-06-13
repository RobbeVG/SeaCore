#pragma once
#include "Time/Time.h"

namespace sea_core
{
	class Renderer;
	class SceneObject;
	
	class Scene
	{
	public:
#pragma region SceneRuleOfFive
		explicit Scene(const std::string& name, unsigned int id);
		~Scene();
		Scene(const Scene& other) = delete;
		Scene(Scene&& other) = delete;
		Scene& operator=(const Scene& other) = delete;
		Scene& operator=(Scene&& other) = delete;
#pragma endregion

		enum class LoadingState
		{
			NotLoaded = 0,
			Loading = 1,
			Loaded = 2,
			Unloading = 3
		};
		
		bool IsLoaded() const { return m_LoadingState == LoadingState::Loaded; }
		LoadingState GetLoadingState() const { return m_LoadingState; }
		
		void Add(SceneObject* object);
		
		void Start();
		void FixedUpdate();
		void Update();
		void Render(const Renderer* pRenderer) const;
		//void Render();

		//void OnGui() {};
		//void OnEnable() {};
		//void OnDisable() {};
		//void OnDestroy() {};
		

		unsigned int GetId() const { return m_Id; }
		
	private: 
		//float m_TimeSinceSceneLoaded;
		
		unsigned int m_Id;
		std::string m_Name;
		std::vector <SceneObject*> m_Objects;


		LoadingState m_LoadingState;
	};

}
