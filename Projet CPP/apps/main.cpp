#include <iostream>

#include "Game.hpp"

int main(int argc, char const *argv[])
{
	Game *game = nullptr;

	game = new Game();

	game->init("WorldCup", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	while(game->running()) {

		game->event();
		game->update();
		game->render();

	}

	game->clean();

	return 0;
}