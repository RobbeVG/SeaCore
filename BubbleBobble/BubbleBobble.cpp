#include "BubbleBobble.h"

#include <iostream>

#include "Components/Physics/Colliders/PolygonCollider.h"
#include "Components/Physics/CommandComponent.h"
#include "Components/Render/SpriteRenderer.h"

#include "Graphics/Texture2D.h"
#include "Helpers/BinaryReader.h"
#include "Objects/GameObject.h"
#include "Resources/ResourceManager.h"

#include "Components/Transform.h"
#include "Helpers/EnumHelpers.h"
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
	delete m_pJumpBob;
	delete m_pMoveBob;
	
	delete m_pJumpBub;
	delete m_pMoveBub;
}

void sea_core::BubbleBobble::Update()
{
	const InputManager& pInputManager = InputManager::GetInstance();
	if (pInputManager.IsAction(UpBob))
		m_pCommandBob->AddCommand(m_pJumpBob);
	if (pInputManager.IsAction(LeftBob))
	{
		m_pMoveBob->SetDisplacement({ -1.0f, 0.0f });
		m_pCommandBob->AddCommand(m_pMoveBob);
	}
	if (pInputManager.IsAction(RightBob))
	{
		m_pMoveBob->SetDisplacement({ 1.0f, 0.0f });
		m_pCommandBob->AddCommand(m_pMoveBob);
	}
	if (pInputManager.IsAction(DownBob))
	{
		m_pMoveBob->SetDisplacement({ 0.0f, -1.0f });
		m_pCommandBob->AddCommand(m_pMoveBob);
	}
	if (pInputManager.IsAction(FireBob))
	{	}

	
	if (pInputManager.IsAction(UpBub))
		m_pCommandBub->AddCommand(m_pJumpBub);
	if (pInputManager.IsAction(LeftBub))
	{
		m_pMoveBub->SetDisplacement({ -1.0f, 0.0f });
		m_pCommandBub->AddCommand(m_pMoveBub);
	}
	if (pInputManager.IsAction(RightBub))
	{
		m_pMoveBub->SetDisplacement({ 1.0f, 0.0f });
		m_pCommandBub->AddCommand(m_pMoveBub);
	}
	if (pInputManager.IsAction(DownBub))
	{
		m_pMoveBub->SetDisplacement({ 0.0f, -1.0f });
		m_pCommandBub->AddCommand(m_pMoveBub);
	}
	if (pInputManager.IsAction(FireBub))
	{	}

	///
	if (pInputManager.IsAction(Next))
		SceneManager::GetInstance().ActivateNextScene();
	if (pInputManager.IsAction(Prev))
		SceneManager::GetInstance().ActivatePreviousScene();

}

void sea_core::BubbleBobble::Load()
{
	ResourceManager::GetInstance().Textures().SetDataPath("Data/Textures/");

	LoadLevels();
	LoadEnemies();
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


	
	const int amountLevels = 5; //100
	const int amountRows = 25;
	const int amountBytesPerRow = 4;
	
	
	for (int nrLevel = 1; nrLevel <= amountLevels; ++nrLevel)
	{
		float yLocation = GetProjectSettings().windowSettings.Height - float(radiusTile) / 2.0f;
		
		Scene& scene = SceneManager::GetInstance().CreateScene("Level" + std::to_string(nrLevel));
		//Loading of the level blocks
		{
			for (int nrRow = 0; nrRow < amountRows; ++nrRow)
			{
				float xLocation = float(radiusTile) / 2.0f;

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

							b2Filter groundFilter;
							groundFilter.categoryBits = ConvertEnum(BubbleBobbleCollisionFlags::Ground);
							groundFilter.maskBits = 0xFFFF;
							
							ColliderDesc colliderDesc{ 0.2f, 0.0f, 0.0f, false, groundFilter };
							pTile->AddComponent(new PolygonCollider(pRigidBody, colliderDesc, 8.0f, 8.0f));
							
							scene.Add(pTile);
						}
						currentTile >>= 1;
						xLocation += radiusTile;
					}
				}
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

void sea_core::BubbleBobble::LoadEnemies() const
{
	BinaryReader reader;

	FileManager& pFileManager = ResourceManager::GetInstance().Files();
	pFileManager.SetOpenMode(std::ios::in | std::ios::binary);
	std::fstream* pFile = pFileManager.Load("SeperatedEnemyData.dat");

	if (!pFile)
		return;
	reader.SetStream(pFile);

	const int amountLevels = 5; //100

	enum class EnemyType : unsigned char
	{
		Zenchan = 0,
		Hidegons = 1,
		Banebou = 2,
		Pulpul = 3,
		Monsta = 4,
		Drunk = 5,
		Mighta = 6,
		Invader = 7
	};

	b2Filter enemyFilter;
	enemyFilter.categoryBits = ConvertEnum(BubbleBobbleCollisionFlags::Enemy);
	enemyFilter.maskBits = ConvertEnum(BubbleBobbleCollisionFlags::Friendly | BubbleBobbleCollisionFlags::Ground | BubbleBobbleCollisionFlags::Enemy);
	
	for (int nrLevel = 1; nrLevel <= amountLevels; ++nrLevel)
	{
		Scene* scene = SceneManager::GetInstance().GetScene(nrLevel - 1);
		if (!scene)
			return;
		
		//Loading enemies
		{
			while (true)
			{
				const char byte1 = reader.Read<char>();
				if (byte1 == 0)
					break;

				const EnemyType type = ConvertEnum<EnemyType>(byte1 & 7); //(0000 0111)
				const int columnOffset = (byte1 & 248) >> 3; //(1111 1000)
				

				const char byte2 = reader.Read<char>();
				const int rowOffset = (byte2 & 248) >> 3; //(1111 1000)
				
				const char byte3 = reader.Read<char>();
				int framesDelay = (byte3 & 31) << 1;
				std::cout << framesDelay << std::endl;

				GameObject* pEnemy = new GameObject();
				pEnemy->GetTransform()->SetPosition(8.0f + (float(columnOffset) * 16.0f), 504 - (float(rowOffset) * 16.0f));

				SpriteRendererDesc spriteRendererDesc{ false, 16, 16, 0, 0, 7, 0, 4 };

				const RigidBodyDesc rigidBodyDesc{ RigidBody::Dynamic, b2Vec2(), 0.0f, 0.0f, 0.0f, false, true, true };
				RigidBody* pRigidBody = new RigidBody(pEnemy->GetTransform(), rigidBodyDesc);
				pEnemy->AddComponent(pRigidBody);

				const ColliderDesc colliderDesc{ 0.2f, 0.0f, 0.0f, false, enemyFilter };
				ColliderComponent* pCollider = new PolygonCollider(pRigidBody, colliderDesc, 8.0f, 8.0f);
				pEnemy->AddComponent(pCollider);
				
				switch (type)
				{
					case EnemyType::Zenchan:
						spriteRendererDesc.StartRow = 4;
						spriteRendererDesc.EndRow = 4;
						pEnemy->AddComponent(new SpriteRenderer("Sprites0.png", spriteRendererDesc));
					break;
					case EnemyType::Hidegons:
						spriteRendererDesc.StartRow = 6;
						spriteRendererDesc.EndRow = 6;
						pEnemy->AddComponent(new SpriteRenderer("Sprites0.png", spriteRendererDesc));
					break;
					case EnemyType::Banebou:
						spriteRendererDesc.StartRow = 8;
						spriteRendererDesc.EndRow = 8;
						pEnemy->AddComponent(new SpriteRenderer("Sprites0.png", spriteRendererDesc));
					break;
					case EnemyType::Pulpul:
						spriteRendererDesc.StartRow = 10;
						spriteRendererDesc.EndRow = 10;
						pEnemy->AddComponent(new SpriteRenderer("Sprites0.png", spriteRendererDesc));
					break;
					case EnemyType::Monsta:
						spriteRendererDesc.StartRow = 11;
						spriteRendererDesc.EndRow = 11;
						pEnemy->AddComponent(new SpriteRenderer("Sprites0.png", spriteRendererDesc));
					break;
					case EnemyType::Drunk:
						spriteRendererDesc.StartRow = 13;
						spriteRendererDesc.EndRow = 13;
						pEnemy->AddComponent(new SpriteRenderer("Sprites0.png", spriteRendererDesc));
					break;
					case EnemyType::Mighta:
						spriteRendererDesc.StartRow = 15;
						spriteRendererDesc.EndRow = 15;
						pEnemy->AddComponent(new SpriteRenderer("Sprites0.png", spriteRendererDesc));
					break;
					case EnemyType::Invader:
						spriteRendererDesc.StartRow = 2;
						spriteRendererDesc.EndRow = 2;
						pEnemy->AddComponent(new SpriteRenderer("Sprites1.png", spriteRendererDesc));
					break;
				default: ;
				}

				scene->Add(pEnemy);
			}
		}
	}

	pFileManager.UnLoad("SeperatedEnemyData.dat");
	pFileManager.SetOpenMode();
}

void sea_core::BubbleBobble::LoadCharacters()
{
	b2Filter friendlyFilter;
	friendlyFilter.categoryBits = ConvertEnum(BubbleBobbleCollisionFlags::Friendly);
	friendlyFilter.maskBits = ConvertEnum(BubbleBobbleCollisionFlags::Enemy | BubbleBobbleCollisionFlags::Ground | BubbleBobbleCollisionFlags::Food);
	
	Scene& scene = SceneManager::GetInstance().GetActiveScene();
	{
		GameObject* pBob = new GameObject();
		pBob->SetPosition(256, 256);

		SpriteRendererDesc spriteRendererDesc{ false, 16, 16, 0, 0, 7, 0, 4 };
		pBob->AddComponent(new SpriteRenderer("Sprites0.png", spriteRendererDesc));

		const RigidBodyDesc rigidBodyDesc{ RigidBody::Dynamic, b2Vec2(), 0.0f, 0.0f, 0.0f, false, true, true };
		RigidBody* pRigidBody = new RigidBody(pBob->GetTransform(), rigidBodyDesc);
		pBob->AddComponent(pRigidBody);

		const ColliderDesc colliderDesc{0.2f, 0.0f, 0.0f, false, friendlyFilter };
		ColliderComponent* pCollider = new PolygonCollider(pRigidBody, colliderDesc, 8.0f, 8.0f);
		pBob->AddComponent(pCollider);

		m_pCommandBob = new CommandComponent();
		pBob->AddComponent(m_pCommandBob);
		m_pJumpBob = new JumpCommand(pRigidBody, pCollider, 2000.0f);
		m_pMoveBob = new MoveCommand(pRigidBody, b2Vec2(), 100.0f);

		scene.Add(pBob);
	}
	
	{
		GameObject* pBub = new GameObject();
		pBub->SetPosition(256, 256);

		SpriteRendererDesc spriteRendererDesc{ false, 16, 16, 0, 2, 7, 2, 4 };
		pBub->AddComponent(new SpriteRenderer("Sprites0.png", spriteRendererDesc));

		const RigidBodyDesc rigidBodyDesc{ RigidBody::Dynamic, b2Vec2(), 0.0f, 0.0f, 0.0f, false, true, true };
		RigidBody* pRigidBody = new RigidBody(pBub->GetTransform(), rigidBodyDesc);
		pBub->AddComponent(pRigidBody);

		const ColliderDesc colliderDesc{ 0.2f, 0.0f, 0.0f, false, friendlyFilter };
		ColliderComponent* pCollider = new PolygonCollider(pRigidBody, colliderDesc, 8.0f, 8.0f);
		pBub->AddComponent(pCollider);

		m_pCommandBub = new CommandComponent();
		pBub->AddComponent(m_pCommandBub);
		m_pJumpBub = new JumpCommand(pRigidBody, pCollider, 2000.0f);
		m_pMoveBub = new MoveCommand(pRigidBody, b2Vec2(), 100.0f);

		scene.Add(pBub);
	}
}

void sea_core::BubbleBobble::SetupInput()
{
	InputAction* pUpBob = new InputAction(UpBob);
	pUpBob->AddKeyAction(SDLK_z, OutputTriggerState::Down);
	InputAction* pDownBob = new InputAction(DownBob);
	pDownBob->AddKeyAction(SDLK_s, OutputTriggerState::Down);
	InputAction* pLeftBob = new InputAction(LeftBob);
	pLeftBob->AddKeyAction(SDLK_q, OutputTriggerState::Down);
	InputAction* pRightBob = new InputAction(RightBob);
	pRightBob->AddKeyAction(SDLK_d, OutputTriggerState::Down);
	InputAction* pFireBob = new InputAction(FireBob);
	pFireBob->AddKeyAction(SDLK_SPACE, OutputTriggerState::Down);

	
	InputAction* pUpBub = new InputAction(UpBub);
	pUpBub->AddKeyAction(SDLK_UP, OutputTriggerState::Down);
	InputAction* pDownBub = new InputAction(DownBub);
	pDownBub->AddKeyAction(SDLK_DOWN, OutputTriggerState::Down);
	InputAction* pLeftBub = new InputAction(LeftBub);
	pLeftBub->AddKeyAction(SDLK_LEFT, OutputTriggerState::Down);
	InputAction* pRightBub = new InputAction(RightBub);
	pRightBub->AddKeyAction(SDLK_RIGHT, OutputTriggerState::Down);
	InputAction* pFireBub = new InputAction(FireBub);
	pFireBub->AddMouseAction(SDL_BUTTON_LEFT, OutputTriggerState::Down);


	
	//DEBUG
	InputAction* pNext = new InputAction(Next);
	pNext->AddKeyAction(SDLK_F3, OutputTriggerState::Down);
	InputAction* pPrev = new InputAction(Prev);
	pPrev->AddKeyAction(SDLK_F4, OutputTriggerState::Down);
	
	InputManager::GetInstance().AddAction(pUpBob);
	InputManager::GetInstance().AddAction(pDownBob);
	InputManager::GetInstance().AddAction(pLeftBob);
	InputManager::GetInstance().AddAction(pRightBob);
	InputManager::GetInstance().AddAction(pFireBob);
	
	InputManager::GetInstance().AddAction(pUpBub);
	InputManager::GetInstance().AddAction(pDownBub);
	InputManager::GetInstance().AddAction(pLeftBub);
	InputManager::GetInstance().AddAction(pRightBub);
	InputManager::GetInstance().AddAction(pFireBub);
	
	InputManager::GetInstance().AddAction(pNext);
	InputManager::GetInstance().AddAction(pPrev);
}