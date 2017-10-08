#include "zorkish1.h"

#include "GameState.h"
#include "StateManager.h"
#include "Inventory.h"
#include "PlayerCharacter.h"
#include "Item.h"

//#include "mainMenuState.h"
#include "chooseAdventureState.h"
#include "aboutState.h"
#include "highScoreState.h"
#include "helpState.h"



//--------------------------------Forward_Declarations-------------------------------

class StateManager;
class chooseAdventureState;
class mainMenuState;



// ------------------------------------------main--------------------------------

int main() {
	// makes a pointer to Gamestate
	GameState * gameState ;

	//gameState->gameStateName(mainMenuState);
	//gameState->changeState( gameState );
	

	////makes a new gamestate
	gameState = new mainMenuState();

	// make a new state called newState with a pointer *- instantiate
	StateManager* newState = new StateManager();

	//set/change the state to main menu
	newState->changeState(gameState);

	// while q isn't chosen
	while (mychar != 'q')
	{

		// draws the gameState
		newState->render();

		//gets imput
		newState->input();

		//newState->determine();

		//changes the state
		//newState->changeState(gameState);

		if (mychar == '1'){
			gameState = new chooseAdventureState();
			newState->changeState(gameState);
		}
		if (mychar == '2') {
			gameState = new highScoreState();
			newState->changeState(gameState);
		}
		if (mychar == '3') {
			gameState = new helpState();
			newState->changeState(gameState);
		}
		if (mychar == '4') {
			gameState = new aboutState();
			newState->changeState(gameState);
		}
		
		if (mychar == 'esc') {
			gameState = new mainMenuState();
			newState->changeState(gameState);
		}
		if (mychar == '5') {
			mychar = 'q';
		}
	}

	//creates a new Item variable called 'item'
	Item item;
	//make the new item variables name equal to 'cat'
	item.itemName = "cat";
	// create a new inventory variable
	Inventory inventory;

	inventory.addItem(item);
	// add a new item to the inventory
		
	item.itemName = "dog";
	inventory.addItem(item);

	inventory.printItems();

	std::cout << "add your name: ";
	std::cin >> mystring;
	//create variable called playercharacter
	PlayerCharacter playerCharacter;
	//initialize characyer with user string
	playerCharacter.initialize(mystring);
	//print out new name
	playerCharacter.printName();

	while (mystring != "q")
	{
		inventory.getItem(inventory, item);
	}

	return 0;
}

