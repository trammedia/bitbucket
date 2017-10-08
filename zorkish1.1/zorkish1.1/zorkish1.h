#pragma once
// zorkish Game in C++
//author Justin Caddaye
//created August 2017
//Swinburne Games Programming

//incude input output stream
#include <iostream>
//include string functions
#include <string>
//standard library .h means header
#include <stdlib.h>
#include <thread>
#include <vector>

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
//--------------------------------GLOBAL_VARIABLES-------------------------------

// declaring  variables:
//define a string outside a class makes it a global variable
std::string mystring;

char mychar;
