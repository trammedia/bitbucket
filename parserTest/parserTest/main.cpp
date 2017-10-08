#include <sstream>
#include <istream>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <algorithm>
#include <vector>

std::vector <std::string> command;

std::string mystring;

std::vector <std::string> test(std::vector <std::string> command, std::string mystring) {

	std::string line;

	std::string action;

	// grab a line from standard input

	// break the input in to tokens using a space as the delimeter
	std::istringstream stream(mystring);

	std::string token;
	std::string token2;

	// break the input in to tokens using a space as the delimeter
	while (getline(stream, token, ' ')) {

		// convert string to all caps
		//transform(token.begin(), token.end(), token.begin(), (int(*)(int)) tolower);

		// print each token on a separate line
		std::cout << "token 1 " << token << std::endl;

		//put token into array
		command.push_back(token);
		std::cin >> mystring;
		//std::cout << "stream " << stream << std::endl;
		std::istringstream stream(mystring);
		////get new token
		getline(stream, token2, '\0');
		command.push_back(token2);
		
		//// print each token on a separate line
		std::cout << "token 2" << token2 << std::endl;
		////put token into array
		//command.push_back(token);
		
		return command;
	};
};

int main() {
	
	std::cin >> mystring;

	command = test(command, mystring);
	std::cout << command[0] << "com2" << std::endl;
	std::cout << command[1] << "com1" << std::endl;
			if (command[0] == "l" || command[0] == "look")
			{
				std::cout << "look!!! \n";
				//		this->changeState(gameState, mapped2);
				//this->Look();
			};
			if (mystring == "e" || mystring == "exit")
			{
				std::cout << "---Exits!---\n";
				//this->Exits();
			};
			if (command[0] == "g" || command[0] == "go")
			{
				std::cout << "---change!---\n";
				//this->changeState(gameState, mapped2);
			}
			else { std::cout << "nah"; };

			std::cin >> mystring;
		
return 0; 

};