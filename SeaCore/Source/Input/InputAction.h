#pragma once
#include <SDL.h>
#include <unordered_map>

enum class PlayerIndex : unsigned char
{
	PlayerOne = 0,
	PlayerTwo = 1,
	PlayerThree = 2,
	PlayerFour = 3
};

enum class OutputTriggerState : unsigned char
{
	Nothing,
	Down,
	Pressed,
	Up
};

class InputAction
{
public:
	InputAction(const unsigned int actionId, PlayerIndex playerIndex = PlayerIndex::PlayerOne)
	: m_ActionId(actionId)
	, m_PlayerIndex(playerIndex)
	{}

	void AddKeyAction(const SDL_Keycode keyCode, const OutputTriggerState output) { m_KeyStates[keyCode] = output; };
	void AddMouseAction(const Uint8 mouseCode, const OutputTriggerState output) { m_MouseStates[mouseCode] = output; };

	const std::unordered_map<SDL_Keycode, OutputTriggerState>& GetKeyStates() const { return m_KeyStates; };
	const std::unordered_map<Uint8, OutputTriggerState>& GetMouseStates() const { return m_MouseStates; };
	
	PlayerIndex GetPlayerIndex() const { return m_PlayerIndex; }
	unsigned int GetActionId() const { return m_ActionId; }
	
	inline bool operator==(const InputAction& other) const;
	inline bool operator<(const InputAction& other) const;

private:
	const unsigned int m_ActionId;
	PlayerIndex m_PlayerIndex;
	
	std::unordered_map<SDL_Keycode, OutputTriggerState> m_KeyStates;
	std::unordered_map<Uint8, OutputTriggerState> m_MouseStates;
	
	//std::vector<>
	//SDL_Keycode KeyboardCode;
	//Uint8 MouseButtonCode;

	//WORD GamepadButtonCode; //XINPUT_GAMEPAD_...
	
};

