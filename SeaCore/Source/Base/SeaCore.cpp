#include "SeaCore_pch.h"
#include "SeaCore.h"

#include <Box2D/Dynamics/b2Body.h>
#include <chrono>
#include <SDL.h>
#include <thread>

#include "../Resources/ResourceManager.h"

#include "../Input/InputManager.h"

#include "../Scene/Scene.h"
#include "../Scene/SceneManager.h"
#include "../Physics/Physics.h"
#include "../Graphics/Renderer.h"

using namespace std;

void sea_core::SeaCore::Run()
{
	Awake();

	// tell the resource manager where he can find the game data
	ResourceManager::GetInstance().Init("Data/");

	//StartUpTime::m_TimeAtStartUp = 0.0f;

	//Physics()->Step()
	

	//Time.GetTimeSinceStartUp() = 50.f;
	//Time::TimesinceStartupLoaded;
	{
		auto& renderer = Renderer::GetInstance();
		auto& sceneManager = SceneManager::GetInstance();
		auto& input = InputManager::GetInstance();

		m_Project->Load();
		delete m_Project;
		
		const float fixedDeltaTime = Time().GetFixedDeltaTime();
		
		bool running = true;
		while (running)
		{
			Scene* scene = &sceneManager.GetActiveScene();
			//scene->OnEnable();
			
			if (!scene->IsLoaded())
				scene->Start();

			auto lastTime = Time().Now();
			float lag = 0.0f;

			while (running && (scene->GetId() == sceneManager.GetActiveScene().GetId()))
			{
				auto currentTime = Time().Now();
				const float deltaTime = std::chrono::duration<float>(currentTime - lastTime).count();
				Time().m_DeltaTime.deltaTime = deltaTime;
				
				lastTime = currentTime;
				lag += deltaTime;
				
				running = input.ProcessInput();				
				while (lag >= fixedDeltaTime) //-> Catch up 
				{
					Physics()->Step(fixedDeltaTime, 6, 2);

					b2Body* body = Physics()->GetBodyList();
					b2Vec2 position = body->GetPosition();
					float angle = body->GetAngle();
					printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
					
					scene->FixedUpdate();
					lag -= fixedDeltaTime;
				}

				
				Time().m_FpsTime.UpdateFps(deltaTime);
				
				scene->Update();
				//Update();
				//LateUpdate();

				//Render();

				Time().m_PercentageNextFrame = lag / fixedDeltaTime; //-> time between frames = render(lag / MS_PER_UPDATE) READ BOOK p132-133
				
				scene->Render(&renderer); 

				//OnGui();
			}
			//OnDisable();
		}
	}
	
	Destroy();
}

void sea_core::SeaCore::Awake()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		throw std::runtime_error(std::string("SDL_Init Error: ") + SDL_GetError());
	}

	m_Window = SDL_CreateWindow(
		"Programming 4 assignment",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		640,
		480,
		SDL_WINDOW_OPENGL
	);
	if (m_Window == nullptr)
	{
		throw std::runtime_error(std::string("SDL_CreateWindow Error: ") + SDL_GetError());
	}

	Renderer::GetInstance().Init(m_Window);
}

void sea_core::SeaCore::Destroy()
{
	Renderer::GetInstance().Destroy();
	SDL_DestroyWindow(m_Window);
	m_Window = nullptr;
	SDL_Quit();

}
