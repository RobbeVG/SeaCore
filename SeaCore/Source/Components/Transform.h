#pragma once
#pragma warning(push)
#pragma warning (disable:4201)
#include <vec3.hpp>
#pragma warning(pop)

#include "BaseComponent.h"

namespace sea_core
{
	class Transform final : public BaseComponent
	{
	public:
		Transform(GameObject* pParent);
		~Transform() override;
		
		const glm::vec3& GetPosition() const { return m_Position; }
		const glm::vec3& GetScale() const { return m_Scale; }
		const glm::vec3& GetRotation() const { return m_Rotation; }
		
		void SetPosition(float x, float y, float z);
		void SetScale(float x, float y, float z);
		void SetRotation(float x, float y, float z);
		
	private:
		glm::vec3 m_Position;
		glm::vec3 m_Rotation;
		glm::vec3 m_Scale;
	};
}
