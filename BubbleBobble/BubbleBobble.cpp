#include "BubbleBobble.h"


#include "Components/Physics/Colliders/PolygonCollider.h"
#include "Components/Render/SpriteRenderer.h"



#include "Graphics/Texture2D.h"
#include "Helpers/BinaryReader.h"
#include "Objects/GameObject.h"
#include "Resources/ResourceManager.h"

#include "Components/Transform.h"
#include "Physics/Physics.h"

#include "Scene/SceneManager.h"
#include "Scene/Scene.h"

sea_core::BubbleBobble::BubbleBobble()
	: sea_core::SCProject({sea_core::ProjectSettings::WindowSettings(512, 512, "Bubble Bobble - Exam Assingment")})
{
}

void sea_core::BubbleBobble::Update()
{
	b2Body* body = Physics()->GetBodyList();
	const b2Vec2 position = body->GetPosition();
	const float angle = body->GetAngle();
	printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
}

void sea_core::BubbleBobble::Load()
{
	ResourceManager::GetInstance().Textures().SetDataPath("Data/Textures/");
	
	LoadLevels();
	LoadCharacters();
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
	float yLocation = float(radiusTile) /2.0f;
	
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

							SpriteRendererDesc desc{ false, 16, 16, 0, 0, 0, 0, 0 };
							pTile->AddComponent(new SpriteRenderer("LevelBigBlocks.png", desc));
							pTile->SetPosition(xLocation, yLocation);
							scene.Add(pTile);
						}
						currentTile >>= 1;
						xLocation += radiusTile;
					}
				}
				xLocation = float(radiusTile) / 2.0f;
				yLocation += radiusTile;
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

	SpriteRendererDesc spriteRendererDesc{ false, 16, 16, 0, 0, 7, 0, 4 };
	pBob->AddComponent(new SpriteRenderer("Sprites0.png", spriteRendererDesc));

	const RigidBodyDesc rigidBodyDesc{RigidBody::Dynamic};
	RigidBody* pRigidBody = new RigidBody(pBob->GetTransform(), rigidBodyDesc);
	pBob->AddComponent(pRigidBody);
	
	ColliderDesc colliderDesc{};
	pBob->AddComponent(new PolygonCollider(pRigidBody, colliderDesc, 8.0f, 8.0f));
	pBob->SetPosition(8, 8);

	scene.Add(pBob);
}
