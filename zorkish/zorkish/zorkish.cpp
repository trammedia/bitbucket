// zorkish Game in C++
//author Justin Caddaye
//created August 2017
//Swinburne Games Programming

//incude input output stream
#include <iostream>

//include string functions
#include <string>
#include <stdlib.h>
#include <thread>
#include <vector>

using namespace std;

// declaring variables:

//define a string variable
string mystring;

const char mychar = 'a';


void intro() {

	mystring = "";
	cout << mystring;
}

void about() {

	cout << "Zorkish::About";
	cout << "--------------------------------------------------------";
	cout << "Written by : [your name here]";
	cout << "Press ESC or Enter to return to the Main Menu";
}

void help() {

	cout << "Zorkish::Help";
	cout << "--------------------------------------------------------";
	cout << "The following commands are supported :";
	cout << "quit";
	cout << "hiscore(for testing)";
}

void select_adventure() {
	cout << "--------------------------------------------------------";
	cout << "Choose your adventure :";
	cout << "1. Mountain World";
	cout << "2. Water World";
	cout << "3. Box World";
	cout << "Select 1 - 3 :";
}


void hall_of_fame() {}


void high_score() {}


void main_Menu() {
	cout << "Zorkish::Main Menu";
	cout << "--------------------------------------------------------";
	cout << "Welcome to Zorkish Adventures";
	cout << "1. Select Adventure and Play";
	cout << "2. Hall Of Fame";
	cout << "3. Help";
	cout << "4. About";
	cout << "5. Quit";
	cout << "Select 1 - 5:> _";

}


class GameState {
public:

	virtual void init()=0;
	virtual void update(StateManager stateManager)=0;
	virtual void draw(StateManager stateManage) = 0;

	void intro();
	void mainMenu();
	void about();
	void help();
	void select_adventure();
	void hall_of_fame();
	void high_score();

	void changeState(StateManager* stateManager, GameState* gameState)
	{
		stateManager->changeState(gameState);
	}
	
};


void GameState::mainMenu() {
	cout << "Zorkish::Main Menu";
	cout << "--------------------------------------------------------";
	cout << "Welcome to Zorkish Adventures";
	cout << "1. Select Adventure and Play";
	cout << "2. Hall Of Fame";
	cout << "3. Help";
	cout << "4. About";
	cout << "5. Quit";
	cout << "Select 1 - 5:> _";
}


// this will manage the game states 
//pushing and popping them out of a vector (array like) storage
class StateManager {

public:
	
	void init();
	//
	void update();
	//change the state with gamestate params
	void changeState(GameState* gameState);
	//place a new gamestate into the vector
	void pushState(GameState* gameState);
	// take out (pop) a gamestate from the vector
	void popState();
	void draw();
	//clear the states
	void clear();
	bool gameRunning() { return m_running; }

private:
	//make a vector of the states
	vector<GameState*> states;
	
	bool m_running;
};

void StateManager::init(){}
void StateManager::update(){}
void StateManager::changeState(GameState* gameState) {}
void StateManager::pushState(GameState* gameState){}
void StateManager::popState(){}
void StateManager::clear() {}


class introState {
public:
	 void Instance();
	 void intro();
};
void introState() {};
class Instance {};
void Instance() {};
class mainMenu {};
class about{};
class help {};
class select_adventure {};
class hall_of_fame{};
class high_score {};

int main(int argc, char *argv[]) {

	// make a new game state called stateManager
	StateManager stateManager;

	//initialize the game state
	stateManager.init();

	stateManager.changeState(introState::intro());

	while (stateManager.gameRunning());
	{
		stateManager.update();
		stateManager.draw();
	}
	return 0;
}

void introState::Instance()
{
}
