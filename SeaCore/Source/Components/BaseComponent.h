#pragma once
#include "../Objects/GameObject.h"
#include "Messaging/BroadcastTracker.h"

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
		GameObject* GetParent() const { return m_pParent; }
		Broadcaster* GetBroadcaster() const { return m_pBroadcaster; }
		
		virtual void ReceiveMessage(const unsigned int) {} //TODO Update, Render, ...
		
		virtual ~BaseComponent() = default;
	protected:
		explicit BaseComponent();
		BaseComponent(const BaseComponent& other) = delete;
		BaseComponent(BaseComponent&& other) noexcept = delete;
		BaseComponent& operator=(const BaseComponent& other) = delete;
		BaseComponent& operator=(BaseComponent&& other) noexcept = delete;
		
		void BroadcastMessage(const unsigned int message) const; //TODO Broadcast message
		
	//Add component gameObject
		friend class GameObject;		
		GameObject* m_pParent;
		/*
		 * @Brief Broadcaster of the component
		 * @Remark: You can assign this to a broadcaster. It will be automatically added to the BroadcastManager
		 */
		Broadcaster* m_pBroadcaster;

	private:
		virtual inline void AttachToContainer(std::vector<BaseComponent*>& components, std::vector<RendererComponent*>&) { components.push_back(this); } //Force inline?
	};
}
