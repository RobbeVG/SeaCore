#pragma once

#include "Components/Physics/CommandComponent.h"
#include "SCProject.h"

namespace sea_core
{
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
			Fire
		};
		
		void LoadLevels() const;
		void LoadCharacters();
		static void SetupInput();

		Command* m_pJump;
		MoveCommand* m_pMove;
		CommandComponent* m_pCommandComponent;
	};
}
