#pragma once
//incude input output stream
#include <iostream>

//include string functions
#include <string>
#include <stdlib.h>//standard library .h means header
#include <thread>//threads
#include <vector>//vectors
#include "stateManager.h"

class Statemanager;

using namespace std;

char mychar;

//class GameState holds the stages of a gameState
class GameState {

public:
	virtual void input() = 0;

	// virtual means it can be passed through to another class- this is just a empty pattern
	virtual void render() = 0;

	 void determine();

	//friend class StateManager;

	void changeState(GameState* game) ;
};

class mainMenuState {};
