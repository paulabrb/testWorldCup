#include "Game.hpp"
#include "TextureManager.hpp"

SDL_Texture* playerTexture;
SDL_Rect scrR, destR;

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
	else
	{
		std::cout << "Subsystem Initialized" << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if(!window)
			std::cout << "SDL_CreateWindow Error" << std::endl;
		else
			std::cout << "Window Created" << std::endl;

		renderer = SDL_CreateRenderer(window, -1, 0);
		if(!renderer)
			std::cout << "SDL_CreateRenderer Error" << std::endl;
		else
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer Created" << std::endl;
		}

		_running = true;
		_count = 0;

		//Test, display an image


		// SDL_Surface* tempSurface = SDL_LoadBMP("../assets/player.bmp");
		// std::cout << SDL_GetError() << std::endl;
		// playerTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);
		// SDL_FreeSurface(tempSurface);

		playerTexture = TextureManager::IMG_LoadTexture("../assets/player.bmp",renderer);
	
	}
}

void Game::event()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch(event.type)
	{
		case SDL_QUIT:
			_running = false;
			break;

		default:
			break;
	}
}

void Game::update()
{
	_count++;
	destR.h = 64;
	destR.w = 64;

	destR.x = _count;

	//std::cout << _count << std::endl;
}

void Game::render()
{
	SDL_RenderClear(renderer);

	//Add textures to be rendered
	SDL_RenderCopy(renderer, playerTexture, NULL, &destR);
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "End running" << std::endl;
}