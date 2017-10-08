#pragma once
#include "mainMenuState.h"


#include "zorkish1.h"
//#include "GameState.h"

//mainMenuState::mainMenuState()
//{
//}
//
//
//mainMenuState::~mainMenuState()
//{
//}

//inherits all member functions from from GameState 
//a game state i.e main menu state
//input can mean different things in different states
// the public allows access to GameStates private members 
class mainMenuState : public GameState {

	//StateManager* newState;

public:

	void input() {

		std::cin >> mychar;

	};

	//implement the changed state choice
	/*void changeState(GameState* gameState) {
	cout << "main menu change state";
	StateManager* newState;
	newState->changeState(gameState);
	};
	*/
	//overrides GameState init() from other class
	void render() override {

		std::cout << "Zorkish::Main Menu" << std::endl;
		std::cout << "--------------------------------------------------------" << std::endl;
		std::cout << "Welcome to Zorkish Adventures" << std::endl;
		std::cout << "1. Select Adventure and Play" << std::endl;
		std::cout << "2. Hall Of Fame" << std::endl;
		std::cout << "3. Help" << std::endl;
		std::cout << "4. About" << std::endl;
		std::cout << "5. Quit" << std::endl;
		std::cout << "Select 1 - 5:> _" << std::endl;

	}
};