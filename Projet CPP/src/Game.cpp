#include "Game.hpp"

Game::Game()
{}

Game::~Game()
{}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if(fullscreen)
		flags = SDL_WINDOW_FULLSCREEN;

	if(SDL_Init(SDL_INIT_EVERYTHING))
	{
		std::cout << "SDL_Init Error" << std::endl;
		_running = false;
	}
	std::cout << "Subsystem Initialized" << std::endl;

	window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
	if(!window)
	{
		std::cout << "SDL_CreateWindow Error" << std::endl;
		_running = false;
	}
	std::cout << "Window Created" << std::endl;

	renderer = SDL_CreateRenderer(window, -1, 0);
	if(!renderer)
	{
		std::cout << "SDL_CreateRenderer Error" << std::endl;
		_running = false;
	}
	std::cout << "Renderer Created" << std::endl;

	_running = true;
}

void Game::event()
{

}

void Game::update()
{
	
}

void Game::render()
{

}

void Game::clean()
{
	
}