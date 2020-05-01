#include "SeaCore_pch.h"
#include "SeaCore.h"
#include <chrono>
#include <SDL.h>
#include <thread>

#include "../Components/Render/SpriteRenderer.h"
#include "../Components/Render/TextRenderer.h"
#include "../Graphics/Renderer.h"

#include "../Input/InputManager.h"
#include "../Resources/ResourceManager.h"
#include "../Scene/SceneManager.h"

#include "../Objects/GameObject.h"

#include "../Scene/Scene.h"

using namespace std;

void sea_core::SeaCore::Run()
{
	Awake();

	// tell the resource manager where he can find the game data
	ResourceManager::GetInstance().Init("Data/");

	//StartUpTime::m_TimeAtStartUp = 0.0f;
	
	//Time.GetTimeSinceStartUp() = 50.f;
	//Time::TimesinceStartupLoaded;
	{
		auto& renderer = Renderer::GetInstance();
		auto& sceneManager = SceneManager::GetInstance();
		auto& input = InputManager::GetInstance();

		m_Project->Load();
		
		const float fixedDeltaTime = Time.GetFixedDeltaTime();
		
		bool running = true;
		while (running)
		{
			Scene* scene = &sceneManager.GetActiveScene();
			//scene->OnEnable();
			
			if (!scene->IsLoaded())
				scene->Start();


			auto lastTime = Time.Now();
			float lag = 0.0f;

			while (running && (scene->GetId() == sceneManager.GetActiveScene().GetId()))
			{
				auto currentTime = Time.Now();
				const float deltaTime = std::chrono::duration<float>(currentTime - lastTime).count();

				Time.m_DeltaTime.deltaTime = deltaTime;
				
				lastTime = currentTime;
				lag += deltaTime;

				running = input.ProcessInput();				
				while (lag >= fixedDeltaTime) //-> Can lag not be 0???
				{
					scene->FixedUpdate();
					lag -= fixedDeltaTime;
				}

				
				scene->Update();
				//Update();
				//LateUpdate();

				//Render();

				Time.m_PercentageNextFrame = lag / fixedDeltaTime; //-> time between frames = render(lag / MS_PER_UPDATE) READ BOOK p132-133
				
				scene->Render(); 

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

//void sea_core::SeaCore::LoadProject()
//{
	//auto& scene = SceneManager::GetInstance().CreateScene("Demo");

	//GameObject* object = new GameObject();
	//object->AddComponent(new SpriteRenderer("Resources/background.jpg"));
	//scene.Add(object);

	//object = new GameObject();
	//object->AddComponent(new SpriteRenderer("Resources/logo.png"));
	//object->SetPosition(216, 180);
	//scene.Add(object);

	//const auto font = ResourceManager::GetInstance().LoadFont("Resources/Lingua.otf", 36);

	//GameObject* textObject = new GameObject();
	//textObject->AddComponent(new TextRenderer("Programming 4 Assignment", font));
	//textObject->SetPosition(80, 20);
	//scene.Add(textObject);

	//GameObject* fpsCounter = new GameObject();
	//TextRenderer* text = new TextRenderer("60", font);
	//fpsCounter->AddComponent(text);
	//
	//fpsCounter->SetPosition(80, 20);
	//scene.Add(fpsCounter);
//}

//void sea_core::SeaCore::OnEnable()
//{
//}
//
//void sea_core::SeaCore::Start()
//{
//}
//
//void sea_core::SeaCore::FixedUpdate()
//{
//}
//
//void sea_core::SeaCore::Update()
//{
//}
//
//void sea_core::SeaCore::LateUpdate()
//{
//}
//
//void sea_core::SeaCore::Render()
//{
//}
//
//void sea_core::SeaCore::OnGui()
//{
//}
//
//void sea_core::SeaCore::OnDisable()
//{
//}
//
//void sea_core::SeaCore::OnDestroy()
//{
//}

void sea_core::SeaCore::Destroy()
{
	Renderer::GetInstance().Destroy();
	SDL_DestroyWindow(m_Window);
	m_Window = nullptr;
	SDL_Quit();
}


//bool doContinue = true;
//while (doContinue)
//{
//	const auto currentTime = high_resolution_clock::now();
//	
//	doContinue = input.ProcessInput();
//	sceneManager.Update();
//	renderer.Render();
//	
//	auto sleepTime = duration_cast<duration<float>>(currentTime + milliseconds(MsPerFrame) - high_resolution_clock::now());
//	this_thread::sleep_for(sleepTime);
//}