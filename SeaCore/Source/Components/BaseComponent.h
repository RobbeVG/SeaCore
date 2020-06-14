#pragma once
#include "../Objects/GameObject.h"


namespace sea_core
{
	class Endpoint;

	class BaseComponent
	{
	public:
		virtual ~BaseComponent();
		
		GameObject* GetParent() const { return m_pParent; }
	protected:
		virtual void SetParent(GameObject* pParent);
		
	public:
		void AttachToParent(GameObject* pParent);

		virtual void UpdateComponent() {}
		virtual void RenderComponent() {}
		virtual void FixedUpdateComponent() {}
		
	protected:
		explicit BaseComponent();
		BaseComponent(const BaseComponent& other) = delete;
		BaseComponent(BaseComponent&& other) noexcept = delete;
		BaseComponent& operator=(const BaseComponent& other) = delete;
		BaseComponent& operator=(BaseComponent&& other) noexcept = delete;

	private:
		GameObject* m_pParent;
	protected:
		Endpoint* m_Endpoint;		
	};

	/*
	 * Unique component will be stored on the game object = BaseComponent
	 * Shared component will be stored in container = derived component add pointers to other specific components
	 */

	/*
	* Components :https://docs.unity3d.com/ScriptReference/Component.html
	* Renderer :https://docs.unity3d.com/ScriptReference/Renderer.html
	* Mesh renderer :https://docs.unity3d.com/ScriptReference/MeshRenderer.html
	*/

	/* DESIGN CHOICES
	*
	* No delta time parameters... Some components do not need them. Use Time!
	* Components cannot be added during runtime (Add component and disable!)
	*/
	
}

		/*
		 * @Brief Broadcaster of the component
		 * @Remark: You can assign this to a broadcaster. It will be automatically added to the BroadcastManager
		 */