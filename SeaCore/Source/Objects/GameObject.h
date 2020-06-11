#pragma once
#include <unordered_set>

#include "../Scene/SceneObject.h"
#include "Messaging/Channels/Bus.h"

namespace sea_core
{
	//Todo Components should follow each other in memory
	class Transform;
	class BaseComponent;
	
	class GameObject : public SceneObject
	{
	public:
		GameObject();
		virtual ~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

		void Start() override;
		void Render() const override;
		void Update() override;
		void FixedUpdate() override;
		void LateUpdate() override;

		void SetPosition(float x, float y) const;

		void AddComponent(BaseComponent* component);

		//MessagingChannel::Bus* GetChannel() const { return m_pComponentChannel; }
		//MessagingChannel::Bus* GetComponentChannel() const { return m_pComponentChannel; }
		MessagingChannel::Bus* GetMonoBehaviourChannel() const { return m_pMonoBehaviourChannel; }

		Transform* GetTransform() const { return m_pTransform; }

		//template<typename T>
		//T* GetComponent();

		//template<typename T>
		//std::vector<T*> GetComponents();
	private:
		Transform* m_pTransform;
		std::unordered_set<BaseComponent*> m_Components;

		//MessagingChannel::Bus* m_pComponentChannel;
		MessagingChannel::Bus* m_pMonoBehaviourChannel;
	};

	//template <typename T>
	//T* GameObject::GetComponent()
	//{
	//	retur
	//}

	//template <typename T>
	//std::vector<T*> GameObject::GetComponents()
	//{
	//}
}
