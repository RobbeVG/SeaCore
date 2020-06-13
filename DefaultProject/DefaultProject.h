#pragma once
#include "Components/Behaviour/MonoBehaviour.h"
#include "SCProject.h"

namespace sea_core 
{
	class TextRenderer;
	
	class DefaultProject final : public SCProject
	{
	public:
		explicit DefaultProject();
		~DefaultProject();


		void Load() override;
		void Update() override;
	};

	class FpsRenderer final : public MonoBehaviour
	{
	public:
		FpsRenderer();
	protected:
		void OnStart() override;
		void Update() override;

	private:
		TextRenderer* m_FpsText;
	};
}
