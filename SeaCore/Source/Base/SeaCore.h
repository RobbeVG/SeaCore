#pragma once
struct SDL_Window;

namespace sea_core
{
	class SCProject;
	
	class SeaCore
	{
	public:
		SeaCore();
		
		void SetProject(SCProject* project) { m_Project = project; }
		void Run();

	private:
		void Awake();

		//void LoadProject();
		
		//void OnEnable();
		//void Start();
		//void FixedUpdate();
		//void Update();
		//void LateUpdate();
		//void Render();
		//void OnGui();
		//void OnDisable();
		//void OnDestroy();
		void Destroy();
		
		
	private:
		static const int MsPerFrame = 16; //16 for 60 fps, 33 for 30 fps

		SDL_Window* m_Window;
		SCProject* m_Project;
	};
}