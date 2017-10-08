#pragma once
//incude input output stream
#include <iostream>

//include string functions
#include <string>
//standard library .h means header
#include <stdlib.h>
#include <thread>//threads
#include <vector>//vectors

#include "gameState.h"



class GameState;

void changeState(GameState* gameState);

using namespace std;

class StateManager {

public:

	//place a new gamestate into the vector
	void pushState(GameState* gameState);

	// take out (pop) a gamestate from the vector
	void popState(GameState* gameState);

	void render();

	void input();

	void determine();

	//change the state with abstract gamestate param, but return nothing, 'void'
	void changeState(GameState* gameState);

private:
	//make a vector of the <Gamestates> called m_states , an array like object
	// this is private
	vector <GameState*> m_states;
};

