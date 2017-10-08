// zorkish Game in C++
//author Justin Caddaye
//created August 2017
//Swinburne Games Programming

#include "gameState.h"
#include "zorkish1.h"
#include "stateManager.h"

using namespace std;

class GameState;
class mainMenuState;
class StateManager;

//char mychar;

int main() { 
	// makes a pointer to Gamestate
	GameState * gameState;
	
	////makes a new gamestate
	gameState = new mainMenuState();

	// make a new state called newState with a pointer *- instantiate
	StateManager* newState = new StateManager();
	
	//set/change the state to main menu
	newState->changeState(gameState);
	
	// while q isn't chosen
	while (mychar != 'q') {

		// draws the gameState
		newState->render();
		
		//gets imput
		newState->input();

		newState->determine();

		//changes the state
		newState->changeState(gameState);
		
	}

	return 0;
}