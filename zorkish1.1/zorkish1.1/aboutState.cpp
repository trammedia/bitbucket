#pragma once

#include "aboutState.h"

//
//
//aboutState::aboutState()
//{
//}
//
//
//aboutState::~aboutState()
//{
//}


//
class aboutState : public GameState {
public:

	virtual void input() override { std::cin >> mychar; };
	virtual void changeState(StateManager* newState) {
	};
	//overrides GameState init() from other class
	virtual void render() override {

		std::cout << "Zorkish::About" << std::endl;
		std::cout << "--------------------------------------------------------" << std::endl;
		std::cout << "Written by : Justin C" << std::endl;
		std::cout << "Press ESC or Enter to return to the Main Menu" << std::endl;
		std::cin >> mychar;
	}

};