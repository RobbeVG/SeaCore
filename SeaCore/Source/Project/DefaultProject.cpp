#include "SeaCore_pch.h"
#include "DefaultProject.h"

#include <Box2D/Box2D.h>



#include "Components/Behaviour/MonoBehaviour.h"
#include "Components/Render/SpriteRenderer.h"
#include "Components/Render/TextRenderer.h"
#include "Scene/SceneManager.h"
#include "Scene/Scene.h"
#include "Components/Transform.h"
#include "Physics/Physics.h"


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
	fpsCounter->SetPosition(320.0f, 300.0f);
	scene.Add(fpsCounter);

	//ground
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0.0f, -10.0f);

	b2Body* groundBody = Physics()->CreateBody(&groundBodyDef);

	b2PolygonShape groundBox;
	groundBox.SetAsBox(50.0f, 10.0f);

	groundBody->CreateFixture(&groundBox, 0.0f);

	//box
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(0.0f, 4.0f);
	b2Body* body = Physics()->CreateBody(&bodyDef);

	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(1.0f, 1.0f);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;

	body->CreateFixture(&fixtureDef);
}

sea_core::FpsRenderer::FpsRenderer()
{
	const auto font = ResourceManager::GetInstance().LoadFont("Resources/Lingua.otf", 36);

	m_FpsText = new TextRenderer("60", font);
}

void sea_core::FpsRenderer::OnStart()
{
	m_FpsText->AttachToParent(GetParent());
}

//void sea_core::FpsRenderer::OnStart()
//{
//	const auto font = ResourceManager::GetInstance().LoadFont("Resources/Lingua.otf", 36);
//	
//	m_FpsText = new TextRenderer("60", font);
//	GetParent()->AddComponent(m_FpsText);
//}

void sea_core::FpsRenderer::Update()
{
	m_FpsText->SetText(std::to_string(Time().GetFramesPerSeconds()));
}
