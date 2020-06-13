#pragma once

#include "SCProject.h"

namespace sea_core
{
	class BubbleBobble : public SCProject
	{
	public:
		explicit BubbleBobble();

		void Load() override;
	};
}
