#pragma once
#include <vector>
#include "../Scene/SceneObject.h"

namespace sea_core
{
	//Todo Components should follow each other in memory
	class Transform;

	class BaseComponent;
	class RendererComponent;
	
	class GameObject : public SceneObject
	{
	public:
		GameObject();
		virtual ~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

		void Update(float deltaSeconds) override;
		void Render(float deltaSeconds) const override;

		void SetPosition(float x, float y) const;
		
		void AddComponent(BaseComponent* component);
		
		Transform* GetTransform() const;
		
	private:
		std::vector<BaseComponent*> m_Components;
		std::vector<RendererComponent*> m_RenderComponents;
	};
}
