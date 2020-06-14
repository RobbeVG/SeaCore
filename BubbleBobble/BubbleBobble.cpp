#include "BubbleBobble.h"

#include "Components/Render/SpriteRenderer.h"
#include "Graphics/Texture2D.h"
#include "Helpers/BinaryReader.h"
#include "Objects/GameObject.h"
#include "Resources/ResourceManager.h"

#include "Components/Transform.h"

#include "Scene/SceneManager.h"
#include "Scene/Scene.h"

sea_core::BubbleBobble::BubbleBobble()
	: sea_core::SCProject({sea_core::ProjectSettings::WindowSettings(512, 512, "Bubble Bobble - Exam Assingment")})
{
}

void sea_core::BubbleBobble::Load()
{
	LoadLevels();
}

void sea_core::BubbleBobble::LoadLevels()
{
	BinaryReader reader;

	FileManager& pFileManager = ResourceManager::GetInstance().Files();
	pFileManager.SetOpenMode(std::ios::in | std::ios::binary);
	std::fstream* pFile = pFileManager.Load("SeperatedLevelData.dat");
	
	if (!pFile)
		return;
	reader.SetStream(pFile);

	Texture2D* pTexture = ResourceManager::GetInstance().Textures().Load("Textures/LevelBigBlocks.png"); //Texture is 10*10!
	const float radiusTile = float(pTexture->GetWidth()) / 10.0f;

	float xLocation = float(radiusTile) /2.0f;
	float yLocation = float(radiusTile) /2.0f;
	
	const int amountLevels = 1; //100
	const int amountRows = 25;
	const int amountBytesPerRow = 4;
	
	
	for (int nrLevel = 1; nrLevel <= amountLevels; ++nrLevel)
	{
		Scene& scene = SceneManager::GetInstance().CreateScene("Level" + std::to_string(nrLevel));

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

						SpriteRendererDesc desc {false, 16, 16, 0, 0, 0, 0, 0};
						pTile->AddComponent(new SpriteRenderer("Textures/LevelBigBlocks.png", desc));
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


	pFileManager.UnLoad("SeperatedLevelData.dat");
	pFileManager.SetOpenMode();
}
