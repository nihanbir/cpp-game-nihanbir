#include "Window.h"

Window::Window(int width, int height) : success{}
{
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO))
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return;
	}

	//Create window 
	window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	if (!window)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return;
	}
	//Get window surface
	screenSurface = SDL_GetWindowSurface(window);
	success = true;
}

Window::~Window() {
	//Destroy window
	SDL_DestroyWindow(window);
	window = nullptr;

	//Quit SDL subsystems
	SDL_Quit();
}
/*
void Window::clear() {
	SDL_FillRect();
}*/

void Window::render(Image* image, SDL_Rect* destination) {
	//Apply the image
	SDL_BlitSurface(image->getResource(), nullptr, screenSurface, destination);
	//Update the surface
	SDL_UpdateWindowSurface(window);
}

/*
void Window::present() {
	//Update the surface
	SDL_UpdateWindowSurface(window);
}*/