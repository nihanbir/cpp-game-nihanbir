#include "Window.h"
#include <cstdio>
#include <SDL.h>

bool Window::init(int width, int height)
{
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO))
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return false;
	}

	//Create window 
	gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	if (!gWindow)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return false;
	}
	//Get window surface
	gScreenSurface = SDL_GetWindowSurface(gWindow);
	return true;
}

Window::~Window() {
	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = nullptr;

	//Quit SDL subsystems
	SDL_Quit();
}

void Window::render(Image& image) {
	//Apply the image
	SDL_BlitSurface(image.getResource(), nullptr, gScreenSurface, nullptr);
	//Update the surface
	SDL_UpdateWindowSurface(gWindow);
}