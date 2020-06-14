#pragma once

#include "SCProject.h"

namespace sea_core
{
	class BubbleBobble : public SCProject
	{
	public:
		explicit BubbleBobble();

		void Update() override;
		void Load() override;

	private:
		void LoadLevels() const;
		static void LoadCharacters();
	};
}
