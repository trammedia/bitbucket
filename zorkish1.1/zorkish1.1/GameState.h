#pragma once
//#include "zorkish1.h"
////#include "StateManager.h"
//class StateManager;

// --------------------------------GameState_Class--------------------------------

//class GameState holds the stages of a gameState
class GameState {

public:

	GameState();
	~GameState();

	/*std::string gameStateName;

	inline std::string printItems() const
	{
		return this->gameStateName;
	};*/

	virtual void input() = 0;

	// virtual means it can be passed through to another class- this is just a empty pattern
	virtual void render() = 0;

	//void changeState(GameState* game);
};

