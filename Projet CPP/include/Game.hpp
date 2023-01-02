#pragma once

#include <iostream>
#include <SDL2/SDL.h>

class Game {

public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	
	void event();
	void update();
	void render();
	void clean();

	bool running() {return _running;};

private:
	bool _running;
	SDL_Window* window;
	SDL_Renderer* renderer;

};