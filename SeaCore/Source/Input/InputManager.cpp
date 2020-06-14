#include "SeaCore_pch.h"
#include "InputManager.h"
#include <SDL.h>
#include <unordered_map>


sea_core::InputManager::InputManager()
{
	if (SDL_Init(SDL_INIT_JOYSTICK) < 0)
	{
		fprintf(stderr, "Couldn't initialize SDL: %s\n", SDL_GetError());
		exit(1);
	}
}

sea_core::InputManager::~InputManager()
{
	for (std::pair<const int, const InputAction*> action : m_InputActions)
	{
		delete action.second;
	}
}

void sea_core::InputManager::AddAction(const InputAction* pInputAction)
{
	if (m_InputActions.find(pInputAction->GetActionId()) == m_InputActions.end())
	{
		m_InputActions[pInputAction->GetActionId()] = pInputAction;
	}
	else
		delete pInputAction;
}

void sea_core::InputManager::RemoveAction(const int id)
{
	delete m_InputActions[id];
	m_InputActions.erase(id);
}

bool sea_core::InputManager::ProcessInput()
{
	std::unordered_set<SDL_Keycode> keyCodes;
	std::unordered_set<Uint8> mouseCodes;

	for (const std::pair<SDL_Keycode, OutputTriggerState> keyState : m_KeyboardKeyStates)
	{
		keyCodes.insert(keyState.first);
	}
	for (const std::pair<Uint8, OutputTriggerState> mouseState : m_MouseButtonStates)
	{
		mouseCodes.insert(mouseState.first);
	}

	SDL_JoystickEventState(SDL_ENABLE);
	SDL_Joystick* joystick = SDL_JoystickOpen(0);
	
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			return false;
		}
		
		//Keyboard key pressed
		if (e.type == SDL_KEYDOWN)
		{
			if (m_KeyboardKeyStates.find(e.key.keysym.sym) == m_KeyboardKeyStates.end())
				m_KeyboardKeyStates[e.key.keysym.sym] = OutputTriggerState::Down;
			else
			{
				if (m_KeyboardKeyStates[e.key.keysym.sym] == OutputTriggerState::Down)
					m_KeyboardKeyStates[e.key.keysym.sym] = OutputTriggerState::Pressed;
				else if (m_KeyboardKeyStates[e.key.keysym.sym] != OutputTriggerState::Pressed)
					m_KeyboardKeyStates[e.key.keysym.sym] = OutputTriggerState::Down;
			}

			//std::cout << " DOWN" << std::endl;
			
			keyCodes.erase(e.key.keysym.sym);
		}
		else if (e.type == SDL_KEYUP)
		{
			//std::cout << " UP" << std::endl;

			
			m_KeyboardKeyStates[e.key.keysym.sym] = OutputTriggerState::Up;
			keyCodes.erase(e.key.keysym.sym);
		}

		//Mouse button pressed
		else if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			m_MouseButtonStates[e.button.button] = OutputTriggerState::Down;

			if (m_MouseButtonStates.find(e.button.button) == m_MouseButtonStates.end())
				m_MouseButtonStates[e.button.button] = OutputTriggerState::Down;
			else
			{
				if (m_MouseButtonStates[e.button.button] == OutputTriggerState::Down)
					m_MouseButtonStates[e.button.button] = OutputTriggerState::Pressed;
				else if (m_MouseButtonStates[e.button.button] != OutputTriggerState::Pressed)
					m_MouseButtonStates[e.button.button] = OutputTriggerState::Down;
			}
			mouseCodes.insert(e.button.button);
		}
		else if (e.type == SDL_MOUSEBUTTONUP)
		{
			m_MouseButtonStates[e.button.button] = OutputTriggerState::Up;
			mouseCodes.insert(e.button.button);
		}

		//else if (e.type == SDL_JOYAXISMOTION)
		//{
		//	if ((e.jaxis.value < -3200) || (e.jaxis.value > 3200))
		//	{
		//		if (e.jaxis.axis == 0)
		//		{
		//			/* Left-right movement code goes here */
		//		}

		//		if (e.jaxis.axis == 1)
		//		{
		//			/* Up-Down movement code goes here */
		//		}
		//	}
		//	break;
		//}

		else if (e.type == SDL_JOYBUTTONDOWN)
		{
			
		}
		else if (e.type == SDL_JOYBUTTONUP)
		{

				std::cout << "<sjsj" << std::endl;
			
		}

	}

	SDL_JoystickClose(joystick);

	
	//Erase the ones not being used 
	for (SDL_Keycode unUsedKey : keyCodes)
	{
		m_KeyboardKeyStates.erase(unUsedKey);
	}
	for (Uint8 mouseKey : mouseCodes)
	{
		m_MouseButtonStates.erase(mouseKey);
	}
	
	return true;
}

bool sea_core::InputManager::IsAction(const int id) const
{
	const std::map<int, const InputAction*>::const_iterator it = m_InputActions.find(id);
	if (it == m_InputActions.end())
		return false;

	const InputAction* pInputAction = (*it).second;
	for (const std::pair<SDL_Keycode, OutputTriggerState> keyState : pInputAction->GetKeyStates())
	{
		std::unordered_map<int, OutputTriggerState>::const_iterator keyIt = m_KeyboardKeyStates.find(keyState.first);
		if (keyIt != m_KeyboardKeyStates.end())
		{
			if ((*keyIt).second == keyState.second)
				return true;
		}
	}
	for (const std::pair<Uint8, OutputTriggerState> mouseState : pInputAction->GetMouseStates())
	{
		std::unordered_map<Uint8, OutputTriggerState>::const_iterator mouseIt = m_MouseButtonStates.find(mouseState.first);
		if (mouseIt != m_MouseButtonStates.end())
		{
			if ((*mouseIt).second == mouseState.second)
				return true;
		}
	}
	return false;
}


//
//bool sea_core::InputManager::IsPressed(ControllerButton button) const
//{
//	switch (button)
//	{
//	case ControllerButton::ButtonA:
//		return m_CurrentState.Gamepad.wButtons & XINPUT_GAMEPAD_A;
//	case ControllerButton::ButtonB:
//		return m_CurrentState.Gamepad.wButtons & XINPUT_GAMEPAD_B;
//	case ControllerButton::ButtonX:
//		return m_CurrentState.Gamepad.wButtons & XINPUT_GAMEPAD_X;
//	case ControllerButton::ButtonY:
//		return m_CurrentState.Gamepad.wButtons & XINPUT_GAMEPAD_Y;
//	default: return false;
//	}
//}

