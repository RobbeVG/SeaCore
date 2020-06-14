#include "BubbleBobble.h"


#include "Components/Physics/Colliders/PolygonCollider.h"
#include "Components/Physics/CommandComponent.h"
#include "Components/Render/SpriteRenderer.h"



#include "Graphics/Texture2D.h"
#include "Helpers/BinaryReader.h"
#include "Objects/GameObject.h"
#include "Resources/ResourceManager.h"

#include "Components/Transform.h"
#include "Input/Commands/JumpCommand.h"
#include "Input/Commands/MoveCommand.h"
#include "Input/InputManager.h"
#include "Physics/Physics.h"

#include "Scene/SceneManager.h"
#include "Scene/Scene.h"

sea_core::BubbleBobble::BubbleBobble()
	: SCProject({
		ProjectSettings::WindowSettings(512, 512, "Bubble Bobble - Exam Assingment"),
		ProjectSettings::GameSettings(-9.81f, 0.1f)
	})
{
}

sea_core::BubbleBobble::~BubbleBobble()
{
	delete m_pJump;
	delete m_pMove;
}

void sea_core::BubbleBobble::Update()
{
	const InputManager& pInputManager = InputManager::GetInstance();
	if (pInputManager.IsAction(Up))
		m_pCommandComponent->AddCommand(m_pJump);
	if (pInputManager.IsAction(Left))
	{
		m_pMove->SetDisplacement({ -1.0f, 0.0f });
		m_pCommandComponent->AddCommand(m_pMove);
	}
	if (pInputManager.IsAction(Right))
	{
		m_pMove->SetDisplacement({ 1.0f, 0.0f });
		m_pCommandComponent->AddCommand(m_pMove);
	}
	if (pInputManager.IsAction(Down))
	{
		
		m_pMove->SetDisplacement({ 0.0f, -1.0f });
		m_pCommandComponent->AddCommand(m_pMove);
	}
	if (pInputManager.IsAction(Fire))
	{
		
		//m_pCommandComponent->AddCommand(m_pMove);
	}
	

}

void sea_core::BubbleBobble::Load()
{
	ResourceManager::GetInstance().Textures().SetDataPath("Data/Textures/");
	
	LoadLevels();
	LoadCharacters();
	SetupInput();
}

void sea_core::BubbleBobble::LoadLevels() const
{
	BinaryReader reader;

	FileManager& pFileManager = ResourceManager::GetInstance().Files();
	pFileManager.SetOpenMode(std::ios::in | std::ios::binary);
	std::fstream* pFile = pFileManager.Load("SeperatedLevelData.dat");
	
	if (!pFile)
		return;
	reader.SetStream(pFile);

	Texture2D* pTexture = ResourceManager::GetInstance().Textures().Load("LevelBigBlocks.png"); //Texture is 10*10!
	const float radiusTile = float(pTexture->GetWidth()) / 10.0f;

	float xLocation = float(radiusTile) /2.0f;
	float yLocation = GetProjectSettings().windowSettings.Height - float(radiusTile) /2.0f;
	
	const int amountLevels = 1; //100
	const int amountRows = 25;
	const int amountBytesPerRow = 4;
	
	
	for (int nrLevel = 1; nrLevel <= amountLevels; ++nrLevel)
	{
		Scene& scene = SceneManager::GetInstance().CreateScene("Level" + std::to_string(nrLevel));
		//Loading of the level blocks
		{
			for (int nrRow = 0; nrRow < amountRows; ++nrRow)
			{
				for (int bytesPerRow = 0; bytesPerRow < amountBytesPerRow; ++bytesPerRow)
				{
					const unsigned char tileRow = reader.Read<char>();
					unsigned char currentTile = 128; // 1000 0000

					//every bit is one tile
					for (int i = 0; i < 8; ++i)
					{
						if (currentTile & tileRow)
						{
							GameObject* pTile = new GameObject();
							pTile->SetPosition(xLocation, yLocation);

							SpriteRendererDesc spriteRendererDesc{ false, 16, 16, 0, 0, 0, 0, 0 };
							pTile->AddComponent(new SpriteRenderer("LevelBigBlocks.png", spriteRendererDesc));

							RigidBodyDesc rigidBodyDesc{};
							RigidBody* pRigidBody = new RigidBody(pTile->GetTransform(), rigidBodyDesc);
							pTile->AddComponent(pRigidBody);

							ColliderDesc colliderDesc{};
							pTile->AddComponent(new PolygonCollider(pRigidBody, colliderDesc, 8.0f, 8.0f));
							
							scene.Add(pTile);
						}
						currentTile >>= 1;
						xLocation += radiusTile;
					}
				}
				xLocation = float(radiusTile) / 2.0f;
				yLocation -= radiusTile;
			}
		}

		//Loading of the level enemies
		{
			
		}
	}


	pFileManager.UnLoad("SeperatedLevelData.dat");
	pFileManager.SetOpenMode();
}

void sea_core::BubbleBobble::LoadCharacters()
{
	Scene& scene = SceneManager::GetInstance().GetActiveScene();

	GameObject* pBob = new GameObject();
	pBob->SetPosition(256, 256);

	SpriteRendererDesc spriteRendererDesc{ false, 16, 16, 0, 0, 7, 0, 4 };
	pBob->AddComponent(new SpriteRenderer("Sprites0.png", spriteRendererDesc));

	const RigidBodyDesc rigidBodyDesc{RigidBody::Dynamic, b2Vec2(), 0.0f, 0.0f, 0.0f, true, true, true};
	RigidBody* pRigidBody = new RigidBody(pBob->GetTransform(), rigidBodyDesc);
	pBob->AddComponent(pRigidBody);

	const ColliderDesc colliderDesc{};
	ColliderComponent* pCollider = new PolygonCollider(pRigidBody, colliderDesc, 8.0f, 8.0f);
	pBob->AddComponent(pCollider);

	m_pCommandComponent = new CommandComponent();
	pBob->AddComponent(m_pCommandComponent);


	m_pJump = new JumpCommand(pRigidBody, pCollider, 200.0f);
	m_pMove = new MoveCommand(pRigidBody, b2Vec2(), 100.0f);
	
	scene.Add(pBob);
}

void sea_core::BubbleBobble::SetupInput()
{
	InputAction* pUp = new InputAction(Up);
	pUp->AddKeyAction(SDLK_z, OutputTriggerState::Down);
	InputAction* pDown = new InputAction(Down);
	pDown->AddKeyAction(SDLK_s, OutputTriggerState::Down);
	InputAction* pLeft = new InputAction(Left);
	pLeft->AddKeyAction(SDLK_q, OutputTriggerState::Down);
	InputAction* pRight = new InputAction(Right);
	pRight->AddKeyAction(SDLK_d, OutputTriggerState::Down);
	InputAction* pFire = new InputAction(Fire);
	pFire->AddMouseAction(SDL_BUTTON_LEFT, OutputTriggerState::Down);
	
	InputManager::GetInstance().AddAction(pUp);
	InputManager::GetInstance().AddAction(pDown);
	InputManager::GetInstance().AddAction(pLeft);
	InputManager::GetInstance().AddAction(pRight);
	InputManager::GetInstance().AddAction(pFire);
}