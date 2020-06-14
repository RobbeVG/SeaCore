#pragma once
#include <map>

#include "Helpers/Singleton.h"
#include "InputAction.h"

#include <unordered_set>

namespace sea_core
{
	//enum class ControllerButton
	//{
	//	ButtonA,
	//	ButtonB,
	//	ButtonX,
	//	ButtonY
	//};

	class InputManager final : public Singleton<InputManager>
	{
	public:
		InputManager();
		~InputManager();
		
		void AddAction(const InputAction* pInputAction);
		void RemoveAction(int id);
		
		bool ProcessInput();
		bool IsAction(int id) const;

	private:		
		std::map<int, const InputAction*> m_InputActions;

		std::unordered_map<SDL_Keycode, OutputTriggerState> m_KeyboardKeyStates;
		std::unordered_map<Uint8, OutputTriggerState> m_MouseButtonStates;
		
		//XINPUT_STATE m_CurrentState{};
	};

}
