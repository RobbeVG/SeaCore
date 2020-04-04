#pragma once
#include "../Objects/GameObject.h"
#include "Messaging/BroadcastManager.h"

namespace sea_core
{

	/*
	 * Unique component will be stored on the game object = BaseComponent
	 * Shared component will be stored in container = derived component add pointers to other specific components
	 */

	/*
	 * Components :https://docs.unity3d.com/ScriptReference/Component.html
	 * Renderer :https://docs.unity3d.com/ScriptReference/Renderer.html
	 * Mesh renderer :https://docs.unity3d.com/ScriptReference/MeshRenderer.html
	 */
	
	class BaseComponent
	{
	public:
		GameObject* GetParent() const;
		
		virtual void Update(const float deltaSeconds) = 0;
		virtual void ReceiveMessage(const unsigned int) {}
		
		virtual ~BaseComponent() = default;
	protected:
		explicit BaseComponent();
		BaseComponent(const BaseComponent& other) = delete;
		BaseComponent(BaseComponent&& other) noexcept = delete;
		BaseComponent& operator=(const BaseComponent& other) = delete;
		BaseComponent& operator=(BaseComponent&& other) noexcept = delete;

		void BroadcastMessage(const unsigned int message) const;
		
	//Add component gameObject
		friend class GameObject;
		
		
		GameObject* m_pParent;
		/*
		 * @Brief Broadcaster of the component
		 * @Remark: To initialize use -> m_pBroadcaster = GetBroadcaster("NameOfBroadCast")
		 */
		Broadcaster const* m_pBroadcaster;
		
	private:
		virtual inline void AttachToContainer(std::vector<BaseComponent*>& components, std::vector<const RenderComponent*>&) { components.push_back(this); } //Force inline?
	};
}
