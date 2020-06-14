#pragma once
#include "Helpers/EnumHelpers.h"
#include "Components/Physics/CommandComponent.h"
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
			Up,
			Down,
			Left,
			Right,
			Fire,

			//DEBUG
			Next,
			Prev
		};
		
		void LoadLevels() const;
		void LoadEnemies() const;
		void LoadCharacters();
		static void SetupInput();

		Command* m_pJump;
		MoveCommand* m_pMove;
		CommandComponent* m_pCommandComponent;
	};
}
