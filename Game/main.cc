#include <SFML/Graphics.hpp>
#include "Game.h"
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		std::cout << argv[1] << '\n';
		Game game{argv[1]};
		game.run();
	}
	else
	{
		std::cerr << "Needs a map file as an argument" << '\n';
		return 1;
	}
	

	return 0;
}
