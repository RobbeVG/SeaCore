#include "MiniginPCH.h"
#include "Minigin.h"
#include <chrono>
#include <thread>
#include <SDL.h>


#include "../Components/Render/SpriteRenderer.h"
#include "../Components/Render/TextRenderer.h"
#include "../Graphics/Renderer.h"

#include "../Input/InputManager.h"
#include "../Resources/ResourceManager.h"
#include "../Scene/SceneManager.h"

#include "../Objects/GameObject.h"

#include "../Scene/Scene.h"

using namespace std;

void sea_core::Minigin::Initialize()
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

/**
 * Code constructing the scene world starts here
 */
void sea_core::Minigin::LoadGame() const
{
	auto& scene = SceneManager::GetInstance().CreateScene("Demo");

	GameObject* object = new GameObject();
	object->AddComponent(new SpriteRenderer("background.jpg"));
	scene.Add(object);

	object = new GameObject();
	object->AddComponent(new SpriteRenderer("logo.png"));
	object->SetPosition(216, 180);
	scene.Add(object);

	GameObject* textObject = new GameObject();
	const auto font = ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	textObject->AddComponent(new TextRenderer("Programming 4 Assignment", font));
	textObject->SetPosition(80, 20);
	scene.Add(textObject);
}

void sea_core::Minigin::Cleanup()
{
	Renderer::GetInstance().Destroy();
	SDL_DestroyWindow(m_Window);
	m_Window = nullptr;
	SDL_Quit();
}

void sea_core::Minigin::Run()
{
	Initialize();

	// tell the resource manager where he can find the game data
	ResourceManager::GetInstance().Init("../Data/");
	
	LoadGame();

	{
		auto& renderer = Renderer::GetInstance();
		auto& sceneManager = SceneManager::GetInstance();
		auto& input = InputManager::GetInstance();
		
		bool running = true;
		auto lastTime = std::chrono::high_resolution_clock::now();
		float lag = 0.0f;
		
		while (running)
		{
			const auto currentTime = std::chrono::high_resolution_clock::now();
			const float deltaTime = std::chrono::duration<float>(currentTime - lastTime).count();
			lastTime = currentTime;
			lag += deltaTime;  running = input.ProcessInput();
			while (lag >= MS_PER_UPDATE)
			{
				sceneManager.Update(MS_PER_UPDATE);
				lag -= MS_PER_UPDATE;
			}
			renderer.Render(lag / MS_PER_UPDATE); //-> time between frames = render(lag / MS_PER_UPDATE) READ BOOK p132-133
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
	}

	Cleanup();
}
