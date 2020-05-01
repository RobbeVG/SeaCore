#include "SeaCore_pch.h"
#include "DefaultProject.h"



#include "Components/Behaviour/MonoBehaviour.h"
#include "Components/Render/SpriteRenderer.h"
#include "Components/Render/TextRenderer.h"


sea_core::DefaultProject::DefaultProject()
	: SCProject(ProjectSettings{ProjectSettings::WindowSettings(640, 480, "DefaultProject")})
{
}

sea_core::DefaultProject::~DefaultProject()
{
}

void sea_core::DefaultProject::Load()
{
	auto& scene = SceneManager::GetInstance().CreateScene("Demo");

	GameObject* object = new GameObject();
	object->AddComponent(new SpriteRenderer("Resources/background.jpg"));
	scene.Add(object);

	object = new GameObject();
	object->AddComponent(new SpriteRenderer("Resources/logo.png"));
	object->SetPosition(216, 180);
	scene.Add(object);

	const auto font = ResourceManager::GetInstance().LoadFont("Resources/Lingua.otf", 36);

	GameObject* textObject = new GameObject();
	textObject->AddComponent(new TextRenderer("Programming 4 Assignment", font));
	textObject->SetPosition(80, 20);
	scene.Add(textObject);

	GameObject* fpsCounter = new GameObject();
	fpsCounter->AddComponent(new FpsRenderer());
	fpsCounter->SetPosition(0.0f, 5.0f);
	scene.Add(fpsCounter);
}

void sea_core::FpsRenderer::Start()
{
	const auto font = ResourceManager::GetInstance().LoadFont("Resources/Lingua.otf", 36);
	
	m_FpsText = new TextRenderer("60", font);
	m_pParent->AddComponent(m_FpsText);
}

void sea_core::FpsRenderer::Update(const float deltaSeconds)
{
	m_FpsText->SetText(std::to_string(Time.GetFramesPerSeconds()));
}

