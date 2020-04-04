#pragma once
namespace sea_core
{
	class SceneObject
	{
	public:
		virtual void Update(float deltaSecond) = 0;
		virtual void Render(float deltaSecond) const = 0;

		SceneObject() = default;
		virtual ~SceneObject() = default;
		SceneObject(const SceneObject& other) = delete;
		SceneObject(SceneObject&& other) = delete;
		SceneObject& operator=(const SceneObject& other) = delete;
		SceneObject& operator=(SceneObject&& other) = delete;
	};
}
