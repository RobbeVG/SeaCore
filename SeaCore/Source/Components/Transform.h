#pragma once

#include <Box2D/Common/b2Math.h>

#include "BaseComponent.h"

namespace sea_core
{
	class Transform final : public BaseComponent
	{
	public:
		explicit Transform(GameObject* pParent);
		~Transform() override;
		
		const b2Vec2& GetPosition() const { return m_Position; }
		const b2Vec2& GetScale() const { return m_Scale; }
		float GetRotation() const { return m_RotationAngle; }
		
		void SetPosition(float x, float y);
		void SetScale(float x, float y);
		void SetRotation(float degrees);
		//void SetRotation(float radians);
		
	private:
		b2Vec2 m_Position;
		b2Vec2 m_Scale;
		float  m_RotationAngle;
	};
}
