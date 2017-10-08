// gridWorld Game in C++
//author Justin Caddaye
//created August 2017
//Swinburne Games Programming

//incude input output stream
#include <iostream>

//include string functions
#include <string>
#include <stdlib.h>
#include <thread>


using namespace std;

// declaring variables:

//define a string variable
string mystring;

string choice1;

char choice2;

bool newinfo;

// setting the map characters

const char goal = 'G';
const char wall = '#';
const char emptySpace = ' ';
const char trap = 'D';
const char start = 'S';
const char player = 'P';


//set the movement keystrokes
enum Keys
{
	Up = 'n',
	Down = 's',
	Right = 'e',
	Left = 'w',
	Quit = 'q'
};

//set the movement states

enum playerStatus
{
	death,
	exitdoor,
	ooof,
	playerAlive,
	QuitGame

};

// set the map size
const int mapW = 8;
const int mapH = 8;

//set the map size and type 'char'
char gamemap[mapW][mapH];

//when called sets up the map with walls and symbols
void drawMap(char gamemap[mapW][mapH]) {
	//outside walls 
	for (int i = 0; i < 8; ++i)
	{
		gamemap[i][0] = wall;
		gamemap[i][7] = wall;
		gamemap[7][i] = wall;
		gamemap[0][i] = wall;

	}
	//top - bottom wall
	for (int i = 0; i < 6; i++)
	{
		gamemap[4][i] = wall;
	}

	//central wall l-r
	for (int i = 2; i < 6; i++)
	{
		gamemap[i][5] = wall;
	}

	//left wall
	for (int i = 0; i < 3; i++)
	{
		gamemap[i][3] = wall;
	}

	//objects as symbols
	gamemap[1][1] = goal;
	gamemap[3][1] = trap;
	gamemap[5][1] = trap;
	gamemap[6][3] = trap;

	//player
	gamemap[2][7] = player;

}

//when called actually draws the map on the screen
void printmap(const char gamemap[mapW][mapH])
{
	for (int y = 0; y < 8; ++y)
	{
		for (int x = 0; x < 8; ++x)
		{
			cout << gamemap[x][y];
		}
		cout << "\n";
	}
}

//clears the map area by refilling it with spaces
void clearmap(char gamemap[mapW][mapH])
{
	for (int y = 0; y < 8; ++y)
	{
		for (int x = 0; x < 8; ++x)
		{
			gamemap[x][y] = emptySpace;
		}
	}
}

//function called 'moveplayer()' 
//returns a 'Movement' enum e.g. playerAlive
//takes in the map, current positions and next position as params
//curPlayX,Y are referenced with a '&', so we dont alter the original integer
playerStatus moveplayer(char gamemap[mapW][mapH], int & curPlayPosX, int & curPlayPosY, int nextPosX, int nextPosY, bool newinfo2)
{
	
	//check if new info
	if (newinfo2 == true) {

		bool *changeinfo;
		changeinfo = &newinfo2;
		*changeinfo = newinfo2;
		

		// Make sure we dont go off the map edge
		if (nextPosX < 0) { nextPosX = 0; }
		if (nextPosY < 0) { nextPosY = 0; }
		if (nextPosX > 7) { nextPosX = 7; }
		if (nextPosY > 7) { nextPosY = 7; }

		// new word, 'newMove' defined as an enum to be returned by 'movement' function, to create a new gamestate
		playerStatus newMove;

		// see if we hit a trap
		//if the gamemap at this position equal a trap 
		if (gamemap[nextPosX][nextPosY] == trap)
		{
			cout << "You fell down a trap! You died! Sorry!\n";
			//new playerStatus gamestate is death, returned to main()
			newMove = death;
			*changeinfo = false;
			//cout << "in trap" << newinfo2 << *changeinfo<< newMove;
			return newMove;
		}
		else if (gamemap[nextPosX][nextPosY] == goal)
		{
			cout << "You found the exitdoor! Hooray!\n";
			newMove = exitdoor;
			*changeinfo = false;
			//cout << "in exit" << newinfo2 << *changeinfo << newMove;
			return newMove;
		}
		else if (gamemap[nextPosX][nextPosY] == wall)
		{
			cout << "There is a wall there!\n";

			//nothing bad happens, the player is still  alive
			newMove = playerAlive;
			newinfo = false;
			*changeinfo = false;
			//cout << "in wall" << newinfo2 << *changeinfo << newMove;
			//needed so the game continue the move into the wall
			//essentially a 'break', skips the rest of the function below
			return newMove;
		}
		else
		{
			newMove = playerAlive;
		}

		//-----------moves the player symbol---------------------

		// Clear the current player position to empty so he can appear to move
		gamemap[curPlayPosX][curPlayPosY] = emptySpace;

		// Place the 'player' symbol in the new position
		gamemap[nextPosX][nextPosY] = player;

		//make the change in curPlayPosX position to the new position
		curPlayPosX = nextPosX;
		curPlayPosY = nextPosY;

		//-----------returns a new playerStatus-------------------

		newinfo = false;
		//*changeinfo = false;
		//cout << "in return move" << newinfo2 << *changeinfo << newMove;
		
		// return the new game state-- change playerStatus
		return newMove;

	}
}

//print up the introduction
void intro() {
	//---------------begin game welcome---------------------
	mystring = "Welcome to the deadly Maze. Can you find gold and Escape?!";

	cout << mystring << endl;

	//empty new line
	cout << "\n";

	mystring = "You are in a maze of tunnels , press N,S,E,W to move";

	// print out the result: cout means character output , << means next step, endl means end line
	cout << mystring << endl;

	mystring = "Careful, there are pitfalls about!";

	cout << mystring << endl;

	mystring = "----------------------------------------------";

	cout << mystring << endl;

	//---------------end game welcome---------------------

}


// this is the thread fooThread
void playerInput() {

	while (choice2 != 'q')
	{
		//gather the first choice as a string
		cin >> choice1;

		if (choice1 != "q")
		{
			//convert string to lowercase
			for (unsigned int i = 0; i < choice1.size(); i++)
			{
				choice1.at(i) = tolower(choice1.at(i));
			}

			//cast string as a char
			choice2 = choice1[0];
			//choice1 = " in playerInput ";
			newinfo = true;
			//cout << "newinfo=" << newinfo << choice1;

		}
		else {
			newinfo = false;
		}
	}
}

void render(){

	//place player in map position
	int playerPosX = 2;
	int playerPosY = 7;

	// a variable to hold the size of the map, 'gamemap' variable is used IN the function, this is just a number
	char worldmap[8][8];

	// calls the function to clear  the map variable 'gamemap'
	clearmap(worldmap);

	//calls the function to draw the map variable 'gamemap'
	drawMap(worldmap);

	//calls the function to show the map variable 'gamemap' onscreen
	printmap(worldmap);

	// make the player status 'alive'
	playerStatus movement = playerAlive;

	// define varible type to get char value as char
	char *choice4;

	//get the address of choice2 in playerInput()
	choice4 = &choice2;
	
	//get the value of choice2 in playerInput()
	*choice4 = choice2;

	//begin main game loop
	while (movement == playerAlive)
	{
		if (newinfo == true) {

			if (*choice4 == Right)
			{
				//movement is the playerStatus returned after the changes
				//move player is the function call to move and check the playerStatus
				movement = moveplayer(worldmap, playerPosX, playerPosY, playerPosX + 1, playerPosY, newinfo);
				//clears the screen
				//system("cls");

			}
			else if (*choice4 == Left)
			{
				movement = moveplayer(worldmap, playerPosX, playerPosY, playerPosX - 1, playerPosY, newinfo);
				//system("cls");
			}
			else if (*choice4 == Up)
			{
				movement = moveplayer(worldmap, playerPosX, playerPosY, playerPosX, playerPosY - 1, newinfo);
				//system("cls");
			}
			else if (*choice4 == Down)
			{
				movement = moveplayer(worldmap, playerPosX, playerPosY, playerPosX, playerPosY + 1, newinfo);
				//system("cls");
			}
			else if (*choice4 == Quit)
			{
				movement = QuitGame;
			}
			system("cls");
			printmap(worldmap);
		}
	}
}



// main game 
int main()
{
	//get the intro
	intro();

	// Spawn new thread that calls foo()
	thread fooThread(playerInput);
	thread fooThread2(render);
	fooThread.join();
	fooThread2.join();

}
	

	
