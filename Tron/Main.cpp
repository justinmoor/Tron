#include <iostream>
#include "Game.h"

int main(){

	try {
		Game game;
		game.run();
	} catch (std::exception &e) {
		std::cout << "\n Something went wrong: " << e.what() << std::endl;
	}
		
	return EXIT_SUCCESS;
}
