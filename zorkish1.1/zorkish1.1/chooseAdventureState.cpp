#pragma once

#include "chooseAdventureState.h"



//chooseAdventureState::chooseAdventureState()
//{
//}
//
//
//chooseAdventureState::~chooseAdventureState()
//{
//}


//choose adventure state class event
class chooseAdventureState : public GameState {

public:

	//StateManager* newState;

	void input() { std::cin >> mychar; }

	/*void changeState(StateManager* newState) {
	}*/

	//overrides GameState init() from other class
	void render() override {

		std::cout << "--------------------------------------------------------" << std::endl;
		std::cout << "Choose your adventure :" << std::endl;
		std::cout << "1. Mountain World" << std::endl;
		std::cout << "2. Water World" << std::endl;
		std::cout << "3. Box World" << std::endl;
		std::cout << "Select 1 - 3 :" << std::endl;
	}

};