#pragma once
#include "highScoreState.h"


//
//highScoreState::highScoreState()
//{
//}
//
//
//highScoreState::~highScoreState()
//{
//}


//
class highScoreState : public GameState {
public:
	
	virtual void input() { std::cin >> mychar; };
	virtual void changeState(StateManager* newState) {
	};
	//overrides GameState init() from other class
	virtual void render() override {

		std::cout << "Zorkish::Hall Of Fame" << std::endl;
		std::cout << "--------------------------------------------------------" << std::endl;
		std::cout << "Top 10 Zorkish Adventure Champions" << std::endl;
		std::cout << "1. Fred, Mountain World, 5000" << std::endl;
		std::cout << "2. Mary, Mountain World, 4000" << std::endl;
		std::cout << "3. Joe, Water World, 3000" << std::endl;
		std::cout << "4. Henry, Mountain World, 2000" << std::endl;
		std::cout << "5. Susan, Mountain World, 1000" << std::endl;
		std::cout << "6. Alfred, Water World, 900" << std::endl;
		std::cout << "7. Clark, Mountain World, 800" << std::endl;
		std::cout << "8. Harold, Mountain World, 500" << std::endl;
		std::cout << "9. Julie, Water World, 300" << std::endl;
		std::cout << "10. Bill, Box World, -5" << std::endl;
		std::cout << "Press ESC or Enter to return to the Main Menu" << std::endl;
	}

};