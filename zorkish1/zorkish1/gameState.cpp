#include "gameState.h"
#include "zorkish1.h"

// declaring variables:
//define a string outside a class makes it a global variable
string mystring;

char mychar;


//inherits all member functions from from GameState 
//a game state i.e main menu state
//init can mean different things in different states
class mainMenuState : public GameState {

	StateManager* newState;

public:

	void input() {

		cin >> mychar;
		cout << "main menu input state";

	};

	void determine() {
		if (mychar == 2) {
			GameState* gameState;
			gameState = new chooseAdventureState();
		}
	}

	//implement the changed state choice
	void changeState(GameState* gameState) {
		cout << "main menu change state";
		newState->changeState(gameState);
	};

	//overrides GameState init() from other class
	void render() override {

		cout << "Zorkish::Main Menu" << endl;
		cout << "--------------------------------------------------------" << endl;
		cout << "Welcome to Zorkish Adventures" << endl;
		cout << "1. Select Adventure and Play" << endl;
		cout << "2. Hall Of Fame" << endl;
		cout << "3. Help" << endl;
		cout << "4. About" << endl;
		cout << "5. Quit" << endl;
		cout << "Select 1 - 5:> _" << endl;

	}
};

//
class chooseAdventureState : public GameState {
public:

	StateManager* newState;

	void input() { cin >> mychar; }

	void changeState(StateManager* newState) {
	}

	//overrides GameState init() from other class
	void render() override {

		cout << "--------------------------------------------------------";
		cout << "Choose your adventure :" << endl;
		cout << "1. Mountain World" << endl;
		cout << "2. Water World" << endl;
		cout << "3. Box World" << endl;
		cout << "Select 1 - 3 :" << endl;
	}

};
//
class highScoreState : public GameState {
public:

	virtual void input() { cin >> mychar; };
	virtual void changeState(StateManager* newState) {
	};
	//overrides GameState init() from other class
	virtual void render() override {

		cout << "Zorkish::Hall Of Fame";
		cout << "--------------------------------------------------------" << endl;
		cout << "Top 10 Zorkish Adventure Champions" << endl;
		cout << "1. Fred, Mountain World, 5000" << endl;
		cout << "2. Mary, Mountain World, 4000" << endl;
		cout << "3. Joe, Water World, 3000" << endl;
		cout << "4. Henry, Mountain World, 2000" << endl;
		cout << "5. Susan, Mountain World, 1000" << endl;
		cout << "6. Alfred, Water World, 900" << endl;
		cout << "7. Clark, Mountain World, 800" << endl;
		cout << "8. Harold, Mountain World, 500" << endl;
		cout << "9. Julie, Water World, 300" << endl;
		cout << "10. Bill, Box World, -5" << endl;
		cout << "Press ESC or Enter to return to the Main Menu" << endl;
	}

};

//
class helpState : public GameState {
public:

	void input() override { cin >> mychar; };
	void changeState(StateManager* newState) {
	};
	//overrides GameState draw() from other class
	void render() override {

		cout << "Zorkish::Help" << endl;
		cout << "--------------------------------------------------------" << endl;
		cout << "The following commands are supported :" << endl;
		cout << "quit" << endl;
		cout << "hiscore(for testing)" << endl;
	}

};

//
class aboutState : public GameState {
public:

	virtual void input() override { cin >> mychar; };
	virtual void changeState(StateManager* newState) {
	};
	//overrides GameState init() from other class
	virtual void render() override {

		cout << "Zorkish::About" << endl;
		cout << "--------------------------------------------------------" << endl;
		cout << "Written by : Justin C" << endl;
		cout << "Press ESC or Enter to return to the Main Menu" << endl;
		std::cin >> mychar;
	}

};



