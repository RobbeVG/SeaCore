#pragma once
//#include "Transform.h"
#include <vector>

#include "../Scene/SceneObject.h"

namespace sea_core
{
	class Transform;
	class Texture2D;

	class BaseComponent;
	class RenderComponent;

	//Todo Components should follow each other in memory
	
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
		std::vector<const RenderComponent*> m_RenderComponents;
	};
}
