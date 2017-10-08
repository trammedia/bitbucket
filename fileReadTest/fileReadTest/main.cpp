#include <istream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <stdlib.h>
//#include "Area.h"
//#include "main.h"
//#include "GameState.h"
//#include "StateManager.h"

//--Global Variable Declaration---

char mychar;

std::string mystring;

// gets the whole line, puts the heading into the key, value into the element by Csv file 'Comma separated values'
//
std::unordered_multimap<std::string, std::string> getMap3(std::unordered_multimap<std::string, std::string> mapped2)
{
	std::ifstream myfile;
	int i = 0;
	std::string line, desc, exits, idNum;
	
	std::cout << "\n -----------Map Listings-------------- \n";

	//open the text file
	myfile.open("adventure4.txt");

	if (myfile.is_open())
	{
		while (myfile.good())
		{
			//get all the characters until ':'
			getline(myfile, mystring, ':');
			std::cout << "name: " << mystring << " " << std::endl;
			//add then into the map as 'name,name'
			mapped2.insert({ mystring ,mystring });
			
			//get the new char until ':'
			getline(myfile, idNum, ':');
			std::cout << "ID: " << idNum << " "<< std::endl;
			// add as 'name, idnumber'
			mapped2.insert({ mystring ,idNum });

			getline(myfile, desc, ':');
			std::cout << "desc: " << desc << " ";
			mapped2.insert({ mystring ,desc });

			//get the exits as a group
			getline(myfile, exits);
			std::cout << "exits: " << exits << " "<< std::endl;
			// get the group characters
			std::stringstream ss(exits);

			std::string token;
			std::string token2;
			//get all the characters from the group break at ',' i.e. 'south'
			//nect pass will get the number i.e.'4'
			while(std::getline(ss,token,','))
			{
				std::cout << token << "\n";
				// add into the map as 'name, exit to room number'
				mapped2.insert({ mystring ,token });
				
			}
		}
	};

	myfile.close();

	std::cout << " \n -----------Map Listings End--------------\n";

	return mapped2;
}

int main() {

	typedef std::unordered_multimap<std::string, std::string> defineArea;
	
	defineArea mapped2;

	//assign results of getMap to mapped2
	mapped2 = getMap3(mapped2);

	//print all entries by iteration
	for (auto it = mapped2.begin(); it != mapped2.end(); ++it) {
		//std::cout << "\n";
		std::cout << " first entry about the map.= " << it->first << std::endl;
		std::cout << " 2nd entry= " << it->second << std::endl;
	};

	//cycle through all entries that begin with 'a'
	std::cout << "Entries with a:" << std::endl;
	auto range = mapped2.equal_range("Staircase");
	for_each(
		range.first,
		range.second,
		
		[](defineArea::value_type& x) {std::cout << " " << x.second << std::endl; }
	);

	//create a new area and give it's details
	//Area * areaState;
	//areaState = new Area();
	//areaState->name = "River";
	////areaState->name. mapped2.begin();
	//areaState->description = "Your at a bend in the river. There are is a path north. A path across the river to the east. Or you can go south to the wood along a dirt track.";
	//areaState->mapExits.push_back("n");
	//areaState->mapExits.push_back("s");
	//areaState->mapExits.push_back("e");

	std::cin >> mystring;
	return 0; 
}