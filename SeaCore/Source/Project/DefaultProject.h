#pragma once
#include "Components/Behaviour/MonoBehaviour.h"
#include "Components/Render/TextRenderer.h"
#include "SCProject.h"

namespace sea_core 
{
	class TextRenderer;
	
	class DefaultProject : public SCProject
	{
	public:
		explicit DefaultProject();
		~DefaultProject() override;


		void Load() override;
		//void Update() override;
	};

	class FpsRenderer final : public MonoBehaviour
	{
	protected:
		void Start() override;
		void Update(const float deltaSeconds) override;

	private:
		TextRenderer* m_FpsText;
	};
	
}

