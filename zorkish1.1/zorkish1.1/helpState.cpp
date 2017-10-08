#pragma once

#include "helpState.h"

//
//
//helpState::helpState()
//{
//}
//
//
//helpState::~helpState()
//{
//}


//
class helpState : public GameState {
public:

	void input() override { std::cin >> mychar; };
	void changeState(StateManager* newState) {
	};
	//overrides GameState draw() from other class
	void render() override {

		std::cout << "Zorkish::Help" << std::endl;
		std::cout << "--------------------------------------------------------" << std::endl;
		std::cout << "The following commands are supported :" << std::endl;
		std::cout << "quit" << std::endl;
		std::cout << "hiscore(for testing)" << std::endl;
	}

};