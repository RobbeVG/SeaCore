#pragma once
#include "Helpers/EnumHelpers.h"
#include "Components/Physics/CommandComponent.h"
#include "Input/Commands/JumpCommand.h"
#include "SCProject.h"

namespace sea_core
{
	enum class BubbleBobbleCollisionFlags : uint16
	{
		Ground			= 1,
		Friendly		= 2,
		Enemy			= 4,
		Food			= 8,
		
	};
	ENUM_FLAGS(BubbleBobbleCollisionFlags)

	
	class MoveCommand;

	class BubbleBobble : public SCProject
	{
	public:
		explicit BubbleBobble();
		~BubbleBobble();
		
		void Update() override;
		void Load() override;

	private:
		enum Input
		{
			UpBob,
			DownBob,
			LeftBob,
			RightBob,
			FireBob,

			UpBub,
			DownBub,
			LeftBub,
			RightBub,
			FireBub,

			//DEBUG
			Next,
			Prev
		};
		
		void LoadLevels() const;
		void LoadEnemies() const;
		void LoadCharacters();
		static void SetupInput();

		JumpCommand* m_pJumpBob;
		MoveCommand* m_pMoveBob;
		CommandComponent* m_pCommandBob;

		
		JumpCommand* m_pJumpBub;
		MoveCommand* m_pMoveBub;
		CommandComponent* m_pCommandBub;
	};
}
